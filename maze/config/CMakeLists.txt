project(Configs)

FetchContent_Declare(
    boost-cmake
    GIT_REPOSITORY  https://github.com/Orphis/boost-cmake.git
)
FetchContent_MakeAvailable(boost-cmake)

add_subdirectory(tests)

#find_package(Boost COMPONENTS program_options REQUIRED)

#include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS
    ${PROJECT_SOURCE_DIR}/include/StartupConfig.h
)

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/StartupConfig.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Boost::boost Boost::program_options
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
