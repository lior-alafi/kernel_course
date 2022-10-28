#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");
char *text = "text\0";
module_param(text,charp,S_IWUSR | S_IRUSR);
extern int kencrypt(char *text,int len);

static int skload(void) {
    int rc = -1;
    printk(KERN_INFO "%s\n: using myencryption is loaded\ntext: %s %d\n",__func__,text,strlen(text));
    rc = kencrypt(text,strlen(text));
    printk(KERN_INFO "%s\n: using myencryption encrypted text: \"%s\" with status: %d\n",__func__,text,rc);

    return 0;
}

static void skteardown(void) {
    printk(KERN_INFO "%s\n: using myencryption is exiting\n",__func__);

}





module_init(skload);
module_exit(skteardown);