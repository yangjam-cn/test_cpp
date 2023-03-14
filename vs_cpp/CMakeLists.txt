function(build_case name)
    add_executable(${name} ${name}.cpp)
endfunction()

build_case(case036)