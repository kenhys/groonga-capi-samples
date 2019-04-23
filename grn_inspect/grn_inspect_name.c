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

  grn_obj *object;

  const char *object_names[] = {
    "Int8PatTable",
    "ShortTextPatTable",
    "Int8HashTable",
    "ShortTextHashTable",
    "NoKeyTable",
    "Int8",
    "TokenBigram",
    "TokenMecab",
    NULL
  };

  int i = 0;
  grn_obj buffer;
  while (object_names[i]) {
    GRN_TEXT_INIT(&buffer, 0);

    object = grn_ctx_get(&context, object_names[i], strlen(object_names[i]));
    grn_inspect_name(&context, &buffer, object);
    printf("INSPECT <%s>: <%.*s>\n", object_names[i], (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));
    i++;
  }

  GRN_OBJ_FIN(&context, &buffer);
  
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
