#include <stdio.h>

void statistic(int *arr, int count){
	// 先假设一个最大值，一个最小值
	int max = arr[0], min = arr[0];
	// 求和，平均值
	int sum = 0, average;

	for(int i = 0; i < count; i++){
		// printf("%d\n", arr[i]);
		// 求最大
		if(max < arr[i]){
			max = arr[i];
		}
		// 求最小
		if(min > arr[i]){
			min = arr[i];
		}
		// 求和
		sum += arr[i];
	}
	// 求平均值
	average = sum/count;
	printf("max is %d\tmin is %d\tsum is %d\taverage is %d\n", max, min, sum, average);
}

int main(){

	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	// C语言中获取数组长度的办法 .. 
	int count = sizeof(a)/sizeof(int);
	// printf("main arr count is %d\n", count);
	statistic(a, count);
	return 0;
}