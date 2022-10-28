#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
int counter = 1,
     arr =0; //counts actual array elements inserted
char *name="TEST";
int myarr[4];
MODULE_LICENSE("GPL");
module_param(counter,int,S_IRUGO); // module_param(<name>,<type: int,charp(char*)>,<permissions>)
module_param(name,charp,S_IRUGO); // to pass name like "hello world" you need to wrap it like name='"hello world"'
module_param_array(myarr,int,&arr,S_IWUSR | S_IRUSR);
// permissions: ootlin.com/linux/latest/source/include/linux/stat.h#L11

static int kern_init(void) {
    int i,j;
    for(i=0;i < counter; ++ i)
        printk(KERN_INFO "%s: %s has started\n",__func__,name,i);

    for(j=0;j < 4; ++j)
        printk(KERN_INFO "%s: %s iter: %d value: %d\n",__func__,name,j,myarr[j]);
    return 0;
}

static void kern_cleanup(void) {
    printk(KERN_INFO "%s: has ended\n",__func__);
}

module_init(kern_init);
module_exit(kern_cleanup);
