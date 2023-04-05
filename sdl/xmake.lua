add_requires('sdl2', {system='true'})
add_requires('SDL2_image', {system='true'})


function sdl_test(name)
    build_case(name, nil, {'sdl2', 'SDL2_image'})
end

sdl_test('sdl_case01')
sdl_test('sdl_case02')
build_case('sdl_case03', {'spdlog', 'fmt'}, {'sdl2'})
build_case('sdl_case04', {'spdlog', 'fmt'}, {'sdl2'})
build_case('sdl_case05', {'spdlog', 'fmt'}, {'sdl2', 'SDL2_image'})