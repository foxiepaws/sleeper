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
sw_sleep (int force) {
#if defined(__FreeBSD__)
    /* write memory suspend trigger code */
    char str;
    if (force < 1) {
        printf("Sleep on FreeBSD is considered an \033[1mEXPERIMENTAL\033[0m feature\n"
               "Are you sure you want to continue? [y/N] ");
        scanf("%1c", &str);
    } else {
        str = 'y';
    }
     
    if (str == 'y' || str == 'Y') { 
        write_powerstate("mem");
    } else {
        fprintf (stderr,"Nevermind\n");
        exit (1);
    }
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
sw_hiber (int force) {
#if defined(__FreeBSD__)
       fprintf (stderr,"FreeBSD does not have a memory image loader for hibernate, exiting.\n");
       exit (1);
#elif defined (__linux__)
    #if defined(sysfs)
    write_powerstate("disk");
    #elif defined(systemd)
    /* systemd sleep activation via dbus/logind */
    #endif
#endif
}
/* -----  end of function sw_hiber  ----- */

