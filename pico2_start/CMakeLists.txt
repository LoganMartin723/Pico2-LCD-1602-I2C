# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico2 CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico2_start C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
# set(SOURCE_DIR 
#     pico2_start.c 
#     LCD_i2c.c 
#     LCD_i2c.c)

file(GLOB SOURCE_DIR
    "src/*.c"
)

list(APPEND SOURCE_DIR "pico2_start.c")

# add_executable(pico2_start pico2_start.c )
add_executable(pico2_start ${SOURCE_DIR})

pico_set_program_name(pico2_start "pico2_start")
pico_set_program_version(pico2_start "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(pico2_start 1)
pico_enable_stdio_usb(pico2_start 0)

# Personal Laptop
# set(INC_DIR "C:/Users/LogMa.000/Documents/pico_projects/pico2_start/inc")

# Work Laptop
set(INC_DIR "C:/Users/lmartin/Documents/git/Pico-Projects/pico2_start/inc")

# Add the standard library to the build
target_link_libraries(pico2_start
        pico_stdlib
        hardware_i2c
        hardware_uart
        )

# Add the standard include files to the build
target_include_directories(pico2_start PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${INC_DIR})

pico_add_extra_outputs(pico2_start)

