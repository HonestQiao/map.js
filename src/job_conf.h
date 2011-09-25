#ifndef job_conf_h
#define job_conf_h

#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

class JobConf : public ObjectWrap {

public:
    static Persistent<FunctionTemplate> constructor_template;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments& args);
    static Handle<Value> GetMapper(Local<String> property, const AccessorInfo& info);
    static void SetMapper(Local<String> property, Local<Value> value, const AccessorInfo& info);
    
    int _mapper;
};

//Persistent<FunctionTemplate> JobConf::constructor_template;

#endif // job_conf_h
