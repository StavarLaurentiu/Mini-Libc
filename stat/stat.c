// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <sys/stat.h>

int stat(const char *restrict path, struct stat *restrict buf) {
    /* TODO: Implement stat(). */
    int result = syscall(4, path, buf);

    if (result >= 0)
        return result;
    else
        errno = -result;

    return -1;
}
