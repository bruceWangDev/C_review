#include <stdio.h>

enum BOOL {
	FALSE, 	// 0
	TRUE	// 1
} flag;

BOOL isLeapYear(int year){

	// 闰年的计算方法，能被4整除不能被100整除
	// 或者可以被400整除
	if(((year % 4 == 0)&&(year % 100 != 0))||(year % 400 == 0)){
		return TRUE;
	}else{
		return FALSE;
	}
}

int main(){

	flag = isLeapYear(2000);
	printf("flag is %d\n", flag);
	return 0;
}