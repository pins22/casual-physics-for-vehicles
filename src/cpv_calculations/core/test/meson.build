test_sources = ['coretest.cpp']
testcore = executable('testcore', test_sources,
                     include_directories : inc,
                     dependencies : [
                        gtest_dep,
                        gmock_dep],
                     link_with : corelib)
test('core tests', testcore) 
