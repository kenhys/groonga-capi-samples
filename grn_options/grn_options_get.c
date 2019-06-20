#include <stdio.h>
#include <string.h>

#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

#include <groonga.h>
#include "grn.h"
#include "grn_obj.h"
#include "grn_options.h"

int
main(void)
{
  grn_ctx context;
  grn_ctx *ctx;
  grn_obj *db;

  grn_default_logger_set_max_level(GRN_LOG_DEBUG);
  grn_default_logger_set_path("groonga.log");
  grn_init();

  ctx = &context;
  grn_ctx_init(ctx, 0);

  db = grn_db_open(ctx, "testdb/db");

  grn_io *io = grn_obj_get_io(ctx, db);
  if (!io) {
    printf("io must not null\n");
    goto exit;
  }

  if (!io->path) {
    printf("io->path must not null\n");
    goto exit;
  }

  char options_path[PATH_MAX];
  grn_snprintf(options_path,
               PATH_MAX,
               PATH_MAX,
               "%s.grndb",
               io->path);
  printf("options path prefix: %s\n", options_path);
  grn_options *options = grn_options_open(ctx, options_path, "[grndb]");
  if (!options) {
    printf("failed to open options path: <%s>\n", options_path);
    goto exit;
  }

  grn_id id = 1;
  grn_obj values;
  grn_option_revision revision;
  revision = grn_options_get(ctx, options, id,
                             "timestamp", strlen("timestamp"),
                             GRN_OPTION_REVISION_NONE, &values);
  if (revision == GRN_OPTION_REVISION_NONE) {
    printf("failed to get: GRN_OPTION_REVISION_NONE\n");
  } else if (revision == GRN_OPTION_REVISION_UNCHANGED) {
    printf("failed to call: GRN_OPTION_REVISION_UNCHANGED\n");
  } else {
  }
#if 0
  uint32_t last_modified = GRN_UINT32_VALUE_AT(&values, 0);
  printf("last_modified: <%u>\n", last_modified);

  last_modified = GRN_UINT32_VALUE(&values);
  printf("last_modified: <%u>\n", last_modified);
#else
  GRN_LOG(ctx, GRN_LOG_DEBUG, "timestamp: <%s>\n", revision);
#endif

exit:
  grn_db_unmap(ctx, db);
  grn_ctx_fin(ctx);
  grn_fin();

  return 0;
}
