AM_CFLAGS = $(GROONGA_CFLAGS) $(GLIB_CFLAGS)
LIBS = $(GROONGA_LIBS) $(GLIB_LIBS)

bin_PROGRAMS = \
	grn_obj_is_accessor		\
	grn_obj_is_builtin		\
	grn_obj_is_bulk			\
	grn_obj_is_column		\
	grn_obj_is_corrupt		\
	grn_obj_is_data_column		\
	grn_obj_is_dirty		\
	grn_obj_is_expr			\
	grn_obj_is_function_proc	\
	grn_obj_is_id_accessor		\
	grn_obj_is_index_column		\
	grn_obj_is_key_accessor		\
	grn_obj_is_lexicon		\
	grn_obj_is_normalizer_proc	\
	grn_obj_is_number_family_bulk	\
	grn_obj_is_proc			\
	grn_obj_is_reference_column	\
	grn_obj_is_scalar_column	\
	grn_obj_is_scorer_proc		\
	grn_obj_is_selector_only_proc	\
	grn_obj_is_selector_proc	\
	grn_obj_is_table		\
	grn_obj_is_text_family_bulk	\
	grn_obj_is_text_family_type	\
	grn_obj_is_token_filter_proc	\
	grn_obj_is_tokenizer_proc	\
	grn_obj_is_true			\
	grn_obj_is_type			\
	grn_obj_is_vector		\
	grn_obj_is_vector_column	\
	grn_obj_is_weight_vector_column	\
	grn_obj_is_window_function_proc

init:
	rm -fr testdb
	mkdir -p testdb
	groonga -n testdb/lexicon < lexicon.grn
	groonga -n testdb/scalar_column < scalar_column.grn
	groonga -n testdb/vector_column < vector_column.grn
	groonga -n testdb/weight_vector < weight_vector.grn

grn_obj_cast_SOURCES = grn_obj_cast.c
grn_obj_clear_option_values_SOURCES = grn_obj_clear_option_values.c
grn_obj_get_disk_usage_SOURCES = grn_obj_get_disk_usage.c
grn_obj_get_last_modified_SOURCES = grn_obj_get_last_modified.c
grn_obj_is_accessor_SOURCES = grn_obj_is_accessor.c
grn_obj_is_builtin_SOURCES = grn_obj_is_builtin.c
grn_obj_is_bulk_SOURCES = grn_obj_is_bulk.c
grn_obj_is_column_SOURCES = grn_obj_is_column.c
grn_obj_is_corrupt_SOURCES = grn_obj_is_corrupt.c
grn_obj_is_data_column_SOURCES = grn_obj_is_data_column.c
grn_obj_is_dirty_SOURCES = grn_obj_is_dirty.c
grn_obj_is_expr_SOURCES = grn_obj_is_expr.c
grn_obj_is_function_proc_SOURCES = grn_obj_is_function_proc.c
grn_obj_is_id_accessor_SOURCES = grn_obj_is_id_accessor.c
grn_obj_is_index_column_SOURCES = grn_obj_is_index_column.c
grn_obj_is_key_accessor_SOURCES = grn_obj_is_key_accessor.c
grn_obj_is_lexicon_SOURCES = grn_obj_is_lexicon.c
grn_obj_is_normalizer_proc_SOURCES = grn_obj_is_normalizer_proc.c
grn_obj_is_number_family_bulk_SOURCES = grn_obj_is_number_family_bulk.c
grn_obj_is_proc_SOURCES = grn_obj_is_proc.c
grn_obj_is_reference_column_SOURCES = grn_obj_is_reference_column.c
grn_obj_is_scalar_column_SOURCES = grn_obj_is_scalar_column.c
grn_obj_is_scorer_proc_SOURCES = grn_obj_is_scorer_proc.c
grn_obj_is_selector_only_proc_SOURCES = grn_obj_is_selector_only_proc.c
grn_obj_is_selector_proc_SOURCES = grn_obj_is_selector_proc.c
grn_obj_is_table_SOURCES = grn_obj_is_table.c
grn_obj_is_text_family_bulk_SOURCES = grn_obj_is_text_family_bulk.c
grn_obj_is_text_family_type_SOURCES = grn_obj_is_text_family_type.c
grn_obj_is_token_filter_proc_SOURCES = grn_obj_is_token_filter_proc.c
grn_obj_is_tokenizer_proc_SOURCES = grn_obj_is_tokenizer_proc.c
grn_obj_is_true_SOURCES = grn_obj_is_true.c
grn_obj_is_type_SOURCES = grn_obj_is_type.c
grn_obj_is_vector_SOURCES = grn_obj_is_vector.c
grn_obj_is_vector_column_SOURCES = grn_obj_is_vector_column.c
grn_obj_is_weight_vector_column_SOURCES = grn_obj_is_weight_vector_column.c
grn_obj_is_window_function_proc_SOURCES = grn_obj_is_window_function_proc.c
grn_obj_name_is_column_SOURCES = grn_obj_name_is_column.c
grn_obj_reindex_SOURCES = grn_obj_reindex.c
grn_obj_set_option_values_SOURCES = grn_obj_set_option_values.c
grn_obj_touch_SOURCES = grn_obj_touch.c
grn_obj_type_to_string_SOURCES = grn_obj_type_to_string.c

clean:
	rm -f $(bin_PROGRAMS) *.o

reset:
	rm -fr testdb/*
