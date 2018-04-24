#include <stdio.h> // C语言标准输入输出库 stdio.h

// 求两个整数之和
int sum(int x,int y){
	int result = x + y;
	return result;
}

// 求两个整数中的较大者
int max(int x,int y){
	// 常规处理
	// int result;
	// if(x > y){
	// 	result = x;
	// }else{
	// 	result = y;
	// }
	// return result;

	// 条件运算符 一句话搞定..
	return x>y?x:y;
}

// 求三个整数中的最大值
int max3(int x, int y, int z){
	int result;
	int tmp;
	// 求前两个数最大值，再和第三个数进行比较
	if (x > y){
		tmp = x;
	}else{
		tmp = y;
	}

	if(tmp > z){
		result = tmp;
	}else{
		result = z;	
	}

	return result;
}

// 求5!
int mul5(){
	int result = 1;
	for(int i = 1; i <= 5; i++){
		result = result * i;
	}
	return result;
}

// 求n的阶乘
int mulNum(int n){
	int result = 1;
	for(int i = 1; i <= n; i++){
		result *= i;
	}
	return result;
}

int main(){

	int a = sum(3,4);
	printf("no.1 answer = %d\n",a);

	int b = max(11,90);
	printf("no.2 answer = %d\n",b);

	int c = max3(1,22,3);
	printf("no.3 answer = %d\n",c);

	printf("no.4 answer = %d\n",mul5());

	printf("阶乘Test = %d\n",mulNum(6));

	printf("Hello World!\n");
	return 0;
}