#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main (int argc, char **argv)
{
  grn_ctx context;
  grn_obj *db;
  
  grn_init();
  grn_ctx_init(&context, 0);
  db = grn_db_open(&context, "./testdb/db");

  grn_obj *table = grn_ctx_get(&context, "Users", strlen("Users"));

  grn_obj buffer;
  GRN_TEXT_INIT(&buffer, 0);
  grn_inspect(&context, &buffer, table);
  printf("inspect: <%.*s>\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  GRN_TEXT_INIT(&buffer, 0);
  grn_inspect_limited(&context, &buffer, table);
  printf("limited inspect: <%.*s>\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  grn_obj *obj = grn_ctx_get(&context, "Int8", strlen("Int8"));
  GRN_TEXT_INIT(&buffer, 0);
  grn_inspect_indented(&context, &buffer, obj, "aaa");
  printf("indented inspect: %.*s\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  GRN_OBJ_FIN(&context, &buffer);
  
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
