#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");

char *key = {255,255,255,255};
module_param(key,charp,S_IWUSR | S_IRUSR);

int kencrypt(char *text,int len) {
    int i=0;
    int keylen = strlen(key);

    if(len == 0 ) {
        return 1;
    } 
    printk(KERN_INFO "%s: text: %s\n",__func__,text);
    printk(KERN_INFO "%s: key: %s len: %d\n",__func__,key,keylen);

    for(i=0;i< len; ++i) {

       text[i] ^= key[i % keylen];
    } 
    printk(KERN_INFO "\n%s: text: \"%s\"\n",__func__,text);
    return 0;
}

EXPORT_SYMBOL(kencrypt);

static int kload(void) {
    printk(KERN_INFO "%s\n: myencryption is loaded\nkey: %s %d\n",__func__,key,strlen(key));
 
    
    return 0;
}

static void kteardown(void) {
    printk(KERN_INFO "%s\n: myencryption is exiting\n",__func__);

}





module_init(kload);
module_exit(kteardown);