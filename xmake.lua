
set_project('StudyCpp')

set_version('0.0.1')

-- 设置c++11标准
set_languages('cxx14')
-- 设置工具链为clang
set_toolchains('clang')
-- 设置优化等级为O1
set_optimize('fast')
-- 启用所有警告，并当做编译错误处理
set_warnings('all', 'error')

add_cxxflags('-v')

includes('vs_cpp', 'ffmpeg')

--[[
usage: name为文件名去后缀部分
    xmake b(build) [name] -- 编译程序
    xmake r(run) [name]   -- 运行程序
]]--