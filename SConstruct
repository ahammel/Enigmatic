import os

ENV = Environment(CXX="clang++", CCFLAGS="--std=c++11")
ENV['ENV']['TERM'] = os.environ['TERM']

SOURCES = Glob("src/*.cpp")
OBJECT_LIST = ENV.Object(source=SOURCES)

PROGRAM = ENV.Program('test_runner', ['test/test_main.cpp'] + SOURCES)
TEST_ALIAS = Alias('test', [PROGRAM], PROGRAM[0].path)
AlwaysBuild(TEST_ALIAS)
