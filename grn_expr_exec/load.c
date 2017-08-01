#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <groonga.h>

int main(void)
{
  grn_ctx ctx;

  grn_init();
  grn_ctx_init(&ctx, 0);
  grn_db_open(&ctx, "./testdb/db");

  grn_obj *command = grn_ctx_get(&ctx, "load", strlen("load"));

  assert(command != NULL);
  grn_obj *values = grn_expr_get_var(&ctx, command, "values", strlen("values"));
  grn_obj_reinit(&ctx, values, GRN_DB_TEXT, 0);
  GRN_TEXT_PUTS(&ctx, values, "[{\"uri\": \"http://groonga.org\", \"comment\": \"Groonga Offical Website\"}]");

  grn_obj *table = grn_expr_get_var(&ctx, command, "table", strlen("table"));
  grn_obj_reinit(&ctx, table, GRN_DB_TEXT, 0);
  GRN_TEXT_PUTS(&ctx, table, "bookmarks");

  grn_expr_exec(&ctx, command, 0);

  grn_ctx_info info;
  grn_ctx_info_get(&ctx, &info);
  printf("%.*s\n", (int)GRN_TEXT_LEN(info.outbuf), GRN_TEXT_VALUE(info.outbuf));
}
