static int uptime_show(struct seq_file *m, void *v) {
    unsigned long current_time = jiffies;  
    unsigned long uptime = (current_time - start_time) / HZ;  

    seq_printf(m, "Uptime del módulo: %lu segundos\n", uptime);
    return 0; 
}

static int uptime_open(struct inode *inode, struct file *file) {
    return single_open(file, uptime_show, NULL);
}
