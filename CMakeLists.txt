cmake_minimum_required(VERSION 3.17)
project(nano_vm_port C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

if (OnNano)
    add_definitions(-DOnNano=0)
endif()

if (DebugXtoa)
    add_definitions(-DDebugXtoa=0)
endif()

add_executable(nano_vm_port
        src/BSL/_console.c
        src/BSL/_cout.c
        src/BSL/_out.h
        src/BSL/_outdesc.h
        src/BSL/_stdtype.h
        src/BSL/_xtoa.c
        src/BSL/_xtoa.h
        src/admin.c
        src/HAL/hal.c
        src/HAL/hal.h
        src/ioreg.c
        src/ioreg.h
        src/opcode.h
        src/HAL/out.c
        src/HAL/out.h
        src/vm.c
        src/vm.h
        src/vmstack.c
        src/vmstack.h)
