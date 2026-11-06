*This project has been created as part of the 42 curriculum by lseabra-*

# Philosophers

## Description

The **Philosophers** project is a classic concurrency problem that simulates the
famous "Dining Philosophers" scenario. At first glance, it may look like a
simple dinner story, but it is really a study in how multiple threads share
resources, coordinate with each other, and avoid failing states such as deadlocks
and race conditions.

This project is a practical introduction to multithreading in C. Each
philosopher behaves like an independent thread, and the forks represent shared
resources that must be protected. The real challenge is not just making the
simulation run, but making it run correctly under timing changes and without
allowing threads to block each other indefinitely.

At a deeper level, this project is about understanding what happens when several
independent tasks try to use the same resources at the same time. It is a very
good example of why software systems need synchronization, careful ownership of
shared data, and clear rules for when a thread can proceed or must wait.

### Goal

Create a simulation where philosophers alternate between eating, sleeping, and
thinking while sharing limited forks around a circular table. Each philosopher
needs two forks to eat, creating a challenge in resource allocation and thread
synchronization. The implementation must prevent **deadlocks** and **race conditions**
while ensuring philosophers do not starve and the program ends cleanly when the
rules are violated or when the required number of meals is reached.

The idea behind the project is not only to simulate a dinner; it is to understand
how to design a system where multiple actors cooperate without interfering with
one another. In other words, the problem is about coordination, fairness, and
stability under concurrency.

### Key Concepts

- **Multithreading**: Each philosopher runs in its own thread.
- **Mutual Exclusion**: Each fork is protected by a mutex, preventing two
  philosophers from using it simultaneously.
- **Synchronization**: Threads must coordinate to avoid deadlocks and inconsistent
  states.
- **Monitoring**: A dedicated thread checks whether a philosopher has exceeded the
  allowed time without eating.
- **Shared State**: The simulation must safely manage shared variables such as the
  running condition and the logged output.
- **Deadlock and Starvation**: The system must avoid infinite waiting and ensure
  progress is still possible.

## Instructions

### Compilation

Navigate to the `philo` directory and run:

```bash
cd philo
make
```

This will compile the project and generate the `philo` executable in the
`philo` directory.

**Clean Commands:**
- `make clean` - Remove object files and directories created during build
- `make fclean` - Remove all generated files including the executable
- `make re` - Clean and recompile the executable

### Execution

Run the simulation with the following syntax:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] \
  [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

**Parameters:**
- `number_of_philosophers`: Number of philosophers
- `time_to_die`: Time in milliseconds before a philosopher dies of starvation
- `time_to_eat`: Time in milliseconds it takes to eat
- `time_to_sleep`: Time in milliseconds a philosopher sleeps
- `number_of_times_each_philosopher_must_eat` *(optional)*: If specified,
  the simulation stops when all philosophers have eaten this many times

**Example:**

```bash
./philo 5 800 200 200 10
```

This simulates 5 philosophers with 800ms until starvation, 200ms eating time,
200ms sleeping time, and stops after each philosopher eats 10 times.

### Requirements

- A philosopher must eat at least once before dying.
- Philosophers must not eat if they do not have both forks.
- Each philosopher can use only the forks on their left and right sides.
- A philosopher must sleep after eating and think after sleeping.
- The program must track all actions with timestamps in milliseconds.
- Actions must be logged atomically to avoid interleaved output.

## Project Structure

```text
philo/
├── src/                                  # Source files
│   ├── main.c                            # Program entry point
│   ├── actions.c                         # Philosopher actions (eat, sleep, think)
│   ├── ft_routine.c                      # Main philosopher thread routine
│   ├── ft_monitoring_routine.c            # Monitor for starvation
│   ├── ft_init_simulation.c              # Simulation initialization
│   ├── ft_start_simulation.c             # Simulation start
│   ├── ft_parse_rules.c                  # Argument validation parsing
│   ├── ft_cleanup_simulation.c           # Resource cleanup
│   ├── ft_get_timestamp.c                # Timestamp utilities
│   ├── ft_is_running.c                   # Simulation state checks
│   ├── ft_print_action.c                 # Action logging
│   ├── ft_safe_atol.c                    # Safe string to long conversion
│   ├── ft_safe_usleep.c                  # Safe microsecond sleep
│   ├── mutex_utils.c                     # Mutex utility functions
│   └── print_utils.c                     # Print utility functions
├── include/                              # Header files
│   ├── philosophers.h                    # Main header with structures and declarations
│   ├── structs.h                         # Data structure definitions
│   ├── enums.h                           # Enumeration definitions
│   └── macros.h                          # Macro definitions
└── Makefile                              # Build configuration
```

## Resources

### Concepts studied

#### Concurrency
Concurrency is the idea that multiple tasks can be active in overlapping time
windows, even within the same process. In this project, the philosophers are
threads that share memory and resources, so their execution order is not fixed.

#### Threads
A thread is a lightweight execution flow inside a process. Each philosopher is a
thread, which gives the simulation independent behavior while still sharing the
same program state and resources.

#### Mutex
A mutex is a lock used to protect shared resources and avoid simultaneous access.
In this project, each fork is represented by a mutex, and the program also uses
mutexes for output and simulation state to avoid race conditions and mixed logs.

#### Deadlock and starvation
The challenge is not only about allowing philosophers to eat; it is also about
making sure they do not wait forever for a fork or remain unable to make progress.
Deadlock happens when everyone waits for the other to release a resource, while
starvation occurs when a philosopher is repeatedly delayed and never gets to eat.

#### Shared state and synchronization
The most important lesson in this project is understanding what is shared, what
needs protection, and how timing affects behavior. A good implementation is not
only correct in isolation; it must behave correctly when multiple threads run at
once.

### References
- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [The Dining Philosophers Problem - Austin Walters](https://austingwalters.com/multithreading-dining-philosophers-problem/)
- [Difference between Process and Thread - GeeksforGeeks](https://www.geeksforgeeks.org/operating-systems/difference-between-process-and-thread/)
- [Deadlock - GeeksforGeeks](https://www.geeksforgeeks.org/deadlock-in-operating-system/)
- [CodeVault - C Threads Playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

### AI Usage

AI was used to assist with the following aspects of this project:

- **Code Documentation**: Generating function headers to improve code
  readability and maintainability
- **Debugging Assistance**: Analyzing thread synchronization issues and
  suggesting solutions for deadlock and race condition prevention
- **Code Patterns**: Helping me follow good patterns for function and
  variable names
- **README Creation**: Structuring and formatting documentation to meet
  project requirements
