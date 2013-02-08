/* 
 * syssy.h
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#ifndef SYSSY_H
#define	SYSSY_H

#include <stddef.h>

struct _system;
typedef struct {
    int (*init)(struct _system *system);
    int (*write)(unsigned long addr, unsigned long long data, unsigned int size);
    int (*read)(unsigned long addr, unsigned long long *data, unsigned int size);
} memctl_t;

typedef struct {
    int (*init)(struct _system *system);
} devctl_t;

typedef struct _system {
    memctl_t *memctl;
    devctl_t *devctl;
} system_t;

extern system_t *system_create(memctl_t *memctl, devctl_t *devctl);
extern void system_destroy(system_t *sys);
extern int system_run_simulation(system_t *sys);

typedef enum {
    NONE,
    ZEROMEM,
} syssy_alloc_flags_t;

extern void *syssy_alloc(unsigned int size, syssy_alloc_flags_t flags);
extern void syssy_free(void *ptr);

#endif	/* SYSSY_H */

