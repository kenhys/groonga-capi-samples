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

void text_options_set(grn_ctx *ctx, grn_options *options)
{
  grn_obj vector;
  GRN_TEXT_INIT(&vector, GRN_OBJ_VECTOR);
  GRN_LOG(ctx, GRN_LOG_DEBUG, "vector size: <%d>\n", grn_vector_size(ctx, &vector));
  grn_vector_add_element(ctx, &vector,
                         (const char *)"foobar", strlen("foobar"),
                         0, GRN_DB_TEXT);
  GRN_LOG(ctx, GRN_LOG_DEBUG, "vector size: <%d>\n", grn_vector_size(ctx, &vector));

  const char *raw_value;
  grn_id domain;
  unsigned int size;
  size = grn_vector_get_element(ctx, &vector, 0,
                                &raw_value, NULL, &domain);
  GRN_LOG(ctx, GRN_LOG_DEBUG, "domain: <%s>\n", domain == GRN_DB_TEXT ? "GRN_DB_TEXT" : "unknown");

  grn_id id = 1;
  grn_rc rc = grn_options_set(ctx, options, id,
                              "timestamp", strlen("timestamp"),
                              &vector);
  GRN_OBJ_FIN(ctx, &vector);
  if (rc != GRN_SUCCESS) {
    GRN_LOG(ctx, GRN_LOG_ERROR, "rc: %u\n", rc);
    return;
  }
}

void uint32_options_set(grn_ctx *ctx, grn_options *options)
{
  uint32_t last_modified = 100;
  grn_obj vector;
  GRN_UINT32_INIT(&vector, GRN_OBJ_VECTOR);
  GRN_LOG(ctx, GRN_LOG_DEBUG, "vector size: <%d>\n", grn_vector_size(ctx, &vector));
  grn_vector_add_element(ctx, &vector,
                         (const char *)(&last_modified), sizeof(uint32_t),
                         0, GRN_DB_UINT32);
  GRN_LOG(ctx, GRN_LOG_DEBUG, "vector size: <%d>\n", grn_vector_size(ctx, &vector));

  const char *raw_value;
  grn_id domain;
  unsigned int size;
  size = grn_vector_get_element(ctx, &vector, 0,
                                &raw_value, NULL, &domain);

  //printf( "get: |%u|\n", last_modified);
  printf("size: <%u> domain: <%u>\n", size, domain);

  last_modified = grn_vector_get_element_uint32(ctx, &vector, 0, -1);
  printf("last_modified: <%u>\n", last_modified);

  last_modified = 0;
  last_modified = GRN_UINT32_VALUE_AT(&vector, 0);
  GRN_LOG(ctx, GRN_LOG_DEBUG, "last_modified: <%u>\n", last_modified);

  grn_id id = 1;
  grn_rc rc = grn_options_set(ctx, options, id,
                              "timestamp", strlen("timestamp"),
                              &vector);
  GRN_OBJ_FIN(ctx, &vector);
  if (rc != GRN_SUCCESS) {
    GRN_LOG(ctx, GRN_LOG_ERROR, "rc: %u\n", rc);
    return;
  }
}

int
main(void)
{
  grn_ctx context;
  grn_ctx *ctx;
  grn_obj *db;

  unlink("groonga.log");

  grn_default_logger_set_max_level(GRN_LOG_DEBUG);
  grn_default_logger_set_path("groonga.log");
  grn_init();

  ctx = &context;
  grn_ctx_init(ctx, 0);

  db = grn_db_open(ctx, "testdb/db");

  grn_io *io = grn_obj_get_io(ctx, db);
  if (!io) {
    GRN_LOG(ctx, GRN_LOG_ERROR, "io must not null\n");
    goto exit;
  }

  if (!io->path) {
    GRN_LOG(ctx, GRN_LOG_ERROR, "io->path must not null\n");
    goto exit;
  }

  char options_path[PATH_MAX];
  grn_snprintf(options_path,
               PATH_MAX,
               PATH_MAX,
               "%s.grndb",
               io->path);
  unlink("testdb/db.grndb.options");
  GRN_LOG(ctx, GRN_LOG_DEBUG, "options path prefix: %s\n", options_path);
  grn_options *options = grn_options_create(ctx, options_path, "[grndb]");
  if (!options) {
    GRN_LOG(ctx, GRN_LOG_ERROR, "failed to create options path: <%s>\n", options_path);
    goto exit;
  }

  text_options_set(ctx, options);
  grn_options_close(ctx, options);

exit:
  grn_db_unmap(ctx, db);
  grn_ctx_fin(ctx);
  grn_fin();

  return 0;
}
