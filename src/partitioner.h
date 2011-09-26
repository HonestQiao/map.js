#ifndef partitioner_h
#define partitioner_h

#include <v8.h>
#include <node.h>
#include <string>
#include "mapjs.h"

using namespace v8;
using namespace node;
using namespace std;
using namespace mapjs;

namespace mapjs {

class Partitioner : public ObjectWrap {

public:
    static Persistent<FunctionTemplate> constructor_template;
    //static Persistent<Function> mapFunction;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments& args);
    static Handle<Value> GetPartition(const Arguments& args);
};

} // namespace mapjs

#endif // partitioner_h
