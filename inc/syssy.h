/* 
 * syssy.h
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#ifndef SYSSY_H
#define	SYSSY_H

#include <stdio.h>

#ifdef DEBUG
# define dbg(a...) fprintf(stderr, "debug: " a)
#else
# define dbg(a...)
#endif

#define info(a...) fprintf(stderr, "info: " a)
#define warn(a...) fprintf(stderr, "warning: " a)
#define err(a...) fprintf(stderr, "error: " a)

#include <stddef.h>

typedef unsigned long sys_addr;
typedef unsigned long long sys_data;

typedef int (*memio_callback_t)(int operation, sys_addr addr, sys_data *data);

struct _system;
typedef struct {
    int (*init)(struct _system *system);
    int (*write)(struct _system *system, sys_addr addr, sys_data data, unsigned int size);
    int (*read)(struct _system *system, sys_addr addr, sys_data *data, unsigned int size);
    int (*install_handler)(struct _system *system, sys_addr base, sys_addr size, memio_callback_t callback);
} memctl_t;

extern const memctl_t default_mcu;

typedef struct {
    int (*init)(struct _system *system);
} devctl_t;

extern const devctl_t default_dcu;

typedef struct _system {
    const memctl_t *memctl;
    void *memctl_priv;
    
    const devctl_t *devctl;
    void *devctl_priv;
} system_t;

extern system_t *system_create(const memctl_t *memctl, const devctl_t *devctl);
extern void system_destroy(system_t *sys);
extern int system_run_simulation(system_t *sys);

typedef enum {
    NONE,
    ZEROMEM,
} syssy_alloc_flags_t;

extern void *syssy_alloc(unsigned int size, syssy_alloc_flags_t flags);
extern void syssy_free(void *ptr);

#endif	/* SYSSY_H */

