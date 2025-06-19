// Se identificó que se necesitaría un programa en C para que exista una interacción con el usuario en el espacio del mismo, el cual lleva por nombre lector_uptime.c
#include <stdio.h>
#include <stdlib.h>

int main() {
char respuesta;
printf("Desea cargar el modulo uptime? (S/N)");
scanf("%c", &respuesta);

if (respuesta == 'S' || respuesta == 's'){ 
        printf("Se procederá a cargar el modulo");
        system("sudo insmod uptime_mod.ko"); //Subimos el modulo

        printf("Se está leyendo el modulo");
        system("cat /proc/uptime_mod"); //Analiza y lee modulo

        printf("Descargando el modulo uptime... \n"); //Baja el modulo
        scanf("sudo rmmod uptime_mod");
} else {
printf("El modulo se cargará, se procederá a salir... \n");
}
return 0;
}
