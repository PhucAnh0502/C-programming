#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//Chuan hoa ten nguoi dung
void chuanhoa(char c[]){
	c[0]=toupper(c[0]);
	for(int i=1;i<strlen(c);i++){
		c[i]=tolower(c[i]);
	}
} 

int main(){
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
		char c[1000],a[20][50];
		int n = 0; //dem so luong tu trong cau
		gets(c);
		char *token = strtok(c," ");
		while(token != NULL){
			strcpy(a[n], token);
			++n;
			token = strtok(NULL," ");
		}
		for(int i=0;i<n;i++){
			chuanhoa(a[i]);
			printf("%s",a[i]);
			if(i!=(n-1)) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
