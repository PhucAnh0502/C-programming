#include<stdio.h>

int check_giong(int arr1[], int arr2[], int n){
	int check = 1;
	for(int i=0; i<n ;i++){
		if(arr1[i] != arr2[i]){
			if(arr1[i]!=arr2[n - i - 1]) check = 0;
			else check = -1;
		}
	}
	return check;
}
int main(){
	int n;
	scanf("%d",&n);
	int arr1[n], arr2[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr1[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&arr2[i]);
	}
	printf("%d",check_giong(arr1,arr2,n));
	return 0;
}
