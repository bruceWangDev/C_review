#include <stdio.h>
#include <stdlib.h> // standard library 标准库
/*
	free 	释放p所指的内存区
	malloc	分配size字节的存储区
	rand	产生0到32767之间的随机整数
	abort	异常终止一个进程
	exit	程序终止执行，返回调用过程
	atof	将字符串转换成一个双精度数值
	atoi	将字符串转换成一个整数值
	atol	将字符串转换成一个长整数
	srand	是随机数发生器的初始化函数
 */

#include <time.h>

#include <stack> // 偷懒包含了一个C++的标准库stack 使用bool

// 产生随机数组
void getArr(int arr[], int n){
	int i;
	unsigned sr = time(NULL); // unsigned 无符号(在默认情况下都是有符号的)
	// time() 返回当前时间的秒数
	/*
		time(NULL)用来获取当前时间，本质上得到的是一个大整数，然后用这个数来随机数
		time()这个函数其实保存的是一个历史时间，所以需要用NULL把这个历史时间清空一下
		time()就会自动保存当前时间了 - 可以简单的理解为NULL就是给time()初始化
	 */
	// printf("%d\n", sr);

	srand(sr); // 没有这个的话每次调用rand函数生成伪随机数列序列都是一样的

	printf("随机生成数组:\n");
	for(int i = 0; i < n; i++){
		arr[i] = 1 + rand()%100;
		printf("%d\t", arr[i]);
	} 
	printf("\n");
}

// exchange
void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// 选择排序
void selectSort(int arr[], int n){

	for(int i = 0; i < n - 1; i++){ // 进行N-1轮选择，也就是i的取值在[0,N-2]
		int minIndex = i; // 记录第i小的数所在的索引
		for(int j = i + 1; j < n; j++){
			if(arr[j] < arr[minIndex]){
				minIndex = j;
			}
		}
		if(i != minIndex){ // 根据记录的第i小的数的索引，找到了第i小的数，将其放到正确的位置
			swap(arr[i], arr[minIndex]);
		}
	}
	printf("选择排序后数组:\n");
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n"); 
}

// 冒泡排序
void bubbleSort(int arr[], int n){
	bool isSorted = true;
	for(int i = 0; i < n - 1; i++){ // 和选择排序一样[0,N-2] - 恰好N-1轮比较
		for(int j = 0; j < n - i - 1; j++){ 
		// 已经排好序的最后i个不用比较，要比较的个数为N-i个，那么需要比较的次数为N-i-1
			if(arr[j] > arr[j + 1]){
				isSorted = false;
				swap(arr[j], arr[j+1]);
			}
		}
		if(isSorted){
			printf("如果没有发生交换，就说明已经排好序了，提前退出循环\n");
			break;
		}
	}
	printf("冒泡排序后数组:\n");
	for(int i = 0; i < n; i++){
		printf("%d\t", arr[i]);
	}
	printf("\n"); 
}

/* - 表示没看懂这个快速排序

// 选择排序(划分排序) - 划分点
int partition(int arr[], int low, int high){
	int key;
	key = arr[low]; // 相当于在索引low处挖坑，下一个就要找合适的数据来填坑
	while(low < high){
		while(low < high && arr[high] >= key){
			high--;
		}
		if(low < high){
			arr[low++] = arr[high];	// 找到了合适的数据填到low坑，但是形成了high坑，继续找数据
		}

		while(low < high && arr[high] <= key){
			low++;
		}
		if(low < high){
			arr[high--] = arr[low]; // low又成了坑
		}
	}
	arr[low] = key;
	return key;
}

// 选择排序
void quickSort(int arr[], int low, int high){
	int pos;
	if(low < high){
		pos = partition(arr, low, high);
		quickSort(arr, low, pos-1);
		quickSort(arr, pos+1, high);
	}
	// printf("快速排序后数组:\n");
	// int len = sizeof(arr)/sizeof(int);
	// for(int i = 0; i < len; i++){
	// 	printf("%d\t", arr[i]);
	// }
	// printf("\n"); 
}

 **/

// 插入排序 - 将元素逐个添加到已经排好序的数组中去
void insertSort(int a[], int n){
	// 要进行N-1趟插入
	for(int i = 1; i < n; i++){ // 假设 第0个已经在正确的位置，要从第一个开始插入
		// 第i趟插入需要在[0, i-1]中找到i的合适位置
		int j = 0;
		while((j < i)&&(a[i] > a[j])){
			j++;
		}
		// 如果找到合适位置i应该!=j，如果i==j，说明i正好在正确的位置上
		if(i != j){
			// 将a[i]插入合适的位置，即位置j，那么[j, i-1]位置上的数应该后移
			// 先保存a[i]，然后后移
			int tmp = a[i];
			for(int k = i; k > j; k--){
				a[k] = a[k - 1];
			}
			a[j] = tmp;
		}
	}
	printf("插入排序后数组:\n");
	for(int i = 0; i < n; i++){
		printf("%d\t", a[i]);
	}
	printf("\n"); 
}

int main(){

	int arr[10];
	int len = sizeof(arr)/sizeof(int);	// 求数组长度
	getArr(arr, len);

	// selectSort(arr, len);

	// bubbleSort(arr, len);

	// quickSort(arr, 0, len);

	insertSort(arr, len);

	return 0;
}