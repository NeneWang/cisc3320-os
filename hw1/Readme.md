# System Calls Application


To run the test run:

```
make
```

## Process calls made 

Systems calls that might be needed internally for the program to run:

- exit: Terminate the execution of the program
- open: For opening file to read.
- create: Used when creating a new file (where we store our ouput)
- close: For closing filestreams once we finish writting on them.
- fork: for reating new processes
- exec: For replacing the process
- wait: For paren process that may wait for a termination of a child process
- read from fd: for detecting user typing a character
- write to fd1: For printing output
- mmap: Mapping files into memory (out.txt and test.txt)
- access: Checks user's permission for a file
- send: To send messages between processes
- receive: Receive messages from processes
- link, symlink: Creating name for files





