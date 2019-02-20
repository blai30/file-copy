Welcome to the File Copy Program by Brian Lai
Enter the name of the file to copy from:
LICENSE
Enter the name of the file to copy to:
LICENSEE
File Copy Successful, 1074 bytes copied
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  // Reading the file, called 56 times
  0.00    0.000000           0        56           read

  // Writing to the file, called 56 times
  0.00    0.000000           0        56           write

  // Closing files, called twice for source file and destination file,
  // two more calls for the mmaps used to print this output
  0.00    0.000000           0         4           close

  // Determines what to do with the file based on the file descriptor
  // Reads from source file and write to destination file
  // Other two calls are for internal source libraries like printing the strace mmap
  0.00    0.000000           0         4           fstat

  // Called at the end of the file before returning 0
  // Used to move the read/write pointer of a file descriptor
  // Returned -1 so an error occurred when trying to move the pointer
  0.00    0.000000           0         1         1 lseek

  // 
  0.00    0.000000           0         5           mmap

  // 
  0.00    0.000000           0         4           mprotect

  // 
  0.00    0.000000           0         1           munmap

  // 
  0.00    0.000000           0         3           brk

  // 
  0.00    0.000000           0         3         3 access

  // 
  0.00    0.000000           0         1           execve

  // 
  0.00    0.000000           0         1           arch_prctl

  // Open files, called twice for source file and destination file,
  // two more calls for internal source libraries
  0.00    0.000000           0         4           openat
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                   143         4 total
