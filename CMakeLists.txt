#Define the CMake version
cmake_minimum_required(VERSION 3.16)

#Set the version for C and C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

#Load and run the Pico's CMake
# This is the git submoduled version of the PicoSDK
include (pico-sdk/pico_sdk_init.cmake)

#Call the project "roboticArm" with the languages followed
project(roboticArm C CXX ASM)

#According to PicoSDK, this must be called after the project() command
pico_sdk_init()

#Creating an executable target with the same name as the project name: "roboticArm"
add_executable(${PROJECT_NAME}
        src/main.cpp
        src/stepper_motor.cpp
        src/stepper_motor.cpp
)

#No clue what this does
pico_add_extra_outputs(${PROJECT_NAME})

# For the linker step, show the linker that we need to add our project's library and pico's
target_link_libraries(${PROJECT_NAME} pico_stdlib)

# This makes the compiler see our header files from our include folder
target_include_directories(${PROJECT_NAME} PRIVATE include)







# # Set minimum required version of CMake
# cmake_minimum_required(VERSION 3.12)
# #include build functions from Pico SDK
# include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
# # Set name of project (as PROJECT_NAME) and C/C++ Standards
# project(roboticArm C CXX ASM)
# set(CMAKE_C_STANDARD 11)
# set(CMAKE_CXX_STANDARD 17)

# #target_include_directories(${PROJECT_NAME} PRIVATE ${include})
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)


# # Creates a pico-sdk subdirectory in our project for the libraries
# pico_sdk_init()
# # point out the CMake, where to find the executable source file
# add_executable(${PROJECT_NAME}
#         ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
#         ${CMAKE_CURRENT_SOURCE_DIR}/include/stepper_motor.hpp
#         ${CMAKE_CURRENT_SOURCE_DIR}/src/stepper_motor.cpp
# )
# # create map/bin/hex/uf2 files.
# pico_enable_stdio_usb(${PROJECT_NAME} 1)
# pico_add_extra_outputs(${PROJECT_NAME})
# # Pull in our pico_stdlib which pulls in commonly used features (gpio, timer-delay etc)
# target_link_libraries(${PROJECT_NAME}
#             pico_stdlib
# )