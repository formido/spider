#!/bin/sh

rm -rf Makefile Makefile.in aclocal.m4 autom4te.cache config.log config.status configure googleurl/Makefile.in googleurl/Makefile

aclocal
autoconf
automake
