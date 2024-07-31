// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int ftruncate(int fd, off_t length) {
    /* TODO: Implement ftruncate(). */
    int result = syscall(77, fd, length);

    if (result >= 0)
        return result;
    else
        errno = -result;

    return -1;
}
