#include "php_fbx.h"
#include "fbx.h"

zend_object_handlers fbx_object_handlers;

struct fbx_object {
    zend_object std;
    FBX* fbx;
};

void fbx_free_storage(void *object)
{
    fbx_object *obj = (fbx_object *)object;
    delete obj->fbx;

    zend_hash_destroy(obj->std.properties);
    FREE_HASHTABLE(obj->std.properties);

    efree(obj);
}

zend_object * create_handler(zend_class_entry *type)
{
    fbx_object *obj = (fbx_object *) ecalloc(1, sizeof(struct fbx_object) + zend_object_properties_size(type));

    zend_object_std_init(&obj->std, type);

    obj->std.handlers = &fbx_object_handlers;

    return &obj->std;
}

zend_class_entry *fbx_ce;

PHP_METHOD(FBX, __construct)
{
    char* file;
    char* dest;
    size_t file_len;
    size_t dest_len;

    FBX* fbx = NULL;
    zval *object = getThis();

    if (zend_parse_parameters(ZEND_NUM_ARGS(), (char *)"ss",
            &file, &file_len, &dest, &dest_len) == FAILURE) {
        RETURN_NULL();
    }

    fbx = new FBX(file, dest);    
    fbx_object *obj = (fbx_object *)((char *)getThis() - XtOffsetOf(struct fbx_object, std));
    obj->fbx = fbx;
}

zend_function_entry fbx_methods[] = {
    PHP_ME(FBX,  __construct,     arginfo_void, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    {
        NULL, NULL, NULL
    }
};

PHP_MINIT_FUNCTION(fbx)
{
    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "FBX", fbx_methods);
    fbx_ce = zend_register_internal_class(&ce);
    fbx_ce->create_object = create_handler;
    memcpy(&fbx_object_handlers,
        zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    fbx_object_handlers.clone_obj = NULL;
    return SUCCESS;
}

zend_module_entry fbx_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_FBX_EXTNAME,
    NULL,                  /* Functions */
    PHP_MINIT(fbx),
    NULL,                  /* MSHUTDOWN */
    NULL,                  /* RINIT */
    NULL,                  /* RSHUTDOWN */
    NULL,                  /* MINFO */
#if ZEND_MODULE_API_NO >= 20010901
    PHP_FBX_EXTVER,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_FBX
extern "C" {
    ZEND_GET_MODULE(fbx)
}
#endif