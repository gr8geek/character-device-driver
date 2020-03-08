#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

int ex07(struct inode *pinode,struct file *pfile)
{
	printk(KERN_ALERT "inside the function function ex07 open");

}
ssize_t ex07_read(struct file 8pfile,char __user *buffer,size_t length,loff_t *offset)
{
        printk(KERN_ALERT "Inside the function %sfunction\n",__FUNCTION__);
}
ssize_t ex07_write(struct *pfile.const char __user *buffer,size_t length,loff_t *offset)
{
	printk(KERN_ALERT "Inside the function %s\n",__FUNCTION__);
	return length;
}
int ex07_close(struct inode *pinode,struct file *pfile)
{
	printk(KERN_ALERT "Inside the function %s\n",__FUNCTION	__);
	return 0;
}

struct file_operations_ex07_file_operations={
	.owner=THIS_MODULE,
	.open =ex07_open,
	.read=ex07_read,
	.write=ex07_write,
	.release=ex07_close,

};
int ex01_simple_module_init(void)
{
	printk(KERN_ALERT "Inside the %s ffunction\n"__FUNCTION__);
	//register the character device driver in the kernel
	register_chardev(240/*major num*/,"Simple Character driver by pratyush",&ex07_file_operations/*file operations*/);
}
void exo1_simple_module_exit(void)
{
	printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
	//unrigester the character device driver
	unregister_chrdev(240,"Simple Chararacter driver by pratyush");

}
module_init(ex01_simple_module_init);
module_exit(ex01_simple_module_exit);
 
