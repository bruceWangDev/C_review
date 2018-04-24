#include <stdio.h>

// 成功的安装sublime text3的C语言的运行环境，但是美中不足在于终端一闪而过
// 1
void exchange(int x, int y){
	printf("before exchange\tx is %d\ty is %d\n", x, y);
	int tmp;
	tmp = x;
	x = y ;
	y = tmp;
	printf("after exchange\tx is %d\ty is %d\n", x, y);
}

// 2
void combine(int x, int y){

	int x1, x2, y1, y2, z;
	x1 = x/10;
	// printf("%d\n", x1);
	x2 = x%10;
	// printf("%d\n", x2);
	y1 = y/10;
	// printf("%d\n", y1);
	y2 = y%10;
	// printf("%d\n", y2);
	z = x1*1000 + y2*100 + x2*10 + y1;
	printf("combine number is %d\n", z);
}

// 3
void alterConstant(int a, int b, int c){
	int tmp; // 中间变量

	// 先判断a和b两个数中的最小
	if(a < b){
		
	}else{
		// a > b 交换a,b的值 确保a最小
		tmp = a;
		a = b;
		b = tmp;
	}

	// 再判断b和c两个数的大小
	if(b < c){

	}else{
		// b > c 交换b,c的值 确保c最大
		tmp = b;
		b = c;
		c = tmp;
	}

	// 最后还要和a进行比较
	if(b < a){
		tmp = b;
		b = a;
		a = tmp;
	}else{

	}

	printf("a is %d\tb is %d\tc is %d\n", a, b, c);
}

int main(){

	// int a;
	// scanf("%d",&a);
	// printf("a is %d\n", a);

	// int a, b;
	// scanf("%d %d", &a, &b);
	exchange(111, 222);

	combine(12, 34);

	alterConstant(-2, 101, 100);

	return 0;
}