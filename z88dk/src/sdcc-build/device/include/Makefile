#
#
#

VERSION         = 4.2.0
VERSIONHI       = 4
VERSIONLO       = 2
VERSIONP        = 0

SHELL           = /bin/sh
CPP             = gcc -E
INSTALL         = ../../install
CP              = cp

top_builddir    = ../..
top_srcdir      = ../..

prefix          = /usr/local
exec_prefix     = ${prefix}
bindir          = ${exec_prefix}/bin
libdir          = ${exec_prefix}/lib
datadir         = ${datarootdir}
datarootdir     = ${prefix}/share
includedir      = ${prefix}/include
inclibdir       = @inclibdir@
mandir          = ${datarootdir}/man
man1dir         = $(mandir)/man1
man2dir         = $(mandir)/man2
infodir         = ${datarootdir}/info

srcdir          = .

include_dir_suffix = sdcc/include
inclib_dir_suffix = sdcc

sdcc_includedir = $(DESTDIR)$(datadir)/$(include_dir_suffix)
sdcc_inclibdir = $(DESTDIR)$(datadir)/$(inclib_dir_suffix)

CPPFLAGS        =  -I$(top_builddir)


# Compiling entire program or any subproject
# ------------------------------------------
all:

# Compiling and installing everything and running test
# ----------------------------------------------------
install: all installdirs
	$(CP) -r $(srcdir)/asm $(srcdir)/*.h $(sdcc_includedir)
	for target in mcs51 ds390 pic14 pic16 z80 hc08 stm8; \
	do \
	  if [ "`grep $${target} $(top_builddir)/ports.build`" = "$${target}" ]; \
	  then \
	    for mask in '*.h' '*.inc' '*.txt'; \
	    do \
	      if `ls $(srcdir)/$${target}/$${mask} > /dev/null 2>&1`; \
	      then \
	        $(CP) $(srcdir)/$${target}/$${mask} $(sdcc_includedir)/$${target}/; \
	      fi; \
	    done; \
	  fi; \
	done;
	# z80 family: z180, r2k, r2ka, r3ka, etc
	if [ "`grep z80 $(top_builddir)/ports.build`" = "z80" ]; \
	then \
	  for target in z180 rab; \
	  do \
	    for mask in '*.h' '*.inc' '*.txt'; \
	    do \
	      if `ls $(srcdir)/$${target}/$${mask} > /dev/null 2>&1`; \
	      then \
	        $(CP) $(srcdir)/$${target}/$${mask} $(sdcc_includedir)/$${target}/; \
	      fi; \
	    done; \
	  done; \
	fi
	# ds390 family: ds400
	if [ "`grep ds390 $(top_builddir)/ports.build`" = "ds390" ]; \
	then \
	  for target in ds400; \
	  do \
	    for mask in '*.h' '*.inc' '*.txt'; \
	    do \
	      if `ls $(srcdir)/$${target}/$${mask} > /dev/null 2>&1`; \
	      then \
	        $(CP) $(srcdir)/$${target}/$${mask} $(sdcc_includedir)/$${target}/; \
	      fi; \
	    done; \
	  done; \
	fi
	# 6808 family: s08
	if [ "`grep hc08 $(top_builddir)/ports.build`" = "hc08" ]; \
	then \
	  for target in s08; \
	  do \
	    for mask in '*.h' '*.inc' '*.txt'; \
	    do \
	      if `ls $(srcdir)/$${target}/$${mask} > /dev/null 2>&1`; \
	      then \
	        $(CP) $(srcdir)/$${target}/$${mask} $(sdcc_includedir)/$${target}/; \
	      fi; \
	    done; \
	  done; \
	fi
	find $(sdcc_includedir) -type d -name '.svn' -exec rm -rf {} \;
	# correct file modes
	find $(sdcc_includedir) -type f -exec chmod 644 {} \;


# Deleting all the installed files
# --------------------------------
uninstall:
	rm -rf $(sdcc_includedir)
	rm -rf $(sdcc_inclibdir)


# Performing self-test
# --------------------
check:


# Performing installation test
# ----------------------------
installcheck:


# Creating installation directories
# ---------------------------------
installdirs:
	mkdir -p $(sdcc_includedir)
	for target in mcs51 ds390 ds400 pic14 pic16 z180 rab hc08 mos6502; \
	do \
	  if [ -d $(srcdir)/$${target} ]; \
	  then \
	    mkdir -p $(sdcc_includedir)/$${target}; \
	  fi; \
	done


# Creating dependencies
# ---------------------
dep:

include $(srcdir)/clean.mk

# My rules
# --------


# Remaking configuration
# ----------------------
checkconf:
	@if [ -f $(top_builddir)/devel ]; \
	then \
	  $(MAKE) -f $(srcdir)/conf.mk srcdir="$(srcdir)" top_builddir="$(top_builddir)" \
	  freshconf; \
	fi

# End of main_in.mk/main.mk
