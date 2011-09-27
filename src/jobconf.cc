#include "jobconf.h"

using namespace v8;
using namespace node;
using namespace std;
using namespace mapjs;

Persistent<FunctionTemplate> JobConf::constructor_template;

void JobConf::Initialize(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    constructor_template = Persistent<FunctionTemplate>::New(t);
    constructor_template->InstanceTemplate()->SetInternalFieldCount(2);
    constructor_template->SetClassName(String::NewSymbol("JobConf"));
    target->Set(String::NewSymbol("JobConf"), constructor_template->GetFunction());
    target->SetAccessor(String::New("inputPath"), GetInputPath, SetInputPath);
    target->SetAccessor(String::New("outputPath"), GetInputPath, SetInputPath);
}

Handle<Value> JobConf::New(const Arguments& args) {
    HandleScope scope;

    JobConf* jobconf = new JobConf();
    jobconf->Wrap(args.This());
    return args.This();
}

Handle<Value> JobConf::GetInputPath(Local<String> property, const AccessorInfo& info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    void* ptr = wrap->Value();
    std::string value = static_cast<JobConf*>(ptr)->_inputPath;
    return String::New(value.c_str());
}

void JobConf::SetInputPath(Local<String> property, Local<Value> value, const AccessorInfo& info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    void* ptr = wrap->Value();
    static_cast<JobConf*>(ptr)->_inputPath = value->NumberValue();
}

Handle<Value> JobConf::GetOutputPath(Local<String> property, const AccessorInfo& info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(1));
    void* ptr = wrap->Value();
    std::string value = static_cast<JobConf*>(ptr)->_outputPath;
    return String::New(value.c_str());
}

void JobConf::SetOutputPath(Local<String> property, Local<Value> value, const AccessorInfo& info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(1));
    void* ptr = wrap->Value();
    static_cast<JobConf*>(ptr)->_outputPath = value->NumberValue();
}
