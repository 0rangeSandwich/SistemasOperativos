#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


/*
Procesos abuelo -> hijo
Padre -> Hijo -> 2 Nietos
*/
int main(void)
{

   pid_t pid;
   pid_t pid1;
   int proc1,proc2;
 
   for(proc1=1;proc1<=1;proc1++)
   {
      pid1=fork(); 
      if(pid1)
      {
         printf("el abuelo es: %d\n",getpid());
         sleep(2);
      }
      else
      {
         printf("Proceso padre: %d, Su padre es %d\n",getpid(),getppid());
         sleep(2);

	for(proc2=1;proc2<=1;proc2++)
         {
            pid=fork();
            if(pid)
            {
               printf("Soy padre de nuevo %d\n",getpid());
               sleep(2);
            }
            else
            {
              printf("Proceso nieto: %d, Proceso padre es %d, el abuelo es %d\n",getpid(),getppid(),getppid()-1);
              sleep(2);
              exit(0);
            }
         }
         exit(0);
      }
  
    }
    return 0;
}
