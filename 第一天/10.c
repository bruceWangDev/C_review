#include <stdio.h>

double process(double n){
	n = n * 100; // 12312.3
	n = n + 0.5; // 12312.8 // 四舍五入+0.5就好了
	n = (int)n;  // 12312
	n = n/100.0; // 123.12
	return n;
}

int main(){

	printf("process is %f\n", process(123.128));

	return 0;
}