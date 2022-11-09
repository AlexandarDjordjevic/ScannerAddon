{
  "targets": [
    {
      "cppflags": ["std=c++17"],
      "defines": [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "target_name": "addon",
      "sources": [
          "src/cpp/addon.cpp",
          "src/cpp/Scanner.cpp",
          "src/cpp/ScannerManager.cpp" 
      ],
      "include_dirs": ["<!(node -p \"require('node-addon-api').include_dir\")"],
    }
  ]
}
