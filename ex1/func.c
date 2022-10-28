#include <linux/kernel.h>

void func(void) {
    printk(KERN_INFO"%s: in func \n",__func__);
}