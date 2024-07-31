// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>

int open(const char *filename, int flags, ...) {
    /* TODO: Implement open system call. */
    va_list valist;
    va_start(valist, flags);

    mode_t mode = va_arg(valist, mode_t);
    int result = syscall(2, filename, flags, mode);

    va_end(valist);

    if (result >= 0)
        return result;
    else
        errno = -result;

    return -1;
}
