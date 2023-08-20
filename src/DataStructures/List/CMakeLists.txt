project(List)

list(APPEND PUBLIC_SOURCES 
AddTwoNumbers.hpp
)

add_library(${PROJECT_NAME} INTERFACE ${PUBLIC_SOURCES})