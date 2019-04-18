AM_CFLAGS = $(GROONGA_CFLAGS)
LIBS = $(GROONGA_LIBS)

bin_PROGRAMS = \
	grn_inspect \
	grn_inspect_limited \
	grn_inspect_encoding \
	grn_inspect_name \
	grn_inspect_type

grn_inspect_SOURCES = grn_inspect.c
grn_inspect_limited_SOURCES = grn_inspect_limited.c
grn_inspect_encoding_SOURCES = grn_inspect_encoding.c
grn_inspect_name_SOURCES = grn_inspect_name.c
grn_inspect_type_SOURCES = grn_inspect_type.c

clean:
	rm -f $(bin_PROGRAMS) *.o

reset:
	rm -fr testdb/*
