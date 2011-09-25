#ifndef mapper_h
#define mapper_h

#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

class Mapper : public ObjectWrap {

public:
    static Persistent<FunctionTemplate> constructor_template;
    static Persistent<Function> mapFunction;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments& args);
    static Handle<Value> Map(const Arguments& args);

};



#endif // mapper_h
