# Port specification for compiling on the host machines compiler

# runtimeout in seconds
RUN_TIMEOUT = 1

SDCC = gcc
SDCCFLAGS =  -pipe -ggdb -g -O2 --std=c99 $(CPPFLAGS) -DPORT_HOST=1 -DREENTRANT= -I$(top_builddir) -I$(top_srcdir)
SDLDFLAGS = 
# disable all warnings:
SDCCFLAGS+= -w
# enable all warnings:
#SDCCFLAGS+= -Wall -Wno-parentheses

BINEXT = .bin
OBJEXT = .o
INC_DIR = .

# otherwise `make` deletes testfwk.o and `make -j` will fail
.PRECIOUS: $(PORT_CASES_DIR)/%$(OBJEXT)

# Required extras
EXTRAS = $(PORT_CASES_DIR)/testfwk$(OBJEXT) $(PORT_CASES_DIR)/support$(OBJEXT)
include $(srcdir)/fwk/lib/spec.mk

%.out: %$(BINEXT) $(CASES_DIR)/timeout
	mkdir -p $(dir $@)
	-$(CASES_DIR)/timeout $(RUN_TIMEOUT) $< > $@
	-grep -n FAIL $@ /dev/null || true

%$(BINEXT): %$(OBJEXT) $(EXTRAS) $(FWKLIB)
	$(SDCC) $(SDCCFLAGS) $(SDLDFLAGS) -o $@ $< $(EXTRAS) $(FWKLIB) -lm

%$(OBJEXT): %.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

$(PORT_CASES_DIR)/%$(OBJEXT): $(PORTS_DIR)/$(PORT)/%.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

$(PORT_CASES_DIR)/%$(OBJEXT): $(srcdir)/fwk/lib/%.c
	$(SDCC) $(SDCCFLAGS) -c $< -o $@

_clean:
