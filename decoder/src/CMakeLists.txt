set(PROJECT_NAME "adbs-decode")



file( GLOB SRCS *.cpp *.h)

find_package(fmt)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} fmt::fmt)
# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
