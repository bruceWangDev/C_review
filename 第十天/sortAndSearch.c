#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = 12 + rand()%10;
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

void quickSort(int arr[], int begin, int end){
	if(begin < end){
		int pos = partition(arr, begin, end);
		quickSort(arr, begin, pos - 1);
		quickSort(arr, pos + 1, end);
	}
}

void insertSort(int arr[], int n){
	int key, index, temp;
	for(int i = 1; i < n; i++){
		key = arr[i]; 	// 默认第一个数有序
		index = i - 1;  // 取前一个元素进行对比
		while(index >= 0 && arr[index] > key){
			arr[index + 1] = arr[index];
			index--;
		}
		arr[index + 1] = key;
	}
	printf("insertSort:\n");
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
	printf("shellSort:\n");
}

int binarySearch(int arr[], int x, int begin, int end){
	if(begin > end) return -1;
	while(begin < end){
		int mid = (begin + end)/2;
		if(x > arr[mid]){
			begin = mid + 1;
		}else if(x < arr[mid]){
			end = mid -1;
		}else{
			return mid;
		}
	}
	return -1;
}

// 递归调用
int search(int arr[], int x, int begin, int end){
	if(begin > end || x < arr[begin] || x > arr[end]) return -1;
	int mid = (begin + end)/2;
	if(x < arr[mid]){
		return search(arr, x, begin, mid - 1);
	}else if(x > arr[mid]){
		return search(arr, x, mid + 1, end);
	}else{
		return mid;
	}
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);

	getArr(arr, len);
	printArr(arr, len);

	// bubbleSort(arr, len);
	// selectSort(arr, len);
	// quickSort(arr, 0 , len - 1);
	// insertSort(arr, len);
	shellSort(arr, len);
	printArr(arr, len);

	int result = search(arr, 13, 0, len - 1);
	printf("%d\n", result);

	return 0;
}