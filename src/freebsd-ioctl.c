/*
 * =====================================================================================
 *
 *       Filename:  freebsd-ioctl.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16/12/14 21:07:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Allie Theze (foxiepaws), fox@foxiepa.ws
 *   Organization:  
 *
 * =====================================================================================
 */


/* code is based off of acpiconf. */
#if defined(__FreeBSD__)
#include "freebsd-ioctl.h"


void write_powerstate(char* state) {
    int sleeptype;
    if (strcmp(state,"mem") == 0) {
        sleeptype = 3;
    } else {
        fprintf(stderr,"Invalid sleep mode: %s\n", state);
        exit(1);
    }
    int acpifd;
    acpifd = open (ACPIDEV, O_RDWR);
    if (acpifd == -1) {
        acpifd = open(ACPIDEV, O_RDONLY);
    }
    if (acpifd == -1) {
        fprintf ( stderr, "failed to open" ACPIDEV "\n" );
    }

    if (ioctl(acpifd, ACPIIO_REQSLPSTATE, &sleeptype) != 0) {
        fprintf(stderr, "Failed to request sleep type %d\n", sleeptype);
    }
}
#endif
