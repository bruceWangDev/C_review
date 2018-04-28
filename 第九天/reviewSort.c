#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = 11 + rand()%10;
	}
	printf("随机生成的数组:\n");
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void bubbleSort(int arr[], int n){
	int temp;
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

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

void insertSort(int arr[], int n){
	int key, index, temp;
	// 假设第一个元素已经有序
	for(int i = 1; i < n; i++){
		key = arr[i];
		index = i - 1; // 前一个数的下标
		while(index >= 0 && arr[index] > key){
			arr[index + 1] = arr[index]; // 数组元素后移
			index--;
		}
		arr[index + 1] = key;
	}
}

void shellSort(int arr[], int n){
	int temp;
	for(int gap = n/2; gap > 0; gap /= 2){
		for(int i = gap; i < n; i++){
			for(int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j -= gap){
				temp = arr[j];
				arr[j] = arr[j + gap];
				arr[j + gap] = temp;
			}
		}
	}
}

int partition(int arr[], int begin, int end){

	if(begin > end){
		return 0;
	}

	int key = arr[begin];
	while(begin < end){
		while(begin < end && arr[end] >= key){
			end--;
		}
		arr[begin] = arr[end];
		while(begin < end && arr[begin] <= key){
			begin++;
		}
		arr[end] = arr[begin];
	}

	arr[begin] = key;
	return begin;
}

void quickSort(int a[], int begin, int end){

	if(begin < end){
		int result = partition(a, begin, end);
		quickSort(a, begin, result - 1);
		quickSort(a, result + 1, end);
	}
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printArr(arr, len);

	// bubbleSort(arr, len);
	// printArr(arr, len);

	// selectSort(arr, len);
	// printArr(arr, len);

	// insertSort(arr, len);
	// printArr(arr, len);

	shellSort(arr, len);
	printArr(arr, len);

	// quickSort(arr, 0, len - 1);
	// printArr(arr, len);

	return 0;
}