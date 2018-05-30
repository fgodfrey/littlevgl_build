# Base rules for Makefiles

%.o:  %.c
	$(CC) -c $(CFLAGS) $<

# Phony targets for common rules
.PHONY: all build install headers clean
