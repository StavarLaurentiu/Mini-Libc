// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <stdlib.h>
#include <sys/mman.h>

// sources:
// https://codebrowser.dev/linux/linux/arch/x86/mm/mmap.c.html
// https://codebrowser.dev/linux/linux/mm/mremap.c.html

void *mmap(void *addr, size_t length, int prot, int flags, int fd,
           off_t offset) {
    /* TODO: Implement mmap(). */
    long result = syscall(9, addr, length, prot, flags, fd, offset);

    if (result >= 0) return (void *)result;

    errno = -result;
    return MAP_FAILED;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags) {
    /* TODO: Implement mremap(). */
    long int result = syscall(25, old_address, old_size, new_size, flags);

    if (result >= 0) return (void *)result;
    errno = -result;
    return MAP_FAILED;
}

int munmap(void *addr, size_t length) {
    /* TODO: Implement munmap(). */
    int result = syscall(11, addr, length);

    if (result >= 0)
        return result;
    else
        errno = -result;

    return -1;
}
