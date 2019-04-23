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

  grn_obj *ii = grn_ctx_get(&context, "Bigram.contents", strlen("Bigram.contents"));

  grn_p_ii_values(&context, ii);

  grn_db_unmap(&context, db);
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
