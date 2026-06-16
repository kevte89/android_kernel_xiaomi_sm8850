/* SPDX-License-Identifier: GPL-2.0 */
/* Stub for Xiaomi mca_sysfs - no-ops since real mca driver is not present.
 *
 * Note: The field naming is intentionally Xiaomi-original. `sysfs_attr_name`
 * actually holds an integer prop ID, while `name` is the visible sysfs node
 * label that mca_sysfs_lookup_attr searches by.
 */
#ifndef _LINUX_MCA_COMMON_MCA_SYSFS_H_
#define _LINUX_MCA_COMMON_MCA_SYSFS_H_

#include <linux/types.h>
#include <linux/sysfs.h>
#include <linux/string.h>

/* Stub device IDs */
#define SYSFS_DEV_3 3

/* Field layout matches Xiaomi's expected struct */
struct mca_sysfs_attr_info {
    const char *name;          /* sysfs filename ("super_speed", etc) */
    int sysfs_attr_name;       /* prop ID enum (DWC3_MSM_PROP_*) */
    umode_t mode;
};

/* Macro layout: (prefix, mode, prop_id, attr_name)
 * Stores name as the string and sysfs_attr_name as the prop ID.
 */
#define mca_sysfs_attr_ro(prefix, mode_, prop_, name_) { #name_, prop_, mode_ }
#define mca_sysfs_attr_rw(prefix, mode_, prop_, name_) { #name_, prop_, mode_ }

/* Stub functions - real impl would create actual sysfs entries */
static inline struct mca_sysfs_attr_info *
mca_sysfs_lookup_attr(const char *name,
                      struct mca_sysfs_attr_info *tbl,
                      int tbl_size)
{
    int i;
    if (!name || !tbl)
        return NULL;
    for (i = 0; i < tbl_size; i++) {
        if (tbl[i].name && strcmp(tbl[i].name, name) == 0)
            return &tbl[i];
    }
    return NULL;
}

static inline int
mca_sysfs_create_files(int dev_id,
                       struct mca_sysfs_attr_info *tbl,
                       int tbl_size)
{
    return 0;  /* No actual sysfs files created */
}

#endif /* _LINUX_MCA_COMMON_MCA_SYSFS_H_ */
