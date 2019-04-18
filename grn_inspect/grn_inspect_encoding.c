#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main (int argc, char **argv)
{
  grn_ctx context;
  grn_obj *db;
  
  grn_init();
  grn_ctx_init(&context, 0);

  const int encodings[] = {
    GRN_ENC_DEFAULT,
    GRN_ENC_NONE,
    GRN_ENC_EUC_JP,
    GRN_ENC_UTF8,
    GRN_ENC_SJIS,
    GRN_ENC_LATIN1,
    GRN_ENC_KOI8R,
    -1
  };

  int i = 0;
  grn_obj buffer;
  while (encodings[i] != -1) {
    GRN_TEXT_INIT(&buffer, 0);
    grn_inspect_encoding(&context, &buffer, encodings[i]);
    printf("%d: ENCODING: <%.*s>\n", i, (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));
    i++;
  }

  GRN_OBJ_FIN(&context, &buffer);
  
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
