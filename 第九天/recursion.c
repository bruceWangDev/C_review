#include <stdio.h>

/* 
	递归就是函数调用自己
	所有的循环都可以转成递归，但是递归并不一定可以转成循环

 */

/*
	1		2		3		4		5		6 .. 
	必须有一定的规律
	f(1)	f(2) .. 						f(n) ..

	以下是完整的递归表达式:
	f(n) = f(n - 1) + 1	递归关系
	f(1) = 1			递归出口


	1		3		5		7		9		11 ..
	f(1)	f(2) .. 						f(n) ..
	
	f(n) = f(n - 1) + 2	递归关系
	f(1) = 1			递归出口

	为什么要有递归出口呢？
	因为:
	2		4		6		8		10		12 ..
	也满足 f(n) = f(n - 1) + 2

	f(n) = f(n - 1) + 2	递归关系
	f(1) = 2			递归出口
 */

int f(int n){
	if(n == 1){
		return 1;
	}else{
		return f(n - 1) + 2;
	}
}

/*
	Fibonacci:1		1		2		3		5		8		13 .. 
	f(n) = f(n - 1) + f(n + 2)
	f(1) = 1
	f(2) = 2
 */ 

int f1(int n){
	if(n == 1){
		return 1;
	}else if(n == 2){
		return 1;
	}else{
		return f1(n - 1) + f1(n - 2);
	}
}

/*
	计算1 + 2 + 3 + 4 + ... + 100
	for(int i = 0; i < 100; i++){
		sum += i;
	} 

	将其转换为递归

	f(n) = 1 + 2 + 3 + ... + n
	f(100) = 1 + 2 + 3 + ... + 100

	f(n) = f(n - 1) + n  // f(n - 1) 是前 n - 1 项的和
	f(1) = 1
 */

int f2(int n){
	if(n == 1){
		return 1;
	}else{
		return f2(n - 1) + n;
	}
}

/*
	int arr[ ] = {1,7,8,6,4,7,3};

	sum(arr, n) = sum(arr, n - 1) + arr[n] // sum(arr, n - 1) - 前 n - 1 的和 
	sum(arr, 0) = arr[0]
 */

// 递归求和
int sum(int arr[], int n){
	if(n == 0){
		return arr[0];
	}else{
		return sum(arr, n - 1) + arr[n];
	}
}

/*
	arr[ ] = {7,4,8,6,3,2,9,11,5}

	max(arr, n) -> max(arr, n - 1) 和 arr[n] 比较

 */

// 递归求最大值
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

	printf("%d\n", f(3));
	printf("%d\n", f1(8));
	printf("%d\n", f2(100));

	int arr[10] = {9,8,7,6,5,4,3,2,1};
	printf("%d\n", sum(arr, 8));
	int	arr1[10] = {7,4,8,6,3,2,9,11,15};
	printf("%d\n", max(arr1, 7));
	return 0;
}