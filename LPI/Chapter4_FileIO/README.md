# Chapter 4: File I/O 

---

### Implementation
* [copy.c](copy.c)


### Useful Information
* Standard File Descriptors
| File Descriptor | Purpose         | POSIX name    | stdio stream |
| :-:             | :-:             | :-:           | :-:          |
| 0               | standard input  | STDIN_FILENO  | stdin        |
| 1               | standard output | STDOUT_FILENO | stdout       |
| 2               | standard error  | STDERR_FILENO | stderr       |



### Syscalls
* open()
* flags = bitmask that specifies the _access modes_ for the file using:
	* O_RDONLY	= open file as read only
	* O_WRONLY	= open file as write only
	* O_RDWR	= open file as read and write
 
	* O_CREAT	= Create file if it doesn't exist
	* O_TRUNC	= Truncate existing file to 0 length
	* O_APPEND	= Writes always appended to EOF (either R/W +x)
 
* bitmask permissions on created file
	* S_ISUID	= 04000
	* S_ISGID	= 02000
	* S_ISVTX	= 01000
	* S_IRUSR	= 0400
	* S_IWUSR	= 0200
	* S_IXUSR	= 0100
	* S_IRGRP	= 040
	* S_IWGRP	= 020
	* S_IXGRP	= 010
	* S_IROTH	= 04
	* S_IWOTH	= 02
	* S_IXOTH	= 01
```c
int open(const char *pathname, int flags, mode_t mode);
```

* read()
* fd = open file descriptor to read from
* buf = the address of the memory buffer for input data; size at least of _count_
* count = maximum number of bytes to read
* SUCCESS RETURN = number of bytes read
```c
ssize_t read(int fd, void *buf, size_t count);
```

* write()
* fd = file descriptor to which the data is written
* buf = address of the data to be written
* count = number of bytes to write from buffer
* SUCCESS RETURN = number of bytes written
```c
ssize_t write(int fd, const void *buf, size_t count);
```

* close()
```c
int close(int fd);
```

* lseek()
* fd = file descriptor
* offset = specifies value in byes - off_t = signed integer
* whence = basepoint from which _offset_ will be interpreted:
	* SEEK_SET = The file offset is set offset bytes from the beginning of the file. Must be Postive
	* SEEK_CUR = The file offset is adjusted by offset bytes relative to the current file offset. Can be Positive or Negative
	* SEEK_END = The file offset is set to the size of the file plus offset. In other words, offset is interpreted with repsect to the next byte after the last byte in the file. Can be Positive or Negative
```c
off_t lseek(int fd, off_t offset, int whence);
```
       


### Useful Directories/Files
* /proc/PID/fdinfo, obtain FD info on any process
	* pos = file offset
	* flags = octal showing access mode flags and open file status flags
---

## Notes


