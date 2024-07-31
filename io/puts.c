// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <string.h>

int puts(const char *str) {
    int len = strlen(str);

    syscall(1, 1, str, len);
    syscall(1, 1, "\n", 1);

    return len + 1;
}
