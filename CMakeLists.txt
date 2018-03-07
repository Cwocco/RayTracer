project(rt C)
cmake_minimum_required(VERSION 3.9)

add_subdirectory(libft)
add_subdirectory(minilibx_macos)

file(GLOB_RECURSE HDRS ${HDRS} incs/*.h)
file(GLOB_RECURSE SRCS ${SRCS} srcs/*.c)
add_executable(rt ${HDRS} srcs/main.c
    srcs/error.c
    srcs/raytracer.c
    srcs/vector_utilities.c
    srcs/intersection.c
    srcs/light.c
    srcs/parser.c
    srcs/parser_obj.c
    srcs/parser_utils.c
    srcs/parser_libft.c
    srcs/math_utilities.c
    srcs/pixel.c
    srcs/obj_normal.c
    srcs/light_phong_shading.c
    srcs/m4.c
    srcs/m4_mul.c
    srcs/m4_rot.c
    srcs/m4_trans.c
    srcs/vector_rotate.c
    srcs/draw.c
    srcs/hook.c
    srcs/anti_alias.c
    srcs/set_perlin.c
    srcs/set_param_perlin.c
    srcs/inter_perlin.c
    srcs/main_perlin.c)
target_include_directories(rt PUBLIC incs
  /Library/Frameworks/SDL2.framework/Headers)
target_link_libraries(rt PUBLIC ft mlx pthread
  "-framework AppKit" "-framework OpenGL"
  "-F /Library/Frameworks/SDL2.framework/Versions/Current")
