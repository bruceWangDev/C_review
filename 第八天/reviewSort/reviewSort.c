#include <stdio.h>
#include "common.h"
#include <time.h>

// bubbleSort
void bubbleSort(int a[], int n){
	int temp;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1]){
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

// selectSort
void selectSort(int a[], int n){
	int key, temp;
	for(int i = 0; i < n - 1; i++){
		key = i;
		for(int j = i + 1; j < n; j++){
			if(a[key] > a[j]){
				key = j;
			}
		}
		if(key != i){
			temp = a[i];
			a[i] = a[key];
			a[key] = temp;
		}
	}
}

// insertSort
void insertSort(int a[], int n){
	int key, temp, beforeIndex;
	for(int i = 1; i < n - 1; i++){
		key = a[i];
		beforeIndex = i - 1; // 前一个数的下标
		while(beforeIndex >= 0 && a[beforeIndex] > key){
			// 判断条件是不越界 && 并且第一个数大于第二个数 - 循环从第二个数开始
			a[beforeIndex + 1] = a[beforeIndex]; // 数字后移
			beforeIndex--;
		}
		a[beforeIndex + 1] = key; // 插入元素
	}
}

// shellSort
void shellSort(int a[], int n){
	int temp;
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i++){
			for(int j = i - gap; j > 0 && a[j] > a[j + gap]; gap -= gap){
				temp = a[j];
				a[j] = a[j + gap];
				a[j + gap] = temp;
			}
		}
	}
}

// quickSort
int partition(int a[], int begin, int end){

	if(begin > end) return 0;

	int key = a[begin];
	while(begin < end){
		while(begin < end && a[end] >= key){
			end--;
		}
		a[begin] = a[end];
		while(begin < end && a[begin] <= key){
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = key;
	return begin;
}

void quickSort(int a[], int begin, int end){
	if(begin < end){
		int result = partition(a, begin, end);
		quickSort(a, begin, result - 1);
		quickSort(a, result + 1, end);
	}
}

// 获取当前时间
void nowTime(){

	time_t t = time(NULL);
	printf("time is %d\n", (int)t);
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);

	nowTime();
	getArr(arr, len);
	printArr(arr, len);

	printf("bubbleSort result is:\n");
	bubbleSort(arr, len);
	printArr(arr, len);

	printf("selectSort result is:\n");
	selectSort(arr, len);
	printArr(arr, len);

	printf("insertSort result is:\n");
	insertSort(arr, len);
	printArr(arr, len);

	printf("shellSort result is:\n");
	shellSort(arr, len);
	printArr(arr, len);

	printf("quickSort result is:\n");
	quickSort(arr, 0, len - 1);
	printArr(arr, len);

	nowTime();

	return 0;
}