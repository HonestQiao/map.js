#ifndef output_collector_h
#define output_collector_h

#include <v8.h>
#include <node.h>
#include <map>
#include <string>

using namespace v8;
using namespace node;
using namespace std;

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

    static std::string V8StringToStdString(Local<Value> value) {
        char c[1024];
        Local<String> s = value->ToString();
        s->WriteAscii((char*)&c);
        return std::string(c);
    }

private:
    OutputCollectorMap* _map;
};

#endif // output_collector_h
