#ifndef job_client_h
#define job_client_h

#include <v8.h>
#include <node.h>
#include <stdio.h>
using namespace v8;
using namespace node;

namespace mapjs {

class JobClient : public ObjectWrap {

public:
    static Persistent<FunctionTemplate> constructor_template;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments& args);
    static Handle<Value> Run(const Arguments& args);
};

} // namespace mapjs

#endif // job_client_h
