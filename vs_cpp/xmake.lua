
-- 添加第三方库，通过system=true指定优先本地搜索
add_requires("gtest", {system=true, alias="gtest"})



build_case('case037')
build_case('test_spdlog', {'spdlog', 'fmt'})
build_case('case038', nil, {'gtest'})