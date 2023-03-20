#include "fbx.h"
#include "common.h"
#include <string>
//-----------------------------------------------------------------------------



FBX::FBX(const char* path, const char* destination)
{
    std::string out = destination;
    int idx = (out.find_last_of(".")) + 1;
    std::string ext = out.substr(idx).c_str();

    FbxString fbxPath = FbxString(path);
    if (fbxPath.IsEmpty() == false)
    {
        FbxManager* sdkManager = NULL;
        FbxScene* scene = NULL;

        InitializeSdkObjects(sdkManager, scene);

        bool result = LoadScene(sdkManager, scene, fbxPath.Buffer());
        if (result == false)
        {
            FBXSDK_printf("Call to LoadScene() failed.\n");
        }
        else
        {
            int format = sdkManager->GetIOPluginRegistry()->FindWriterIDByExtension(ext.c_str());
            if (format == 0) // binary fbx
            {
                format = 1; // ascii fbx    
            }
            
            FBXSDK_printf("format: %d\n", format);

            FbxExporter* exporter = FbxExporter::Create(sdkManager, "");
            result = exporter->Initialize(destination, format, sdkManager->GetIOSettings());
            if (result)
            {
                result = exporter->Export(scene);
                if (result == false)
                {
                    FBXSDK_printf("Call to FbxExporter::Export() failed.\n");
                    FBXSDK_printf("Error returned: %s\n\n", exporter->GetStatus().GetErrorString());
                }
            }
            else
            {
                FBXSDK_printf("Call to FbxExporter::Initialize() failed.\n");
                FBXSDK_printf("Error returned: %s\n\n", exporter->GetStatus().GetErrorString());
            }
            exporter->Destroy();            
        }
        DestroySdkObjects(sdkManager, result);
    }
}