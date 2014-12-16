/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  sleep and hibernate.
 *
 *        Version:  1.0
 *        Created:  12/13/14 16:26:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Olivia Theze (foxiepaws), fox@foxiepa.ws
 *
 * =====================================================================================
 */


#include "generic.h"
#include "powermgmt.h"
#include <getopt.h>

/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int
main ( int argc, char *argv[] )
{
    if (argc < 2) goto fail;
    unsigned int fgs = 0;
    int o;
    while ((o = getopt(argc,argv,"sH")) != -1) {
        switch (o) {
            case 's': /* sleep */
                if (fgs & 1) {
                    goto fail;
                }
                fgs += 1;
                break;
                ;;
            case 'H': /* hibernate */
                if (fgs & 2) {
                    goto fail;
                }
                fgs += 2;
                break;
                ;;
            case 'f': /* force */
                if (fgs & 4) {
                    goto fail;
                }
                fgs += 4;
                break;
            default:
                goto fail;
                ;;
        }
    }
    if (fgs == 3) {
        /* both flags are set, failure */
        goto fail;
    }
    if (fgs == 1) {
        if (fgs & 4) {
            sw_sleep(1);
        } else {
    	    printf("attempting to sleep\n");
            sw_sleep(0);
	        printf("Welcome Back =)\n");
        }
    }
    if (fgs == 2) {
        if (fgs & 4) {
            sw_hiber(1);
        } else {
    	    printf("attempting to hibernate\n");
            sw_hiber(0);
	        printf("Welcome Back =)\n");
        }
	printf("Welcome Back =)\n");
    }

    return EXIT_SUCCESS;
fail:
    fprintf(stderr,
            "USAGE: %s [-f] [-s|-H]\n",
            argv[0]);
    return EXIT_FAILURE;
}
/* ----------  end of function main  ---------- */
