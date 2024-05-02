#include<stdio.h>
void thay_the(char c[], char c1, char c2){
	for(int i=0;i<strlen(c);i++){
		if(c[i]==c1) c[i] = c2;
	}
	
}
int main(){
	char c[1000];
	gets(c);
	char c1, c2;
	scanf("%c %c", &c1, &c2);
	thay_the(c,c1,c2);
	printf("%s",c);
	return 0;
}
