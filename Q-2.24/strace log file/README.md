## List of System Calls made:
### 1. **read():** 
```
ssize_t read(int fd, void *buf, size_t count);
```
Line 39 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
read(0, "sample.txt\n", 1024)           = 11
```
Line 45 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
read(3, "This is a sample file.\r\n\r\nThe co"..., 8192) = 241
```
In the above 2 read() statements:
* The file descriptor(int fd) is mentioned
* The text being read is in buffer(void *buf)
* The count (size_t - unsigned integer in POSIX) is bytes read.
* The number of bytes read is returned (0 indicates EOF), and the file position is advanced by this number.
* ssize_t is the same as size_t, but is a signed type - read ssize_t as “signed size_t”. ssize_t is able to represent the number -1, which is returned by several       as a way to indicate error.

### 2. **write():** 
```
ssize_t write(int fd, const void *buf, size_t count);
```
Line 38 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
write(1, "Enter name of the source file : ", 32) = 32
```
In the above  write() statement:
* The file descriptor(int fd) is mentioned
* The text being wriiten is in buffer(void *buf)
* The count (size_t - unsigned integer in POSIX) is  bytes read (32 in the case of Line 38).
* On success, the number of bytes written is returned. On error -1 is returned, and errno is set to indicate the error.

### 3. **execve():** 
```
int execve(const char *pathname, char *const argv[],char *const envp[]);
```
Line 1 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
execve("./answer.o", ["./answer.o"], 0x7ffc8cf35e38 /* 47 vars */) = 0
```

In the above execve() statement:
* The path name is the object file to be executed
* *argv* is an array of pointers to strings passed to the new program as its command-line arguments (in the above case is "answer.o").
* *envp* is an array of pointers to strings, conventionally of the form key=value, which are passed as the environment of the new program.The envp array must be terminated by a NULL pointer(in our case is a hexadecimal address).
* On success, execve() returns 0, on error -1 is returned,and errno is set to indicate the error.

### 4. **openat():** 
```
int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode);
```
Line 6 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
```
Line 10 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
```
Line 40 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
openat(AT_FDCWD, "sample.txt", O_RDONLY) = 3
```
Line 43 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
openat(AT_FDCWD, "output.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666) = 4
```

In the above 4 openat() statements:
* If pathname is relative and dirfd is the special value AT_FDCWD, then pathname is interpreted relative to the current working directory of the calling process
* The pathnames are given as arguments.
* Flags are O_RDONLY|O_CLOEXEC, O_RDONLY, O_WRONLY|O_CREAT|O_TRUNC
* mode_t mode is given as 0666
* Returned values are used as the **file descriptor** arguments for all the respective system calls.

### 5. **close():** 
```
int close(int fd);
```
Line 9 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
close(3)                                = 0
```
Line 22 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
close(3)                                = 0
```
Line 49 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
close(3)                                = 0
```
Line 51 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
close(4)                                = 0
```

In the above 4 close() statements:
* close() returns 0 on success and -1 on error
* int fd is the file descriptor which is to be closed.
> 3 was the file descriptor of "/etc/ld.so.cache" , "/lib/x86_64-linux-gnu/libc.so.6" , "sample.txt" and 4 was the file descriptor of "output.txt".
Refer [4. openat()](https://github.com/khushi201me127/os-assignment/edit/main/Q-2.24/strace%20log%20file#4-openat)

### 6. **newfstatat():** 
```
 int newfstatat(int dirfd, const char *restrict pathname,
                struct stat *restrict statbuf, int flags);
```
Line 7 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=68379, ...}, AT_EMPTY_PATH) = 0
```
Line 15 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=2216304, ...}, AT_EMPTY_PATH) = 0
```
Line 33 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
newfstatat(1, "", {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}, AT_EMPTY_PATH) = 0
```
Line 37 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
newfstatat(0, "", {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}, AT_EMPTY_PATH) = 0
```
Line 44 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
newfstatat(3, "", {st_mode=S_IFREG|0770, st_size=241, ...}, AT_EMPTY_PATH) = 0
```
Line 46 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
newfstatat(4, "", {st_mode=S_IFREG|0770, st_size=0, ...}, AT_EMPTY_PATH) = 0
```

