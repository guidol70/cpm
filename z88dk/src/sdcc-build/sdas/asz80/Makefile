#
#
#

VERSION         = 4.2.0
VERSIONHI       = 4
VERSIONLO       = 2
VERSIONP        = 0

SHELL           = /bin/sh
CC              = gcc
CPP             = gcc -E
INSTALL         = ../../install
STRIP           = strip
MAKEDEP         = g++ -std=gnu++11 -MM

top_builddir    = ../..
top_srcdir      = ../..

srcdir          = .
prefix          = /usr/local
exec_prefix     = ${prefix}
bindir          = ${exec_prefix}/bin
libdir          = ${exec_prefix}/lib
datadir         = ${datarootdir}
datarootdir     = ${prefix}/share
includedir      = ${prefix}/include
mandir          = ${datarootdir}/man
man1dir         = $(mandir)/man1
man2dir         = $(mandir)/man2
infodir         = @info@

EXEEXT          = 



CPPFLAGS        =  -DSDCDB -DNOICE -DINDEXLIB -I. -I$(srcdir) -I$(srcdir)/../asxxsrc -I$(srcdir)/../../support/util
CFLAGS          =  -pipe -ggdb -g -O2 -Wall -Wno-parentheses $(CPPFLAGS)
LDFLAGS         = 
LIBS            = -lm

OBJDIR = obj

UTILLIB = $(srcdir)/../../support/util
UTILSRC = dbuf.c dbuf_string.c
UTILLIBOBJS = $(UTILSRC:%.c=$(OBJDIR)/%.o)

ASXXLIB = $(srcdir)/../asxxsrc
ASXXLIBSRC = asdbg.c asdata.c asexpr.c aslex.c aslist.c asmain.c asout.c assubr.c assym.c asmcro.c sdas.c strcmpi.c
ASXXLIBOBJS = $(ASXXLIBSRC:%.c=$(OBJDIR)/%.o)

SRC = z80pst.c z80mch.c z80adr.c
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

ASSOURCES = $(SRC) $(ASXXLIBSRC:%.c=$(ASXXLIB)/%.c) $(UTILSRC:%.c=$(UTILLIB)/%.c)

ASOBJECTS = $(OBJS) $(ASXXLIBOBJS) $(UTILLIBOBJS)

ASX = $(top_builddir)/bin/sdasz80$(EXEEXT)
#DEST = $(DESTDIR)$(bindir)/sdasz80$(EXEEXT)
DEST = sdasz80
DESTPATH = $(DESTDIR)$(bindir)/

transform       = s,x,x,

# Compiling entire program or any subproject
# ------------------------------------------
all: checkconf $(ASX)

$(ASX): $(ASOBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(ASOBJECTS) $(LIBS)

# Compiling and installing everything and running test
# ----------------------------------------------------
install: all installdirs
	$(INSTALL) $(ASX) $(DESTPATH)`echo $(DEST)|sed '$(transform)'`$(EXEEXT)
	$(STRIP) $(DESTPATH)`echo $(DEST)|sed '$(transform)'`$(EXEEXT)

# Deleting all the installed files
# --------------------------------
uninstall:
	rm -f $(DESTPATH)`echo $(DEST)|sed '$(transform)'`$(EXEEXT)


# Performing self-test
# --------------------
check:


# Performing installation test
# ----------------------------
installcheck:


# Creating installation directories
# ---------------------------------
installdirs:
	$(INSTALL) -d $(DESTDIR)$(bindir)


# Creating dependencies
# ---------------------
dep: Makefile.dep

Makefile.dep: $(ASSOURCES) $(srcdir)/*.h
	$(MAKEDEP) $(CPPFLAGS) $(filter %.c,$^) >Makefile.dep

ifeq "$(findstring $(MAKECMDGOALS),uninstall check installcheck installdirs \
                                   clean distclean mostlyclean realclean)" ""
  -include Makefile.dep
endif
include $(srcdir)/clean.mk

# My rules
# --------
$(OBJDIR)/.stamp:
	mkdir -p $(OBJDIR)
	touch $(OBJDIR)/.stamp

$(OBJDIR)/%.o: %.c $(OBJDIR)/.stamp
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/%.o: $(ASXXLIB)/%.c $(OBJDIR)/.stamp
	$(CC) -c $(CFLAGS) -o $@ $<

$(OBJDIR)/%.o: $(UTILLIB)/%.c $(OBJDIR)/.stamp
	$(CC) -c $(CFLAGS) -o $@ $<


# Remaking configuration
# ----------------------
checkconf:
	@if [ -f $(top_builddir)/devel ]; then\
          $(MAKE) -f ../conf.mk srcdir="$(srcdir)" top_builddir="$(top_builddir)" freshconf;\
        fi

# End of Makefile
