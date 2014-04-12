AC_INIT([distsnmp], [0.1], [cmouse@cmouse.fi], [main_c], [https://github.com/cmouse/distsnmp])

AC_CANONICAL_TARGET
AC_CANONICAL_HOST
AC_CANONICAL_SYSTEM

AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.10 no-define])
AM_SILENT_RULES([yes])
AC_USE_SYSTEM_EXTENSIONS
AC_CONFIG_HEADERS([include/config.h])
AC_CONFIG_MACRO_DIR([m4])
LT_INIT
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AM_PROG_CC_C_O
AC_GNU_SOURCE

AC_ARG_ENABLE(pie,
	[AC_HELP_STRING([--enable-pie],
			[Produce position independent executables @<:@default=yes@:>@])],
	enable_pie=$enableval,
	enable_pie="maybe")

AC_ARG_ENABLE(relro,
	[AC_HELP_STRING([--enable-relro],
			[Enable relocations read-only support @<:@default=yes@:>@])],
	enable_relro=$enableval,
	enable_relro="maybe")

AC_ARG_ENABLE(all-static, 
        [AC_HELP_STRING([--enable-all-static],
                        [Enable fully static build @<:@default=no@:>@])],
        enable_all_static=$enableval,
        enable_all_static="no")

AC_ARG_ENABLE(debug,
        [AC_HELP_STRING([--enable-debug],
                        [Enable debug code @<:@default=yes@:>@])],
        enable_debug=$enableval,
        enable_debug="yes")

if test "x$enable_all_static" != "xno"; then
	STATIC_LDFLAGS="-all-static"
	enable_pie="no"
fi
AC_SUBST([STATIC_LDFLAGS])

if test "x$enable_debug" != "xno"; then
	enable_pie="no"
	enable_relro="no"
	DEBUG_CFLAGS="-DDEBUG"
	CFLAGS="-g -O0"
else
	DEBUG_CFLAGS="-DNDEBUG"
        CFLAGS="-O2"
fi

AC_SUBST([DEBUG_CFLAGS])
if test "x$enable_pie" == "xmaybe"; then
   AC_MSG_CHECKING([whether $CC accepts -fpie -pie])
   OLD_CPPFLAGS="$CPPFLAGS"
   CPPFLAGS="$CPPFLAGS -fpie -pie"
   AC_TRY_COMPILE(,,enable_pie=yes,enable_pie=no)
   CPPFLAGS="$OLD_CPPFLAGS"
   AC_MSG_RESULT($enable_pie);
fi

if  test "x$enable_pie" != "xno"; then
	PIE_CFLAGS="-fpie -pie"
else
	PIE_CFLAGS=""
fi

AC_SUBST([PIE_CFLAGS])

if test "x$enable_relro" == "xmaybe"; then
   AC_MSG_CHECKING([whether $CC accepts -Wl,-z,relro])
   OLD_CFLAGS="$CFLAGS"
   CFLAGS="$CFLAGS -Wl,-z,relro"
   AC_TRY_LINK(,,enable_relro=yes,enable_relro=no)
   CFLAGS="$OLD_CFLAGS"
   AC_MSG_RESULT($enable_relro);
fi

if test "x$enable_relro" != "xno"; then
	RELRO_CFLAGS="-Wl,-z,relro"
else
	RELRO_CFLAGS=""
fi
AC_SUBST([RELRO_CFLAGS])

AC_ARG_WITH([net-snmp-config], AC_HELP_STRING([--with-net-snmp-config=path], [Path to net-snmp-config script]),
  [NETSNMP_CONFIG=$withval])


AC_C_CONST
AC_C_BIGENDIAN
AC_C_INLINE
AC_SYS_LARGEFILE
AC_PROG_LN_S 

AC_HEADER_STDC
AC_FUNC_VPRINTF
AC_HEADER_DIRENT 
AC_FUNC_MMAP 
AC_FUNC_MEMCMP 
AC_STRUCT_ST_RDEV
AC_STRUCT_TM

# some library checks

AC_PATH_PROG([NETSNMP_CONFIG], [net-snmp-config])

if test x$NETSNMP_CONFIG == x; then
  AC_MSG_ERROR([cannot find net-snmp-config])
fi

BOOST_REQUIRE
BOOST_FOREACH
BOOST_PROGRAM_OPTIONS

AC_SUBST([SNMP_CFLAGS])
AC_SUBST([SNMP_LDFLAGS])

SNMP_CFLAGS=`$NETSNMP_CONFIG --base-lib-cflags`
SNMP_LDFLAGS=`$NETSNMP_CONFIG --libs`

PKG_CHECK_MODULES([libhiredis], [libhiredis])
PKG_CHECK_MODULES([libzmq], [libzmq])
PKG_CHECK_MODULES([libevent], [libevent])

AC_CONFIG_FILES([Makefile src/Makefile tests/Makefile doc/Makefile])
AC_OUTPUT
