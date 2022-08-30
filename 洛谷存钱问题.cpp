#include<stdio.h>
#include<math.h>
int main(){
	int msum=0;
	int cost;
	int rest=0;
	int i;
	int imprise=1;
	int cun;
	int flag;
	for(i=1;i<=12;i++){
		scanf("%d",&cost);
		rest=300+rest-cost;
	
		if(rest<0){
			if(imprise==1){
			flag=i;
		}
			imprise=0;
		}
		else {
			cun=rest/100*100;
	        msum=msum+cun;
		   rest=rest-cun;
		}
	
	}
	if(imprise==0)printf("-%d",flag);
	else {
		int a=(int)(msum*1.2+rest);
		printf("%d",a+1);
	}
	return 0;
} 
