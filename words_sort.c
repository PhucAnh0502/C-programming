#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

//Sap xep cac tu trong xau theo thu tu tu dien
void ss(char a[][50], int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(strcmp(a[j],a[min])<0) min=j;
		}
		char tmp[100];
		strcpy(tmp,a[min]);
		strcpy(a[min],a[i]);
		strcpy(a[i],tmp);
	}
}
//sap xep cac tu trong xau theo thu tu chieu dai
//Neu muon a dung truoc b thi return -1
//Neu muon a dung sau b thi return 1
int cmp(const void *a, const void *b){
	char *x=(char*)a;
	char *y=(char*)b;
	if(strlen(x)!=strlen(y)){
		if(strlen(x)<strlen(y)) return -1;
		else return 1;
	}
	else{
		if(strcmp(x,y)<0) return -1;
		else return 1;
	}
}
int main(){
	char c[1000];
	gets(c);
	char a[20][50];
	int n = 0; //dem so luong tu trong cau
	char *token = strtok(c," ");
	while(token != NULL){
		strcopy(a[n], token);
		++n;
		token = strtok(NULL," ");
	}
	sx(a,n);
	for(int i=0;i<n;i++){
		printf("%s ",a[i]);
	}
	printf("\n");
	qsort(a,n,sizeof(a[0]),cmp);
	for(int i=0;i<n;i++){
		printf("%s ",a[i]);
	}
	printf("\n");
	return 0;
}
