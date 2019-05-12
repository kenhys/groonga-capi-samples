AM_CFLAGS = $(GROONGA_CFLAGS) $(GLIB_CFLAGS)
LIBS = $(GROONGA_LIBS) $(GLIB_LIBS)

bin_PROGRAMS = \
	grn_table_create

grn_table_create_SOURCES = grn_table_create.c

clean:
	rm -f $(bin_PROGRAMS) *.o

reset:
	rm -fr testdb/*
