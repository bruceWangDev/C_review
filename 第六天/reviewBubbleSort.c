#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 产生随机数组
void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = 24 + rand()%10;
	}
	printf("随机生成的数组为:\n");
}

// 打印数组
void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

// bubbleSort
void bubbleSort(int arr[], int n){
	int temp;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// and 顺便在带一个选择排序好吧，我省的写前面两个函数了
// selectSort - 思路是key
void selectSort(int arr[], int n){
	int key, temp;
	for(int i = 0; i < n - 1; i++){
		key = i;
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[key]){
				key = j;
			}
		}
		if(key != i){
			temp = arr[key];
			arr[key] = arr[i];
			arr[i] = temp;
		}
	}
}

int main(){

	int arr[6];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printArr(arr, len);

	bubbleSort(arr, len);
	printf("bubblesSort result is:\n");
	printArr(arr, len);

	selectSort(arr, len);
	printf("selectSort result is:\n");
	printArr(arr, len);

	return 0;
}