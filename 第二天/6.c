#include <stdio.h>

// 打印9*9乘法表
void mul99(){
	for(int i = 1; i <= 9; i++){ // 第一层for循环控制行数
		for(int j = 1; j <= i; j++){ // 第二层for循环控制列数
			printf("%d * %d = %d\t", j, i, i*j);
		}
		printf("\n");
	}
}

// 平面等腰三角形
void eqTrangle(){
	for(int i = 1; i <= 6; i++){
		for(int k = 6; k > i; k--){
			printf(" ");
		}
		for(int j = 1; j <= i; j++){
			printf("*");
		}
		for(int n = 2; n <= i; n++){
			printf("*");
		}
		printf("\n");
	}
}

// 倒立等腰三角形
void reflectEqTrangle(){
	for(int i = 1; i <= 6; i++){
		for(int k = 1; k < i; k++){
			printf(" ");
		}
		for(int j = 6; j >= i; j--){
			printf("*");
		}
		for(int n = 5; n >= i; n--){
			printf("*");
		}
		printf("\n");
	}
}

int main(){

	mul99();

	eqTrangle();

	reflectEqTrangle();

	return 0;
}