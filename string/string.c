// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

#define MAX_SIZE 1000001

// Sources:
// https://www.geeksforgeeks.org/c-program-copy-string-without-using-strcpy-function/
// https://www.geeksforgeeks.org/concatenating-two-strings-in-c/
// https://www.geeksforgeeks.org/write-your-own-strcmp-which-ignores-cases/
// https://www.techiedelight.com/implement-strstr-function-c-iterative-recursive/
// https://www.geeksforgeeks.org/write-memcpy/
// https://aticleworld.com/memcmp-in-c/

char *strcpy(char *destination, const char *source) {
    /* TODO: Implement strcpy(). */
    if (destination == NULL) return NULL;

    size_t offset = 0;
    while (source[offset] != '\0') {
        destination[offset] = source[offset];
        offset++;
    }

    destination[offset] = '\0';

    return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
    /* TODO: Implement strncpy(). */
    if (destination == NULL) return NULL;

    size_t offset = 0;
    while (source[offset] != '\0' && len > 0) {
        destination[offset] = source[offset];
        offset++;
        len--;
    }

    if (len > 0) destination[offset] = '\0';

    return destination;
}

char *strcat(char *destination, const char *source) {
    /* TODO: Implement strcat(). */
    size_t dest_offset = 0, source_offset = 0;
    while (destination[dest_offset] != '\0') dest_offset++;
    while (source[source_offset] != '\0') {
        destination[dest_offset + source_offset] = source[source_offset];
        source_offset++;
    }

    destination[dest_offset + source_offset] = '\0';

    return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
    /* TODO: Implement strncat(). */
    size_t dest_offset = 0, source_offset = 0;
    while (destination[dest_offset] != '\0') dest_offset++;
    while (source[source_offset] != '\0' && len > 0) {
        destination[dest_offset + source_offset] = source[source_offset];
        source_offset++;
        len--;
    }
    destination[dest_offset + source_offset] = '\0';

    return destination;
}

int strcmp(const char *str1, const char *str2) {
    /* TODO: Implement strcmp(). */
    size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;

        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}

int strncmp(const char *str1, const char *str2, size_t len) {
    /* TODO: Implement strncmp(). */
    size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && len > 0) {
        if (str1[i] > str2[i])
            return 1;
        else if (str1[i] < str2[i])
            return -1;

        i++;
        len--;
    }

    if (len > 0 && str1[i] == '\0') return -1;
    if (len > 0 && str2[i] == '\0') return 1;
    return 0;
}

size_t strlen(const char *str) {
    size_t i = 0;

    for (; *str != '\0'; str++, i++)
        ;

    return i;
}

char *strchr(const char *str, int c) {
    /* TODO: Implement strchr(). */
    size_t i = 0;
    while (*(str + i) != '\0') {
        if (*(str + i) == c) return str + i;

        i++;
    }

    return NULL;
}

char *strrchr(const char *str, int c) {
    /* TODO: Implement strrchr(). */
    size_t len = strlen(str) - 1;
    while (len > 0) {
        if (*(str + len) == c) return str + len;

        len--;
    }

    return NULL;
}

char *strstr(const char *haystack, const char *needle) {
    /* TODO: Implement strstr(). */
    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);
    size_t i;

    for (i = 0; i < haystack_len; i++) {
        const char *to_compare = haystack + i;
        if (strncmp(to_compare, needle, needle_len) == 0) {
            return to_compare;
        }
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
    /* TODO: Implement strrstr(). */
    size_t i;
    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);
    size_t i_max = -1;

    for (i = 0; i < haystack_len; i++) {
        if (strncmp(haystack + i, needle, needle_len) == 0) {
            i_max = i;
        }
    }

    if (i_max != (size_t)-1) return haystack + i_max;
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
    /* TODO: Implement memcpy(). */
    if (destination == NULL) return NULL;

    size_t offset = 0;
    while (num > 0) {
        ((char *)destination)[offset] = ((const char *)source)[offset];
        offset++;
        num--;
    }

    return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
    /* TODO: Implement memmove(). */
    char aux[MAX_SIZE];
    size_t i;

    for (i = 0; i < num; i++) aux[i] = ((const char *)source)[i];
    for (i = 0; i < num; i++) ((char *)destination)[i] = aux[i];

    return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
    /* TODO: Implement memcmp(). */
    size_t i;

    for (i = 0; i < num; i++) {
        if (((const char *)ptr1)[i] > ((const char *)ptr2)[i])
            return 1;
        else if (((const char *)ptr1)[i] < ((const char *)ptr2)[i])
            return -1;
    }

    return 0;
}

void *memset(void *source, int value, size_t num) {
    /* TODO: Implement memset(). */
    size_t i;
    for (i = 0; i < num; i++) {
        ((char *)source)[i] = value;
    }

    return source;
}
