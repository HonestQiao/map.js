#include <node.h>

#include "mapper.h"
#include "job_conf.h"

extern "C" void
init(Handle<Object> target) {
    HandleScope scope;
    Mapper::Initialize(target);
    JobConf::Initialize(target);
}
