#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <malloc.h>
#include <memory.h> 

#define BUFFER_SIZE 50
#define MAX_LINE 80

char buffer[BUFFER_SIZE];
char* shared_memory;
 /* 每次输入的命令规定不超过80个字符 */
/* * setup() 用于读入下一行输入的命令，并将它分成没有空格的命令和参数存于数组args[]中，
 * 用NULL作为数组结束的标志 
 */
/*
 * setup() 用于读入下一行输入的命令，并将它分成没有空格的命令和参数存于数组args[]中，
 * 用NULL作为数组结束的标志 
 */

void setup(char inputBuffer[], char *args[], int *background)
{
    int length, /* 命令的字符数目 */
        i,      /* 循环变量 */
        start,  /* 命令的第一个字符位置 */
        ct;     /* 下一个参数存入args[]的位置 */
    
    ct = 0;
    /* 读入命令行字符，存入inputBuffer */
    length = read(STDIN_FILENO, inputBuffer, MAX_LINE);  
    start = -1;
    
    if (length == 0) exit(0);       /* 输入ctrl+d，结束shell程序 */
    if (length < 0){ 
        perror("error reading the command");
    	exit(-1);           /* 出错时用错误码-1结束shell */
    }    
  	/* 检查inputBuffer中的每一个字符 */
    for (i=0; i<length; i++) { 
        switch (inputBuffer[i]){
      		case ' ':
      		case '\t' :               /* 字符为分割参数的空格或制表符(tab)'\t'*/
      			if(start != -1){
            		args[ct] = &inputBuffer[start];    
          			ct++;
      			}
        		inputBuffer[i] = '\0'; /* 设置 C string 的结束符 */
      			start = -1;
      			break;

        	case '\n':                 /* 命令行结束 */
      			if (start != -1){
                	args[ct] = &inputBuffer[start];     
          			ct++;
      			}
            	inputBuffer[i] = '\0';
            	args[ct] = NULL;  /* 命令及参数结束 */
      			break;

      		default :             /* 其他字符 */
      			if (start == -1)
          			start = i;
            	if (inputBuffer[i] == '&'){  
          			*background  = 1;          /*置命令在后台运行*/
                	inputBuffer[i] = '\0';
            	}
    	} 
    }    
    args[ct] = NULL; /* 命令字符数 > 80 */
} 

void handle_SIGIHT(){
	write(STDIN_FILENO, shared_memory, strlen(shared_memory));
	exit(0);
}

int main(void)
{
	int segment_id;
	const int segment_size = 1024;
	segment_id = shmget(IPC_PRIVATE, segment_size, S_IRUSR | S_IWUSR);
	shared_memory = (char*)shmat(segment_id, NULL, 0);
    char inputBuffer[MAX_LINE]; /* 这个缓存用来存放输入的命令*/
    int background;             /* ==1时，表示在后台运行命令，即在命令后加上'&' */
    char *args[MAX_LINE/2+1];/* 命令最多40个参数 */

    /*创建信号处理器*/
    struct sigaction handler;
    handler.sa_handler = handle_SIGIHT;
    sigaction(SIGINT, &handler, NULL);

    while (1){            /* 程序在setup中正常结束*/
    	background = 0;
    	printf("COMMAND->"); //输出提示符，没有换行，仅将字符串送入输出缓存
        fflush(stdout);                          //输出缓存内容
    	setup(inputBuffer,args,&background);       /* 获取下一个输入的命令 */
    	/* 这一步要做:
     	(1) 用fork()产生一个子进程
     	(2) 子进程将调用execvp()执行命令,即 execvp(args[0],args);
     	(3) 如果 background == 0, 父进程将等待子进程结束, 即if(background==0) wait(0);
         否则，将回到函数setup()中等待新命令输入.
    	*/
    	pid_t pid = fork();
    	// 子进程
    	if (pid == 0){
    	 	//execvp(args[0],args);
			int i;
			strcat(shared_memory, "\n");
    		for (i = 0; i < sizeof(args); ++i)
    		{
    			strcat(shared_memory, args[i]);	
				if(args[i] == NULL)
					strcat(shared_memory, "\n");
				else
					strcat(shared_memory, " ");
    		}
			execvp(args[0],args);	
    	}
    	// 父进程
    	else if (pid > 0){
    	 	if(background==0) wait(0);
    	 	else setup(inputBuffer, args, &background);
    	}
    }
}
