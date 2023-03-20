AC_PROG_CXX

PHP_ARG_WITH(fbx, for FBX Support,
    [  --with-fbx[=DIR]     Include FBX support. DIR is the FBX SDK lib directory])

if test $PHP_FBX != "no"; then
    PHP_REQUIRE_CXX()
    PHP_SUBST(FBX_SHARED_LIBADD)
    
    PHP_NEW_EXTENSION(fbx, php_fbx.cc fbx.cc common.cxx, $ext_shared)

    dnl this is used to perform any shell expansion necessary (such as dealing with '~')
    PHP_FBX_DIR=`cd "$PHP_FBX" && pwd`
    FBX_INC_DIR="$PHP_FBX_DIR/include"
    FBX_LIB_DIR="$PHP_FBX_DIR/lib"

    PHP_ADD_INCLUDE($FBX_INC_DIR)
    
    dnl (comment): PHP_ADD_LIBRARY_WITH_PATH(fbxsdk, $FBX_LIB_DIR, FBX_SHARED_LIBADD) - dynamic link

    PHP_ADD_LIBRARY(fbxsdk, 1, FBX_SHARED_LIBADD)
    PHP_ADD_LIBRARY(stdc++, 1, FBX_SHARED_LIBADD)
fi
