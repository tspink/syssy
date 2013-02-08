/* 
 * system/memory-controller.c
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#include <syssy.h>
#include <sys/mman.h>

struct mcu {
    void *vmem;
    unsigned long size;
};

static inline struct mcu *get_mcu(system_t *sys)
{
    return (struct mcu *)sys->memctl_priv;
}

static int mcu_init(system_t *sys)
{
    struct mcu *mcu;
    mcu = syssy_alloc(sizeof(struct mcu), NONE);
    if (!mcu)
        return -1;
    
    mcu->size = 0xFFFFFFFF;
    mcu->vmem = mmap(NULL, mcu->size, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    if (!mcu->vmem) {
        syssy_free(mcu);
        return -1;
    }
    
    sys->memctl_priv = mcu;
    return 0;
}

static int mcu_write(system_t *sys, sys_addr addr, sys_data data, unsigned int size)
{
    struct mcu *mcu = get_mcu(sys);
    return -1;
}

static int mcu_read(system_t *sys, sys_addr addr, sys_data *data, unsigned int size)
{
    struct mcu *mcu = get_mcu(sys);
    return -1;
}

static int mcu_install_handler(system_t *sys, sys_addr base, sys_addr length, memio_callback_t callback)
{
    struct mcu *mcu = get_mcu(sys);
    return -1;
}

const memctl_t default_mcu = {
    .init = mcu_init,
    .write = mcu_write,
    .read = mcu_read,
    .install_handler = mcu_install_handler,
};
