#include <stdio.h>

// 建立在已经排好序的数组的基础上 - 查找

// 最简单的查找数组
int lineAtSearch(int arr[], int len, int key){
	for(int i = 0; i < len; i++){
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
} 

// 二分法
int binarySearch(int arr[], int len, int key){
	int lh = 0;
	int rh = len - 1;
	while(lh <= rh){
		int mid = (lh + rh)/2;
		// printf("arr mid is%d\n", mid);
		if(key == arr[mid]){
			return mid;
		}
		if(key < arr[mid]){
			rh = mid - 1;
		}else{
			lh = mid + 1;
		}
	}
	return -1;
}

int main(){

	int arr[] = {11,33,22,34,55,78};
	int len = sizeof(arr)/sizeof(int);
	int result = lineAtSearch(arr, len, 11);
	printf("result is %d\n", result);

	printf("binarySearch is %d\n", binarySearch(arr, len, 11));

	return 0;
}