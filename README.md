–––––––––––––––––––––––––––––––
THE DINING PHILOSOPHERS PROBLEM
–––––––––––––––––––––––––––––––


In computer science, the dining philosophers problem is an example often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

42's Philosophers project is teaching you to work with multipiple threads that share and work on the same memory. If a variable is accessed by more than one thread, it will need a mutex to protect it. Mutex stand for mutual exclusion in order to avoid data races. Avoiding deadlocks is a key element in making sure all philosophers can eat, and optimizing the program to run smooth and fast is the point of this exercise.


Mandatory part:

Implement dining philosophers problem with threads and mutexes.

    pthread_create() - creates a new thread
    pthread_join() - waits until certain thread finishes, not to have zombie threads in the end.
    pthread_mutex_init() - creates a mutex
    pthread_mutex_destroy() - destroys a mutex
    pthread_mutex_lock() - locks a mutex
    pthread_mutex_unlock() - unlocks a mutex
    usleep() - makes a thread to sleep for microseconds
    gettimeofday() - returns number of microseconds passed since 1 January 1970
    malloc() - allocates memory on the heap
    free() - frees allocated memory from heap
    printf() - prints to stdoutput

Allowed functions: memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, thread_mutex_lock, pthread_mutex_unlock

Not allowed: libft
