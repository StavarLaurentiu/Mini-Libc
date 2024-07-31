// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int result = syscall(35, req, rem);

    if (result >= 0) return result;

    return -1;
}
