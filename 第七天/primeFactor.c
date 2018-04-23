#include <stdio.h>

void primeFactor(int num){

	int i = 2; // 分解质因素，除数从2开始
	while(i < num){
		if(num % i == 0){
			printf("%d\t", i);
			num /= i;
		}else{
			i++;
		}
	}
	printf("%d\n", i);
}

int main(){

	primeFactor(24);
	return 0;
}