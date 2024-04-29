#include<stdio.h>

int main(){
	char c[10000];
	gets(c);
	int cnt[26] = {0};
	for(int i=0;i<strlen(c);i++){
		c[i] = tolower(c[i]);
		cnt[c[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]!=0) printf("The letter %c appears %d times\n",i+'a',cnt[i]);
	}
	return 0;
}
