#include <stdio.h>

// 判断素数
int isPrimeNumber(int num){
	if(num <= 2){
		// printf("N\n");
		return 0;
	}else{
		for(int i = 2; i < num; i++){
			if(num % i == 0){ // 如果能被整除说明不是素数
				// printf("N\n");
				return 0;
			}
		}
	}
	// printf("Y\n");
	return 1;
}

enum BOOL {
	FALSE,
	TRUE
}flag;

// 打印0-100内的素数并统计个数 .. 
void printPrimeNumber(){
	int count = 0;
	
	// 从2开始 .. 
	for(int i = 2; i <= 100; i++){
		int flag = 1;
		for(int j = 2; j < i; j++){
			if(i % j == 0){
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			count++;
			printf("%d\n", i);
		}
	}
	printf("count is %d\n", count);
}

int main(){

	// int num = isPrimeNumber(4);
	// printf("BOOL isPrimeNumber %d\n", num);

	printPrimeNumber();

	return 0;
}