#include <stdio.h>
#include <string.h>

#include <groonga.h>

const char *tables[] = {
  "UInt8PatTable",
  "ShortTextPatTable",
  NULL,
};

int
main(void)
{
  grn_ctx context;
  grn_obj *db;

  grn_init();
  grn_ctx_init(&context, 0);

  db = grn_db_open(&context, "./testdb/db");

  int i = 0;
  while (tables[i]) {
    grn_obj *table = grn_ctx_get(&context, tables[i], strlen(tables[i]));

    grn_obj key_buffer;
    GRN_OBJ_INIT(&key_buffer, GRN_BULK, GRN_OBJ_DO_SHALLOW_COPY, table->header.domain);

    grn_obj buffer;
    GRN_TEXT_INIT(&buffer, 0);
  
    unsigned char key[16];
    int key_size = 0;
    key_size = grn_table_get_key(&context, table, 1, key, 16);
    GRN_TEXT_SET(&context, &key_buffer, key, key_size);
    printf("key buffer: <%.*s>\n", (int)GRN_TEXT_LEN(&key_buffer), GRN_TEXT_VALUE(&key_buffer));
    grn_inspect(&context, &buffer, &key_buffer);
    GRN_OBJ_FIN(&context, &key_buffer);

    printf("grn_text_printf: <%.*s>\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

    GRN_TEXT_INIT(&buffer, 0);
    GRN_OBJ_INIT(&key_buffer, GRN_BULK, GRN_OBJ_DO_SHALLOW_COPY, GRN_DB_TEXT);
    void *null_key = NULL;
    key_size = 0;
    GRN_TEXT_SET(&context, &key_buffer, null_key, key_size);
    grn_inspect(&context, &buffer, &key_buffer);
    GRN_OBJ_FIN(&context, &key_buffer);

    printf("null key: <%.*s>\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

    GRN_OBJ_FIN(&context, &buffer);
    i++;
  }
  
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
