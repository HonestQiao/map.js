#include <v8.h>
#include <node.h>
#include <string.h>
#include <stdlib.h>

using namespace v8;
using namespace node;
using namespace std;

class Mapper : public ObjectWrap {

    static Persistent<FunctionTemplate> constructor_template;

public:

    static Persistent<Function> mapFunction;

    static void Initialize(Handle<Object> target) {
        HandleScope scope;

        Local<FunctionTemplate> t = FunctionTemplate::New(New);
        constructor_template = Persistent<FunctionTemplate>::New(t);
        constructor_template->InstanceTemplate()->SetInternalFieldCount(1);
        constructor_template->SetClassName(String::NewSymbol("Mapper"));

        NODE_SET_PROTOTYPE_METHOD(constructor_template, "map", Map);
        target->Set(String::NewSymbol("Mapper"), constructor_template->GetFunction());
        target->Set(String::New("map"), FunctionTemplate::New(Map)->GetFunction());
    }

    static Handle<Value> New(const Arguments& args) {
        HandleScope scope;

        //Local<Function> f = Local<Function>::Cast(args[0]);
        //mapFunction = Persistent<Function>::New(f);

        //mapFunction = Persistent<Function>::Cast(args[0]);

        Mapper* mapper = new Mapper();
        mapper->Wrap(args.This());
        return args.This();
    }

    static Handle<Value> Map(const Arguments& args) {
        HandleScope scope;

        printf("Inside Mapper.Map()\n");

        Local<Function> mapFunction = Local<Function>::Cast(args[0]);
        Local<Value> v[2];
        v[0] = Integer::New(1);
        v[1] = Integer::New(2);
        mapFunction->Call(Context::GetCurrent()->Global(), 2, v);

        return Undefined();
    }
};

Persistent<FunctionTemplate> Mapper::constructor_template;

extern "C"
void init(Handle<Object> target) {
    HandleScope scope;

    Mapper::Initialize(target);
}
