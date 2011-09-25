#include <v8.h>
#include <node.h>
#include <string>

#ifndef mapjs_h
#define mapjs_h

using namespace v8;
using namespace node;
using namespace std;

namespace mapjs {

static std::string V8StringToStdString(Local<Value> value) {
        char c[1024];
        Local<String> s = value->ToString();
        s->WriteAscii((char*)&c);
        return std::string(c);
}

} // namespace mapjs

#endif // mapjs_h
