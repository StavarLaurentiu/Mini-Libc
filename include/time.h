#ifndef _TIME_H
#define _TIME_H

// Sources:
// https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/
// https://www.gnu.org/software/libc/manual/html_node/Time-Types.html

// Types
typedef int clock_t;
typedef long long time_t;
typedef unsigned long size_t;

// Structures
struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#endif
