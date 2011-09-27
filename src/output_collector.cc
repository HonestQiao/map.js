#include "output_collector.h"

using namespace v8;
using namespace node;
using namespace mapjs;

Persistent<FunctionTemplate> OutputCollector::constructor_template;

void OutputCollector::Initialize(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    OutputCollector::constructor_template = Persistent<FunctionTemplate>::New(t);
    OutputCollector::constructor_template->InstanceTemplate()->SetInternalFieldCount(1);
    OutputCollector::constructor_template->SetClassName(String::NewSymbol("OutputCollector"));

    NODE_SET_PROTOTYPE_METHOD(OutputCollector::constructor_template, "collect", Collect);
    NODE_SET_PROTOTYPE_METHOD(OutputCollector::constructor_template, "values", Values);
    target->Set(String::NewSymbol("OutputCollector"), OutputCollector::constructor_template->GetFunction());
    target->Set(String::New("collect"), FunctionTemplate::New(Collect)->GetFunction());
    target->Set(String::New("values"), FunctionTemplate::New(Values)->GetFunction());
}

Handle<Value> OutputCollector::New(const Arguments& args) {
    HandleScope scope;

    OutputCollector* outputCollector  = new OutputCollector();
    outputCollector->Wrap(args.This());
    return args.This();
}

Handle<Value> OutputCollector::Collect(const Arguments& args) {
    HandleScope scope;

    printf("Inside OutputCollector.Collect()\n");

    std::string key = V8StringToStdString(args[0]);
    std::string value = V8StringToStdString(args[1]);

    OutputCollector* outputCollector = ObjectWrap::Unwrap<OutputCollector>(args.This());
    outputCollector->_map->insert(std::pair<std::string, std::string>(key, value));
    
    return Undefined();
}

Handle<Value> OutputCollector::Values(const Arguments& args) {
    HandleScope scope;

    printf("Inside OutputCollector.Values()\n");

    OutputCollector* outputCollector = ObjectWrap::Unwrap<OutputCollector>(args.This());

    std::string key = V8StringToStdString(args[0]);
    OutputCollectorMap* map = outputCollector->map();
    OutputCollectorMap::iterator itr;
    itr = map->find(key);

    Local<Array> array = Array::New();
    int i = 0;
    for(itr, i; itr != map->end(); ++itr, ++i) {
        array->Set(Integer::New(i), String::New((*itr).second.c_str()));
    }

    return scope.Close(array);
}

Handle<Value> OutputCollector::Join(const Arguments& args) {
    HandleScope scope;

    OutputCollector* outputCollector = ObjectWrap::Unwrap<OutputCollector>(args.This());
    OutputCollector* outputCollector2 = ObjectWrap::Unwrap<OutputCollector>(args[0]->ToObject());

    outputCollector->map()->insert(outputCollector2->map()->begin(),
        outputCollector2->map()->end());

    return Undefined();
}
