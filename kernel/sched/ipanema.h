#ifndef IPANEMA_H
#define IPANEMA_H

#include "sched.h"
#include <linux/ipanema.h>
#include <linux/latencytop.h>
#include <linux/sched.h>
#include <linux/cpumask.h>
#include <linux/cpuidle.h>
#include <linux/profile.h>
#include <linux/interrupt.h>
#include <linux/mempolicy.h>
#include <linux/migrate.h>
#include <linux/task_work.h>
#include <linux/proc_fs.h>
#include <linux/sort.h>

struct rq_flags;

extern struct list_head ipanema_modules;
extern struct list_head ipanema_policies;

int ipanema_set_policy(char *policies_str);
// void ipanema_core_entry(struct ipanema_policy *policy, unsigned int core);
// void ipanema_core_exit(struct ipanema_policy *policy, unsigned int core);
// enum ipanema_core_state ipanema_get_core_state(struct ipanema_policy *policy,
// 					       unsigned int core);
// int ipanema_new_prepare(struct process_event *e);
// void ipanema_new_place(struct process_event *e);
// void ipanema_new_end(struct process_event *e);
// void ipanema_tick(struct process_event *e);
// void ipanema_yield(struct process_event *e);
// void ipanema_block(struct process_event *e);
// int ipanema_unblock_prepare(struct process_event *e);
// void ipanema_unblock_place(struct process_event *e);
// void ipanema_unblock_end(struct process_event *e);
// void ipanema_terminate(struct process_event *e);
// void ipanema_schedule(struct ipanema_policy *policy, unsigned int core);
// void ipanema_newly_idle(struct ipanema_policy *policy, unsigned int core,
// 			struct rq_flags *rf);
// void ipanema_enter_idle(struct ipanema_policy *policy, unsigned int core);
// void ipanema_exit_idle(struct ipanema_policy *policy, unsigned int core);
// void ipanema_balancing_select(void);
// void ipanema_init(void);


extern rwlock_t ipanema_rwlock;

/* Variables exposed by the sysfs interface */
extern int ipanema_fsm_check;
extern int ipanema_fsm_log;
extern int ipanema_sched_class_log;

#ifdef CONFIG_CGROUP_IPANEMA
struct ipanema_group {
	struct cgroup_subsys_state css;

	struct ipanema_policy *policy;
};

#define ipanema_group_of(css) (container_of(css, struct ipanema_group, css))
#endif	/* CONFIG_CGROUP_IPANEMA */

#endif	/* IPANEMA_H */
