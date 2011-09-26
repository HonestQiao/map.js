#include "partitioner.h"

using namespace v8;
using namespace node;
using namespace mapjs;

Persistent<FunctionTemplate> Partitioner::constructor_template;

void Partitioner::Initialize(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    Partitioner::constructor_template = Persistent<FunctionTemplate>::New(t);
    Partitioner::constructor_template->InstanceTemplate()->SetInternalFieldCount(0);
    Partitioner::constructor_template->SetClassName(String::NewSymbol("Partitioner"));

    NODE_SET_PROTOTYPE_METHOD(Partitioner::constructor_template, "getPartition", GetPartition);
    target->Set(String::NewSymbol("Partitioner"), Partitioner::constructor_template->GetFunction());
    target->Set(String::New("getPartition"), FunctionTemplate::New(GetPartition)->GetFunction());
}

Handle<Value> Partitioner::New(const Arguments& args) {
    HandleScope scope;

    Partitioner* partitioner = new Partitioner();
    partitioner->Wrap(args.This());
    return args.This();
}

Handle<Value> Partitioner::GetPartition(const Arguments& args) {
    HandleScope scope;

    printf("Inside Partitioner.GetPartition()\n");

    std::string key = V8StringToStdString(args[0]);
    std::string value = V8StringToStdString(args[1]);
    int numPartitions = args[3]->Int32Value();

    return Undefined();
}

