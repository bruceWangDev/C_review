#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 产生随机数组
void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	printf("产生的随机数组:\n");
	for(int i = 0; i < n; i++){
		arr[i] = 24 + rand()%10;
	}
}

// 打印数组
void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

// 冒泡排序
void bubbleSort(int arr[], int n){
	int temp;
	for(int i = 0; i < n - 1; i++){ // i [0,n-1]
		for(int j = 0; j < n - i - 1; j++){ // j [0,n-i-1]
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("bubbleSort after arr is:\n");
}

int main(){

	int arr[10];
	int length = sizeof(arr)/sizeof(int);
	getArr(arr, length);
	printArr(arr, length);

	bubbleSort(arr, length);
	printArr(arr, length);

	return 0;
}