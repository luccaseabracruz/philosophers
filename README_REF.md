*This project has been created as part of the 42 curriculum by lseabra-*

# Philosophers

## Description

The **Philosophers** project is a classic concurrency and synchronization
problem that simulates the famous "Dining Philosophers" scenario. The project
explores fundamental concepts of multithreading, mutual exclusion, and deadlock
prevention through a dining simulation where multiple philosophers share
limited forks.

### Goal

Create a simulation where philosophers alternate between thinking, eating, and
sleeping while sharing limited forks around a circular table. Each philosopher
needs two forks to eat, creating a challenge in resource allocation and thread
synchronization. The implementation must prevent deadlocks and race conditions
while ensuring philosophers don't starve.

### Key Concepts

- **Multithreading**: Each philosopher runs in its own thread
- **Mutual Exclusion**: Forks protected by mutexes to prevent simultaneous
  access
- **Synchronization**: Careful coordination to ensure fairness and prevent
  deadlocks
- **Timestamp Logging**: Real-time tracking of each philosopher's actions

## Instructions

### Compilation

Navigate to the `philo` directory and run:

```bash
cd philo
make
```

This will compile the project and generate the `philo` executable in the
build directory.

**Clean Commands:**
- `make clean` - Remove object files
- `make fclean` - Remove all generated files
- `make re` - Clean and recompile

### Execution

Run the simulation with the following syntax:

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] \
  [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

**Parameters:**
- `number_of_philosophers`: Number of philosophers (and forks)
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

- A philosopher must eat at least once before dying
- Philosophers must not eat if they don't have both forks
- A philosopher must sleep after eating and think after sleeping
- The program must track all actions with timestamps in milliseconds
- Actions must be logged atomically to avoid interleaved output

## Project Structure

```
philo/
├── src/                     # Source files
│   ├── main.c              # Program entry point
│   ├── actions.c           # Philosopher actions (eat, sleep, think)
│   ├── ft_routine.c        # Main philosopher thread routine
│   ├── ft_monitoring_routine.c  # Monitor for starvation
│   ├── ft_init_simulation.c     # Simulation initialization
│   ├── ft_start_simulation.c    # Simulation start
│   ├── ft_parse_rules.c         # Argument parsing
│   ├── ft_cleanup_simulation.c  # Resource cleanup
│   └── [other utilities]        # Helper functions
├── include/
│   └── philosophers.h   # Header with structures and declarations
└── Makefile            # Build configuration
```

## Resources

### Documentation & Articles

- [Dining Philosophers Problem - Wikipedia]
  (https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming]
  (https://computing.llnl.gov/tutorials/pthreads/)
- [Mutex Synchronization - Linux Man Pages]
  (https://man7.org/linux/man-pages/man3/pthread_mutex_init.3p.html)

### Recommended Reading

- "The Little Book of Semaphores" by Allen B. Downey - Excellent resource
  on synchronization
- "Operating System Concepts" (Silberschatz, Galvin, Gagne) - Chapter on
  Process Synchronization
- [Deadlock - GeeksforGeeks]
  (https://www.geeksforgeeks.org/deadlock-in-operating-system/)

### AI Usage

AI was used to assist with the following aspects of this project:

- **Code Documentation**: Generating function headers and inline comments
  to improve code readability and maintainability
- **Testing Strategy**: Helping identify edge cases and potential race
  conditions to test
- **Debugging Assistance**: Analyzing thread synchronization issues and
  suggesting solutions for deadlock prevention
- **Error Handling**: Improving error messages and validation logic
- **README Creation**: Structuring and formatting documentation to meet
  project requirements

