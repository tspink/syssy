/* 
 * system/alloc.c
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#include <syssy.h>
#include <malloc.h>

/**
 * Allocates memory on the heap.
 * @param size The amount of memory to allocate.
 * @param flags Flags governing the way the memory is created.
 * @return A pointer to newly allocated memory, or zero if allocation failed.
 */
void *syssy_alloc(unsigned int size, syssy_alloc_flags_t flags)
{
    return malloc(size);
}

/**
 * Frees previously allocated memory.
 * @param ptr The pointer to the memory to be freed.
 */
void syssy_free(void *ptr)
{
    free(ptr);
}