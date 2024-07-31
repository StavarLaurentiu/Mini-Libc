// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

// sources:
// https://codereview.stackexchange.com/questions/276869/implementing-malloc-with-mmap
// https://stackoverflow.com/questions/23668080/memory-reallocation-using-mremap

void *malloc(size_t size) {
    /* TODO: Implement malloc(). */
    if (size == 0) return NULL;

    void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS,
                -1, 0);
    mem_list_add(ptr, size);
    return ptr;
}

void *calloc(size_t nmemb, size_t size) {
    /* TODO: Implement calloc(). */
    size_t total_size = nmemb * size;

    void *p = malloc(total_size);

    if (p != NULL) {
        memset(p, 0, total_size);
    }

    return p;
}

void free(void *ptr) {
    /* TODO: Implement free(). */
    struct mem_list *item = mem_list_find(ptr);
    munmap(item->start, item->len);
    mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size) {
    /* TODO: Implement realloc(). */
    void *result = mremap(ptr, sizeof(ptr), size, MREMAP_MAYMOVE);
    if (result != NULL) return result;

    return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
    /* TODO: Implement reallocarray(). */
    void *result = mremap(ptr, sizeof(ptr), size * nmemb, MREMAP_MAYMOVE);
    if (result != NULL) return result;

    return NULL;
}
