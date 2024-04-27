#include<stdio.h>
#include<math.h>

//Neu muon sang cac so nguyen to khong vuot qua n 
//Phai tao mang co kich thuoc n+1 phan tu
int prime[1000001];

void sieve(){
	//Coi cac phan tu 0 cho toi n la cac so nguyen to
	for(int i=0;i<=1000000;i++){
		prime[i] = 1;
	//Loai 0 va 1
	}
	prime[0] = prime[1] = 0;
	for(int i=2;i<=1000;i++){
		//Neu i la so nguyen to
		if(prime[i]){
			//Duyet tat ca cac boi so cua i va cho no khong la so nguyen to
			for(int j=i*i;j<=1000000;j+=i){
				prime[j] = 0; //j khong con la so nguyen to nua
			}
		}
	}
}
//kiem tra tat ca cac chu so co phai so nguyen to 
int digitprime(int n){
	while(n){
		int r=n%10;
		if(r!=2&&r!=3&&r!=5&&r!=7)
		return 0;
		n/=10;
	}
	return 1;
}

int main(){
	int t;
	sieve();
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d%d",&a,&b);
		int cnt=0;
		for(int i=a;i<=b;i++){
			if (prime[i]&&digitprime(i))
				++cnt;
		}
		printf("%d",cnt);
	}
}
