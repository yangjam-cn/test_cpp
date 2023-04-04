add_requires("libavcodec", {system=true})
add_requires("libavdevice", {system=true})
add_requires("libavfilter", {system=true})
add_requires("libavformat", {system=true})
add_requires("libavutil", {system=true})

add_requires('spdlog', {system=true})


build_case('log_test', nil, {'libavutil'})
build_case('ffmpeg_ls', nil, {'libavutil', 'libavformat'})
build_case('get_info', nil, {'libavformat', 'libavutil', 'spdlog'})
build_case('ff_test04', nil, {'libavformat', 'libavcodec', 'libavutil', 'spdlog'})