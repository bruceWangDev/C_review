#include <stdio.h>

// study 如何自定义一个C语言头文件 .. 
// 其实只需要一个.h文件 里面放代码就好，用双引号引用
#include "common.h"

void shellSort(int arr[], int n){
	int temp;
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i++){
			for(int j = i - gap; (j >= 0)&&(arr[j] > arr[j + gap]); j-= gap){
				temp = arr[j];
				arr[j] = arr[j + gap];
				arr[j + gap] = temp;
			}
		}
	}
}

// void shellSort2(int arr[], int n){
// 	int temp;
// 	for(int d = n/2; d > 0; d /= 2){
// 		for(int i = d; i < n; i++){
// 			temp = arr[i];
// 			for(int j = i; j >= d && arr[j - d] > temp; j -= d){
// 				arr[i] = arr[i - d];
// 			}
// 			arr[i] = temp;
// 		}
// 	}
// }

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printArr(arr, len);

	shellSort(arr, len);
	printf("shellSort result is:\n");
	printArr(arr, len);

	return 0;
}