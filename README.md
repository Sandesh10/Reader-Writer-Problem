# Reader-Writer-Problem

The readers/writers problem is one of the classic problems to test synchronization and concurrency mechanism. This problem occurs when a data area is to be shared among several concurrent processes. 

The data area could be a file, a block of main memory, or even a bank of processor register. Some of the processes may want to only to read the content of the shared area, whereas others may want to update the shared object. We distinguish between these two types of processes by referring to those processes that are interested in only reading as readers, and to the rest as writers.The problems deal with situations in which many processes must access the same shared memory at one time,  some reading and some writing, with the natural constraint that no process may access the share for reading or writing while another process is in the act of writing to it. 

Following are the two readers-writers problems:

1) First Reader Writer Problem:
“No reader shall be kept waiting unless a writer has already obtained permission to use the shared object.” This is also called readers-preference.

2) Second Reader Writer Problem:
The second readers-writers problem requires that “once a writer is ready, that writer performs its write as soon as possible.” This is also called writers- preference.

