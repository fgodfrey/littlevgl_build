TOPDIR ?= ..

include $(TOPDIR)/build-support/globals.mk

SUBDIRS=lvgl lv_drivers
INSTDIR=$(INSTALLROOT)/include

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
	for file in *.h ; do 				\
		$(INSTALL) -m 444 $$file $(INSTDIR) ;	\
	done

clean:
	for DIR in $(SUBDIRS) ; do	 			\
		$(MAKE) -C $$DIR clean TOPDIR=$(TOPDIR)/.. ;	\
	done

include $(TOPDIR)/build-support/base-rules.mk
