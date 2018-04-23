#include <stdio.h>

/*
	水仙花数也称为超完全数字不变数，是指一个n位数(n >= 3)，
	它的每个位上的数字的n次幂之和等于它本身
	for example: 1^3 + 5^3 + 3^3 = 153
 */

// 都是假定三位数
void narcissticNumber(int num){
	int a, b, c;
	a = num/100;
	b = num/10%10;
	c = num%10;
	printf("a is %d\tb is %d\tc is %d\n", a, b, c);\
	if(num == a*a*a + b*b*b + c*c*c){
		printf("%d是水仙花数\n", num);
	}else{
		printf("NO!\n");
	}
}

// 判断一个数字的位数 - 思路：因为整数除以整数的结果是整数，所以一个数每除以10，位数就少1，所以可以采用while循环依次除以10，直到结果为0，每除以10位数加1
int function(int num){
	int n = 0;
	while(num){
		num = num/10;
		n++;
	}
	return n;
}

int main(){

	narcissticNumber(372);
	printf("num is %d\n", function(10000));

	return 0;
}