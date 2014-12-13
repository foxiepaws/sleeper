/*
 * =====================================================================================
 *
 *       Filename:  sleep.c
 *
 *    Description:  sleeps a laptop
 *
 *        Version:  1.0
 *        Created:  12/13/14 16:27:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Olivia Theze (foxiepaws), fox@foxiepa.ws
 *   Organization:  
 *
 * =====================================================================================
 */


#include "sleep.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sw_sleep
 *  Description:  
 * =====================================================================================
 */
void
sw_sleep () {
#ifdef __FreeBSD__
    /* write memory suspend trigger code */
#endif
#ifdef __linux__
    #ifdef usesysfs
    /* sysfs */
    FILE* powerstate = fopen("/sys/power/state", "w");
    fprintf(powerstate, "mem\n");
    #endif
#endif
}
/* -----  end of function sw_sleep  ----- */
 
