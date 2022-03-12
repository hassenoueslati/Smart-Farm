## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projectc

projectc_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	capteur.c capteur.h \
	enregistrement.c enregistrement.h \
	client.c client.h \
	employe.c employe.h \
	plante.c plante.h \
	annee.c annee.h \
	equipement.c equipement.h \
	ouvrier.c ouvrier.h \
	tree.c tree.h \
	CRUD.c CRUD.h

projectc_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

