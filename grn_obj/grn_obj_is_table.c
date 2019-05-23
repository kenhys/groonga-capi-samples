#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main(int argc, char *argv[])
{
  grn_ctx context;
  grn_obj *db;
  grn_obj *obj;
  
  grn_init();
  grn_ctx_init(&context, 0);
  db = grn_db_open(&context, "./testdb/lexicon");

  if (argc == 2) {
    obj = grn_ctx_get(&context, argv[1], strlen(argv[1]));
    if (obj) {
      printf("<%s> table?: <%s>\n",
             argv[1], grn_obj_is_table(&context, obj) ? "true" : "false");
    }
    goto exit;
  }

  const char *obj_names[] = {
    "Site.title",
    "Site",
    NULL
  };

  int i = 0;
  while (obj_names[i]) {
    obj = grn_ctx_get(&context, obj_names[i], strlen(obj_names[i]));
    printf("<%s> table?: <%s>\n",
           obj_names[i], grn_obj_is_table(&context, obj) ? "true" : "false");
    i++;
  }
exit:  
  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
