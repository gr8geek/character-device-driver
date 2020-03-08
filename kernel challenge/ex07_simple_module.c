#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

int ex07_open(struct inode *pinode,struct file *pfile)
{
	printk(KERN_ALERT "inside the function function ex07 open\n");
	return 0;

}
ssize_t ex07_read(struct file *pfile,char __user *buffer,size_t length,loff_t *offset)
{
        printk(KERN_ALERT "Inside the function read function\n");
	return 0;
}
ssize_t ex07_write(struct file *pfile,const char __user *buffer,size_t length,loff_t *offset)
{
	printk(KERN_ALERT "Inside the function write\n");
	return length;
}
int ex07_close(struct inode *pinode,struct file *pfile)
{
	printk(KERN_ALERT "Inside the function close\n");
	return 0;
}

struct file_operations ex07_file_operations={
	.owner=THIS_MODULE,
	.open =ex07_open,
	.read=ex07_read,
	.write=ex07_write,
	.release=ex07_close,

};
int ex01_simple_module_init(void)
{
	printk(KERN_ALERT "Inside the init function\n");
	//register the character device driver in the kernel
	register_chrdev(240/*major num*/,"Simple Character driver by pratyush",&ex07_file_operations/*file operations*/);
	return 0;
}
void ex01_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside the exit function\n");
	//unrigester the character device driver
	unregister_chrdev(240,"Simple Chararacter driver by pratyush");

}
module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);
 
