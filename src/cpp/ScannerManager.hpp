#pragma once

#include <napi.h>

class ScannerManager : public Napi::ObjectWrap<ScannerManager> {
public:
  ScannerManager(const Napi::CallbackInfo &info);
  static void Initialize(Napi::Env &env, Napi::Object &target);
  Napi::Value getScanners(const Napi::CallbackInfo &info);
};
