# nano-vm-port

## Setup

For CLion:
1. Open or import nano_vm_port project
2. Do `Run` > `Edit Configurations...`
  - Working directory: `~/nano-vm-port/tests/task_0`
  - Program arguments (optional): Any test unit you want to run (e.g. T01.exe)
3. Do `Preferences...` > `Build, Execution, Deployment` > `CMake`. Put `-DonTarget=0 -DDebugXtoa=0` in `CMake options`.
`onTarget` indicates whether this run is on the host (computer) or on the target (ATmega328p). `DebugXtoa` prints debug
strings from the target
4. Build/run

## Running Tasks

### Tasks 0-1

1. Open your terminal in `~/nano-vm-port`
2. Run `cd tests/`
3. Run `bash testRunner.sh`

Now in your project structure you can go to `tests/task_0/output.txt` to find the output for all task 0 tests.

### Task 3

For this we will use two tabs in the terminal.

1. Open your terminal in `~/nano-vm-port`
2. Run `cd tasks/task_3`
3. Compile task 3 on the target by running `bash task_3_runner.sh`
4. Open a second tab in your terminal
5. Run `ls /dev/tty.*` to know what port your chip is connected to
6. Run `screen portName` where `portName` is the port being used by your chip. This will allow us to see the serial monitor

You should now be able to see the output in your terminal
