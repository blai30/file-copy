# CSC 415 - Project 2 - File copy

## Student Name : Brian Lai

## Student ID   : 916818167

## Build Instructions
### Windows
```
gcc filecopy.c [filename]
```
or if `make` is configured in %PATH% with MinGW or Cygwin
```
make
```

### Mac OS X
```
make
```

### Linux
```
make
```

## Run Instructions
### Windows
If no filename was given
```
./a
```
If filename was given while building, where filename is the file's name
```
./filename
```
If `make` was used
```
./fc
```

### Mac OS X
```
./fc
```

### Linux
```
./fc
```

## strace/dtruss output
```
Welcome to the File Copy Program by Brian Lai
Enter the name of the file to copy from:
LICENSE
Enter the name of the file to copy to:
LICENSEE
File Copy Successful, 1074 bytes copied
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  // Reading the file, called 56 times because of the buffer size,
  // how big the source file is, and other internal system libraries
  0.00    0.000000           0        56           read

  // Writing to the file, called 56 times because of the buffer size,
  // how big the destination file is, and other internal system libraries
  0.00    0.000000           0        56           write

  // Closing files, called twice for source file and destination file,
  // two more calls for file descriptors
  0.00    0.000000           0         4           close

  // Used to read permissions from source file
  0.00    0.000000           0         1           stat

  // Determines what to do with the file based on the file descriptor
  // Reads from source file and write to destination file
  // Other two calls are for internal system libraries
  0.00    0.000000           0         4           fstat

  // Called at the end of the file before returning 0
  // Used to move the read/write pointer of a file descriptor
  // Returned -1 so an error occurred when trying to move the pointer
  0.00    0.000000           0         1         1 lseek

  // Allocates memory for file desciptors, sets permissions,
  // offsets the start of memory address
  0.00    0.000000           0         5           mmap

  // Set protection for permissions on memory
  0.00    0.000000           0         4           mprotect

  // Release memory starting at an address
  0.00    0.000000           0         1           munmap

  // Finds location of the pointer to memory and end of memory address
  0.00    0.000000           0         3           brk

  // Check if file exists with read access
  0.00    0.000000           0         3         3 access

  // Executes this program in memory, called at the very beginning
  0.00    0.000000           0         1           execve

  // Used to write permissions from source file to destination file
  0.00    0.000000           0         1           chmod
  0.00    0.000000           0         1           arch_prctl

  // Open files, called twice for source file and destination file,
  // two more calls for internal system libraries
  0.00    0.000000           0         4           openat
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                   145         4 total
```
