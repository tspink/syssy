/* 
 * system/memory-controller.c
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#include <syssy.h>

struct mcu {
    int tag;
};

static int mcu_init(system_t *sys)
{
    sys->memctl_priv = syssy_alloc(sizeof(struct mcu), NONE);
    if (!sys->memctl_priv)
        return -1;
    return 0;
}

static int mcu_write(system_t *sys, sys_addr addr, sys_data data, unsigned int size)
{
    return -1;
}

static int mcu_read(system_t *sys, sys_addr addr, sys_data *data, unsigned int size)
{
    return -1;
}

static int mcu_install_handler(system_t *sys, sys_addr base, sys_addr length, memio_callback_t callback)
{
    return -1;
}

const memctl_t default_mcu = {
    .init = mcu_init,
    .write = mcu_write,
    .read = mcu_read,
    .install_handler = mcu_install_handler,
};
