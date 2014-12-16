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
        printf("%s%s",
               "Sleep on FreeBSD is considered an \033[1mEXPERIMENTAL\033[0m feature\n"
               "Are you sure you want to continue? [y/N] ");
        scanf("%1[ynYN\n]", str);
    } else {
        str = "y";
    }
     
    if (str == 'y' || str == 'Y') { 
        power_pm_suspend(POWER_SLEEP_STATE_SUSPEND); /* I beleive this is the same as 
                                                        sleep, vs standby which has the 
                                                        CPU in a low power state instead
                                                        of losing CPU context. 
                                                      */
    } else {
        printf ("Nevermind\n");
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
    /* write memory suspend trigger code */
    char str;
    if (force < 1) {
        printf("%s%s",
               "Hibernate on FreeBSD is considered an \033[1mEXPERIMENTAL\033[0m feature\n"
               "Are you sure you want to continue? [y/N] ");
        scanf("%1[ynYN\n]", str);
    } else {
        str = "y";
    }
     
    if (str == 'y' || str == 'Y') { 
        power_pm_suspend(POWER_SLEEP_STATE_HIBERNATE); /* I beleive this is the same as 
                                                        sleep, vs standby which has the 
                                                        CPU in a low power state instead
                                                        of losing CPU context. 
                                                      */
    } else {
        printf ("Nevermind\n");
        exit (1);
    }
#elif defined (__linux__)
    #if defined(sysfs)
    write_powerstate("disk");
    #elif defined(systemd)
    /* systemd sleep activation via dbus/logind */
    #endif
#endif
}
/* -----  end of function sw_hiber  ----- */

