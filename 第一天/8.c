#include <stdio.h>

// 给定一个大写字母A，输出其小写字母
void shift1(char a){
	char result;
	result = a + 32;
	printf("num is %d\nchar is %c\n", result, result);
}

/*
ASCII American Standard Code for Information Interchange，美国信息交换标准代码
是基于拉丁字母的一套电脑编码系统，主要用于显示现代英语和其他西欧语言。
是如今最通用的单字节编码系统

65 - 90 为26个大写字母，97 - 122 为26个小写字母
48 - 57 为0到9十个阿拉伯数字
*/

int main(){

	// printf("112233");
	shift1('A');
	return 0;
}