#include <stdio.h>
#include <string.h>

#include <glib.h>
#include <stdlib.h>
#include <groonga.h>

int main(int argc, char **argv)
{
  grn_ctx context, *ctx;
  grn_obj *db;

  grn_init();
  ctx = &context;
  grn_ctx_init(ctx, 0);
  if (argc != 2) {
    fprintf(stderr, "Usage: %s DB_PATH\n", argv[0]);
    exit(1);
  }

  g_mkdir_with_parents(g_path_get_dirname(argv[1]), 0777);

  GRN_DB_OPEN_OR_CREATE(ctx, argv[1], NULL, db);

  grn_table_create(ctx,
                   "nokey", strlen("nokey"),
                   NULL,
                   GRN_OBJ_PERSISTENT|GRN_OBJ_TABLE_NO_KEY,
                   NULL,
                   NULL);
  grn_table_create(ctx,
                   "pat", strlen("pat"),
                   NULL,
                   GRN_OBJ_PERSISTENT|GRN_OBJ_TABLE_PAT_KEY,
                   grn_ctx_at(ctx, GRN_DB_SHORT_TEXT),
                   NULL);
  grn_table_create(ctx,
                   "hash", strlen("hash"),
                   NULL,
                   GRN_OBJ_PERSISTENT|GRN_OBJ_TABLE_HASH_KEY,
                   grn_ctx_at(ctx, GRN_DB_SHORT_TEXT),
                   NULL);

  grn_db_unmap(ctx, db);
  grn_ctx_fin(ctx);
  grn_fin();

  return 0;
}
