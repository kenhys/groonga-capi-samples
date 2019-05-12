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
  ctx = &context;
  grn_ctx_init(ctx, 0);

  char db_path[PATH_MAX];
  if (argc != 2) {
    fprintf(stderr, "Usage: %s DB_PATH\n", argv[0]);
    exit(1);
  } else {
    strcpy(db_path, argv[1]);
  }
  struct stat st = {0};
  if (stat(db_path, &st) == -1) {
    mkdir(argv[1], 0777);
  }
  strcat(db_path, "/db");
  printf("db path:%s\n", db_path);

  db = grn_db_create(ctx, db_path, NULL);

  grn_db_unmap(ctx, db);
  grn_ctx_fin(ctx);
  grn_fin();

  return 0;
}
