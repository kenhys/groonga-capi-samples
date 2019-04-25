#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main(void)
{
  grn_ctx context;
  grn_obj *db;
  
  grn_init();
  grn_ctx_init(&context, 0);
  db = grn_db_open(&context, "./testdb/db");

  grn_obj *table = grn_ctx_get(&context, "Users", strlen("Users"));

  const char *table_names[] = {
    "Int8PatTable",
    "ShortTextPatTable",
    "Int8HashTable",
    "ShortTextHashTable",
    "NoKeyTable",
    NULL
  };

  int i = 0;
  grn_obj buffer;
  while (table_names[i]) {
    GRN_TEXT_INIT(&buffer, 0);

    table = grn_ctx_get(&context, table_names[i], strlen(table_names[i]));
    grn_inspect(&context, &buffer, table);
    printf("INSPECT <%s>: <%.*s>\n", table_names[i], (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));
    i++;
  }

  GRN_TEXT_INIT(&buffer, 0);
  grn_inspect_limited(&context, &buffer, table);
  printf("limited inspect: <%.*s>\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  grn_obj *obj = grn_ctx_get(&context, "Int8", strlen("Int8"));
  GRN_TEXT_INIT(&buffer, 0);
  grn_inspect_indented(&context, &buffer, obj, "aaa");
  printf("indented inspect: %.*s\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  GRN_TEXT_INIT(&buffer, 0);
  grn_inspect_name(&context, &buffer, obj);
  printf("indented inspect: %.*s\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  GRN_TEXT_INIT(&buffer, 0);
  grn_inspect_encoding(&context, &buffer, GRN_ENC_UTF8);
  printf("encoding: %.*s\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  GRN_TEXT_INIT(&buffer, 0);
  grn_inspect_type(&context, &buffer, table->header.type);
  printf("type: %.*s\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  GRN_TEXT_INIT(&buffer, 0);
  grn_text_printf(&context, &buffer, "init");
  grn_inspect(&context, &buffer, table);
  printf("append?: %.*s\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  GRN_OBJ_FIN(&context, &buffer);
  
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
