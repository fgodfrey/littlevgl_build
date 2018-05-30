TOPDIR ?= ..

include $(TOPDIR)/build-support/globals.mk

SUBDIRS=test sysmon

build:
	for DIR in $(SUBDIRS) ; do 			\
		$(MAKE) -C $$DIR build TOPDIR=$(TOPDIR)/.. ;		\
	done

all: headers build install

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

include $(TOPDIR)/build-support/base-rules.mk
