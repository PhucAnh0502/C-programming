#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct shop{
	int id;
	char name[20];
	int income;
	int money;
	int customer[5];
};
typedef struct shop shop;

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
	int N;
	scanf("%d",&N);
	shop arr[N+1];
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i].id);
		scanf("%s",&arr[i].name);
		scanf("%d",&arr[i].income);
		scanf("%d",&arr[i].money);
		scanf("%d",&arr[i].customer[0]);
		scanf("%d",&arr[i].customer[1]);
		scanf("%d",&arr[i].customer[2]);
		scanf("%d",&arr[i].customer[3]);
		scanf("%d",&arr[i].customer[4]);
	}
	
	int x;
	char a[20];
	scanf("%d",&x);
	scanf("%s",&a);
	int check=1;
	for(int i=1;i<=N;i++){
		if(strcmp(arr[i].name,a)==0){
			check=0;
			break;
		}
		else if(strcmp(strrev(a),arr[i].name)==0){
			check=0;
			break;
		}
		else if(strstr(arr[i].name,a)==0||strstr(a,arr[i].name)){
			check=0;
			break;
		}
	}
	printf("%d",check);
	return 0;
}
