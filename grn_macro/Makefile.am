AM_CFLAGS = $(GROONGA_CFLAGS)
LIBS = $(GROONGA_LIBS)

bin_PROGRAMS = grn_text_set

grn_text_set_SOURCES = grn_text_set.c

clean:
	rm -f $(bin_PROGRAMS) *.o

reset:
	rm -fr testdb/*
