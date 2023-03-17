# Process Manager

The Process Manager is a command-line tool that allows users to manage processes on a Unix-based system. It provides users with a way to start and stop processes, send signals to running processes, and view information about running processes such as CPU and memory usage. ***Still in the process of build***

## Requirements

- Unix-based operating system
- C/C++ compiler
- GNU Make

## Installation

1. Clone the repository: `git clone https://github.com/Alperencode/Process-Manager.git`
2. Navigate to the project directory: `cd Process-Manager`
3. Compile and run the program: `make`

## Usage

The Process Manager provides the following commands:

- `start <command>`: Starts a new process with the specified command.
- `stop <pid>`: Stops the process with the specified process ID (PID).
- `signal <pid> <signal>`: Sends a signal to the process with the specified PID.
- `info <pid>`: Displays information about the process with the specified PID.
- `list`: Displays a list of all running processes.
- `help`: Displays a list of available commands.

## Examples

- Start a new process: `start ls -l`
- Stop a process: `stop 1234`
- Send a signal to a process: `signal 1234 SIGTERM`
- Display information about a process: `info 1234`
- List all running processes: `list`