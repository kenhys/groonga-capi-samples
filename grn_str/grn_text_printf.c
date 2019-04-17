#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main(void)
{
  grn_ctx context;
  
  grn_init();
  grn_ctx_init(&context, 0);

  grn_obj buffer;
  GRN_TEXT_INIT(&buffer, 0);
  grn_text_printf(&context, &buffer, "%s\n", "first printf");
  grn_text_printf(&context, &buffer, "%s\n", "second printf");
  
  printf("grn_text_printf: <%.*s>\n", (int)GRN_TEXT_LEN(&buffer), GRN_TEXT_VALUE(&buffer));

  GRN_OBJ_FIN(&context, &buffer);
  
  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
