AM_CFLAGS = $(GROONGA_CFLAGS)
LIBS = $(GROONGA_LIBS)

bin_PROGRAMS = \
	grn_inspect \
	grn_inspect_limited \
	grn_inspect_encoding \
	grn_inspect_name \
	grn_inspect_type \
	grn_inspect_query_log_flags \
	grn_p \
	grn_p_geo_point

grn_inspect_SOURCES = grn_inspect.c
grn_inspect_limited_SOURCES = grn_inspect_limited.c
grn_inspect_encoding_SOURCES = grn_inspect_encoding.c
grn_inspect_name_SOURCES = grn_inspect_name.c
grn_inspect_type_SOURCES = grn_inspect_type.c
grn_inspect_query_log_flags_SOURCES = grn_inspect_query_log_flags.c
grn_p_SOURCES = grn_p.c
grn_p_geo_point_SOURCES = grn_p_geo_point.c

clean:
	rm -f $(bin_PROGRAMS) *.o

reset:
	rm -fr testdb/*
