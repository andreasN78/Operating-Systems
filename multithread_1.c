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


// argc einai tolength of argv
// argv[0] einai to file kai argv[1] to rep

typedef struct 
{
  
  int repStruct;

} DOTDATA;

DOTDATA orismaStr; /*The function  is activated when the thread is created.
 All input to this routine is obtained from a structure 
 of type DOTDATA and all output from this function is written into
 this structure.*/

void *functionSychronize(void *orisma)
{   
    int i;
    char *print;
    int temp;



    temp=orismaStr.repStruct;
pthread_mutex_lock(&myMutex); //LOCK
    for (int i=0;i<temp;i++)//εδω κανω epaναληψη μεχρι ρεπ φορεσ
    {   
          //pthread_mutex_lock(&myMutex); //LOCK
          display(orisma);
          //pthread_mutex_unlock(&myMutex); //UNLOCK
    }
    
    

                pthread_mutex_unlock(&myMutex); //UNLOCK            
    pthread_exit((void*) 0);

            
}


int main(int argc , char* argv[])
{
    

    int i;
    int rep=atoll(argv[1]);
    char *print;
    int *repStruct;
    int k;
    char *orismaPrint;
    //pthread_mutex_unlock(&myMutex); //UNLOCK

    pthread_t thread; //creating the thread

    
    orismaStr.repStruct=rep;
    k=2;
    while(k<argc){
        //pthread_mutex_lock(&myMutex); //LOCK
    orismaPrint = argv[k];
        
        pthread_create(&thread, NULL, (void *)functionSychronize, (void *)orismaPrint);
        k++;
        //pthread_mutex_unlock(&myMutex);

    }

    

        for(i=2;i<argc;i++){
    pthread_join(thread, NULL); //perimenw na termatisoun ola apmexri argc
}

    
    
    pthread_mutex_destroy(&myMutex); //katastrefw  to thread

  return 0;
}

