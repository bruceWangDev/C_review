#include <stdio.h>
#include "common.h"

// 结构体
struct MyStruct{
	int a;
	int b;
	int c;
};

// 用指针来遍历数组
void traverseArr(int arr[], int n){

	int *p = arr;
	for(int i = 0; i < n; i++){
		// (*p)++;
		printf("%d\n", *p);				
		p++;
	}
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);
	// getArr(arr, len);
	// printArr(arr, len);

	// traverseArr(arr, len);

	// 声明了结构体对象 ss
	struct MyStruct ss = {11, 22, 33};

	struct MyStruct *p = &ss;

	int *p1 = (int*)&ss;

	printf("%d\n", (*p).a);

	printf("%d\n", *p1+2);

	return 0;
}
