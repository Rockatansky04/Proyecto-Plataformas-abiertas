static void __exit uptime_mod_exit(void) {
    remove_proc_entry(PROC_NAME, NULL); //Acá ya está contemplada una de las funciones que nos da Kerngod
    pr_info("uptime_mod removido.\n");
}