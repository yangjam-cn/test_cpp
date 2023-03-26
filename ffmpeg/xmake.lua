add_requires("libavcodec", {system=true})
add_requires("libavdevice", {system=true})
add_requires("libavfilter", {system=true})
add_requires("libavformat", {system=true})
add_requires("libavutil", {system=true})

function build_case(name, libs, packages)
    target(name)
        set_kind('binary')
        add_files(name..".cpp")

        if (libs)
        then
            add_links(libs)
        end

        if(packages)
        then
            add_packages(packages)
        end
    target_end()
end

build_case('log_test', nil, {'libavutil'})