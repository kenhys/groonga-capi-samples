#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main(int argc, char *argv[])
{
  grn_ctx context, *ctx;
  grn_obj *db;
  grn_obj *obj;
  
  grn_init();
  ctx = &context;
  grn_ctx_init(ctx, 0);
  db = grn_db_open(ctx, "./testdb/lexicon");

  if (argc == 2) {
    obj = grn_ctx_get(ctx, argv[1], strlen(argv[1]));
    if (obj) {
      printf("<%s> type?: <%s>\n",
             argv[1], grn_obj_is_type(ctx, obj) ? "true" : "false");
    }
    goto exit;
  }

  const char *obj_names[] = {
    "Int8",
    "Int8PatTable",
    NULL
  };

  int i = 0;
  while (obj_names[i]) {
    obj = grn_ctx_get(ctx, obj_names[i], strlen(obj_names[i]));
    printf("<%s> type?: <%s>\n",
           obj_names[i], grn_obj_is_type(ctx, obj) ? "true" : "false");
    i++;
  }
exit:  
  grn_db_unmap(ctx, db);
  grn_ctx_fin(ctx);
  grn_fin();

  return 0;
}
