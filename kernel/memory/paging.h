#pragma once

#include <cstdint>
#include <cstddef>

namespace kernel::memory {

// Gestionnaire de pagination
class PageManager {
public:
    void init();
    void enable();
    
    // Mapping de pages
    void map_page(uint64_t virtual_addr, uint64_t physical_addr, bool writable = true);
    void unmap_page(uint64_t virtual_addr);
    
    // Traduction d'adresses
    uint64_t virtual_to_physical(uint64_t virtual_addr);
    
private:
    uint64_t* m_pml4 = nullptr;  // Page Map Level 4 (pour 64-bit)
};

// Initialisation et activation de la pagination
void init_paging();
void enable_paging();

} // namespace kernel::memory
