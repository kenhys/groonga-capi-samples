AM_CFLAGS = $(GROONGA_CFLAGS)
LIBS = $(GROONGA_LIBS)

bin_PROGRAMS = load_one_entry load_at_once

load_one_entry_SOURCES = load-one-entry.c
load_at_once_SOURCES = load-at-once.c

clean:
	rm -f $(bin_PROGRAMS) *.o

reset:
	rm -fr testdb/*
