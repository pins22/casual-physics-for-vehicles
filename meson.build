project('cpv', 'cpp')

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')
gmock_dep = gtest_proj.get_variable('gmock_dep')

rapidjson_proj = subproject('rapidjson')
rapidjson_dep = rapidjson_proj.get_variable('rapidjson_dep')


subdir('src')

 