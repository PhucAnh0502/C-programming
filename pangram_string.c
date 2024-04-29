#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

//xau pangram la xau xuat hien day du cac thu tu tu A -> Z

int pangram(char c[]){
	strlwr(c);
	int count[26]={0};
	for(int i=0;i<strlen(c);i++){
		count[c[i]-'a'] = 1;
	}
	for(int i=0;i<26;i++){
		if(count[i]==0) return 0;
	}
	return 1;
}

int main(){
	char c[1000];
	gets(c);
	if(pangram(c)) printf("YES\n");
	else printf("NO\n");
	return 0;
}
