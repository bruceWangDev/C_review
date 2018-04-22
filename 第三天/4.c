#include <stdio.h>

// 4
void flashback(){

	int arr[10];
	for(int i = 0; i < 10; i++){
		arr[i] = i + 1;
	}
	for(int i = 9; i >= 0; i--){
		printf("result is %d\n", arr[i]);
	}

}

// 输入10个数字并且按照从大到小的顺序排列
void sort(){

	int temp; // 中间变量

	int arr[10] = {1,2,3,4,5,11,22,33,24,23};

	// 先假定第一个元素为最大值，然后进行双重for循环
	// 第一次进行9次比较，比较出最大的值
	// 依次类推，每往后一次减少一次循环
	int max = arr[0];
	for(int i = 0; i < 10 - 1; i++){ // 循环数组的10个元素
		for(int j = 0; j < 10 - i - 1; j++){ // 元素要从它的后一个元素进行比较
			if(arr[j] < arr[j + 1]){ // 交换 exchange
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		// printf("\n");
	}

	for(int i = 0; i < 10; i++){
		printf("%d\n", arr[i]);
	}
}

int main(){

	// flashback();
	sort();

	return 0;
}