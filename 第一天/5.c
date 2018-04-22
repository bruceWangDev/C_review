#include <stdio.h>

// C语言也是逻辑真假的，在C语言中非0为真，0为假
// 第一种方法 使用枚举
enum BOOL {
	FALSE,	// 0
	TRUE    // 1
};

enum BOOL flag;

// 枚举是C语言中的一种基本数据类型，并不是构造类型，它可以用于声明一组常量
// 当一个变量有几个固定的可能取值时，可以将其定义为枚举类型
// 比如可以用一个枚举类型的变量来表示春夏秋冬 .. 表示C中没有的bool .. 
enum Season{
	spring,
	summer,
	autumn,
	winter
};

enum Season s;

// ————————————————————————————————————————————

// 第二种方法 宏定义

// 定义布尔类型
// #define BOOL int
// #define TRUE 1
// #define FALSE 0

// 定义一个布尔变量
// BOOL flag = FALSE;

float sum(){
	float sum = 1;
	// bool symbol = true; // error C语言中没有bool类型变量，C不支持这种数据类型
	flag = FALSE;
	for(int i = 2; i <= 100; i++){
		if (flag == FALSE){
			sum = sum - 1.0/i;
			// printf(" - %f\n", 1.0/i);
			flag = TRUE;
		}else{
			sum = sum + 1.0/i;
			// printf(" + %f\n", 1.0/i);
			flag = FALSE;
		}
	}
	return sum;
}

// 思路非常的巧妙，除了第一个数字1 剩余的将符号和数字看做一个整体，-1/2，1/3，-1/4
float sum2(){
	int sign = 1;
	float deno = 2.0, sum = 1.0, term;
	while(deno <= 100){
		sign = -sign; // 将符号顺带一块解决了 nice
		term = sign/deno;
		sum = sum + term;
		deno++;
	}
	return sum;
}

int main(){

	// for(s = spring; s <= winter; s++){
	// 	printf("enum element is %d\n", s);
	// }

	printf("sum is %f\n",sum());;
	printf("sum2 is %f\n",sum2());;

	return 0;
}