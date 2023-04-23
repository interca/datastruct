
int num[1000];
//移动次数
int countMove = 0;
//比较次数
int countCompare = 0;

//初始化
void init(){
    countMove = 0;
    countCompare = 0;
    //随机数
    srand((unsigned)time(NULL));
    for(int i = 0 ; i < 1000 ; i ++){
        num[i] = rand()%10000;
    }
}