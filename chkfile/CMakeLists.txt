cmake_minimum_required(VERSION 3.0)
project(chkfile)
set(SOURCE chkfile.cpp)
find_package(Boost COMPONENTS filesystem REQUIRED)
add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} Boost::filesystem)