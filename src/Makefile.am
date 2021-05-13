MAINTAINERCLEANFILES = Makefile.in

#Subdirs; place '.' before any directory to force the current directory to
#be compiled before the subdirs.
SUBDIRS = lib


# Program name
bin_PROGRAMS = sd

sd_SOURCES = main.c
sd_LDADD = lib/libsd.la
sd_CFLAGS = -Ilib
