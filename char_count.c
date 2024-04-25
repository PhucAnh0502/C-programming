#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

int main(){
	//Dem so luong chu cai,chu so va ki tu dac biet
	int cnt1=0, cnt2=0;
	char c[1005];
	gets(c);
	for(int i=0;i<=strlen(c);i++){
		if(isalpha(c[i])) ++cnt1;
		else if(isdigit(c[i])) ++cnt2;
	}
	printf("%d %d %d\n",cnt1,cnt2,strlen(c)-cnt1-cnt2);
	
	//In chu cai cung so lan xuat hien cua no theo thu tu tu dien
	int cnt[26]={0};
	for(int i=0;i<=strlen(c);i++){
		cnt[c[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]!=0){
			printf("%c %d\n",i+'a',cnt[i]);
		}
	}
	
	//
	return 0;
}
