
# Almost all CMake files should start with this 
# You should always specify a range with the newest
# And oldest tested Versions of CMake. This will ensure
# You pick up the best policies.

cmake_minimum_required(VERSION 3.1...3.24)


# This is your project statement. You should always list all languages;
# Listing the version is nice here since it set lots of useful varialbes
project(
    ModerCMakeExample
    VERSION 1.0
    LANGUAGES CXX)


# If you set any CMAKE_ variables, that can go here.
# (But usually don't do this, except maybe for c++ standard)


# Find packages go here

# You should usually split this into folders but this is a simple examples 


# This is a "Default " library and will match the *** variable setting.
# Other common choices are STATIC, SHARED, and MODULE
# Including header files here helps IDEs but is not required.
# Output libname matches target name, with the usual extensions on your system
add_library(MyLibExample simple_lib.cpp simple_lib.hpp)


# Link each target with other targets or add options, etc.

# Adding something we can run - Output name matches targer name
add_executable(MyExample simple_example.cpp)

# Make sure you link your targets with this command. It can also link libraries and
# even flags so linking a targer that does not exist will not give a configure-time error

target_link_libraries(MyExample PRIVATE MyLibExample)

## [main]

# This part is so the Modern CMake book can verify this example build. For your code,
# you'll probably want tests too
enable_testing()
add_test(NAME MyExample COMMAND MyExample)