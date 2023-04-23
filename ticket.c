#include "wrapper.h" 
int tickets =10; 
void *counter(void *); 
int main(int argc, char **argv) 
{
    pthread_t  tid[5];
    int  i;
    for(i=1 ; i<=2; i++)
        pthread_create(&tid[i], NULL, counter, (void*)i);     

    for(i=1 ; i<=2; i++)
        pthread_join(tid[i], NULL); 
      pthread_exit(0);
}
void *counter(void *no) 
{
    while(tickets>0) {
	    printf("柜台%d 卖出一张票，票号为%d\n", (int)no, tickets);     
        usleep(1);
        tickets --; 
        usleep(1);
    }
}