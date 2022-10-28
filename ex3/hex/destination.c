#include <linux/string.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>


#include "struct.h"

MODULE_LICENSE("GPL");
char *modname =  __stringify(KBUILD_MODNAME); //loads the module name to modname

extern struct MyStruct person;

static int kinit(void) {
    printk(KERN_INFO "%s: (%s) name = %s x = %d y = %d\n",__func__,modname,person.name,person.x,person.y);
    /*
     * print_hex_dump - print a text hex dump to syslog for a binary blob of data
 * @level: kernel log level (e.g. KERN_DEBUG)
 * @prefix_str: string to prefix each line with;
 *  caller supplies trailing spaces for alignment if desired
 * @prefix_type: controls whether prefix of an offset, address, or none
 *  is printed (%DUMP_PREFIX_OFFSET, %DUMP_PREFIX_ADDRESS, %DUMP_PREFIX_NONE)
 * @rowsize: number of bytes to print per line; must be 16 or 32
 * @groupsize: number of bytes to print at a time (1, 2, 4, 8; default = 1)
 * @buf: data blob to dump
 * @len: number of bytes in the @buf
 * @ascii: include ASCII after the hex output
    
    https://github.com/spotify/linux/blob/master/lib/hexdump.c
    */
    print_hex_dump(KERN_INFO, "buffer: ",DUMP_PREFIX_ADDRESS,16,1,&person,sizeof(struct MyStruct), 1);
    return 0;
}

static void kexit(void) {
        dump_stack();
        printk(KERN_INFO "%s: (%s)  BYE name = %s x = %d y = %d\n",__func__,modname,person.name,person.x,person.y);
}



module_init(kinit);
module_exit(kexit);



