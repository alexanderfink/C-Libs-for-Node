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
          "<(module_root_dir)/src/MathLibrary.lib",
       ],
       "copies": [
              {
              "destination": "<(module_root_dir)/build/Release/",
                  "files": [
                      "<(module_root_dir)/src/MathLibrary.lib"
                  ]
              },
          ]
    },
  ]
}