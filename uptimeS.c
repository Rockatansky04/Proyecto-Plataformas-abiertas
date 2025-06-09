static int uptime_show(struct seq_file *m, void *v) {
    unsigned long current_time = jiffies;  
    unsigned long uptime = (current_time - start_time) / HZ;  

    seq_printf(m, "Uptime del módulo: %lu segundos\n", uptime);  //Acá ya está contemplada una de las funciones que nos da Kerngod

    return 0; 
}
