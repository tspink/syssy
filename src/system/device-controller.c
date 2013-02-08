/* 
 * system/device-controller.c
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#include <syssy.h>

struct dcu {
    int tag;
};

static int dcu_init(system_t *sys)
{
    struct dcu *dcu;
    
    dcu = syssy_alloc(sizeof(*dcu), NONE);
    if (!dcu) {
        err("unable to allocate memory for dcu private structure\n");
        return -1;
    }
    
    sys->devctl_priv = dcu;
    return 0;
}

const devctl_t default_dcu = {
    .init = dcu_init
};
