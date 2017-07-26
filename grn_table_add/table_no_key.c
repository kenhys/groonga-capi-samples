#include <stdio.h>
#include <string.h>

#include <groonga.h>

static grn_obj *bookmarks, *uri_column, *comment_column;

int
main (int argc, char **argv)
{
  grn_ctx context;
  grn_id id;
  grn_obj value;
  grn_obj *db;
  int added = 0;
  
  grn_init();
  grn_ctx_init(&context, 0);
  db = grn_db_create(&context, "./testdb/db", NULL);

  bookmarks = grn_table_create(&context,
                               "bookmarks", strlen("bookmarks"),
                               NULL,
                               GRN_OBJ_PERSISTENT|GRN_OBJ_TABLE_NO_KEY,
                               NULL,
                               NULL);
  uri_column = grn_column_create(&context,
                                 bookmarks,
                                 "uri", strlen("uri"),
                                 NULL,
                                 GRN_OBJ_COLUMN_SCALAR,
                                 grn_ctx_at(&context, GRN_DB_SHORT_TEXT));
  comment_column = grn_column_create(&context,
                                     bookmarks,
                                     "comment", strlen("comment"),
                                     NULL,
                                     GRN_OBJ_COLUMN_SCALAR,
                                     grn_ctx_at(&context, GRN_DB_SHORT_TEXT));

  id = grn_table_add(&context, bookmarks, NULL, 0, &added);
  printf("bookmarks: %p\n", bookmarks);
  printf("uri_column: %p\n", uri_column);
  printf("comment_column: %p\n", comment_column);
  printf("added:%d id:%d\n", added, id);
  
  GRN_OBJ_INIT(&value, GRN_BULK, 0, GRN_DB_TEXT);
  GRN_TEXT_SET(&context, &value, "http://groonga.org/", strlen("http://groonga.org/"));
  grn_obj_set_value(&context, uri_column, id, &value, GRN_OBJ_SET);
  GRN_OBJ_FIN(&context, &value);
  
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
