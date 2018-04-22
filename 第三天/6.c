#include <stdio.h>

void average(){

	int arr[5][3] = {{80,75,92},{61,65,71},{59,63,70},{85,87,90},{76,77,85}};
	int sum = 0, average = 0;
	for(int i = 0; i < 5; i++){
		sum += arr[i][0];
	}
	average = sum/5;
	printf("average is %d\n", average);
}

int main(){
	
	average();

	return 0;
}