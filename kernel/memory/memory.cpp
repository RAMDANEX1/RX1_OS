#include "memory.h"

namespace kernel::memory {

// Heap allocator
HeapAllocator g_heap;

void* malloc(size_t size) {
    return g_heap.allocate(size);
}

void free(void* ptr) {
    g_heap.deallocate(ptr);
}

void* calloc(size_t count, size_t size) {
    size_t total = count * size;
    void* ptr = malloc(total);
    if (ptr) {
        // TODO: Initialiser la mémoire à zéro
    }
    return ptr;
}

void* realloc(void* ptr, size_t new_size) {
    // TODO: Implémentation du reallocate
    return nullptr;
}

} // namespace kernel::memory
