// lanzador_1.c
/////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, const char * argv[]) {
    int i, id;

    if (argc <= 1) {
       fprintf(stderr, "Uso: %s lista_de_programas_a_ejecutar\n", argv[0]);
       exit(1);
    }

    for (i=1; i<argc; i++) {
      switch (id=fork()) {
      case -1:
        perror("fork");
        exit(1);
      case 0:
        if (execlp(argv[i], argv[i], NULL) == -1)
           fprintf(stderr, "El programa %s no se ha podido ejecutar\n", argv[i]);
        break;
      default:
        while ((waitpid(id, NULL, 0)) != id) ; 
        break;
      }
    }
    while ((id=wait(NULL)) != (-1)) 
        fprintf(stderr, "Terminado %i\n", id);
}