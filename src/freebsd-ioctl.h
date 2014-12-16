/*
 * =====================================================================================
 *
 *       Filename:  freebsd-ioctl.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16/12/14 21:23:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Olivia Theze (foxiepaws), fox@foxiepa.ws
 *   Organization:  
 *
 * =====================================================================================
 */
#if defined(__FreeBSD__)
#include "generic.h"
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <dev/acpica/acpiio.h>
#include <contrib/dev/acpica/include/acpi.h>

#define ACPIDEV "/dev/acpi" 

void write_powerstate (char*);
#endif
