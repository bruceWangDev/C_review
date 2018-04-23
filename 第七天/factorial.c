#include <stdio.h>

int fac(int n){
	int f;
	if(n < 0){
		printf("n < 0,error\n");
		return 0;
	}else if(n == 0 || n == 1){
		return 1;
	}else{
		return fac(n-1)*n;
	}
}

int main(){

	printf("result is %d\n", fac(5));
	return 0;
}