# Global Make variables.  Should be included by all Makefiles

# Programs
CC ?= gcc
AR ?= ar
RANLIB ?= ranlib
INSTALL ?= install

# Pathnames
INSTALLROOT ?= /tmp/console_test

# Options
CFLAGS += -I$(INSTALLROOT)/include -Wall -Werror -O3
LDFLAGS += -L$(INSTALLROOT)/lib
AROPTS += -rvcs
