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
    
    system = syssy_alloc(sizeof(*system), NONE);
    if (!system)
        return NULL;
    
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
    /* Run subsystem initialisation routines.  This order is well-defined. */
    sys->memctl->init(sys);
    sys->devctl->init(sys);
    
    /* TODO: Implement the rest of this function. */
    return -1;
}
