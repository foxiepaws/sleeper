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
 *
 * =====================================================================================
 */


#include "sleep.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  sw_sleep
 *  Description:  code to sleep computer
 * =====================================================================================
 */
void
sw_sleep () {
#if defined(__FreeBSD__)
    /* write memory suspend trigger code */
#elif defined (__linux__)
    #if defined(sysfs)
    /* sysfs */
    FILE* powerstate = fopen("/sys/power/state", "w");
    /* check if file was opened correctly */
    if (powerstate == NULL && errno == EACCES) {
        fprintf(stderr, "Encountered EACCES on /sys/power/state. check permissions\n");
        exit(EXIT_FAILURE);
    }
    int wb = fprintf(powerstate, "mem\n");
    /* check we wrote as well */
    if (wb < 0) {
        fclose(powerstate);
        fprintf (stderr, "Failed to write to /sys/power/state\n");
        exit(EXIT_FAILURE);
    }
    fclose(powerstate);
    #elif defined(systemd)
    /* systemd sleep activation via dbus/logind */

    #endif
#endif
}
/* -----  end of function sw_sleep  ----- */
