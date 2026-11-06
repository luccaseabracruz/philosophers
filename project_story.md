# Philosophers: Project Story

## The Story

The Philosophers project became intuitive to me when I understood that **threads**
are **concurrent tasks** running inside one process and **sharing its memory**. The
problem was no longer just philosophers eating around a table. It was several
tasks trying to use the same things at the same time. That was where the idea
clicked for me.

Understanding **mutexes** took more work. I first had to decide what needed to be
protected and how many mutexes the simulation needed. In my implementation,
each fork was represented directly by a mutex. I did not create a separate
fork-resource object and then add a mutex around it; the mutex represented the
fork and prevented two philosophers from using it at the same time. I also
needed a mutex for terminal output, so messages from different threads would
not mix together, and another mutex for the shared state that says whether the
simulation is still running. I found it useful to think about each lock in
terms of the shared thing it protected, and to make sure the thread that
acquired a mutex released it when it was done.

I built the project in steps. I started with the structure and input parsing,
then added the philosopher threads and their actions. After that, I added a
monitor to check whether a philosopher had starved. When the main behavior was
in place, I worked on cases that made the simulation difficult to reason about,
including the order philosophers started and the case where there was only one
philosopher.

One of the hardest problems was a **deadlock** at the beginning of the simulation.
Philosophers could each pick up one fork and then wait indefinitely for the
other, leaving the simulation unable to make progress. I changed the startup
order so alternating philosopher threads started first, with a short pause
before starting the others. The goal was to reduce the synchronized competition
for forks at startup.

I also added `ft_safe_usleep`, a function which waits in short intervals and checks 
whether the simulation is still running. Before that, a philosopher could begin a 
long eat or sleep delay and continue waiting even after the simulation had stopped.
With the check, philosophers can stop promptly when the monitor ends the simulation. 
I was especially proud of this improvement because it made the shutdown behavior 
feel more realistic, even though it was not the main simulation algorithm itself.

As the project grew, I added stricter input checks, guards around pthread and
mutex operations, and a safer number conversion for values that could overflow.
I later separated the headers into files for structures, enums, and macros.
This was the first project where I used many macros, and I liked making the
code's structure cleaner as I learned more about the problem.

Testing concurrent behavior was difficult because the threads did not always
produce the same timing. I tested runs in the terminal and watched the
simulation's behavior. I also used AddressSanitizer and Valgrind to look for
memory problems, and GDB to inspect and switch between threads while debugging.
This was a real algorithm and logic challenge: I had to reason about which
thread could access each fork, what happened when the simulation stopped, and
how to make the pieces work together.

The part I am proudest of is the `safe_usleep` behavior, along with the clean
project structure. The project taught me to look at a concurrent problem by
asking what is shared, what needs protection, and how the whole system behaves
when timing changes.

## How The Project Took Shape

1. Set up the project and parse the program arguments.
2. Create the philosopher thread structure and implement their actions.
3. Add timestamps and a monitor for starvation and simulation completion.
4. Address startup deadlock behavior and the single-philosopher case.
5. Make eating and sleeping interruptible when the simulation stops.
6. Improve input validation, overflow handling, and pthread/mutex error checks.
7. Organize the headers and polish the action logging.

The simulation uses one mutex per fork, plus a print mutex and a running-state
mutex. That is one mutex for each shared fork, one for atomic output, and one
for the shared stop state. Each fork is modeled by its mutex; there is no
separate fork object in the implementation.