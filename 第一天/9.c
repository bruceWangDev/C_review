#include <stdio.h>
// 需要包含数学库
#include <math.h>

// 给定三角形的三边长，求面积
float area(float a, float b, float c){
	float p, s;
	// 海伦-秦九昭公式
	p = (a + b + c)/2;
	s = p*(p - a)*(p - b)*(p - c);

	// 判断能否组成一个三角形，能则输出面积，不能就打印信息
	if(s < 0.0){
		printf("can not be a right triangle!\n");
		return 0;
	}else{
		s = sqrt(s);
		printf("a right triangle area is %f\n",s);
		return s;
	}
}

int main(){

	area(3,4,5);

	return 0;
}