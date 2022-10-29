#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/sched/signal.h>
// architecture dependant
#include <asm/current.h>

/*
USEFUL MACROS:
current   : current process(task in kernel terminology) -contains pid and all the task_struct data



foreach_process  - iterating over the tasks in a given list

init_task - s.e


*/

char buff[256];
char *myGetProcStat(long state);

static int kern_start(void)
{
    struct task_struct *task_list;
    int processCounter = 0;
    struct mm_struct *m;

    pr_info("%s: starting %s\n", __func__, current->comm);
    print_hex_dump(KERN_INFO, "", DUMP_PREFIX_ADDRESS, 16, 1, current->mm, sizeof(struct mm_struct), 1);
    /*
    for (p = &init_task ; (p = next_task(p)) != &init_task ; )
    */
    for_each_process(task_list)
    {
        pr_info("%d - %s status: %s\n", task_list->pid, task_list->comm, myGetProcStat(task_list->__state));
        processCounter++;
    }

    return 0;
}

static void kern_quit(void)
{
    pr_info("%s: exiting\n", __func__);
}

MODULE_LICENSE("GPL");
module_init(kern_start);
module_exit(kern_quit);

char *myGetProcStat(long state)
{
    switch (state)
    {
    case TASK_RUNNING:
        return "TASK_RUNNING";

    case TASK_INTERRUPTIBLE:
        return "TASK_INTERRUPTIBLE";

    case TASK_UNINTERRUPTIBLE:
        return "TASK_UNINTERRUPTIBLE";

    case __TASK_STOPPED:
        return "TASK_STOPPED";

    default:
        return "UNKNOWN";
    }
    return "";
}
