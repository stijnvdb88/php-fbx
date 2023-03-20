#ifndef PHP_FBX_H
#define PHP_FBX_H

#include <fbxsdk.h>

//-----------------------------------------------------------------------------

class FBX {
public:
    FBX(const char* path, const char* dest);
    void Convert(const char* path);

#endif