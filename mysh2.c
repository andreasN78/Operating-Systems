#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 256
#define LIMIT 2000
#include <sys/wait.h>

#include <string.h>
#include <unistd.h>
//functions
int countSentenceIndex(char **sentence_pointer,int count);
int execCmd(char **sentence_pointer);

char *home_directory;

// Tha exw akoma mia metavliti i opoia tha pairnei ta arguments tis entolis
int main()
{
	int lim=0;
	int count=0;
	char *sentence[SIZE];
	char command[LIMIT];
	/*getcwd() shall return the  argument. 
	Otherwise, getcwd() shall return a null pointer and 
	set errno to indicate the error*/
	//
	home_directory=getcwd(NULL,0);
	for(;;) 
	{


	printf("$ ");
	fgets(command,2000,stdin);
	if (strcmp(command,"exit")==0){ 
		break; 
	}
	
	
		sentence[count]=strtok(command," \n\t");
	
	
	while (sentence[count]!=NULL)    //sentence[count]
	{
		count=count+1;
		sentence[count]=strtok(NULL," \n\t");

	}


    
    /*for (int i=0;i<=count;i++)
    {
printf("%s\n",sentence[i]);
}*/


execCmd(sentence);
memset(sentence,0,2000);
}//for
}//main

int execCmd(char **sentence_pointer)
{
	if (!strcmp(sentence_pointer[0],"cd"))
	{
		if(sentence_pointer[1][0]=='~')//an mou dwsei cd ~
		{
			if (strlen(sentence_pointer[1])==1)//elegxos
			// einai mono to ~
{
	if((chdir(home_directory))<0)
	{
		perror("Problem head to start directory");
		return -3;

	}
}
		else {
		char temp[200];
		strcpy(temp,home_directory);
		strcat(temp,sentence_pointer[1]+1);
		if((chdir(temp))<0)
		{
			perror("No path");
			return -1;
		}

	}
}

}
	
	else
	{
		//Creating new process
		pid_t new_process;
		new_process=fork();
	if (new_process<0)//error when -1
		{
			perror("Fork error");
			exit(1);

		}
		if (new_process==0)//fork executed by child
		{
			execvp(sentence_pointer[0],sentence_pointer);
			exit(0);//an grapsw kati pou den iparxei stin exec
		}
		
		
		wait(NULL);//parent
	}//memset(sentence_pointer,0,2000);
	return 0;
}





