cmake_minimum_required(VERSION 3.10)
project(MyShapesProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(
    include
    C:/MyLibs/xege/include  # 添加第三方库的头文件路径
)

# 添加库文件目录
link_directories(
    C:/MyLibs/xege/lib  # 添加第三方库的库文件路径
)

# 添加源文件
file(GLOB_RECURSE SOURCES "src/*.cpp" "main.cpp")

# 创建可执行文件
add_executable(MyShapes ${SOURCES})

# 链接库
target_link_libraries(MyShapes
    graphics  # 你的第三方库
    gdi32
    gdiplus
)