#include <linux/module.h>   // Convierte el programa en modulo
#include <linux/kernel.h>   // Nos permite usar el pr_info()
#include <linux/init.h>     // Permite el uso de las funcion de inicio     
#include <linux/proc_fs.h>  // Nos permite crear los archivos virtuales con proc()
#include <linux/seq_file.h> // Permite escribir contenido en proc     
#include <linux/jiffies.h>  // Nos permite acceder al tiempo desde el boot del sistema

#define PROC_NAME "uptime_mod"

static unsigned long start_time;

static int uptime_show(struct seq_file *m, void *v) {
    unsigned long current_time = jiffies;  
    unsigned long uptime_jiffies = (current_time - start_time);  
    unsigned long uptime_seconds = uptime_jiffies / HZ;

    seq_printf(m, "Tiempo de carga (jiffies): %lu\n", start_time); // Tiempo de carga del módulo
    seq_printf(m, "Tiempo actual (jiffies): %lu\n", current_time); // Tiempo actual del sistema
    seq_printf(m, "Uptime (jiffies): %lu\n", uptime_jiffies); // Uptime del módulo en jiffies
    seq_printf(m, "Uptime (segundos): %lu\n", uptime_seconds); // Uptime del módulo en segundos
    
    return 0; 
}

static int uptime_open(struct inode *inode, struct file *file) {
    return single_open(file, uptime_show, NULL);
}

static const struct proc_ops uptime_fops = {
    .proc_open    = uptime_open, // Desde acá se abre el archivo
    .proc_read    = seq_read,    // Con esta función se lee
    .proc_lseek   = seq_lseek,   // Esta permite moverse en el archivo
    .proc_release = single_release // Libera el archivo
};

static int __init uptime_mod_init(void) {
    start_time = jiffies;

    if (!proc_create(PROC_NAME, 0, NULL, &uptime_fops)) {
        pr_alert("No se pudo crear /proc/%s\n", PROC_NAME);
        return -ENOMEM;
    }

    pr_info("uptime_mod cargado correctamente.\n");
    return 0;
}

static void __exit uptime_mod_exit(void) {
    remove_proc_entry(PROC_NAME, NULL);
    pr_info("uptime_mod removido.\n");
}

module_init(uptime_mod_init);
module_exit(uptime_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Luis Martinez, Daniel Brenes, Daniel Barrantes");
MODULE_DESCRIPTION("Módulo que reporta el tiempo desde que fue cargado.");
