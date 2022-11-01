# Question 4.22

## Statement
Write a multithreaded program that calculates various statistical values for a list of numbers. 
This program will be passed a series of numbers on the command line and will then create three separate worker threads. 
One thread will determine the **average** of the numbers, the second will determine the **maximum** value, and the third will determine the **minimum** value. 
For example, suppose your program is passed the integers 90 81 78 95 79 72 85 

The program will report
>         The average value is 82
>         The minimum value is 72
>         The maximum value is 95

The variables representing the average, minimum, and maximum values will be stored globally. 
The worker threads will set these values, and the parent thread will output the values once the workers have exited. 
(We could obviously expand this program by creating additional threads that determine other statistical values, such as median and standard deviation).
  
## Instructions
[multithreading.c](https://github.com/khushi201me127/os-assignment/blob/main/Q-4.22/multithreading.c) - source code for the program.
  
#### Instructions to follow while compiling this code
Enter the following on the command line<br>
1. ``` gcc multithreading.c -o multithreading -lm -lpthread ```

> -lpthread is very essential to run the code as without it the code won't compile 
The data is then provided on the command line:<br> 
  
2. ``` ./multithreading {data... } ```

The result: maximum, minimum, average, median and standard deviation is display on the command line.
  
## Results
  The statistical values obtained are displayed below
  
  #### 1. For odd number of data elements 
  ![result_stat1](https://github.com/khushi201me127/os-assignment/blob/main/Q-4.22/screenshots/picodd.PNG)
  
  #### 2. For even number of data elements
  ![result_stat2](https://github.com/khushi201me127/os-assignment/blob/main/Q-4.22/screenshots/piceven.PNG)

The following thread fuctions and declarations were used:
  1. ``` pthread_t {thread name }```
      * Used to declare a thread.
      * store the thread ID of the new thread.
      * example : `pthread_t t1;`
  
  2. ``` int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine) (void *arg), void *arg); ```
      * example : `pthread_create(&t1,NULL,&avg,NULL);`
      * First argument is a pointer to pthread_t type that is the data type for threads as per "pthreads.h" library which have already been defined as t1, t2, t3,t4,t5         respectively.
      * Second argument is attr pointing to a pthread_attr_t structure whose contents are used at thread creation time to determine attributes for the new thread. This         structure is initialized using pthread_attr_init() function.In the above case attr is given as NULL, as we want the thread is created with default attributes.
      * Third argument is a pointer to the start_routine of a thread that is the function invoked on the thread creation. In our case the functions invoked are                 *avg*, *min*, *max*,*med*, *standard* respectively.
      * Fourth Argument is *the sole* argument passed to start_routine() when invoked during thread creation. In our case it is NULL i.e. no arg is passed to our               start_routine.
      * On success, these functions return 0; on error, they return a nonzero error number.
  
  3. ```  void pthread_exit(void *status); ```
      * Used to terminate a thread.
      * example : `pthread_exit(NULL);`
  
  4. ``` int pthread_join(pthread_t thread, void **status); ```
      * Used to wait for the termination of a thread
      * example : `pthread_join(t1,NULL);`

 ## References
  * [https://www.homeworklib.com/qaa/1707080/write-in-c-program-write-a-multi-threaded-program](https://www.homeworklib.com/qaa/1707080/write-in-c-program-write-a-multi-threaded-program)
  * [https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-pthread-create-create-thread](https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-pthread-create-create-thread)
  * [https://github.com/RoystonDsouza42/CS252] 
