#ifndef reducer_h
#define reducer_h

#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

class Reducer : public ObjectWrap {

public:
    static Persistent<FunctionTemplate> constructor_template;
    static Persistent<Function> reduceFunction;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments& args);
    static Handle<Value> Reduce(const Arguments& args);
};

#endif // reducer_h
