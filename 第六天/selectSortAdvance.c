#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = 20 + rand()%10;
	}
	printf("随机生成的数组为:\n");
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

// 普通的选择排序
void selectSort(int arr[], int n){
	int key, temp;
	for(int i = 0; i < n; i++){
		key = i; 
		for(int j = i + 1; j < n; j++){
			if(arr[key] > arr[j]){
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

// 升级版本的选择排序
void selectSortAdvance(int arr[], int n){
	int num, index, temp;
	for(int i = 0; i < n; i++){
		num = arr[i];
		index = i;
		for(int j = i + 1; j < n; j++){
			if(num > arr[j]){
				num = arr[j];
				index = j;
			}
		}
		temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;
	}
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printArr(arr, len);

	selectSort(arr, len);
	printArr(arr, len);

	selectSortAdvance(arr, len);
	printArr(arr, len);

	return 0;
}
