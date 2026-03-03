# 25/02/06
## what I've learned

### Threads vs Proccesses
- Threads are similar to proccess when we see from the synchronous execution. In
Other words, executing at the same time. But while proccesses are totaly independent,
isolated and don't share anything besides the hardware that it's beeing used, threads
share resources as memory for example. 
- Processes have more security, are more eficcient int terms of allocation and 
are more encapsulated. Threads, in the other hand, are lighter in terms of a single
task, not copying all resources, is faster and share resources wich make it more
application oriented.
- The disavantage of threads is that they can cause problems such as race conditions
and deadlocks that can compromise the whole execution of a problem/application.

### Thread problems