In the above 6 newfsatat() statements:
* The newfstatat() function shall obtain information about an open file associated with the file descriptor, and shall write it to the area pointed to by buf.
* **int dirfd** contains the file descriptor
* struct stat *restrict statbuf is a buffer pointing to a struct stat
* If pathname is relative and dirfd is the special value AT_FDCWD,
  then pathname is interpreted relative to the current working
  directory of the calling process.

  If pathname is absolute, then dirfd is ignored.
* newfstatat() returns 0 on success and -1 on error.
* flags can either be 0 or include one or more of the following
  flags ORed:
   o  AT_EMPTY_PATH (pathname is an empty string ,operate on a file reffered to by dirfd.
   o  AT_NO_AUTOMOUNT
   o  AT_SYMLINK_NOFOLLOW
      
### 7. **mmap():** 
```
void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
```
Line 4 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f4c6d802000
```
Line 8 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
mmap(NULL, 68379, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f4c6d7f1000
```
Lines 17-21 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
mmap(NULL, 2260560, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f4c6d5c9000
mmap(0x7f4c6d5f1000, 1658880, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7f4c6d5f1000
mmap(0x7f4c6d786000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x7f4c6d786000
mmap(0x7f4c6d7de000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x214000) = 0x7f4c6d7de000
mmap(0x7f4c6d7e4000, 52816, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f4c6d7e4000
```
Line 23 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f4c6d5c6000
```
In the above 8 mmap() statements:
* void *addr contains the pointer to the starting address for the new mapping.
  * If addr is NULL:
    * Kernel chooses the address at which to create the mapping. This is the most portable method of creating a new mapping
  * If addr is not NULL:
    * Kernel takes it as a hint about where to place the mapping
  
* size_t length argument specifies the length of the mapping
* int prot is  the desired memory protection of the mapping which are PROT_READ, PROT_WRITE, PROT_EXEC, PROT_NONE or a bitwise combination of them.
* int flags is the argument determines whether updates to the mapping are visible to other processes mapping the same region, and whether updates are carried through to the underlying file.
* Flags can be be of many types out of which a few are MAP_PRIVATE, MAP_FIXED, MAP_ANONYMOUS, MAP_DENYWRITE etc.
* int fd is the file descriptor
  >3 in the case of the reading of the "sample.txt" file
* The contents of a file mapping, are initialized using length bytes starting at offset offset in the file (or other object)
referred to by the file descriptor fd.  
  > Offset must be a multiple of the page size
* Returns a pointer to the mapped area.  On error, the value MAP_FAILED (that is, (void *) -1) is returned, and errno is set to indicate the error.

### 8. **pread64():** 
```
ssize_t pread(int fd, void *buf, size_t count, off_t offset);
```
Lines 12-14 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
pread64(3, "\4\0\0\0 \0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0"..., 48, 848) = 48
pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0i8\235HZ\227\223\333\350s\360\352,\223\340."..., 68, 896) = 68
```
Lines 16 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
```

In the above  pread64() statements:
* The pread64() function pread() reads up to *int count* bytes from file descriptor *int fd* at *off_t offset* (from the start of the file) into the buffer starting at *buf*. The file offset is not changed.

* pread64() returns the number of bytes read and returns 0 at EOF.

### 9. **brk():** 
```
int brk(void *addr);
```
Line 2 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
brk(NULL)                               = 0x55d8d92dc000
```
Line 35 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
brk(NULL)                               = 0x55d8d92dc000
```
Line 36 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
brk(0x55d8d92fd000)                     = 0x55d8d92fd000
```
In the above 3 brk() statements:
* brk() sets the end of the data segment to the value specified by void *addr, when that value is reasonable, the system has enough memory, and the process does not exceed its maximum data size.
* 0x55d8d92dc000 is the address in our case.

### 10. **mprotect():** 
```
int mprotect(void *addr, size_t len, int prot);
```
Lines 28-30 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
mprotect(0x7f4c6d7de000, 16384, PROT_READ) = 0
mprotect(0x55d8d7c9a000, 4096, PROT_READ) = 0
mprotect(0x7f4c6d83c000, 8192, PROT_READ) = 0
```
In the above 3 mprotect() statements:
* mprotect() changes the access protections for the calling process's memory pages containing any part of the address range in the interval [addr, addr+len-1]
* *int prot* is the desired memory protection needed as discussed in [**mmap()**](https://github.com/VincentPaulV/CS252-OS-Assignment/blob/main/Q1-2.24/README.md#7-mmap)
* Returns 0 on succesful execution and -1 on errors.


### 11. **arch_prctl():** 
```
#include <asm/prctl.h> //Definition of ARCH_* constants
#include <sys/syscall.h> //Definition of SYS_* constants
#include <unistd.h>

int syscall(SYS_arch_prctl, int code, unsigned long addr);
int syscall(SYS_arch_prctl, int code, unsigned long *addr);
```
Line 3 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
arch_prctl(0x3001 /* ARCH_??? */, 0x7fff97b05810) = -1 EINVAL (Invalid argument)
```
Line 24 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
arch_prctl(ARCH_SET_FS, 0x7f4c6d5c6740) = 0
```
In the above 2 arch_prctl() statements:
*  arch_prctl() sets architecture-specific process or thread state.
   *int code* selects a subfunction and passes argument *addr* to it.
* addr is interpreted as either an unsigned long for the "set" operations, or as an unsigned long *, for the "get" operations.

> Line 3 gives us an error with error code EINVAL which indicates that code is not a valid subcommand i.e. ARCH_???

> Line 24 uses ARCH_SET_FS as the code, hence "setting" the 64-bit base for the FS register to address 0x7f4c6d5c6740.

### 12. **munmap():** 
```
int munmap(void *addr, size_t length);
```
Line 32 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
munmap(0x7f4c6d7f1000, 68379)           = 0
```
In the above munmap() statement:
* The munmap() system call deletes the mappings for the specified address range, and causes further references to addresses within the range to generate invalid memory references.
  >Here we are unmapping 0x7f4c6d7f1000, 68379 which was mapped in Line 8
  ```
  mmap(NULL, 68379, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f4c6d7f1000
  ```

* The region is also automatically unmapped when the process is terminated.


  >Closing the file descriptor does not unmap the region.

### 13. **access():** 
```
int access(const char *pathname, int mode);
```
Line 5 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
```
In the above access() statement:
* access() checks whether the calling process can access the file *pathname*.
*  herewe are trying to access *pathname* = "/etc/ld.so.preload" with mode as R_OK (testing whether the file exists and grants read operation).

  >Here we are getting error as EN0ENT 
  i.e. A component of pathname does not exist or is a dangling symbolic link.

### 14. **lseek():** 
```
off_t lseek(int fd, off_t offset, int whence);
```
Line 52 of [**strace_log**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)
```
lseek(0, -1, SEEK_CUR)                  = -1 ESPIPE (Illegal seek)
```
In the above lseek() statement:
* lseek() repositions the file offset of the open file description associated with the file descriptor fd to the argument offset according to the directive whence
* Here the whence is is SEEK_CUR and the file offset is set to its current location plus offset bytes.
* lseek() returns the resulting offset location as measured in bytes from the beginning of the file.On error, the value (off_t) -1 is returned and errno is set to indicate the error.

  >Here we are getting error as ESPIPE
  i.e. fd is associated with a pipe, socket, or FIFO.


