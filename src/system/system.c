/* 
 * system/system.c
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#include <syssy.h>

/**
 * Creates a new system descriptor.
 * @return A pointer to a system descriptor.
 */
system_t *system_create(const memctl_t *memctl, const devctl_t *devctl)
{
    system_t *system;
    
    if (!memctl || !devctl) {
        err("invalid arguments passed to system_create\n");
        return NULL;
    }
    
    system = syssy_alloc(sizeof(*system), NONE);
    if (!system) {
        err("unable to allocate memory for system descriptor\n");
        return NULL;
    }
    
    system->memctl = memctl;
    system->devctl = devctl;
    
    return system;
}

/**
 * Destroys an existing system descriptor.
 * @param sys A pointer to a system descriptor.
 */
void system_destroy(system_t *sys)
{
    syssy_free(sys);
}

/**
 * Runs the simulation.
 * @param sys A pointer to a system descriptor.
 */
int system_run_simulation(system_t *sys)
{
    int rc;
    
    /* Run subsystem initialisation routines.  This order is well-defined. */
    rc = sys->memctl->init(sys);
    if (rc)
        return rc;
    
    rc = sys->devctl->init(sys);
    if (rc)
        return rc;
    
    /* TODO: Implement the rest of this function. */
    info("todo: implement system_run_simulation\n");
    return rc;
}
