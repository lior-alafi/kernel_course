#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

// SPECIFY THE LICENSE (MANDATORY)
MODULE_LICENSE("GPL");

void func(void);
static int ex1_init(void)
{
    printk(KERN_INFO "%s: in init\n", __func__);

    func();
    printk(KERN_INFO "%s: %s\n", __func__, buff);
    return 0;
}

static void ex1_exit(void)
{
    printk(KERN_INFO "%s: in exit\n", __func__);
}

module_init(ex1_init);
module_exit(ex1_exit);