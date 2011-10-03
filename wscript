import Options
from os import unlink, symlink, popen
from os.path import exists

srcdir = '.'
blddir = 'build'
VERSION = '0.0.1'

def set_options(opt):
    opt.tool_options('compiler_cxx')

def configure(conf):
  conf.check_tool("compiler_cxx")
  conf.check_tool("node_addon")

def build(bld):
  obj = bld.new_task_gen("cxx", "shlib", "node_addon")
  obj.target = "mapjs"
  obj.source = "src/mapper.cc src/reducer.cc src/partitioner.cc src/output_collector.cc src/jobconf.cc src/jobclient.cc src/module.cc src/async.cc"
  obj.cxxflags = ["-D_FILE_OFFSET_BITS=64", "-D_LARGEFILE_SOURCE"]

def shutdown():
  if Options.commands['clean']:
    if exists('mapjs.node'): unlink('mapjs.node')
  else:
    if exists('build/default/mapjs.node') and not exists('mapjs.node'):
      symlink('build/default/mapjs.node', 'mapjs.node')

