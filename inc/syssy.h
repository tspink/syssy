/* 
 * syssy.h
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#ifndef SYSSY_H
#define	SYSSY_H

#include <stddef.h>

typedef struct {
    int tag;
} system_t;

extern system_t *system_create(void);
extern void system_destroy(system_t *sys);
extern int system_run_simulation(system_t *sys);

typedef enum {
    NONE,
} syssy_alloc_flags_t;

extern void *syssy_alloc(unsigned int size, syssy_alloc_flags_t flags);
extern void syssy_free(void *ptr);

#endif	/* SYSSY_H */

