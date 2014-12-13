/*
 * =====================================================================================
 *
 *       Filename:  powermgmt.h
 *
 *    Description:  header file for powermgmt.c
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


#include "generic.h"

#if defined(sysfs)
    #include "sysfs.h"
#endif

void sw_sleep ();
void sw_hiber ();

 