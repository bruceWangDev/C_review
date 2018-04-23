#include <stdio.h>

void tdArrSum(int arr[][4], int row, int list){

	for(int i = 0; i < row; i++){
		int sum = 0;
		for(int j = 0; j < list; j++){
			sum += arr[i][j];
		}
		printf("第%d行的和是%d\n", i,sum);
	}

}

int main(){

	int arr[5][4] = { {1,2,3,4},
					{5,6,7,8},
					{9,10,11,12},
					{13,14,15,16},
					{17,18,19,20}};
	tdArrSum(arr, 5, 4);
	return 0;
}