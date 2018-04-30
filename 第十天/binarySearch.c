#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	二分查找算法，二分查找又称为折半查找，是一种效率很高的查找方法

	二分查找方法有两个要求：
	1.必须采用顺序存储结构
	2.必须按关键字大小有序排列(也就是说必须是一个有序数组，或者叫做有序队列) 

	二分查找的原理：将数组分成三个部分，依次是中值前(所谓的中值就是数组中间位置的那个值)，
	中值，中值后；将要查找的值和数组的中值进行比较，若小于中值则在中值前面找，若大于中值则在中值后面找，
	等于中值时直接返回。

	然后依次是一个递归过程，将前半部分或者后半部分继续分解为三部分

	实现：二分查找的实现用递归和循环两种方式
 */

// 首先 我们需要一个数组
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

// 其次我们要对数组进行排序
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
	printf("bubbleSort:\n");
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
			temp = arr[i];
			arr[i] = arr[key];
			arr[key] = temp;
		}
	}
	printf("selectSort:\n");
}

int partition(int arr[], int begin, int end){
	
	if(begin > end) return 0;

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

void qucikSort(int arr[], int begin, int end){
	if(begin < end){
		int pos = partition(arr, begin, end);
		qucikSort(arr, begin, pos - 1);
		qucikSort(arr, pos + 1, end);
	}
}

void insertSort(int arr[], int n){
	int key, index, temp;
	for(int i = 1; i < n; i++){
		key = arr[i];
		index = i - 1;
		while(index >= 0 && arr[index] > key){
			arr[index + 1] = arr[index];
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

// 循环实现二分查找 -1表示无法查到数据
int binarySearch(int arr[],int x, int begin, int end){
	while(begin <= end){
		int mid = (begin + end)/2;
		if(x == arr[mid]){
			return mid;
		}else if(x < arr[mid]){
			end = mid - 1;
		}else{
			begin = mid + 1;
		}
	}
	return -1;
}

// 递归实现 - 二分查找
int binarySearch2(int arr[], int x, int begin, int end){
	
	int mid = (begin + end)/2;

	if(x < arr[begin] || x > arr[end] || begin > end){
		return -1;
	}

	if(x < arr[mid]){
		return binarySearch2(arr, x, begin, mid - 1);
	}else if(x > arr[mid]){
		return binarySearch2(arr, x, mid + 1, end);
	}else{
		return mid;
	}
}

int main(){

	// int arr[10];
	// int len = sizeof(arr)/sizeof(int);
	// getArr(arr, len);
	// printArr(arr, len);

	// bubbleSort(arr, len);
	// selectSort(arr, len);
	// qucikSort(arr, 0, len - 1);
	// insertSort(arr, len);
	// printArr(arr, len);

	// shellSort(arr, len);
	// printArr(arr, len);

	int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
	int arr3[10] = {10,9,8,7,6,5,4,3,2,1};

	int mid = binarySearch(arr3, 6, 0, 9);
	printf("mid is %d\n", mid);

	// 不是很明白 递归逆序数组不能二分查找？？？
	printf("222 is %d\n", binarySearch2(arr2, 1, 0, 9));

	return 0;
}