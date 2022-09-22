# System Calls Application


To run the test run:

```
make
```

## Process calls made 

Systems calls that might be needed internally for the program to run:

- exit: Terminate the execution of the program
- open: For opening a file to read. (target file provided)
- create: Used when creating a new file (where we store our output)
- close: For closing file streams once we finish writing on them.
- fork: for creating new processes. Could be used for starting an internal new process
- exec: For replacing the process, Could have been used together with a `fork` to control the processes
- wait: For parent process that may wait for termination of a child process
- read to fd 1: for detecting user typing a character
- write to fd 1: For printing output
- mmap: Mapping files into memory (out.txt and test.txt) Might have been used to map the txt files into memory
- access: Checks user's permission for a file. Might have been used before reading a file
- send: To send messages between processes, it might have been used for internal communication between different processes
- receive: Receive messages from processes, that might have been used for internal communication between different processes
- link, symlink: Creating names for files. It might have been used when naming the created files based on our inputs



![](/../img/2022-09-22-01-15-31.png)


