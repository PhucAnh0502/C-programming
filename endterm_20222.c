#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct hovaten{
	char ho[20];
	char tendem [20];
	char ten[20];	
};
typedef struct hovaten ten;
int main(){
	int t;
	scanf("%d",&t);
	ten arr[1000];
	for(int i=0;i<t;i++){
		scanf("%s",arr[i].ho);
		arr[i].ho[0]=toupper(arr[i].ho[0]);
		for(int j=1;j<strlen(arr[i].ho);j++){
		arr[i].ho[j]=tolower(arr[i].ho[j]);
		}
		scanf("%s",arr[i].tendem);
		arr[i].tendem[0]=toupper(arr[i].tendem[0]);
		for(int j=1;j<strlen(arr[i].tendem);j++){
		arr[i].tendem[j]=tolower(arr[i].tendem[j]);
		}
		scanf("%s",arr[i].ten);
		arr[i].ten[0]=toupper(arr[i].ten[0]);
		for(int j=1;j<strlen(arr[i].ten);j++){
		arr[i].ten[j]=tolower(arr[i].ten[j]);
		}
	}
	for(int i=0;i<t;i++){
		printf("%s ",arr[i].ho);
		printf("%s ",arr[i].tendem);
		printf("%s\n",arr[i].ten);
	}
}
