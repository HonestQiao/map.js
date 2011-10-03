#ifndef async_h
#define async_h

#include <cstdlib>
#include <node.h>
#include <node_buffer.h>

using namespace v8;
using namespace node;

namespace mapjs {

class Async : public ObjectWrap {
    static Persistent<FunctionTemplate> constructor_template;
    int x, y;

    struct async_request {
        Persistent<Function> cb;
        Async *async;
        int result;
    };

public:
    Async(int xx, int yy) : x(xx), y(yy) {}

    static void Initialize(Handle<Object> target);
    static Handle<Value> New(const Arguments &args);
    static int EIO_Async(eio_req *req);
    static int EIO_AsyncAfter(eio_req *req);
    static Handle<Value> RunAsync(const Arguments &args);
};

} // namespace mapjs

#endif // async_h
