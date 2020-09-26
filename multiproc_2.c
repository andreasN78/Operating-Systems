#include <stdio.h>
#include "util.h"
 
 
#include <unistd.h>
 
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <stdlib.h>
 
 int main(int argc,char *argv[])
{
    // sto prwto kommati tis ergasias
    // prepei na kanw sixronismo diergasiwn
    // tha xrisimopoiisw semaphores ena array apo sem
   //semaphore buffers
    int i;
    int l=0;
    
    
 
   
    int limit=0;
    int rep;
    struct sembuf up ={0, 1, 0};
    struct sembuf down ={0, -1, 0};
    int mysem=semget(IPC_PRIVATE,1,0600);
    
    
    semop(mysem,&up,1);//arxika tha einai 1
    /*for(int j=2;j<=argc;j++){
        display(argv[j]);
    }*/
    rep=atoi(argv[1]);
    for(i=2;i<argc;i++)
    {
    int returnVal=fork();
    if (returnVal==0)// pid of child
    {
		semop(mysem,&down,1);
		init();
		semop(mysem,&up,1);
		
        while(limit<rep)
            {
            	semop(mysem,&down,1);//efoson theloume sixronismo
                
                display(argv[i]);
                semop(mysem,&up,1);

            limit++;
            }
            
            exit(0);
            
       }
   }
         	for(i=2;i<argc;i++){
        
        	wait(NULL);
        }
         	semctl(mysem,0,IPC_RMID); //KILL SEM
        return 0;


}
