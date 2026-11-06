# Philosophers

## Project Overview

Philosophers is a C project about threads, processes, and synchronization. It
models philosophers sharing forks around a table and explores how to coordinate
concurrent work without data races or starvation.

## Simulation Rules

### Table And Actions

- Philosophers sit around a circular table with one fork between each pair.
- Each philosopher repeatedly thinks, eats, and sleeps.
- Eating requires holding both neighboring forks. Once finished eating, a
  philosopher puts the forks down and sleeps; after waking, they think again.
- There are as many forks as philosophers. Philosopher `1` sits next to the last
  philosopher; each other philosopher sits between the preceding and following
  numbers.
- With one philosopher, only one fork is available.
- Philosophers do not communicate or know whether another philosopher is about
  to die.

### End Conditions

The simulation stops when a philosopher dies of starvation. If the optional
meal-count argument is supplied, it also stops once every philosopher has eaten
at least that many times.

## Program Arguments

Both implementations accept:

```text
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Number of philosophers and forks.
- `time_to_die`: Milliseconds without starting a meal before a philosopher
  starves, measured from the simulation start or the start of their last meal.
- `time_to_eat`: Milliseconds required to eat; both forks are held during this
  time.
- `time_to_sleep`: Milliseconds spent sleeping.
- `number_of_times_each_philosopher_must_eat`: Optional number of meals each
  philosopher must complete for the simulation to stop.

## Logging And Correctness

Print every philosopher state change using this format, where the timestamp is
in milliseconds and `X` is the philosopher number:

```text
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Messages must not overlap. A death message must appear within 10 ms of the
philosopher's actual death. The program must not have data races, and
philosophers should avoid starvation.

## Implementation Parts

### Mandatory: Threads And Mutexes

- Program name: `philo`.
- Submit the mandatory implementation in `philo/`.
- Represent every philosopher with a separate thread.
- Protect each fork with a mutex so philosophers cannot take the same fork at
  the same time.

Allowed functions: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`,
`gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`,
`pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, and
`pthread_mutex_unlock`.

### Bonus: Processes And Semaphores

- Program name: `philo_bonus`.
- Submit the bonus implementation in `philo_bonus/`.
- Represent every philosopher with a separate process. The main process
  supervises the simulation and is not a philosopher.
- Place all forks in the middle of the table. Do not model individual fork
  states in memory; use a semaphore to represent the number of available forks.
- The bonus is assessed only if the mandatory part is complete and works
  without malfunctioning.

Allowed functions: `memset`, `printf`, `malloc`, `free`, `write`, `fork`,
`kill`, `exit`, `pthread_create`, `pthread_detach`, `pthread_join`, `usleep`,
`gettimeofday`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, and
`sem_unlink`.

## Shared Project Requirements

- Write the project in C and follow the 42 Norm. Bonus files and functions are
  checked too; a Norm error can result in a failing evaluation.
- Do not use global variables.
- Prevent crashes and undefined behavior. Free heap-allocated memory and clean
  up resources when they are no longer needed; memory leaks are not accepted.
- Use `cc` with `-Wall -Wextra -Werror`.
- The Makefile must avoid unnecessary relinking and provide `$(NAME)`, `all`,
  `clean`, `fclean`, and `re` rules.
- Libft is not authorized.
- The bonus must have a `bonus` rule and keep bonus-only files in `_bonus.c` or
  `_bonus.h` files, unless the subject specifies otherwise.
- The mandatory and bonus parts are evaluated separately.

## README And Submission

Provide an English `README.md` at the repository root. It must include:

- A first line, italicized, reading `This project has been created as part of
  the 42 curriculum by [author name(s)].`, with the actual author name or names
  in place of the placeholder.
- A **Description** section explaining the project and its goal.
- An **Instructions** section explaining compilation and execution.
- A **Resources** section with relevant references and an explanation of how
  AI was used, including which tasks or project parts it supported.

Submit the work to the assigned Git repository; only repository contents are
graded. Testing programs are encouraged, although they are not submitted or
graded. If Deepthought grades the project, an error in any section can stop the
evaluation.

During peer evaluation, you may be asked to make a small change to demonstrate
your understanding. Be ready to explain your reasoning and modify the project in
your usual development environment.

## Using AI During The Project

AI can help with repetitive work, exploring approaches, or designing tests, but
generated results can be incomplete or incorrect and may carry risks or biases.
Check, question, and test anything you use, and only keep work you understand
and can explain. Seek peer review as another check; peers can provide context
and perspectives that an AI may miss. Use prompting to clarify the problem, not
to outsource understanding of a key part of the project.