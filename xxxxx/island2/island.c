#include <linux/module.h>
#include <linux/init.h>
#include <linux/version.h>
#include <linux/errno.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/vmalloc.h>
#include <linux/mman.h>
#include <linux/slab.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0)
#include <linux/wrapper.h>
#endif

#define ISLAND_MAJOR 240
#define ISLAND_NAME "island"

#define LEN (1*1024*1024) // 1MB max
unsigned long * membase, * physbase;

static int __init island_init_module (void) {
  printk("installing island\n");
  membase = kmalloc(LEN, GFP_KERNEL);
  //  memset(membase, 0, LEN);
  physbase = virt_to_phys(membase);
  //  printk("I got: %zu bytes of memory\n", ksize(membase));
  printk("membase=0x%lx\n", membase);
  printk("physbase=0x%lx\n", physbase);
  return 0;
}

static void __exit island_cleanup_module (void) {
	printk("removing island\n");
	kfree(membase);
	unregister_chrdev (ISLAND_MAJOR, ISLAND_NAME);
}

module_init(island_init_module);
module_exit(island_cleanup_module);
MODULE_AUTHOR("_____//http://1010.co.uk");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("island creation");
