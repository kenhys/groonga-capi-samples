AM_CFLAGS = $(GROONGA_CFLAGS) $(GLIB_CFLAGS) -I$(GRN_SOURCE_PATH)/lib
LIBS = $(GROONGA_LIBS) $(GLIB_LIBS)

bin_PROGRAMS = \
	grn_options_set	\
	grn_options_get

grn_options_get_SOURCES = grn_options_get.c
grn_options_set_SOURCES = grn_options_set.c

clean:
	rm -f $(bin_PROGRAMS) *.o

init:
	rm -fr testdb
	mkdir -p testdb
	groonga -n testdb/db shutdown

reset:
	rm -fr testdb/*
