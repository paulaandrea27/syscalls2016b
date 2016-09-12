# 13207002
#include <stdio.h> /*COMUNICACIÓN PADRE HIJO*/
int main(argc,argv[])
int argc; char *argv[];
{int tubería[2], dato, suma, estado;
pipe(tuberia);
if (fork()!=0)
{ /* proceso padre, escribe de 1 a dato */
close(tuberia[0]);
dato=atoi(argv[1]); /*transforma argv[1] en entero*/
for (i=1;i<=dato;i++) write(tuberia[1],&i,sizeof(int));
close(tuberia[1]); 
wait(&estado); 
printf(“El padre finaliza despues que el hijo\n”);
exit(0);
}
else
{ /* proceso hijo , suma de 1 a dato*/
close(tuberia[1]);
suma = 0;
while (read(tuberia[0],&dato,sizeof(int))>0) suma=suma+dato;
close(tuberia[0]); 
prinf(“Suma calculada en el proceso hijo%d\n”,suma);
exit(0);
}
}
