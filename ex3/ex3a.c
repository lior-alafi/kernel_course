#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/jiffies.h>
// #include <linux/moduleparam.h>

char *name = "DEFAULT";
MODULE_LICENSE("GPL");
// module_param(name,charp,S_IRUGO);

void print_jiffies(void) {
    printk(KERN_INFO "%s: %s jiffa: %ld\n",__func__,name,jiffies);
}

static int ker_init(void) {
    printk(KERN_INFO "%s: %s initialized\n",__func__,name);

    return 0;
}


static void ker_exit(void) {
    printk(KERN_INFO "%s: %s teardown\n",__func__,name);

}
EXPORT_SYMBOL(print_jiffies);
module_init(ker_init);
module_exit(ker_exit)