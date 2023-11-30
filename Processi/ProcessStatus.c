#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int p;
int status;
int main(int argc, char*argv[])
{   
    p=fork();

     if (p==0)
    {
        printf("1_Sono il figlio e il mio PID=%d\n",getppid());
        printf("2_Sono il figlio e mio padre ha PID=%d\n",getppid());

        exit(25);
    }else
    {
        printf("4_Sono il padre il mio PID=%d\n",getppid());
        printf("5_Sono il padree e mio padre ha PID=%d\n",getpid());
        printf("attendo che mio figlio %d termini\n",wait(&status));
        printf("Il codice di terminazione di mio figlio è \' WEXITSTATUS(status) = %d \n", WEXITSTATUS(status));
    }
    return 0;
}