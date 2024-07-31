// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <unistd.h>

off_t lseek(int fd, off_t offset, int whence) {
    /* TODO: Implement lseek(). */
    int result = syscall(8, fd, offset, whence);

    if (result >= 0)
        return result;
    else
        errno = -result;

    return -1;
}
