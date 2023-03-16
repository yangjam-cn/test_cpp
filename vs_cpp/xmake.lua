
-- 添加第三方库，通过system=true指定优先本地搜索
add_requires("gtest", {system=true, alias="gtest"})

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
            add_packages('gtest')
        end
    target_end()
end

build_case('case037')
build_case('test_spdlog', {'spdlog', 'fmt'})
build_case('case038', nil, true)