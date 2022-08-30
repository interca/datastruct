#include<stdio.h>
struct student{
	int number;
};
int main(){
	struct student p[10];
	void temp(struct student p[10]);
	int i;
	temp(p);
	for(i=0;i<4;i++){
		printf("%d\n",p[i].number);
	}
	return 0;
}
void temp(struct student p[10]){
	int i;
	for(i=0;i<4;i++){
		scanf("%d",&p[i].number);
	}
	for(i=0;i<4;i++){
		printf("%d ",p[i].number);
	}
}
