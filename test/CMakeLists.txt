find_package(Catch2 3 REQUIRED)

project(Test)

set(SOURCE_PATH ../src)

list(APPEND PUBLIC_SOURCES list.cpp)

add_executable(${PROJECT_NAME} ${PUBLIC_SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${SOURCE_PATH})
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)

