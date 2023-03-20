# PHP FBX extension #

## Usage
```
$fbx = new FBX($path_to_binary_fbx_in, $path_to_fbx_out);
```

Note: you must supply the fully qualified paths for both parameters. The FBX will be exported depending on the extension of the second parameter.
If the extension is ".fbx", the binary FBX will be converted to ascii. Other valid options are .dae, .obj and .dxf (see FBX SDK documentation for more info).

## Compatibility (Linux + Windows)
* php 5.6.4 and higher
* php 7.1, 7.2
* php 8.1, 8.2


## Build instructions (Linux)
* Download the Autodesk FBX SDK: https://www.autodesk.com/developer-network/platform-technologies/fbx-sdk-2020-3-1
* Copy libfbxsdk.dylib to `/usr/local/lib`
* Copy the include/ directory somwehere convenient e.g. /Users/myusername/fbxsdk/include
* Install php-dev packages for your php version: `apt-get install php8.2-dev`
* Clone this repo, cd into it
* `phpize`
* `./configure --with-fbx=/Users/myusername/fbxsdk` (pass in the directory one up from where you copied the /include dir earlier)
* `make`
* The extension should now appear in the modules/ directory.

## Installation (Linux)
* Download the Autodesk FBX SDK: https://www.autodesk.com/developer-network/platform-technologies/fbx-sdk-2020-3-1
* Copy libfbxsdk.dylib to `/usr/local/lib`
* copy the .so file anywhere (e.g. /etc/fbx.so)
* Edit php.ini: ```extension=/etc/fbx.so``` (or wherever you placed the .so file)
* Restart Apache
* Test if the extension was loaded: ```php --ri fbx```

## Build instructions (Windows)
* `git clone https://github.com/Microsoft/php-sdk-binary-tools`
* Open "Developer Command Prompt for VS2019" 
* All commands listed below must be run using the VS2019 command prompt you just opened:
* cd into the directory you just cloned, and run `phpsdk-vs16-x64.bat`
* `phpsdk_buildtree phpdev`
* Download source code of the PHP version you're building for: https://windows.php.net/download/
* Extract the source code under `<php-sdk-binary-tools>/phpdev/vs16/x64/php-8.2.4-src` (replace php version with whatever version you downloaded)
* Download and install the Autodesk FBX SDK: https://www.autodesk.com/developer-network/platform-technologies/fbx-sdk-2020-3-1
* Copy the Autodesk FBX SDK include/ and lib/ directories into `<php-sdk-binary-tools>/phpdev/vs16/x64/fbxsdk`
* Clone this repo into  `<php-sdk-binary-tools>/phpdev/vs16/x64/php-8.2.4-src/ext/fbx`
* `cd <php-sdk-binary-tools>/phpdev/vs16/x64/php-8.2.4-src`
* `buildconf`
* `configure --with-fbx="<php-sdk-binary-tools>/phpdev/vs16/x64/fbxsdk,shared"`
* `nmake`

## Installation (Windows)
* Download and install the Autodesk FBX SDK: https://www.autodesk.com/developer-network/platform-technologies/fbx-sdk-2020-3-1
* Copy libfbxsdk.dll from the installation and place it next to your php.exe binary
* Copy the php_fbx.dll file into your php extension directory (eg. `<path_to_php>/ext/php_fbx.dll`)
* Edit php.ini: ```extension=fbx``` 
* Test if the extension was loaded: ```php --ri fbx```
