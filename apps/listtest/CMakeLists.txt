cmake_minimum_required(VERSION 3.8)

#set the project name
project(listtest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

# Get the stuff we need to use Google Test...
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.13.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


#add the executable, first for manual unit testing
add_executable(listtest listtest.cpp)
add_executable(selflist selflisttest.cpp)

#add the executable, now for using Google Test
add_executable(gtestlist gtestlist.cpp)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(gtestlist GTest::gtest_main)
include(GoogleTest)
#gtest_discover_tests(gtestlist DISCOVERY_MODE PRE_TEST)
gtest_discover_tests(gtestlist)




