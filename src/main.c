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
#include "sleep.h"
#include "hibernate.h"
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
            case 's':
                if (fgs & 1) {
                    goto fail;
                }
                fgs += 1;
                break;
                ;;
            case 'H':
                if (fgs & 2) {
                    goto fail;
                }
                fgs += 2;
                break;
                ;;
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
    	printf("attempting to sleep\n");
        sw_sleep();
	printf("Welcome Back =)\n");
    }
    if (fgs == 2) {
    	printf("attempting to hibernate\n");
        sw_hiber();
	printf("Welcome Back =)\n");
    }

    return EXIT_SUCCESS;
fail:
    fprintf(stderr,
            "Usage: %s [-s|-H]\n",
            argv[0]);
    return EXIT_FAILURE;
}
/* ----------  end of function main  ---------- */
