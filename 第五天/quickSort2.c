#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 产生随机数组
void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = 100 + rand()%10;
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

// 快速排序
int partition(int arr[], int low, int high){ // 返回划分的中间值

	int key = arr[low]; // 相当于在索引low处挖坑，下一步就是要找合适的数据来填坑

	while(low < high){
		while((low < high)&&(arr[high] >= key)){
			high--;
		}
		if(low < high){
			arr[low++] = arr[high];
		}
		while((low < high)&&(arr[low] <= key)){
			low++;
		}
		if(low < high){
			arr[high--] = arr[low];
		}
	}
	arr[low] = key;
	return low;
}

void quickSort(int arr[], int low,int high){
	int pos;
	if(low < high){
		pos = partition(arr, low, high);
		quickSort(arr, low, pos - 1);
		quickSort(arr, pos + 1, high);
	}
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printArr(arr, len);

	quickSort(arr, 0, len - 1);
	printArr(arr, len);

	return 0;
}