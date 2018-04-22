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
	printf("随机生成的数组:\n");
}

// 打印数组
void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

// 冒泡排序的升级版
/*
	通过从低到高选出最大的数放在后面，再从高到低选出最小的数放在前面
	如此反复，直到做界线和右界面重合
	当数组中已有排序好的数时，这种排序比传统冒泡排序性能稍好
 */ 
void bubbleSortAdvance(int arr[], int n){
	// 1.设置数组左右边界
	int left = 0, right = n - 1;
	// 2.当左右边界未重合时，进行排序 - - emmm 感觉这货似曾相识
	while(left < right){
		// 3.从左到右遍历选出最大的数放在数组右边
		for(int i = left; i < right; i++){
			if(arr[i] > arr[i + 1]){
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		right--;
		// 4.从右向左遍历选出最小的数放在数组左边
		for(int j = right; j > left; j--){
			if(arr[j] < arr[j - 1]){
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
		left++;
	}
	printf("升级后的冒泡排序:\n");
}

int main(){

	int arr[10];
	int length = sizeof(arr)/sizeof(int);
	getArr(arr, length);
	printArr(arr, length);

	bubbleSortAdvance(arr, length);
	printArr(arr, length);

	return 0;
}