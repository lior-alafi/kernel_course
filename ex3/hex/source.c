#include <linux/string.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>


#include "struct.h"

MODULE_LICENSE("GPL");


struct MyStruct person;
EXPORT_SYMBOL(person);


static int kinit(void) {
    person.x = 36;
    person.y = 180;
    strcpy(person.name,"lior alafi");
        printk(KERN_INFO "%s: (src) HI name = %s x = %d y = %d\n",__func__,person.name,person.x,person.y);


    return 0;
}

static void kexit(void) {
        printk(KERN_INFO "%s: (src)  BYE name = %s x = %d y = %d\n",__func__,person.name,person.x,person.y);

}



module_init(kinit);
module_exit(kexit);



