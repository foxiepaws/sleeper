/*
 * =====================================================================================
 *
 *       Filename:  powermgmt.c
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


#include "powermgmt.h"

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
    /* use the sysfs code */
    write_powerstate("mem");
    #elif defined(systemd)
    /* systemd sleep activation via dbus/logind */

    #endif
#endif
}
/* -----  end of function sw_sleep  ----- */

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  sw_hiber
 *  Description:  triggers hibernation
 * =====================================================================================
 */

void
sw_hiber () {
#if defined(__FreeBSD__)
    /* write memory suspend trigger code */
#elif defined (__linux__)
    #if defined(sysfs)
    write_powerstate("disk");
    #elif defined(systemd)
    /* systemd sleep activation via dbus/logind */
    #endif
#endif
}
/* -----  end of function sw_hiber  ----- */

