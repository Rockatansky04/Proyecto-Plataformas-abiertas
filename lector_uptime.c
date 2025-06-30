// Se identificó que se necesitaría un programa en C para que exista una interacción con el usuario en el espacio del mismo, el cual lleva por nombre lector_uptime.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char respuesta;

    printf("¿Desea cargar el módulo uptime_mod? (S/N): ");
    scanf(" %c", &respuesta);

    if (respuesta == 'S' || respuesta == 's') {
    
        int cargado = system("lsmod | grep -q '^uptime_mod '");

        if (cargado == 0) {
            printf("El módulo ya estaba cargado. Se procederá a descargarlo primero...\n");
            system("sudo rmmod uptime_mod");

           
            sleep(1);
        }

   printf("Cargando el módulo uptime_mod...\n");
        int ins = system("sudo insmod uptime_mod.ko");

        if (ins != 0) {
            printf(" Error al insertar el módulo.\n");
            return 1;
        }

        sleep(2);

        printf("Leyendo /proc/uptime_mod...\n");
        system("cat /proc/uptime_mod");

       
        printf("Descargando el módulo uptime_mod...\n");
        system("sudo rmmod uptime_mod");

    } else {
        printf("El módulo no ha sido cargado. Saliendo...\n");
    }

    return 0;
}
