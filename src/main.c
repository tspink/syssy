/* 
 * main.c
 * 
 * Copyright (C) University of Edinburgh 2013
 * Tom Spink <t.spink@sms.ed.ac.uk>
 */
#include <stdio.h>
#include <syssy.h>

/**
 * Application entry-point.
 * @param argc The number of arguments present in the argv array.
 * @param argv Pointers to strings representing the command-line arguments
 * to the program.
 * @return An exit code.
 */
int main(int argc, char** argv)
{
    system_t *sys;
    
    sys = system_create();
    if (!sys) {
        printf("error: unable to create system descriptor\n");
        return -1;
    }
    
    system_destroy(sys);
    return 0;
}
