#include "job_conf.h"

using namespace v8;
using namespace node;
using namespace std;

Persistent<FunctionTemplate> JobConf::constructor_template;

void JobConf::Initialize(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    constructor_template = Persistent<FunctionTemplate>::New(t);
    constructor_template->InstanceTemplate()->SetInternalFieldCount(1);
    constructor_template->SetClassName(String::NewSymbol("JobConf"));
    target->Set(String::NewSymbol("JobConf"), constructor_template->GetFunction());

    target->SetAccessor(String::New("mapper"), GetMapper, SetMapper);
}

Handle<Value> JobConf::New(const Arguments& args) {
    HandleScope scope;

    JobConf* jobconf = new JobConf();
    jobconf->Wrap(args.This());
    return args.This();
}

Handle<Value> JobConf::GetMapper(Local<String> property, const AccessorInfo& info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    void* ptr = wrap->Value();
    int value = static_cast<JobConf*>(ptr)->_mapper;
    return Integer::New(value);
}
    
void JobConf::SetMapper(Local<String> property, Local<Value> value, const AccessorInfo& info) {
    Local<Object> self = info.Holder();
    Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
    void* ptr = wrap->Value();
    static_cast<JobConf*>(ptr)->_mapper = value->Int32Value();
}
