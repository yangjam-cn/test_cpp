add_requires('opencv4', {system='true'})

build_case('cv_case01', nil, {'opencv4'})
build_case('cv_case02', {'spdlog', 'fmt'}, {'opencv4'})