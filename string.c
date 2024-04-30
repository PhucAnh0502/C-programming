#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

//int islower(char c)
//int isupper(char c)
//int isalpha(char c)
//int isdigit(char c)
//char tolower(char c)
//char toupper(char c)
//int strcmp(char c[], char d[])
//char* strcpy(char c[], char d[]) copy noi dung cua xau d vao xau c
//char* strcat(char c[], char d[]) noi noi dung cua xau d vao xau c

//strlen(c): Do dai xau ki tu
//fgets(mang,so ki tu toi da,stdin)
char* strlwr(char c[]){ //ham viet thuong tat ca cac ki tu trong xau
	for(int i=0;i<strlen(c);i++){
		if(c[i]>='A'&&c[i]<='Z'){
			c[i]+=32;
		}
	}
	return c;
}

char* strupr(char c[]){ //ham viet hoa tat ca cac ki tu trong xau
	for(int i=0;i<strlen(c);i++){
		if(c[i]>='a'&&c[i]<='z'){
			c[i]-=32;
		}
	}
	return c;
}

int min(int a,int b){
	return a<b?a : b;
}
int strcmp(char c[],char d[]){ //So sanh 2 xau theo thu tu tu dien
	int n1 = strlen(c);
	int n2 = strlen(d);
	for(int i=0;i<min(n1,n2);i++){
		if(c[i]!=d[i]){
			if(c[i]>d[i]) return 1;
			else if(c[i]<d[i]) return -1;
		}
	}
	if(n1==n2) return 0;
	else if(n1<n2) return -1;
	else return 1;
}

long long atoll(char c[]){ //Chuyen 1 xau ki tu so thanh so nguyen long long
	long long res =0;
	for(int i=0;i<strlen(c);i++){
		res = res * 10 + c[i] - '0';
	}
	return res;
}

char* strrev(char c[]){ //Dao nguoc 1 xau
	int l=0, r= strlen(c)-1;
	while(l<r){
		char temp = c[l];
		c[l] = c[r];
		c[r] = temp;
		++l;--r;
	}
}

int main(){
	int x;
	scanf("%d",&x);
	getchar(); //Doc 1 ki tu tu ban phim
	char a[100];
	gets(a);
	printf("%s\n",a);
	printf("%d",strlen(a));
	
	int b[100][100];
}
