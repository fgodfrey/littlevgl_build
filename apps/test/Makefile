TOPDIR?=../..
include $(TOPDIR)/build-support/globals.mk

SUBDIRS=
PROGS=test
OBJS=test_main.o
LIBS += -lvdrivers -lvgl

all: headers build install

build: $(PROGS)

install:
	install -m 755 -d $(INSTALLROOT)/bin
	for p in $(PROGS) ; do                          \
		install -m 555 $$p $(INSTALLROOT)/bin ; \
	done

headers: ;

clean:
	rm -f $(PROGS) *.o

test: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

include $(TOPDIR)/build-support/base-rules.mk
