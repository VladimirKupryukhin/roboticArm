#Define the CMake version
cmake_minimum_required(VERSION 3.16)

#Set the version for C and C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


#Load and run the Pico's CMake
# This is the git submoduled version of the PicoSDK
include (pico-sdk/pico_sdk_init.cmake)
include (FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/pico_sdk_import.cmake)
include (FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

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
pico_enable_stdio_usb(${PROJECT_NAME} 1)


# add_library(freertos         
#         FreeRTOS-Kernel/croutine.c
#         FreeRTOS-Kernel/event_groups.c
#         FreeRTOS-Kernel/list.c
#         FreeRTOS-Kernel/queue.c
#         FreeRTOS-Kernel/stream_buffer.c
#         FreeRTOS-Kernel/tasks.c
#         FreeRTOS-Kernel/timers.c
#         FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/port.c
#         FreeRTOS-Kernel/portable/ThirdParty/GCC/RP2040/idle_task_static_memory.c
# )


# For the linker step, show the linker that we need to add our project's library and pico's
target_link_libraries(${PROJECT_NAME} pico_stdlib FreeRTOS-Kernel FreeRTOS-Kernel-Heap4)

# This makes the compiler see our header files from our include folder
target_include_directories(${PROJECT_NAME} PRIVATE 
        include
        # FreeRTOS-Kernel/include/portable/ThirdParty/GCC/RP2040/include
        # FreeRTOS-Kernel/include
)










