#include <stdio.h>

void pascalTriangle(int n){
	int a[n][n];
	// 第一列全部都是1
	for(int i = 0; i < n; i++){
		a[i][0] = 1;
	}
	// 最后一列全部都是1
	for(int i = 1; i < n; i++){
		a[i][i] = 1;
	}
	// 从第三行下标为2开始，每个数是上一行两个数的和
	for(int i = 2; i < n; i++){
		for(int j = 1; j < i; j++){
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}

	// 打印数组
	for(int i = 0; i < n; i++){
		// 打印空格
		for(int k = n; k > i; k--){
			printf(" ");
		}
		// 输出数据
		for(int j = 0; j <= i; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main(){

	pascalTriangle(6);

	return 0;
}