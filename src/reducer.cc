#include "reducer.h"

using namespace v8;
using namespace node;

Persistent<FunctionTemplate> Reducer::constructor_template;

void Reducer::Initialize(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    Reducer::constructor_template = Persistent<FunctionTemplate>::New(t);
    Reducer::constructor_template->InstanceTemplate()->SetInternalFieldCount(1);
    Reducer::constructor_template->SetClassName(String::NewSymbol("Reducer"));

    NODE_SET_PROTOTYPE_METHOD(Reducer::constructor_template, "reduce", Reduce);
    target->Set(String::NewSymbol("Reducer"), Reducer::constructor_template->GetFunction());
    target->Set(String::New("reduce"), FunctionTemplate::New(Reduce)->GetFunction());
}

Handle<Value> Reducer::New(const Arguments& args) {
    HandleScope scope;

    //Local<Function> f = Local<Function>::Cast(args[0]);
    //mapFunction = Persistent<Function>::New(f);

    //mapFunction = Persistent<Function>::Cast(args[0]);

    Reducer* reducer  = new Reducer();
    reducer->Wrap(args.This());
    return args.This();
}

Handle<Value> Reducer::Reduce(const Arguments& args) {
    HandleScope scope;

    printf("Inside Reducer.Reduce()\n");

    Local<Function> reduceFunction = Local<Function>::Cast(args[0]);
    Local<Value> v[2];
    v[0] = Integer::New(1);
    v[1] = Integer::New(2);
    reduceFunction->Call(Context::GetCurrent()->Global(), 2, v);

    return Undefined();
}
