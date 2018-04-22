#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getArr(int arr[], int n){
	unsigned sr = time(NULL);
	srand(sr);
	for(int i = 0; i < n; i++){
		arr[i] = 66 + rand()%10;
	}
	printf("随机生成的数组:\n");
}

void printArr(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

/* 
	quickSort - 思想：采取分而治之的思想，将要排列的数组分成左右两个部分
	其中一部分元素都比key小，另外一部分元素都比key大
	然后将所得到的两部分数据进行同样的划分，重复执行，直到两个指针撞在一起
 
 	需要一个标尺，一般使用数组的第一个元素或者最后一个元素
 	还需要两个指针，一个从左到右，一个从右到左
	还要注意递归思想
*/

// partition - 划分，分割

int partitionExchange(int arr[], int begin, int end){

	if(begin > end) return;

	int key = arr[begin]; // 假设数组的第一个元素作为标尺
	while(begin < end){ // 当左指针小于右指针的时候就一直循环
		while((begin < end)&&(arr[end] >= key)){ // 前提左指针小于右指针&&右指针大于标尺元素
			end--; // 从右往左找，直到找到比key小的元素
		}
		arr[begin] = arr[end]; // 将这个元素放在key的左边

		while((begin < end)&&(arr[begin] <= key)){ // 左指针小于key
			begin++; // 从左往后找，直到找到比key大的元素
		}
		arr[end] = arr[begin]; // 将这个元素放到key的右边
	}

	// printf("---------------------------------\n");
	arr[begin] = key;
	return begin; // 假设余下的小数组的第一个元素作为标尺
}

void quickSort(int arr[], int begin, int end){
	if(begin < end){
		int result = partitionExchange(arr, begin, end);
		printf("result is %d\n", result);
		quickSort(arr, begin, result - 1);
		quickSort(arr, result + 1, end);
	}
}

int main(){

	int arr[6];
	int len = sizeof(arr)/sizeof(int);
	getArr(arr, len);
	printArr(arr, len);

	quickSort(arr, 0, len - 1);
	printArr(arr, len);

	return 0;
}