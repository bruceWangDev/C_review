#include <stdio.h>

void grade(int socre){
	switch(socre/10){ // 巧妙的解决办法 .. 
		case 9:{
			printf("grade is A\n");
			break;
		};
		case 8:{
			printf("grade is B\n");
			break;
		};
		case 7:{
			printf("grade is C\n");
			break;
		};
		case 6:{
			printf("grade is D\n");
			break;
		};
		default:
			printf("grade is \n");
			break;	
	}

	// if(socre >= 90){
	// 	printf("grade is A\n");
	// }else if(90 > socre && socre >= 80){
	// 	printf("grade is B\n");
	// }else if(80 > socre && socre >= 70){
	// 	printf("grade is C\n");
	// }else if(70 > socre && socre >= 60){
	// 	printf("grade is D\n");
	// }else{
	// 	printf("grade is E\n");
	// }
}

int main(){

	grade(88);

	return 0;
}