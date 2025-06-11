static int uptime_open(struct inode *inode, struct file *file) {
    return single_open(file, uptime_show, NULL);
}
