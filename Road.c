#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Road{
    int id;
    char name[20];
    int from[3];
    int to[3];
    int hR;
    int hL;
    double L;
} Road;

int max(int a,int b){
    if(a>b) return a;
    else return b;
}
int main(){
    int N;
    scanf("%d", &N);
    Road arr[N];
    for(int i = 0; i < N; i++){
        char content[20];
        scanf("%d", &arr[i].id);
        scanf("%s", content);
        strcpy(arr[i].name, content);
        scanf("%lf", &arr[i].L);
        scanf("%d", &arr[i].hR);
        scanf("%d", &arr[i].hL);
        scanf("%d", &arr[i].from[0]);
        scanf("%d", &arr[i].from[1]);
        scanf("%d", &arr[i].from[2]);
        scanf("%d", &arr[i].to[0]);
        scanf("%d", &arr[i].to[1]);
        scanf("%d", &arr[i].to[2]);
    }
    int max1=0;
    double max2=0;
    double matdo[N];
    for(int i=0;i<N;i++){
        if(arr[i].L>max1) max1=arr[i].L;
        matdo[i]=max(arr[i].hR,arr[i].hL)/(arr[i].L*0.001);
        if(matdo[i]>max2) max2=matdo[i]; 
    }
    printf("%d %d",max1+1,(int)max2+1);
}
