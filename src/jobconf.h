#ifndef job_conf_h
#define job_conf_h

#include <v8.h>
#include <node.h>
#include <string>
#include "mapper.h"

using namespace v8;
using namespace node;

namespace mapjs {

class JobConf : public ObjectWrap {

public:
    static Persistent<FunctionTemplate> constructor_template;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments& args);

    // inputPath
    static Handle<Value> GetInputPath(Local<String> property, const AccessorInfo& info);
    static void SetInputPath(Local<String> property, Local<Value> value, const AccessorInfo& info);

    // outputPath
    static Handle<Value> GetOutputPath(Local<String> property, const AccessorInfo& info);
    static void SetOutputPath(Local<String> property, Local<Value> value, const AccessorInfo& info);

    int _mapper;
    std::string _inputPath;
    std::string _outputPath;
};

} // namespace mapjs

#endif // job_conf_h
