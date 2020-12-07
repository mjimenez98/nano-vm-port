# nano-vm-port

## Team Information

### Team #1

- Miguel Jimenez - 40022302
- Mehdi Skouri-Saidi - 40057700
- Mohd Tanvir - 40014010
- Justin Weller - 40026870

## Setup

### Prerequisites
- gcc
- avr-gcc
- avr-dude

### IDE
For CLion:
1. Open or import nano_vm_port project
2. Do `Run` > `Edit Configurations...`
  - Working directory: `~/nano-vm-port/tests/task_0`
  - Program arguments (optional): Any test unit you want to run (e.g. T01.exe)
3. Do `Preferences...` > `Build, Execution, Deployment` > `CMake`. Put `-DOnNano=0 -DDebugXtoa=0` in `CMake options`.
`OnNano` indicates whether this run is on the host (computer) or on the target (ATmega328p). `DebugXtoa` prints debug
strings from the target
4. Build/run

## Running Tasks

### Task 0

1. Open your terminal in `~/nano-vm-port`
2. Run `cd tasks/task_0/`
3. Run `bash task_0_runner.sh compile` to compile `aunit.c` and run the tests using this executable. In the future,
now that you have compiled `aunit.c`, you can do `bash task_0_runner.sh` to only run the tests

Now in your project structure you can go to `tests/task_0/output.txt` to find the output for all task 0 tests.

## Task 1

2. Open your terminal in `~/nano-vm-port`
3. Run `cd tasks/task_1/`
4. Run `bash task_1_runner.sh`

You should now be able to see the output in your terminal.

## Task 2

See `src/BSL/` and `src/HAL/` for the separation.

### Task 3

For this we will use two tabs in the terminal.

1. Open your terminal in `~/nano-vm-port`
2. Run `ls /dev/tty.*` to know what port your chip is connected to. Copy this value
3. In your editor, go to `tasks/task_3/task_3_runner.sh` and replace `/dev/tty.*` with the port value you just copied
4. Back to your terminal, run `cd tasks/task_3`
5. Compile task 3 on the target by running `bash task_3_runner.sh`
6. Open a second tab in your terminal
7. Run `screen portName` where `portName` is the port being used by your chip. It should still be in your clipboard. 
This will allow us to see the serial monitor

You should now be able to see the output in your terminal.

### Task 4

For this we will use two tabs in the terminal.

1. Open your terminal in `~/nano-vm-port`
2. Run `ls /dev/tty.*` to know what port your chip is connected to. Copy this value
3. In your editor, go to `tasks/task_4/task_4_runner.sh` and replace `/dev/tty.*` with the port value you just copied
4. Back to your terminal, run `cd tasks/task_4`
5. Compile task 4 on the target by running `bash task_4_runner.sh`
6. Open a second tab in your terminal
7. Run `screen portName` where `portName` is the port being used by your chip. It should still be in your clipboard. 
This will allow us to see the serial monitor

You should now be able to see the output in your terminal.

## Task 5

1. Open your terminal in `~/nano-vm-port`
2. Run `ls /dev/tty.*` to know what port your chip is connected to. Copy this value
3. In your editor, go to `tasks/task_5/task_5_runner.sh` and replace `/dev/tty.*` with the port value you just copied
4. Repeat step 3 but in the file `tasks/task_5/SerialLoader.cs` for the value in variable `_serialPort.PortName` (line 120)
5. Back to the terminal, install _mono_ using Homebrew by running `brew install mono` if you have not already
6. Run `cd tasks/task_5`
7. Compile task 5 on the target by running `bash task_5_runner.sh`
8. Compile the serial loader by doing `mcs -d:LoadFromFile SerialLoader.cs`
9. Execute the binary file by doing `mono SerialLoader.exe <test-path>` (e.g. `mono SerialLoader.exe ../../tests/ST03.exe`)

## Task 6

For this we will use two tabs in the terminal.

1. Open your terminal in `~/nano-vm-port`
2. Run `ls /dev/tty.*` to know what port your chip is connected to. Copy this value
3. In your editor, go to `tasks/task_6/task_6_runner.sh` and replace `/dev/tty.*` with the port value you just copied
4. Back to your terminal, run `cd tasks/task_6`
5. Compile task 6 on the target by running `bash task_6_runner.sh`
6. Open a second tab in your terminal
7. Run `screen portName` where `portName` is the port being used by your chip. It should still be in your clipboard. 
This will allow us to see the serial monitor

You should now be able to see the output in your terminal.

## Task 7

For this we will use two tabs in the terminal.

1. Open your terminal in `~/nano-vm-port`
2. Run `ls /dev/tty.*` to know what port your chip is connected to. Copy this value
3. In your editor, go to `tasks/task_7/task_7_runner.sh` and replace `/dev/tty.*` with the port value you just copied
4. Back to your terminal, run `cd tasks/task_7`
5. Compile task 7 on the target by running `bash task_6_runner.sh`

You should now be able to see your onboard LED blinking.
