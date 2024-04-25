#include<stdio.h>
#include<math.h>

//Cach 1
int prime1(int n){
	int count=0;
	for(int i=1; i<=n;i++){
		if(n%i==0) ++count;
	}
	if(count==2) return 1;
	else return 0;
	}
	
//Cach 2
int prime2(int n){
	int count = 1;
	for(int i=1;i<=n/2;i++){
		if(n%i==0) ++count;
	}
	if(count==2) return 1;
	else return 0;
}

//Cach 2(Toi uu)
int prime3(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){return 0;}
		}
		
	return n>1;
}

int main(){
	int n;
	scanf("%d",&n);
	if(prime3(n)) {
	printf("Yes");
	}
	else {
	printf("No");}
	return 0;
	
}

