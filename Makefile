
CC = gcc
DEFINES += -Dusesysfs
SRCDIR = src
INCDIR = ${SRCDIR}
OBJDIR = src
BINDIR = bin

TARGET = syswriter

SHELL=/bin/sh
SRC = $(wildcard ${SRCDIR}/*.c)
OBJ = ${SRC:${SRCDIR}/%.c=${OBJDIR}/%.o}


all: syswriter

${OBJ}: $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo CC $<
	@${CC} -o $@ -I${INCDIR} -c ${CFLAGS} $<

syswriter: ${OBJ}
	@echo CC -o ${BINDIR}/${TARGET}
	@mkdir -p ${BINDIR}
	@${CC} -I${INCDIR} -o ${BINDIR}/${TARGET} ${OBJ} ${LDFLAGS} ${CFLAGS} ${DEFINES}

clean:
	@echo cleaning
	@rm -f syswriter ${OBJ}

remove: clean
	@echo deleting binary
	@rm -f ${BINDIR}/${TARGET}
	@rm -r ${BINDIR}
