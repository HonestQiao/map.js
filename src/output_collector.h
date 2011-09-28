#ifndef output_collector_h
#define output_collector_h

#include <v8.h>
#include <node.h>
#include <map>
#include <string>
#include "mapjs.h"

using namespace v8;
using namespace node;
using namespace std;
using namespace mapjs;

namespace mapjs {

typedef std::multimap<std::string, std::string> OutputCollectorMap;

class OutputCollector : public ObjectWrap {

public:
    OutputCollector() : _map(new std::multimap<string, string>()) {};
    ~OutputCollector() { delete _map; };

    std::multimap<string, string>* map() const { return _map; }

    static Persistent<FunctionTemplate> constructor_template;
    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments& args);
    static Handle<Value> Collect(const Arguments& args);
    static Handle<Value> Values(const Arguments& args);
    static Handle<Value> Join(const Arguments& args);
    static Handle<Value> Keys(const Arguments& args);

private:
    OutputCollectorMap* _map;
};

} // namespace mapjs

#endif // output_collector_h
