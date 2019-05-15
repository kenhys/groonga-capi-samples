#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main(void)
{
  grn_ctx context, *ctx;
  grn_obj *db;
  grn_obj *obj;
  
  grn_init();
  ctx = &context;
  grn_ctx_init(ctx, 0);
  db = grn_db_open(ctx, "./testdb/vector_column");

  const char *obj_names[] = {
    "Site.users",
    NULL
  };

  int i = 0;
  while (obj_names[i]) {
    obj = grn_ctx_get(&context, obj_names[i], strlen(obj_names[i]));
    printf("<%s> vector column?: <%s>\n",
           obj_names[i], grn_obj_is_data_column(ctx, obj) ? "true" : "false");
    i++;
  }
  
  grn_db_unmap(ctx, db);
  grn_ctx_fin(ctx);
  grn_fin();

  return 0;
}
