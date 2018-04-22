#include <stdio.h>

void tdArrShow(){

	int a[5][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
	// 经测试 sizeof 只能计算出二维数组的整体长度
	int count = sizeof(a)/sizeof(int);
	// printf("count is %d\n", count);
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 4; j++){
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}

}

int main(){

	tdArrShow();

	return 0;
}