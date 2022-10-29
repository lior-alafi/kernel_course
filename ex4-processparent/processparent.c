#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/sched.h>
#include <linux/sched/signal.h>

#include <linux/kernel.h>


static uint PID = 1;
module_param(PID,uint,0400);

static int kern_init(void) {
    struct task_struct *p = NULL;
    
    pr_info("%s:starting...\n",__func__);
  
    pr_info("%s:pid-%d\n",__func__,PID);

   for_each_process(p)
    {
        // pr_info("%s:process: %s\npid:%d -niet\n",__func__,p->comm,p->pid);
        if (p->pid == (pid_t)PID)
        {
            printk("%s:process: %s\npid:%d\nparent process: %s\nppid:%d",__func__,p->comm,p->pid,p->parent->comm,p->parent->pid);
        }
    }
    
    

    return 0;
}

static void kern_exit(void) 
{
    pr_info("%s:bye\n",__func__);
}



MODULE_LICENSE("GPL");
module_init(kern_init);
module_exit(kern_exit);