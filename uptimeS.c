static int uptime_show(struct seq_file *m, void *v) {
    unsigned long current_time = jiffies;  
    unsigned long uptime = (current_time - start_time);  
    unsigned long uptime_seconds = uptime_jiffies / HZ;

    seq_printf(m, "Tiempo de carga (jiffies): %lu\n", start_time); // Tiempo de carga del módulo
    seq_printf(m, "Tiempo actual (jiffies): %lu\n", current_time); // Tiempo actual del sistema
    seq_printf(m, "Uptime (jiffies): %lu\n", uptime_jiffies); // Uptime del módulo en jiffies
    seq_printf(m, "Uptime (segundos): %lu\n", uptime_seconds); // Uptime del módulo en segundos
    
    return 0; 
}
