#include <stdio.h>

// fibonacci
int f(int n){
	if(n == 1){
		return 1;
	}else if(n == 2){
		return 1;
	}else{
		return f(n - 1) + f(n - 2);
	}
}

// 递归求和
int f1(int n){
	if(n == 1){
		return 1;
	}else{
		return f1(n - 1) + n;
	}
}

// 用递归来求一个数组前n项的和
int sum(int arr[], int n){
	if(n == 0){
		return arr[0];
	}else{
		return sum(arr, n - 1) + arr[n];
	}
}

// 递归求数组最大值
int max(int arr[], int n){
	if(n == 0){
		return arr[0];
	}else{
		if(max(arr, n - 1) > arr[n]){
			return max(arr, n - 1);
		}else{
			return arr[n];
		}
	}
}

int main(){

	printf("Fibonacci is %d\n", f(8));
	printf("sum is %d\n", f1 (100));

	int arr[10] = {9,8,7,6,5,4,3,2,1};
	printf("sum is %d\n", sum(arr ,8));
	printf("max is %d\n", max(arr ,8));

	return 0;
}