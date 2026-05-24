#pragma once

#include <cstddef>
#include <cstdint>

namespace kernel::memory {

// Structure d'un bloc mémoire
struct MemoryBlock {
    size_t size;
    bool used;
    MemoryBlock* next;
};

// Allocateur de heap simple
class HeapAllocator {
public:
    void* allocate(size_t size);
    void deallocate(void* ptr);
    
private:
    MemoryBlock* m_head = nullptr;
};

// Fonctions d'allocation mémoire
void* malloc(size_t size);
void free(void* ptr);
void* calloc(size_t count, size_t size);
void* realloc(void* ptr, size_t new_size);

} // namespace kernel::memory
