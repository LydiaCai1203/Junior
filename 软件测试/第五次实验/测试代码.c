#include<stdio.h>
#include<stdlib.h>

void kleeTest(int a){
	int arr[10];
	int d[10];

	for (int i = 0; i < 10; i++){ //赋初始值
		arr[i] = i;
	}

	if (a < -50){  //求余分母为0
		for (int i = 0; i < 10; i++){
			int num = i;
			d[i] = arr[i] % num;
		}
	}
	else if(a < -25){  //除法分母为0
		for (int i = 0; i <= 10; i++){
			int num = i ;
			d[i] = arr[i] / num;
		}
	}
	else if (a < 0){  //数组越界
		for(int i = 0; i<= 11; i++){
			arr[i] = i;
		}
	}
	else if (a < 25){  //空指针
		int *a = NULL;
		int b = *a + 1;
	}
	else if(a < 50){  //内存泄漏
		free(arr);
	}
}

int main(){
	int n;
	klee_make_symbolic(&n, sizeof(n), "n");
	kleeTest(n);
	return 0;
}