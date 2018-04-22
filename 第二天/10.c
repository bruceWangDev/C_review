#include <stdio.h>

// 计算阶乘
void factorial(int num){
	int mul = 1, sum = 0;
	for(int i = 1; i <= num; i++){
		mul *= i;
		printf("第%d循环的阶乘是%d\n", i, mul);
		sum += mul;
		printf("阶乘每次相加的和是%d\n", sum);
	}
	// printf("%d的阶乘是%d\n", num, sum);
}

int main(){

	factorial(6);

	return 0;
}