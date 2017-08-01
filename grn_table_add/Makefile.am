AM_CFLAGS = $(GROONGA_CFLAGS)
LIBS = $(GROONGA_LIBS)

bin_PROGRAMS = table-no-key

table_no_key_SOURCES = table_no_key.c

clean:
	rm -f $(bin_PROGRAMS) *.o

reset:
	rm -fr testdb/*
