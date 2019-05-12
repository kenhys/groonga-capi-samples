#include <stdio.h>
#include <string.h>

#include <glib.h>
#include <glib/gstdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <groonga.h>

int
main(int argc, char *argv[])
{
  grn_ctx context;
  grn_ctx *ctx;
  grn_obj *db;

  grn_init();
  grn_init();
  ctx = &context;
  grn_ctx_init(ctx, 0);

  char db_path[PATH_MAX];
  if (argc != 2) {
    fprintf(stderr, "Usage: %s DB_PATH(./db/db)\n", argv[0]);
    exit(1);
  } else {
    strcpy(db_path, argv[1]);
  }
  printf("db path: <%s>\n", db_path);

  g_mkdir_with_parents(g_path_get_dirname(db_path), 0777);
  printf("directory path: <%s>\n", g_path_get_dirname(db_path));

  GRN_DB_OPEN_OR_CREATE(ctx, db_path, NULL, db);
  grn_db_unmap(ctx, db);
  grn_ctx_fin(ctx);
  grn_fin();

  return 0;
}
