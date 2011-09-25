#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;
using namespace std;

class JobConf : public ObjectWrap {

    static Persistent<FunctionTemplate> constructor_template2;
    //int _mapper;

public:
    
    static void Initialize(Handle<Object> target) {
        HandleScope scope;

        Local<FunctionTemplate> t = FunctionTemplate::New(New);
        constructor_template2 = Persistent<FunctionTemplate>::New(t);
        constructor_template2->InstanceTemplate()->SetInternalFieldCount(1);
        constructor_template2->SetClassName(String::NewSymbol("JobConf"));

        //target->Set(String::NewSymbol("JobConf"), constructor_template->GetFunction());

        //target->SetAccessor(String::New("mapper"), GetMapper, SetMapper);

        /*target->Set(String::New("setReducer"), FunctionTemplate::New(SetReducer)->GetFunction());
        target->Set(String::New("setCombiner"), FunctionTemplate::New(SetCombiner)->GetFunction());
        target->Set(String::New("setInputFormat"), FunctionTemplate::New(SetInputFormat)->GetFunction());
        target->Set(String::New("getMapper"), FunctionTemplate::New(GetMapper)->GetFunction());
        target->Set(String::New("getReducer"), FunctionTemplate::New(GetReducer)->GetFunction());
        target->Set(String::New("getCombiner"), FunctionTemplate::New(GetCombiner)->GetFunction());
        target->Set(String::New("getInputFormat"), FuncitonTemplate::New(GetInputFormat)->GetFunction());
        */
    }

    static Handle<Value> New(const Arguments& args) {
        HandleScope scope;

        JobConf* jobconf = new JobConf();
        jobconf->Wrap(args.This());
        return args.This();
    }
    /*
     static Handle<Value> GetMapper(Local<String> property, const AccessorInfo& info) {
        Local<Object> self = info.Holder();
        Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
        void* ptr = wrap->Value();
        int value = static_cast<JobConf*>(ptr)->_mapper;
        return Integer::New(value);
    }
    
     static void SetMapper(Local<String> property, Local<Value> value, const AccessorInfo& info) {
        Local<Object> self = info.Holder();
        Local<External> wrap = Local<External>::Cast(self->GetInternalField(0));
        void* ptr = wrap->Value();
        static_cast<JobConf*>(ptr)->_mapper = value->Int32Value();
    }*/
};

Persistent<FunctionTemplate> JobConf::constructor_template2;
