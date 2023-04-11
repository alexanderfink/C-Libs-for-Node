{
  "targets": [
    {
      "target_name": "binding",
      "sources": [ "src/binding.cpp", "src/lib/calculation.h"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "<(module_root_dir)/src/include"
      ],
      "libraries": [
          "C:/Users/alexa/work/JSL/node/node-gyp-base-example/src/lib-calc-emcc.a",
       ],
       "copies": [
              {
              "destination": "<(module_root_dir)/build/Release/",
                  "files": [
                      "C:/Users/alexa/work/JSL/node/node-gyp-base-example/src/lib-calc-emcc.a"
                  ]
              },
          ]
    },
  ]
}