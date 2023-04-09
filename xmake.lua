
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
-- 添加编译选项
add_cxxflags('-g', '-debug')
-- 设置目标文件输出目录
set_targetdir('./')

add_includedirs('include')

--[[
    name: 要编译文件的前缀
    libs：可选项，需要第三方库时，通过表{}传递需要链接的三方库，
    pakages: 可选项，依赖的第三方包，如需要pkg-config导入的包
--]]
function build_case(name, libs, packages)
    target(name)
        set_kind('binary')
        add_files(name..".cpp")

        if (libs)
        then
            add_links(libs)
        end

        if (packages)
        then
            add_packages(packages)
        end
    target_end()
end

includes('cpp', 'ffmpeg', 'opencv', 'sdl')

--[[
usage: name为文件名去后缀部分
    xmake b(build) [name] -- 编译程序
    xmake r(run) [name]   -- 运行程序
]]--