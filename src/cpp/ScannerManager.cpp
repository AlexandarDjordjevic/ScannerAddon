#include "ScannerManager.hpp"
#include "Scanner.hpp"

void ScannerManager::Initialize(Napi::Env &env, Napi::Object &target) {
  Napi::Function constructor = Napi::ObjectWrap<ScannerManager>::DefineClass(
      env, "ScannerManager",
      {InstanceMethod("getScanners", &ScannerManager::getScanners)});
  target.Set("ScannerManager", constructor);
}

ScannerManager::ScannerManager(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<ScannerManager>(info) {}

Napi::Value ScannerManager::getScanners(const Napi::CallbackInfo &info) {
  Napi::Array array = Napi::Array::New(info.Env(), 4);

  for (int i = 0; i < 4; i++) {
    char buffer[32]{0};
    sprintf(buffer, "Scanner - %d", i);
    array[i] = Scanner::New->New({Napi::String::New(info.Env(), buffer)});
  }

  return array;
}
