*This project has been created as part of the 42 curriculum by lseabra-*

# Philosophers

## Description

The **Philosophers** project is a classic concurrency and synchronization
problem that simulates the famous "Dining Philosophers" scenario. Written
in C, the project explores fundamental concepts of multithreading, mutual
exclusion, and deadlock prevention through a dining simulation where multiple
philosophers share limited forks.

### Goal

Create a simulation where philosophers alternate between eating, sleeping, and
thinking while sharing limited forks around a circular table. Each philosopher
needs two forks to eat, creating a challenge in resource allocation
and thread synchronization. The implementation must prevent deadlocks and race
conditions while ensuring philosophers don't starve.

### Key Concepts

- **Multithreading**: Each philosopher runs in its own thread
- **Mutual Exclusion**: Each fork is a mutex preventing simultaneous access
- **Synchronization**: Careful coordination to ensure fairness and prevent
  deadlocks
- **Monitoring Thread**: Tracks philosopher actions and detects starvation

## Instructions

### Compilation

Navigate to the `philo` directory and run:

```bash
cd philo
make
```

This will compile the project and generate the `philo` executable in the
philo directory.

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

- A philosopher must eat at least once before dying
- Philosophers must not eat if they don't have both forks
- Each philosopher can use only the forks on their left and right sides.
- A philosopher must sleep after eating and think after sleeping
- The program must track all actions with timestamps in milliseconds
- Actions must be logged atomically to avoid interleaved output

## Project Structure

```
philo/
├── src/						# Source files
│   ├── main.c					# Program entry point
│   ├── actions.c				# Philosopher actions (eat, sleep, think)
│   ├── ft_routine.c			# Main philosopher thread routine
│   ├── ft_monitoring_routine.c	# Monitor for starvation
│   ├── ft_init_simulation.c	# Simulation initialization
│   ├── ft_start_simulation.c	# Simulation start
│   ├── ft_parse_rules.c		# Argument parsing
│   ├── ft_cleanup_simulation.c	# Resource cleanup
│   └── [other utilities]		# Helper functions
├── include/
│   └── philosophers.h			# Header with structures and declarations
└── Makefile					# Build configuration
```

## Resources

- [POSIX Threads Programming]
  (https://computing.llnl.gov/tutorials/pthreads/)
- [Deadlock - GeeksforGeeks]
  (https://www.geeksforgeeks.org/deadlock-in-operating-system/)
- [CodeVault - C Threads Playlist]
  (https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

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

