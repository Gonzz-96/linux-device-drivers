#define MODULE
#define LINUX
#define __KERNEL__

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Gonz Campos");

static u8              mybyte = 'A';   
static unsigned short myshort = 1;
static int              myint = 20;
static long            mylong = 9999;
static char*         mystring = "blah";
static int      myintArray[2] = { 0, 420 };

module_param(mybyte, "b");
module_param(myshort, "h");
module_param(myint, "i");
module_param(mylong, "l");
module_param(mystring, "s");
module_param(myintArray, "1-2i");

MODULE_PARM_DESC(mybyte, "This byte really does not exist");
MODULE_PARM_DESC(myshort, "This short is extremely important");

static int __init hello_5_init(void) {
    printk(KERN_ALERT "mybyte is an 8 bit integer: %i\n", mybyte);
    printk(KERN_ALERT "myshort is a short integer: %hi\n", myshort);
    printk(KERN_ALERT "myint is an itneger: %i\n", myint);
    printk(KERN_ALERT "mylong is a long integer: %i\n", mylong);
    printk(KERN_ALERT "myshort is a string: %s\n", mystring);
    printk(KERN_ALERT "myintArray is %i and %i\n", myintArray[0],\
                                                    myintArray[1]);
    return 0;
}

static void __exit hello_5_exit(void) {
    printk(KERN_ALERT "Goodbye, world 5\n");
}

module_init(hello_5_init);
module_exit(hello_5_exit);

