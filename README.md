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
2. Run `cd tasks/task_0/`
3. Run `bash task_0_runner.sh`

Now in your project structure you can go to `tests/task_0/output.txt` to find the output for all task 0 tests.

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

You should now be able to see the output in your terminal

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

You should now be able to see the output in your terminal

## Task 5

1. Open your terminal in `~/nano-vm-port`
2. Run `ls /dev/tty.*` to know what port your chip is connected to. Copy this value
3. In your editor, go to `tasks/task_5/task_5_runner.sh` and replace `/dev/tty.*` with the port value you just copied
4. Repeat step 3 but in the file `tasks/task_5/SerialLoader.cs` for the value in variable `_serialPort.PortName` (line 120)
5. Back to the terminal, install _mono_ using Homebrew by running `brew install mono`
6. Run `cd tasks/task_5`
7. Compile the serial loader (~~with the `LoadFromFile` flag~~) by doing (~~`mcs -d:LoadFromFile SerialLoader.cs`~~) `mcs SerialLoader.cs`
8. Execute the binary file by doing `mono SerialLoader.exe`
