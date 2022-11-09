#pragma once

#include <napi.h>

class Scanner : public Napi::ObjectWrap<Scanner> {
  static Napi::Function constructor;
  int ScanerId;
  std::string name;

public:
  static Napi::FunctionReference *New;
  Scanner(const Napi::CallbackInfo &info);
  static void Initialize(Napi::Env &env, Napi::Object &target);
  Napi::Value getId(const Napi::CallbackInfo &info);
  Napi::Value getName(const Napi::CallbackInfo &info);
};
