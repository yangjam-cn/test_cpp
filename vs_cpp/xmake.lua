--[[
    name: 要编译文件的前缀
    libs：可选项，需要第三方库时，通过表{}传递需要链接的三方库，
--]]
function build_case(name, libs)
    target(name)
        set_kind('binary')
        add_files(name..'.cpp')
        if (libs ~= nil)
        then
            add_links(libs)
        end
    target_end()
end

build_case('case037')
build_case('test_spdlog', {'spdlog', 'fmt'})
build_case('case038')