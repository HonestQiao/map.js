#include "async.h"

using namespace v8;
using namespace node;
using namespace mapjs;

Persistent<FunctionTemplate> Async::constructor_template;

void Async::Initialize(Handle<Object> target) {
    HandleScope scope;

    Local<FunctionTemplate> t = FunctionTemplate::New(New);
    constructor_template = Persistent<FunctionTemplate>::New(t);
    constructor_template->InstanceTemplate()->SetInternalFieldCount(1);
    constructor_template->SetClassName(String::NewSymbol("Async"));

    NODE_SET_PROTOTYPE_METHOD(constructor_template, "runAsync", RunAsync);
    target->Set(String::NewSymbol("Async"), constructor_template->GetFunction());
}

Handle<Value> Async::New(const Arguments &args) {
    HandleScope scope;

    Async *async = new Async(args[0]->Int32Value(), args[1]->Int32Value());
    async->Wrap(args.This());
    return args.This();
}

int Async::EIO_Async(eio_req *req) {
    async_request *async_req = (async_request *)req->data;
    Async *async = async_req->async;
    async_req->result = async->x * async->y;
    return 0;
}

int Async::EIO_AsyncAfter(eio_req *req) {
    HandleScope scope;

    ev_unref(EV_DEFAULT_UC);
    async_request *async_req = (async_request *)req->data;

    Local<Value> argv[1];
    argv[0] = Integer::New(async_req->result);

    TryCatch try_catch;

    async_req->cb->Call(Context::GetCurrent()->Global(), 1, argv);

    if (try_catch.HasCaught())
        FatalException(try_catch);

    async_req->cb.Dispose();

    async_req->async->Unref();
    free(async_req);

    return 0;
}

Handle<Value> Async::RunAsync(const Arguments &args) {
    HandleScope scope;

    Local<Function> cb = Local<Function>::Cast(args[0]);
    Async *async = ObjectWrap::Unwrap<Async>(args.This());

    async_request *async_req = (async_request *)malloc(sizeof(async_request));
    async_req->cb = Persistent<Function>::New(cb);
    async_req->async = async;

    eio_custom(EIO_Async, EIO_PRI_DEFAULT, EIO_AsyncAfter, async_req);

    ev_ref(EV_DEFAULT_UC);
    async->Ref();

    return Undefined();
}
