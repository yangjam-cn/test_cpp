add_requires('sdl2', {system='true'})
add_requires('SDL2_image', {system='true'})


build_case('sdl_case01', 'sdl2')
build_case('sdl_case02', {'sdl2', 'SDL2_image'})
build_case('sdl_case03', {'spdlog', 'fmt'}, {'sdl2'})
build_case('sdl_case04', {'spdlog', 'fmt'}, {'sdl2', 'SDL2_image'})
build_case('sdl_case05', {'spdlog', 'fmt'}, {'sdl2', 'SDL2_image'})
build_case('sdl_case06', {'spdlog', 'fmt'}, {'sdl2', 'SDL2_image'})