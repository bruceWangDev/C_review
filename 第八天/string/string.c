#include <stdio.h>
#include <string.h>

/*	
	字符串操作
	strcpy(a, b)		复制字符串
	strncpy(a, b, n)	复制指定长度字符串
	strcat(a, b) 		附加字符串
	strncat(a, b, n)	附加指定长度的字符串
	strlen(str)			取字符串的长度
	strcmp(a, b)		比较字符串
	strcasecmp(a, b)	忽略大小写比较字符串
	strchr(str, c)		在字符串中查找指定字符
	strrchr(str, c)		在字符串中反向查找指定字符
	strpbrk(a, b)		以目标字符串的所有字符作为集合，在当前字符串查找该集合的任一元素
	strspn(a, b)		以目标字符串的所有字符作为集合，在当前字符串查找不属于该集合的任一元素的偏移
	strcspn(a, b)		以目标字符串的所有字符作为集合，在当前字符串查找属于该集合的任一元素的偏移

	字符串到数值类型的转换
	strtod(p, ppend) 	从字符串p中转换double类型数值，并且将后续的字符串指针存储到ppend指向的char*类存储
	strtol(p, ppend, base)	从字符串p中转换long类型整数数值，base显示设置转换的整数进制，设置为0以根据特定格式判断所用进制

	atoi(p)		字符串转换到int
	atof(p)		字符串转换到double
	atol(p)		字符串转换到long

	字符检查
	isalpha()	检查是否为字母字符
	isupper()	检查是否为大写字母字符
	islower()	检查是否为小写字母字符
	isdight()	检查是否为数字
	isxdigit() 	检查是否为十六进制数字表示的有效字符
	isspace() 	检查是否为空格类型字符
	iscntrl() 	检查是否为控制字符
	ispunct() 	检查是否为标点符号
	isalnum() 	检查是否为字母和数字
	isprint() 	检查是否是可打印字符
	isgraph() 	检查是否是图形字符，等效于 isalnum() | ispunct() 
  */

int main(){

	char str1[10] = "A";
	char str2[10] = "Computer";

	printf("%d\n", (int)strlen(str2));
	printf("%s\n", strcpy(str1, str2));
	printf("%s\n", strncpy(str2, str1, 1));

	int a = strcmp(str1, str2);
	printf("%d\n", a);

	return 0;
}