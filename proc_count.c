#include <linux/module.h>
#include <linux/printk.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/seq_file.h>

#define for_each_process(p) for (p = &init_task ; (p = next_task(p)) != &init_task ; )

static struct proc_dir_entry *entry;

static int proc_count(struct seq_file *m, void *v)
{
	// TODO: it's all yours
    struct task_struct *task;
	int count = 0;

	// Traverse the task list
	for_each_process(task)
	{
		count++; // Increment count for each process found
	}

	return count;
	return 0;
}

static int __init proc_count_init(void)
{
	entry = proc_create_single("count", 0, NULL, proc_count);
	pr_info("proc_count: init\n");
	return 0;
}

static void __exit proc_count_exit(void)
{
	proc_remove(entry);
	pr_info("proc_count: exit\n");
}

module_init(proc_count_init);
module_exit(proc_count_exit);

MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("CS111 lab0 count proc number");
MODULE_LICENSE("GPL");
