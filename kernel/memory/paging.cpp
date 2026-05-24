#include "paging.h"

namespace kernel::memory {

// Gestionnaire de pagination
PageManager g_page_manager;

// Page Directory Entry (PDE) - 64-bit
struct PDE {
    uint64_t present : 1;
    uint64_t writable : 1;
    uint64_t user_mode : 1;
    uint64_t write_through : 1;
    uint64_t cache_disabled : 1;
    uint64_t accessed : 1;
    uint64_t reserved : 1;
    uint64_t page_size : 1;
    uint64_t reserved2 : 4;
    uint64_t address : 40;
    uint64_t reserved3 : 11;
    uint64_t no_execute : 1;
};

void init_paging() {
    // TODO: Initialiser les tables de pages
    // TODO: Configurer le registre CR3 (PDBR)
    // TODO: Configurer le registre CR4 pour la pagination
}

void enable_paging() {
    // TODO: Activer la pagination en mode long (64-bit)
}

} // namespace kernel::memory
