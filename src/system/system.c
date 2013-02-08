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
system_t *system_create()
{
    return NULL;
}

/**
 * Destroys an existing system descriptor.
 * @param sys A pointer to a system descriptor.
 */
void system_destroy(system_t *sys)
{
    syssy_free(sys);
}
