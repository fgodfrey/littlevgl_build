#
# Top Level Makfile:  Build Targets
#
# build:  Compiles all non-3rd party code, but doesn't install it.  Assumes
#	  3rd party code and headers are already built and installed.
#
# install:  Installs all non-3rd party targets.  Assumes "build" and "headers"
#           have already been run.
#
# libconfig:  Build and install 3rd party library "libconfig".
#
# all:  Build all targets
#

# Top level of workarea.  Can also be an absolute path
TOPDIR=.

# Global defines for all Makefiles.  All Makefiles should include this
include $(TOPDIR)/build-support/globals.mk

SUBDIRS=littlevgl apps

build:
	install -m 755 -d $(INSTALLROOT)/bin
	install -m 755 -d $(INSTALLROOT)/include
	install -m 755 -d $(INSTALLROOT)/lib
	for DIR in $(SUBDIRS) ; do 			\
		$(MAKE) -C $$DIR build TOPDIR=$(TOPDIR)/.. ;		\
	done

all: libconfig headers build install

install:
	for DIR in $(SUBDIRS) ; do 			\
		$(MAKE) -C $$DIR install TOPDIR=$(TOPDIR)/.. ;		\
	done

headers:
	for DIR in $(SUBDIRS) ; do	 			\
		$(MAKE) -C $$DIR headers TOPDIR=$(TOPDIR)/.. ;	\
	done

clean:
	for DIR in $(SUBDIRS) ; do	 			\
		$(MAKE) -C $$DIR clean TOPDIR=$(TOPDIR)/.. ;	\
	done

# All Makefiles should include this.  Provides basic build rules
include $(TOPDIR)/build-support/base-rules.mk
