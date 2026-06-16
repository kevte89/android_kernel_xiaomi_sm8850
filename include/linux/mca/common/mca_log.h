/* SPDX-License-Identifier: GPL-2.0 */
/* Stub for Xiaomi mca_log */
#ifndef _LINUX_MCA_COMMON_MCA_LOG_H_
#define _LINUX_MCA_COMMON_MCA_LOG_H_

#include <linux/types.h>
#include <linux/printk.h>

/* mca log levels - alias to standard kernel log levels */
#define MCA_LOG_ERR     KERN_ERR
#define MCA_LOG_WARN    KERN_WARNING
#define MCA_LOG_INFO    KERN_INFO
#define MCA_LOG_DBG     KERN_DEBUG

/* Stub log macro - falls back to printk */
#define mca_log(level, fmt, ...) printk(level fmt, ##__VA_ARGS__)
#define mca_log_err(fmt, ...)    printk(KERN_ERR fmt, ##__VA_ARGS__)
#define mca_log_warn(fmt, ...)   printk(KERN_WARNING fmt, ##__VA_ARGS__)
#define mca_log_info(fmt, ...)   printk(KERN_INFO fmt, ##__VA_ARGS__)
#define mca_log_dbg(fmt, ...)    printk(KERN_DEBUG fmt, ##__VA_ARGS__)

#endif /* _LINUX_MCA_COMMON_MCA_LOG_H_ */
