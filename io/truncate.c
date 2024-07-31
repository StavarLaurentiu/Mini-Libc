// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

int truncate(const char *path, off_t length) {
    /* TODO: Implement truncate(). */
    int result = syscall(76, path, length);

    if (result >= 0)
        return result;
    else
        errno = -result;

    return -1;
}
