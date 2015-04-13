
CC ?= gcc
SRCDIR ?= src
INCDIR += -I${SRCDIR}
OBJDIR ?= src
BINDIR ?= bin
INSTALLDIR ?= /usr/local/sbin

TARGET ?= sleeper

CFLAGS += -std=c99


UNAME=$(shell uname -s)
ifeq (${UNAME},FreeBSD) 
INCDIR += -I/sys/
endif 

SHELL=/bin/sh
SRC = $(wildcard ${SRCDIR}/*.c)
OBJ = ${SRC:${SRCDIR}/%.c=${OBJDIR}/%.o}


all: sleeper

${OBJ}: $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo CC $<
	${CC} -o $@ ${INCDIR} -c ${CFLAGS} ${DEFINES} $<

sleeper: ${OBJ}
	@echo CC -o ${BINDIR}/${TARGET}
	@mkdir -p ${BINDIR}
	${CC} -I${INCDIR} -o ${BINDIR}/${TARGET} ${OBJ} ${LDFLAGS} ${CFLAGS} ${DEFINES}

clean:
	@echo cleaning
	@rm -f syswriter ${OBJ}

remove: clean
	@echo deleting binary
	@rm -f ${BINDIR}/${TARGET}
	@rm -r ${BINDIR}

install: sleeper
	mkdir -p ${INSTALLDIR} 
	cp ${BINDIR}/${TARGET} ${INSTALLDIR}/${TARGET}
	chmod 4555 ${INSTALLDIR}/${TARGET}

