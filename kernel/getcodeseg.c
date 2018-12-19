#include <linux/kernel.h>
#include <linux/syscalls.h>


SYSCALL_DEFINE1(getcodeseg, char __user *, codeseg)
{
        struct task_struct *task;

        printk(KERN_INFO "getcode syscall is called (pid = %d)\n", current->pid);
        task = find_task_by_vpid(current->pid);
        sprintf(codeseg, "%lx-%lx", task->mm->start_code, task->mm->end_code);

        return 0;
}
