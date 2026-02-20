*This project has been created as part of the 42 curriculum by mmusquer.*

# Philosophers

## Description

The Dining Philosophers problem is a classic synchronization challenge in computer science. A number of philosophers sit around a table with a bowl of spaghetti. They alternately eat, sleep, and think. To eat, a philosopher needs two forks. If a philosopher doesn't eat within a given time, they die.

The goal is to implement a simulation where every philosopher stays alive as long as possible, using concurrent programming techniques. The mandatory part uses **threads and mutexes**, while the bonus part uses **processes and semaphores**.

### Key technical choices

- **Mandatory**: each philosopher is a thread sharing memory. Forks are individual mutexes. Deadlock is prevented by alternating fork pick-up order based on philosopher ID (even/odd). A central monitoring thread detects starvation.
- **Bonus**: each philosopher is a separate process created with `fork()`. Forks are represented by a semaphore initialized to the number of philosophers. A second semaphore (initialized to `nb_philo - 1`) limits concurrent access to prevent deadlock. Each process runs an internal monitoring thread to detect its own death, since processes don't share memory. The parent process uses `waitpid` to detect termination and `kill` to stop remaining children.

## Instructions

### Compilation

```bash
make
make bonus
make clean
make fclean
make re
```

### Execution

```bash
./philo <nb_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [nb_meals]
./philo_bonus <nb_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [nb_meals]
```

### Examples

```bash
./philo 5 800 200 200        # 5 philosophers, no one should die
./philo 4 410 200 200        # tight timing, should survive
./philo 1 800 200 200        # single philosopher, will die
./philo 5 800 200 200 7      # stops after 7 meals each
```

## Resources

### References

- [POSIX Threads Programming — LLNL](https://hpc-tutorials.llnl.gov/posix/)
- [sem_overview — Linux man page](https://man7.org/linux/man-pages/man7/sem_overview.7.html)
- [fork(2) — Linux man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- And other student insight on the subject

### AI usage

AI was used as a **learning and guidance tool** during the bonus part of the project. It was used to :

- Understand the new concepts of the bonus (semaphores, sem_open, sem_wait, sem_post)
- Help to structure the code
- help when impossibility to find a bug

