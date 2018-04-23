#include <stdio.h>
#include <string.h> // C语言中的字符串类头文件

// 逆向输出
void reversedArr(char str[]){
	char c;
	for(int i = 0; i < strlen(str) - 1; i++){
		c = str[i];
		printf("%c ", c);
	}
	printf("\n");
	for(int i = strlen(str) - 1; i >= 0; i--){
		c = str[i];
		printf("%c ", c);
	}
}

// 将字符串颠倒
void reversedStr(char str[]){
	char c;
	for(int i = 0, j = strlen(str) - 1; i < j; i++, j--){
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
	printf("%s\n", str);	
}

int main(){

	char str[] = "Best Battle";
	reversedStr(str);

	return 0;
}