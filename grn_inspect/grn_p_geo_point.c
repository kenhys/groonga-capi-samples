#include <stdio.h>
#include <string.h>

#include <groonga.h>

int
main (int argc, char **argv)
{
  grn_ctx context;

  grn_init();
  grn_ctx_init(&context, 0);

  int latitude = (45 * 60 * 60 + 0 * 60) * 1000;
  int longitude = (90 * 60 * 60 + 0 * 60) * 1000;

  grn_obj point;
  GRN_WGS84_GEO_POINT_INIT(&point, 0);
  GRN_GEO_POINT_SET(&context, &point, latitude, longitude);
  grn_p_geo_point(&context, (grn_geo_point*)&point);

  grn_ctx_fin(&context);
  grn_fin();

  return 0;
}
