/*
 * =====================================================================================
 *
 *       Filename:  hibernate.c
 *
 *    Description:  hibernates a laptop
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

#include "hibernate.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sw_hiber
 *  Description:  
 * =====================================================================================
 */
void
sw_hiber () {
#ifdef __FreeBSD__
    /* write disk suspend trigger code */
#endif
#ifdef __linux__
    #ifdef usesysfs
    /* sysfs */
    FILE * powerstate = fopen("/sys/power/state", "w");
    fprintf(powerstate, "disk\n");
    fclose (powerstate);
    #endif
#endif
}
/* -----  end of function sw_hiber  ----- */
 
