AC_PREREQ(2.59)
AC_INIT([groonga-capi-samples], 0.0.1, [hayashi@clear-code.com])

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([grn_table_add/table_no_key.c])
AM_CONFIG_HEADER([config.h])

AC_CHECK_HEADERS(pthread.h)

AM_INIT_AUTOMAKE(foreign)
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PROG_CXX

AC_PROG_LIBTOOL

if test "$GCC" = "yes"; then
  CFLAGS="$CFLAGS -Wall -Wextra"
  CFLAGS="$CFLAGS -Wmissing-declarations -Wmissing-prototypes"
fi

AC_ARG_ENABLE(debug,
  [AS_HELP_STRING([--enable-debug],
                  [use debug flags (default=no)])],
  [sample_debug="$enableval"],
  [sample_debug="no"])
if test "x$sample_debug" != "xno"; then
  if test "$CLANG" = "yes"; then
    CFLAGS="$CFLAGS -O0 -g"
  elif test "$GCC" = "yes"; then
    CFLAGS="$CFLAGS -O0 -g3"
  fi
fi

AC_ARG_WITH([groonga-source-path],
            AS_HELP_STRING([--with-groonga-source-path=PATH],
                           [Specify Groonga source path for
                            using internal header files.]),
                           [GRN_SOURCE_PATH="$withval"])
AC_SUBST(GRN_SOURCE_PATH)

GROONGA_REQUIRED_VERSION=7.0.4
PKG_CHECK_MODULES([GROONGA], [groonga >= ${GROONGA_REQUIRED_VERSION}])

_PKG_CONFIG(GROONGA_PLUGINS_DIR, [variable=pluginsdir],    [groonga])
_PKG_CONFIG(GROONGA,             [variable=groonga],       [groonga])
_PKG_CONFIG(GROONGA_HTTPD,       [variable=groonga_httpd], [groonga])

GROONGA_PLUGINS_DIR="${pkg_cv_GROONGA_PLUGINS_DIR}"
GROONGA="${pkg_cv_GROONGA}"
GROONGA_HTTPD="${pkg_cv_GROONGA_HTTPD}"

PKG_CHECK_MODULES([GLIB], [glib-2.0 >= 2.8])

AC_SUBST(GROONGA_PLUGINS_DIR)
AC_SUBST(GROONGA)
AC_SUBST(GROONGA_HTTPD)

AC_CONFIG_FILES([
  Makefile
  grn_expr_exec/Makefile
  grn_table_add/Makefile
  grn_inspect/Makefile
  grn_str/Makefile
  grn_macro/Makefile
  grn_obj/Makefile
  grn_db/Makefile
  grn_table/Makefile
  grn_options/Makefile
])

AC_OUTPUT

echo "$PACKAGE_NAME $PACKAGE_VERSION configuration:"
echo "-----------------------"
echo "  Compiler:              ${CC}"
echo "  CFLAGS:                ${CFLAGS}"
echo "  CXXFLAGS:              ${CXXFLAGS}"
echo "  Libraries:             ${LIBS}"
echo
echo "groonga-hoge"
echo "  CFLAGS:                ${GROONGA_CFLAGS}"
echo "  Libraries:             ${GROONGA_LIBS}"
echo "  install directory:     ${hoge_pluginsdir}"
