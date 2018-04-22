#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 产生随机数组
void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	printf("随机生成的数组:");
	for(int i = 0; i < n; i++){
		arr[i] = 24 + rand()%10;
	}
}

// 打印数组
void printfArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

// 冒泡排序
void bubbleSort(int a[], int n){
	int temp;
	for(int i = 0; i < n - 1; i++){	// 需要N-1轮
		for(int j = 0; j < n - i - 1; j++){	// 需要减去已经排好序的i个
			if(a[j] > a[j + 1]){	// exchange - 相邻的两个数进行比较
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp; 
			}
		}
	}
	printf("bubbleSort:");
}

// 选择排序
void selectSort(int a[], int n){
	int minIndex, temp;
	for(int i = 0; i < n - 1; i++){
		minIndex = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[minIndex]){
				minIndex = j;
			}
		}
		if(minIndex > i){
			temp = a[i];
			a[i] = a[minIndex];
			a[minIndex] = temp;
		}
	}
	printf("selectSort:");
}

int main(){

	int arr[6];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printfArr(arr, len);

	bubbleSort(arr, len);
	printfArr(arr, len);

	selectSort(arr, len);
	printfArr(arr, len);

	return 0;
}