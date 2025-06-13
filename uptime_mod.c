#include <linux/module.h>      
#include <linux/kernel.h>        
#include <linux/init.h>         
#include <linux/proc_fs.h>       
#include <linux/seq_file.h>      
#include <linux/jiffies.h>  

#define PROC_NAME "uptime_mod"

static unsigned long start_time;

static int uptime_show(struct seq_file *m, void *v) {
    unsigned long current_time = jiffies;  
    unsigned long uptime = (current_time - start_time) / HZ;  

    seq_printf(m, "Uptime del módulo: %lu segundos\n", uptime);  //Acá ya está contemplada una de las funciones que nos da Kerngod

    return 0; 
}

static int uptime_open(struct inode *inode, struct file *file) {
    return single_open(file, uptime_show, NULL);
}

static const struct proc_ops uptime_fops = {
    .proc_open    = uptime_open,
    .proc_read    = seq_read,   
    .proc_lseek   = seq_lseek,
    .proc_release = single_release
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
    remove_proc_entry(PROC_NAME, NULL); //Acá ya está contemplada una de las funciones que nos da Kerngod
    pr_info("uptime_mod removido.\n");
}


module_init(uptime_mod_init);
module_exit(uptime_mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Luis Martinez, Daniel Brenes, Daniel Barrantes");
MODULE_DESCRIPTION("Módulo que reporta el tiempo desde que fue cargado.");

//Ya solo falta agregar esas funciones, crear el makefile y estaríamos R muchachos.
