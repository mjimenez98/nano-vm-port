cmake_minimum_required(VERSION 3.17)
project(nano_vm_port C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

if (MACOS OR WIN32 OR WIN64)
    add_definitions(-DonTarget=0)
endif()

if (DDebugBSL)
    add_definitions(-DDebugBSL=1)
endif()

add_executable(nano_vm_port
        src/_console.c
        src/_cout.c
        src/_out.h
        src/_outdesc.h
        src/_stdtype.h
        src/_xtoa.c
        src/_xtoa.h
        src/admin.c
        src/hal.c
        src/hal.h
        src/ioreg.c
        src/ioreg.h
        src/opcode.h
        src/out.c
        src/out.h
        src/vm.c
        src/vm.h
        src/vmstack.c
        src/vmstack.h)
