/*
 * =====================================================================================
 *
 *       Filename:  sysfs.c
 *
 *    Description:  code reuse!
 *
 *        Version:  1.0
 *        Created:  13/12/14 21:58:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Olivia Theze (foxiepaws), fox@foxiepa.ws
 *
 * =====================================================================================
 */

#include "sysfs.h"

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  write_powerstate
 *  Description:  write to /sys/power/state
 * =====================================================================================
 */
void
write_powerstate ( char* state ) {
    /* sysfs */
    FILE* powerstate = fopen("/sys/power/state", "w");
    /* check if file was opened correctly */
    if (powerstate == NULL && errno == EACCES) {
        fprintf(stderr, "Encountered EACCES on /sys/power/state. check permissions\n");
        exit(EXIT_FAILURE);
    }
    int wb = fprintf(powerstate, "%s\n", state);
    /* check we wrote as well */
    if (wb < 0) {
        fclose(powerstate);
        fprintf (stderr, "Failed to write to /sys/power/state\n");
        exit(EXIT_FAILURE);
    }
    fclose(powerstate);
}		/* -----  end of function write_powerstate  ----- */
 
