
# Q 2.24 Solution

Note: All the information written below is specific to Ubuntu operating system

---
### The C Program: [**answer.c**](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/answer.c)

Prompting the user for the name of the source file:
```
char ch, source_file[20], target_file[20];
FILE *source, *target;
printf("Enter name of the source file : ");
scanf("%s", source_file);
```

Here we define 2 pointers to FILE type and they will be assigned the address of a file descriptor, that is, an area of memory that will be associated with an input or output stream.

Opening Source File for Reading
Including all necessary error checking, ensuring that the source file exists:
```
// Open one file for reading
source = fopen(source_file, "r");
if (source == NULL)
{
    printf("Cannot open file %s \n", source_file);
    exit(0);
}
```
Prompting the user for the name of the destination file:
```
printf("Enter name of the destination file : ");
scanf("%s",target_file);
```

Opening Destination File for Writing
Including all necessary error checking, ensuring that the destination file exists:
```
// Open another file for writing
target = fopen(target_file, "w");

if (target == NULL)
{
   fclose(source);
   printf("Cannot open file %s \n", target_file);
   exit(0);
}
```

Reading Content from Source File and Pasting it into Destination file.
```
// Read contents from file
while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);
```
Closing the file pointers:
```
printf("File copied successfully.\n");

fclose(source);
fclose(target);
```

## Requirements

You will require the GNU Compiler Collection (GCC) in order to be able to run the program **answer.c**

[Steps to install GCC compiler on Ubuntu](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/#installing-gcc-on-ubuntu)

---

## Steps to run the program
 - Open the terminal and navigate to the directory where the file **answer.c** is present
 - Create a text file (used as an input file) from which you would like to copy the contents in the same directory as the source file.
 - `gcc answer.c -o answer.o`
 - `./answer.o`
 - The program will prompt to enter the name of the input file and output file
 -  If it has been executed successfully, a "File copied successfully" message will be displayed

## Screenshots
- Running the program 

![App Screenshot](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/screenshots/pic1.PNG)

---

### Command to create a log file in which the system calls are logged
- `strace -ostrace_log ./answer.o`
- The program will prompt the user to provide the name of the input file and output file
- If it has been executed successfully, a "Success" message will be displayed

## Screenshots
- Running the strace command to trace the system calls

[View the strace_log file](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/strace%20log%20file/strace_log)

![App Screenshot](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/screenshots/pic2.PNG)
![App Screenshot](https://github.com/khushi201me127/os-assignment/blob/main/Q-2.24/screenshots/pic3.PNG)


---

## Implementation

- A program was written in C language for copying the contents from an existing file and paste the contents into a new file (which does not exist before executing the program).
- The input file was sample.txt from which the contents were copied.
- The output file was output.txt to which the copied content was pasted.
- A strace_log file was also created in which all the system calls were logged.



## Reference(s)
- https://forgetcode.com/c/577-copy-one-file-to-another-file\
- The code for the assignment has been taken from the above website
- https://man7.org/linux/man-pages/dir_all_by_section.html
- The above link was used to refer to the different system calls logged in the **strace_log** file
- https://github.com/sankronaldo/CS-252-OS-Assignment
- This repository was referred to make the readme file.
