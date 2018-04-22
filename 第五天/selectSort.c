#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 产生随机数组
void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = rand()%10;
	}
	printf("随机数组:\n");
}

// 打印数组
void printArr(int arr[], int n){
	for (int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

// 选择排序 - 就记住需要一个key
void selectSort(int arr[], int n){
	for(int i = 0; i < n; i++){
		int key = i;	// key 用于存放数组最小值的位置
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[key]){
				key = j; // 记录数组最小值的位置
			}
		}
		if(key != i){
			int temp = arr[key];
			arr[key] = arr[i];
			arr[i] = temp;
		}
	}
	printf("选择排序:\n");
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printArr(arr, len);

	selectSort(arr, len);
	printArr(arr, len);

	return 0;
}