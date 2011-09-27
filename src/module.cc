#include <node.h>
#include "mapjs.h"
#include "mapper.h"
#include "reducer.h"
#include "partitioner.h"
#include "output_collector.h"
#include "jobconf.h"
#include "jobclient.h"

using namespace mapjs;

extern "C" void
init(Handle<Object> target) {
    HandleScope scope;
    Mapper::Initialize(target);
    Reducer::Initialize(target);
    Partitioner::Initialize(target);
    OutputCollector::Initialize(target);
    JobConf::Initialize(target);
    JobClient::Initialize(target);
}
