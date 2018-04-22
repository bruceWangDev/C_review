#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 产生随机数组
void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = 10 + rand()%10;
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

// 快速排序 -- 终于到正主了 .. 
int partition(int arr[], int left, int right){

	int key = arr[left]; // 刚开始以第一个数为标尺
	while(left < right){ 
		while((left < right)&&(arr[right] >= key)){
			right--; // 从后往前找，直到找到比key值小的数为止
		}
		arr[left] = arr[right]; // 将该数放到key值的左边
		while((left < right)&&(arr[left] <= key)){
			left++; // 从前往后找，直到找到比key值大的数为止
		}
		arr[right] = arr[left]; // 将该数放到key值的右边
	}
	arr[left] = key; // 将key值填充到low位置，下次重新找key值
 	return left;
}

void quickSort(int arr[], int left, int right){
	if(left < right){
		int result = partition(arr, left, right);
		printArr(arr, 10);
		printf("%d\n", result);
		quickSort(arr, left, result - 1);
		quickSort(arr, result + 1, right);
	}
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printArr(arr, len);

	quickSort(arr, 0, len - 1);
	printf("快速排序后:\n");
	printArr(arr, len);

	return 0;
}