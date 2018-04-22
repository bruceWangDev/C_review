#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = 20 + rand()%10;
	}
	printf("随机生成的数组\n");
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

// 直接插入排序
void insertSort(int arr[], int n){
	// 要进行 n - 1 趟插入
	for(int i = 1; i < n; i++){ // 假设第0个已经在正确的位置，从第一个(arr[1])开始插入
		// 第 i 趟插入需要在[ 0, i - 1]中找到i的合适位置
		int temp = arr[i];
		int j = i - 1;
		while((j >= 0)&&(arr[j] > temp)){
			arr[j + 1] = arr[j]; // 元素后移
			j--;
		}
		arr[j + 1] = temp;
	}
}

// 直排2
void insertSort2(int arr[], int n){

	for(int i = 1; i < n; i++){ // 要进行 n - 1 趟插入
		int j = 0;
		while((j < i)&&(arr[i] > arr[j])){
			j++;
		}
		// 如果找到合适的位置 i 应该不等于j，如果i==j，说明i正好在正确的位置
		if(i != j){
			int temp = arr[i];
			for(int k = i; k > j; k--){
				arr[k] = arr[k - 1];
			}
			arr[j] = temp;
		}
	}
}

int main(){

	int arr[8];
	int len = sizeof(arr)/sizeof(int);

	getArr(arr, len);
	printArr(arr, len);

	insertSort2(arr, len);
	printf("直接插入排序:\n");
	printArr(arr, len);

	return 0;
}