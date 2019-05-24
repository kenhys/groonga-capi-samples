#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main(void)
{
  grn_ctx context, *ctx;
  grn_obj *db;
  grn_obj obj;
  
  grn_init();
  ctx = &context;
  grn_ctx_init(ctx, 0);
  db = grn_db_open(ctx, "./testdb/lexicon");

  GRN_INT32_INIT(&obj, 0);
  printf("number family bulk?: <%s>\n", grn_obj_is_number_family_bulk(ctx, &obj) ? "true" : "false");

  grn_db_unmap(ctx, db);
  grn_ctx_fin(ctx);
  grn_fin();

  return 0;
}
