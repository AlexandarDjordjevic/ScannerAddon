#include "Scanner.hpp"

int gScanerId = 0;
Napi::FunctionReference *Scanner::New;

void Scanner::Initialize(Napi::Env &env, Napi::Object &target) {
  Napi::Function constructor = Napi::ObjectWrap<Scanner>::DefineClass(
      env, "Scanner",
      {InstanceMethod("getId", &Scanner::getId),
       InstanceMethod("getName", &Scanner::getName)});
  target.Set("Scanner", constructor);
  New = new Napi::FunctionReference();
  *New = Napi::Persistent(constructor);
}

Napi::Value Scanner::getId(const Napi::CallbackInfo &info) {
  return Napi::Number::New(info.Env(), ScanerId);
}

Napi::Value Scanner::getName(const Napi::CallbackInfo &info) {
  return Napi::String::New(info.Env(), name);
}

Scanner::Scanner(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<Scanner>(info) {
  ScanerId = gScanerId++;
  name = info[0].ToString().Utf8Value();
}
