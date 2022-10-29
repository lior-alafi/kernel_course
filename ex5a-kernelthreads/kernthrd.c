#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

static task_struct *mythread = NULL;

int threadFunc(void *pv)
{
    int i = 0;
    while (!kthread_should_stop())
    {
        pr_info("%s: in thread func %d", __func__, ++i);
        msleep(1000);
    }
}

static int kern_init(void)
{
    pr_info("%s: started...\n", __func__);
    mythread = kthread_create(threadFunc, NULL, "threadFunc");
    if (mythread)
    {
        pr_info("%s: kthread created successfully\n", __func__);

        wake_up_process(mythread);
        pr_info("%s: kthread running...\n", __func__);

        return 0;
    }

    pr_err("%s: spawning kthread failed\n", __func__);
    return 0;
}

static void kern_exit(void)
{
}

MODULE_LICENSE("GPL");
module_init(kern_init);
module_exit(kern_exit);