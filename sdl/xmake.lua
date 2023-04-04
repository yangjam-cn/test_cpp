add_requires('sdl2', {system='true'})
add_requires('SDL2_image', {system='true'})


function sdl_test(name)
    build_case(name, nil, {'sdl2', 'SDL2_image'})
end

sdl_test('sdl_case01')
sdl_test('sdl_case02')