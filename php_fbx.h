#ifndef PHP_PHP_FBX_H
#define PHP_PHP_FBX_H

#define PHP_FBX_EXTNAME  "fbx"
#define PHP_FBX_EXTVER   "0.1"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif 

#ifdef __cplusplus
extern "C" {
#endif

#include "php.h"

#ifdef __cplusplus
}
#endif


extern zend_module_entry fbx_module_entry;
#define phpext_fbx_ptr &fbx_module_entry

#endif /* PHP_PHP_FBX_H */


ZEND_BEGIN_ARG_INFO(arginfo_void, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_setter, 0, 0, 1)
  ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()