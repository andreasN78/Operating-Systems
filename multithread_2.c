#include <stdio.h>
#include "util.h"
#include <sys/sem.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
pthread_mutex_t myMutex;
pthread_mutex_t myMutex2;
pthread_cond_t countMutexes;
int metritis=0;

// argc einai tolength of argv
// argv[0] einai to file kai argv[1] to rep

typedef struct 
{
  int argcLimit;
  int repStruct;

} DOTDATA;

DOTDATA orismaStr; 

void *functionSychronize(void *orisma)
{   
    int i;
    char *print;
    int temp;
    int temp2;



    temp=orismaStr.repStruct;
    temp2=orismaStr.argcLimit;
    temp2=temp2-2;
    

    pthread_mutex_lock(&myMutex2);
    init();
    metritis++;
    
if (metritis=temp2){
    pthread_mutex_unlock(&myMutex2);
    
        

    
    for (int i=0;i<temp;i++)
        {  
            pthread_mutex_lock(&myMutex2); //LOCK
        
          
          display(orisma);
            pthread_mutex_unlock(&myMutex2); //UNLOCK
          
        }//FOR
            
                }//IF
                            
    pthread_exit((void*) 0);

            
}


int main(int argc , char* argv[])
{
    

    int i;
    int rep=atoll(argv[1]);
    char *print;
    int *repStruct;
    int *argcLimit;
    int k;
    char *orismaPrint;
    //pthread_mutex_unlock(&myMutex); //UNLOCK

    pthread_t thread; //creating the thread
    pthread_mutex_init(&myMutex,NULL);
    pthread_mutex_init(&myMutex2,NULL);
   
    orismaStr.argcLimit=argc;
    orismaStr.repStruct=rep;
    k=2;
    while(k<argc){
        //pthread_mutex_lock(&myMutex); //LOCK
    orismaPrint = argv[k];
        
        pthread_create(&thread, NULL, (void *)functionSychronize, (void *)orismaPrint);
        k++;
       // pthread_mutex_unlock(&myMutex);

    }
    

        for(i=2;i<argc;i++){
    pthread_join(thread, NULL); //perimenw na termatisoun ola apmexri argc
}

    
    
    pthread_mutex_destroy(&myMutex); //katastrefw  to thread
    pthread_mutex_destroy(&myMutex2);
  return 0;
}


