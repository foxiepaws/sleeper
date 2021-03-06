/*
 * =====================================================================================
 *
 *       Filename:  sysfs.h
 *
 *    Description:  Header file for sysfs.c
 *
 *        Version:  1.0
 *        Created:  13/12/14 22:06:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Allie Theze (foxiepaws), fox@foxiepa.ws
 *
 * =====================================================================================
 */

#if defined(__linux__) && defined(sysfs)
#include "generic.h"

void write_powerstate (char*);
#endif

