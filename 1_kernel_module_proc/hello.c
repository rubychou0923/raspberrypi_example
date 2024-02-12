/**
 * hello.c
 *
 * Kernel module that communicates with /proc file system.
 * 
 * The makefile must be modified to compile this program.
 * Change the line "simple.o" to "hello.o"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define BUFFER_SIZE 128

#define PROC_NAME "rf_status"
#define MESSAGE "Delta"

/**
 * Function prototypes
 */
static ssize_t proc_read(struct file *file, char *buf, size_t count, loff_t *pos);
static ssize_t proc_write(struct file *file, const char *buf, size_t count, loff_t *pos);

static struct proc_ops proc_ops = {
        .proc_read = proc_read,
        .proc_write = proc_write,
};


/* This function is called when the module is loaded. */
static int proc_init(void)
{

        // creates the /proc/hello entry
        // the following function call is a wrapper for
        // proc_create_data() passing NULL as the last argument
        proc_create(PROC_NAME, 0666, NULL, &proc_ops);

        printk(KERN_INFO "/proc/%s created\n", PROC_NAME);

    return 0;
}

/* This function is called when the module is removed. */
static void proc_exit(void) {

        // removes the /proc/hello entry
        remove_proc_entry(PROC_NAME, NULL);

        printk( KERN_INFO "/proc/%s removed\n", PROC_NAME);
}

static char buffer[BUFFER_SIZE]={"Hello World!"};
/**
 * This function is called each time the /proc/hello is read.
 * 
 * This function is called repeatedly until it returns 0, so
 * there must be logic that ensures it ultimately returns 0
 * once it has collected the data that is to go into the 
 * corresponding /proc file.
 *
 * params:
 *
 * file:
 * buf: buffer in user space
 * count:
 * pos:
 */
static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos)
{
        int rv = 0;
        static int completed = 0;

        if (completed) {
                completed = 0;
                return 0;
        }

        completed = 1;

        // copies the contents of buffer to userspace usr_buf
        printk("[%s:%d] buffer:%s, sizeof(buffer):%d\n",__func__,__LINE__,buffer,sizeof(buffer));
		
		memset(buffer,0,sizeof(buffer));

		snprintf(buffer,sizeof(buffer),"Freq:%d\n",270000);
        copy_to_user(usr_buf, buffer, sizeof(buffer));
        return sizeof(buffer);
}



static ssize_t proc_write(struct file *file, const char __user *usr_buf, size_t count, loff_t *pos)
{
        int rv = 0;

        printk("[%s:%d]  count:%d\n",__func__,__LINE__,count);
		if(count > BUFFER_SIZE)
			count = BUFFER_SIZE;
        // copies the contents to buffer from userspace usr_buf
        if(copy_from_user(buffer, usr_buf, count))
			return -EFAULT;

        printk("[%s:%d]  buffer:%s \n",__func__,__LINE__,buffer);
        return count;
}


/* Macros for registering module entry and exit points. */
module_init( proc_init );
module_exit( proc_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello Module");