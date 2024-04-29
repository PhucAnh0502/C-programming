#include<stdio.h>
#include<math.h>

int main(){
	int v,x;
	scanf("%d",&v);
	int edge[v][2];
	int count[100001]={0};
	for(int i=0;i<v;i++){
		scanf("%d %d",&edge[i][0],&edge[i][1]);
		count[edge[i][0]]++;
		count[edge[i][1]]++;
	}
	for(int i=0;i<(v-1);i++){
		int min=10000;
		for(int j=0;j<v;j++){	
			if(count[edge[j][0]]==1){
				if(min>edge[j][0]&&edge[j][0]>0){
					min=edge[j][0];
					x=j;
				}
			}
			if(count[edge[j][1]]==1){
				if(min>edge[j][1]&&edge[j][1]>0){
					min=edge[j][1];
					x=j;
				}
			}
		}
		count[edge[x][0]]--;
		count[edge[x][1]]--;
		if(count[edge[x][0]]==0){ 
		    printf("%d ",edge[x][1]);
		    edge[x][1]=10001;
		}
		else {
		    printf("%d ",edge[x][0]);
		    edge[x][0]=10001;
		}
		
	}
	
	return 0;
}
