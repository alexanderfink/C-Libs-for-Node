#include <node.h>
#include <v8.h>
#include <string>
#include <iostream>
#include "include/calculation.h"
#include "include/example.h"



using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Number;

using namespace std; 
using namespace v8;

int addCalculation(int a, int b) {
  MathLibrary::Arithmetic::Add(3, 3);
  // int variable = substraction(3, 3);
  return a + b;
}

void Method(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();
  auto context = isolate->GetCurrentContext();

  Maybe<uint32_t> maybe_param1 = args[0]->Uint32Value(context);
  Maybe<uint32_t> maybe_param2 = args[1]->Uint32Value(context);

  if (maybe_param1.IsJust() && maybe_param2.IsJust()) {
    uint32_t param1 = maybe_param1.FromJust();
    uint32_t param2 = maybe_param2.FromJust();
    
    int result = addCalculation(param1, param2);

    string resultStr = to_string(result);
    char* resultCharPtnr =  &resultStr[0];

    args.GetReturnValue().Set(String::NewFromUtf8(isolate, resultCharPtnr).ToLocalChecked());
    return;
  } 

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, "Incorrect params!").ToLocalChecked());
}

void Initialize(Local<Object> exports) {
  NODE_SET_METHOD(exports, "addition", Method);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

// https://github.com/nodejs/node-gyp/issues/1240
// https://stackoverflow.com/questions/54632751/how-to-use-a-static-library-with-node-gyp-on-windows