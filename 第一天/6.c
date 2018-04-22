#include <stdio.h>

// 华氏温度转换摄氏温度
int temperatureShift(int t){

	int result;
	result = (t - 32)/1.8; // 转换公式为 （华氏温度-32）除以1.8
	return result;
}

// 1000元利率的问题，三次利率分别为0.0036，0.0225,0.0193
void airShow(){ // air is annual interest rate
	float cost = 1000, r1 = 0.0036, r2 = 0.0225, r3 = 0.0193, p1, p2, p3, sum;
	p1 = cost + cost*r1;
	p2 = cost + cost*r2;
	p3 = cost + cost*(r3/2)*2; // 两次半年定期，但是r3是年利率
	printf("p1 is %f\np2 is %f\np3 is %f\n", p1, p2, p3);
}

// 自行输入
void airShow2(){
	float cost, r1, r2, r3, p1, p2, p3, sum;
	printf("请输入成本\n");
	scanf("%f",&cost);
	printf("请按顺序输入年利率，中间以空格隔开\n");
	scanf("%f %f %f", &r1, &r2, &r3);
	p1 = cost + cost*r1;
	p2 = cost + cost*r2;
	p3 = cost + cost*(r3/2)*2; 
	printf("222 p1 is %f\np2 is %f\np3 is %f\n", p1, p2, p3);
}

int main(){

	printf("°C is %d\n",temperatureShift(100));
	airShow();
	// airShow2();
	return 0;
}