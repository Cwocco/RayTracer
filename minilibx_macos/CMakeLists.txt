project(mlx C)
cmake_minimum_required(VERSION 3.9)

file(GLOB_RECURSE HDRS ${HDRS} *.h)
file(GLOB_RECURSE SRCS ${SRCS} *.c)
add_library(mlx mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c)
target_include_directories(mlx PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(mlx PUBLIC "-framework AppKit" "-framework OpenGL")
