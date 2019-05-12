#include <stdio.h>
#include <string.h>

#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
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
  struct stat st = {0};
  if (stat(db_path, &st) == -1) {
    fprintf(stderr, "Failed to stat: <%s>\n", db_path);
    exit(1);
  }
  printf("db path: <%s>\n", db_path);

  db = grn_db_open(ctx, db_path);
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
