#include "jobclient.h"

using namespace v8;
using namespace node;
using namespace mapjs;

Persistent<FunctionTemplate> JobClient::constructor_template;

void JobClient::Initialize(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    JobClient::constructor_template = Persistent<FunctionTemplate>::New(t);
    JobClient::constructor_template->InstanceTemplate()->SetInternalFieldCount(1);
    JobClient::constructor_template->SetClassName(String::NewSymbol("JobClient"));

    NODE_SET_PROTOTYPE_METHOD(JobClient::constructor_template, "run", Run);
    target->Set(String::NewSymbol("JobClient"), JobClient::constructor_template->GetFunction());
    target->Set(String::New("run"), FunctionTemplate::New(Run)->GetFunction());
}

Handle<Value> JobClient::New(const Arguments& args) {
    HandleScope scope;

    JobClient* jobClient = new JobClient();
    jobClient->Wrap(args.This());
    return args.This();
}

Handle<Value> JobClient::Run(const Arguments& args) {
    HandleScope scope;

    printf("inside JobClient::Run\n");

    return Undefined();
}
