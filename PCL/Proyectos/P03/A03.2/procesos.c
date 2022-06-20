// procesos.c
// Prueba de procesos.
/////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>  

int main (int argc, const char * argv[]) {
    int id, i;
    char dato= '0';
    char mensaje[80];

    srandom(time(NULL));  // Para mayor aleatoriedad en las ejecuciones.

    //Proceso principal
    sprintf(mensaje, "--Punto 0  >>> %d: dato= %c\n", getpid(), dato);
    write(1, mensaje, strlen(mensaje));
    switch (id= fork()) {
      //No se crea el proceso
      case -1:
        perror("fork"); 
        exit(1);
      //Se crea el hijo
      case 0:
        sleep(random()%5);
        sprintf(mensaje, "--Punto 1  >>> %d: dato= %c\n", getpid(), dato);
        write(1, mensaje, strlen(mensaje));
        dato= 'a';
        for (i=0; i<5; i++) {
           sleep(random()%5);
           sprintf(mensaje, "--Punto 2.%d>>> %d: dato= %c\n", i, getpid(), dato);
           write(1, mensaje, strlen(mensaje));
           dato++;
        }
        break;
        //Se ejecuta por el proceso padre
      default:
        sleep(random()%5);
        sprintf(mensaje, "--Punto 3  >>> %d: dato= %c\n", getpid(), dato);
        write(1, mensaje, strlen(mensaje));
        dato= 'A';
        for (i=0; i<5; i++) {
           sleep(random()%5);
           sprintf(mensaje, "--Punto 4.%d>>> %d: dato= %c\n", i, getpid(), dato);
           write(1, mensaje, strlen(mensaje));
           dato++;
        }
    }
    sprintf(mensaje, "--Punto 5  >>> %d: dato= %c\n", getpid(), dato);
    write(1, mensaje, strlen(mensaje));
    exit(0);
}

