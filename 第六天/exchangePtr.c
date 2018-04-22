#include <stdio.h>

// 地址不变，交换所存储的数值
void swap(int *p, int *q){
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

int main(){

	int a = 1, b = 2;
	swap(&a, &b);
	printf("a is %d\tb is %d\n", a, b);

	return 0;
}