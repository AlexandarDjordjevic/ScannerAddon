#include "Scanner.hpp"
#include "ScannerManager.hpp"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  ScannerManager::Initialize(env, exports);
  Scanner::Initialize(env, exports);
  return exports;
}

NODE_API_MODULE(so, Init);
