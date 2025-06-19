# Módulo del Kernel de Linux para Reportar Uptime

## Descripción del proyecto

Este proyecto implementa un módulo del kernel de Linux escrito en lenguaje C que expone el **tiempo de actividad del sistema (uptime)** a través del sistema de archivos virtual `/proc`.

Al cargar el módulo, se crea un archivo llamado `/proc/uptime_mod`. Cada vez que un usuario ejecuta `cat /proc/uptime_mod`, el módulo calcula el tiempo transcurrido desde que el sistema se inició y lo imprime en segundos. El propósito del proyecto es comprender e implementar mecanismos de comunicación entre el espacio del núcleo (kernel space) y el espacio de usuario (user space), utilizando interfaces estándar del kernel de Linux.



## Dependencias y pasos para la instalación

Este módulo debe compilarse y ejecutarse en un entorno Linux real** (no funciona en WSL2). Se recomienda usar una máquina virtual con Ubuntu 20.04 o 22.04. La guía para la instalación de las dependencias es la siguiente:

```bash
sudo apt update
sudo apt install build-essential linux-headers-$(uname -r)
```

## Compilación

Una vez realizados los pasos de la instalación de las dependencias, se tiene que:

```bash
make
sudo insmod uptime_mod.ko
lsmod | grep uptime_mod # este paso es opcional.
cat /proc/uptime_mod
./lector_uptime

make valgrind # por si se desea analizar lector_uptime para detectar errores de memoria.
make clean # limpiar el proyecto.
```
## Requisitos
- Sistema operativo: Linux con soporte para carga de módulos
