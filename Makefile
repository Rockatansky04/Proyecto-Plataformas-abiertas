obj-m := uptime_mod.o # Módulo de kernel
USER_PROG := lector_uptime # Programa de usuario

KDIR := /lib/modules/$(shell uname -r)/build # Ruta al directorio de construcción del kernel
PWD  := $(shell pwd) # Ruta al directorio actual

.PHONY: all clean module user valgrind # Objetivos especiales
all: module user # Objetivo por defecto

module: # Compila el módulo del kernel
	$(MAKE) -C $(KDIR) M=$(PWD) modules

user: # Compila el programa de usuario
	gcc -Wall -o $(USER_PROG) lector_uptime.c


valgrind: user # Ejecuta el programa de usuario con Valgrind
	valgrind --leak-check=full ./$(USER_PROG)

clean: # Limpia los archivos generados
	$(MAKE) -C $(KDIR) M=$(PWD) clean 
	rm -f $(USER_PROG)
