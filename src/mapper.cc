#include "mapper.h"

using namespace v8;
using namespace node;
using namespace mapjs;

Persistent<FunctionTemplate> Mapper::constructor_template;

void Mapper::Initialize(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    Mapper::constructor_template = Persistent<FunctionTemplate>::New(t);
    Mapper::constructor_template->InstanceTemplate()->SetInternalFieldCount(1);
    Mapper::constructor_template->SetClassName(String::NewSymbol("Mapper"));

    NODE_SET_PROTOTYPE_METHOD(Mapper::constructor_template, "map", Map);
    target->Set(String::NewSymbol("Mapper"), Mapper::constructor_template->GetFunction());
    target->Set(String::New("map"), FunctionTemplate::New(Map)->GetFunction());
}

Handle<Value> Mapper::New(const Arguments& args) {
    HandleScope scope;

    Mapper* mapper = new Mapper();
    mapper->Wrap(args.This());
    return args.This();
}

Handle<Value> Mapper::Map(const Arguments& args) {
    HandleScope scope;

    return Undefined();
}
