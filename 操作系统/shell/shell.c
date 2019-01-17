#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define  SIZE  1024		// 缓冲区大小

void getCmd(char *buff, char *cmd[]);			 // 获取命令
void showShell(void);							 // 显示终端提示符
void getInput(char buff[]);						 // 获取输入
void insertChar(char buff[], char ch, int *idx); // 字符插入
void deleteChar(char buff[], int *idx);			 // 字符删除
void moveRight(char buff[], int *idx);			 // 光标右移
void moveLeft(char buff[], int *idx);			 // 光标左移

int main(void)
{
	char buff[SIZE] = {0};	// 用户输入
	char *cmd[20];			// 把输入转换为终端命令

	/* 配置界面 */
	system("stty -echo");	// 关闭回显
	system("stty -icanon");	// 关闭缓冲

	/* 进入终端循环 */
	while (1)
	{
		/* 显示终端提示符 */
		showShell();

		/* 获取用户输入 */
		getInput(buff);

		/* 把用户输入转换为终端命令 */
		getCmd(buff,cmd);
		if (NULL == cmd[0])	// 用户输入的回车
		{
			continue;
		}

		/* 命令为exit则退出终端 */
		else if (strcmp(cmd[0],"exit") == 0)
		{
			putchar('\n');			// 退出前换行
			system("stty echo");	// 恢复回显
			system("stty icanon");	// 恢复缓冲
			return 0;
		}

		/* 创建子进程执行用户输入命令 */
		if (0 == fork())
		{
			putchar('\n');		// 把命令执行结果换行显示
			execvp(cmd[0], cmd);
			perror(cmd[0]);		// 如果返回则说明执行错误
			exit(EXIT_FAILURE);
		}

		wait(NULL);	// 回收子进程
	}
}

void getInput(char buff[])
{
	char ch;
	int idx = 0;	// 光标索引
	buff[0] = '\0';

	/* 保存光标位置 */
	printf("\033[s");
	fflush(stdout);

	/* 进入获取用户输入循环，直到输入完成 */
	while (1)
	{
		ch = getchar();
		if ('\033' == ch && getchar() == '[')  // 方向键
		{
			switch (ch = getchar())
			{
				case 'C': moveRight(buff,&idx); break;
				case 'D': moveLeft(buff,&idx);  break;
				default : break;
	 		}
			continue;
		}

		/* 其它键 */
		switch (ch)
		{
			case 127 : deleteChar(buff, &idx);    break;
			case '\n': 					  	     return;
			default  : insertChar(buff, ch, &idx);break; 
		}

		/* 恢复光标-清除光标至行末尾-打印命令-恢复光标位置 */
		printf("\033[u\033[K%s\033[u", buff);

		/* 光标与下标关联 */
		if (idx > 0)
		{
			printf("\033[%dC", idx);
		}
		fflush(stdout);
	}
}

void insertChar(char buff[], char ch, int *idx)
{
	/* 越界问题由光标移动解决 */
	if (strlen(buff) < SIZE-1)
	{
		/* 光标以后的字符右移 */
		memmove(buff+*idx+1,buff+*idx,strlen(buff)-*idx+1);
		buff[*idx] = ch; // 光标处插入字符
		(*idx)++;
	}	
}

void deleteChar(char buff[], int *idx)
{
	if (idx > 0)
	{
		/* 通过移动覆盖达到删除的目的 */
		memmove(buff+*idx-1,buff+*idx,strlen(buff)-*idx+1);
	}
	(*idx)--;
}

void moveRight(char buff[], int *idx)
{
	if (*idx < strlen(buff))
		(*idx)++;
}

void moveLeft(char buff[], int *idx)
{
	if (*idx > 0)
		(*idx)--;
}

void getCmd(char *buff, char *cmd[])
{
	int idx = 0;
	char *ret;

	ret = strtok(buff," \t\n"); // 分割命令
	while (1)
	{
		cmd[idx++] = ret;
		if (NULL == ret)		// 分割命令结束
			return;
		ret = strtok(NULL," \t\n");
	}
}

void showShell(void)
{
	/* 终端提示符组成：[用户名+@+主机名+当前目录]+用户提示符 */
	
	uid_t uid;
	char *ret;
	struct  passwd *user;
	char hostname[100];
	char cwd[120];

	/* 获取用户id */
	uid = getuid();

	/* 根据uid获取用户的passwd结构体 */
	user = getpwuid(uid);
	printf("[%s@",user->pw_name); // 打印用户名

	/* 获取主机名 */
	gethostname(hostname, 100);
	printf("%s:", hostname);	  // 打印主机名

	/* 获取当前工作目录 */
	getcwd(cwd, 120);
	if (strcmp(cwd,user->pw_dir) == 0)
	{
		printf("~"); 			  // 家目录特殊处理
	}
	else
	{
		ret = strrchr(cwd,'/');   // 获取路径的最后一个目录
		if (ret[1] == '\0')
		{
			printf("/]");		  // 根目录
		}
		else
		{
			printf("%s]",ret+1);
		}
	}

	/* 打印用户提示符 */
	if (0 == uid)
	{
		printf("# ");		// 超级用户
	}
	else
	{
		printf("$ ");		// 普通用户
	}

	fflush(stdout);			// 刷新终端提示符
}


