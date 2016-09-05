#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

main() {
	printf("Proceso Padre Inicia\n");
    int num = fork();
    if(num == 0){
    	wait(0);
		printf("Inicia proceso Hijo\n");
		int abrir = open("ArchivoNuevo1", O_WRONLY);
		printf("Abre el archivo proceso Hijo\n");
		write(abrir, "HijoEscribeArchivo", 18);
		printf("Escribe en el archivo proceso Hijo\n");
		close(abrir);
		printf("Se cierra el archivo por proceso Hijo\n");
    }
    else{
    	printf("Proceso Padre crea archivo\n");
		int archivo = creat("ArchivoNuevo1", 0666);
		close(archivo);
		printf("Se cierra el archivo por proceso Padre\n");
		exit(0);
    }
    printf("Finaliza el proceso");
}
