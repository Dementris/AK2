
/*
 * Copyright (c) 2017, GlobalLogic Ukraine LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgment:
 *    This product includes software developed by the GlobalLogic.
 * 4. Neither the name of the GlobalLogic nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GLOBALLOGIC UKRAINE LLC ``AS IS`` AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL GLOBALLOGIC UKRAINE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/slab.h>
#include "hello1.h"

MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static unsigned int repeate_count = 1;

module_param(repeate_count, uint, 0444);
MODULE_PARM_DESC(repeate_count, "Number of times to print 'Hello, world' ");

static int __init hello2_init(void)
{
	int i;

	if (repeate_count == 0 || (repeate_count >= 5 && repeate_count <= 10)) {
		printk(KERN_WARNING "WARNING: Invalid value for repeat_count\n");
		repeate_count = 1;
	} else if (repeate_count > 10) {
		printk(KERN_ERR "ERROR: Invalid value for repeat_count, cannot load the module\n");
		return -EINVAL;
	}

	for (i = 0; i < repeate_count; i++) {
        print_hello();
    }

	return 0;
}

static void __exit hello2_exit(void)
{
	pr_info("Hello2 module unloaded\n");
}

module_init(hello2_init);
module_exit(hello2_exit);
