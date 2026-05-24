#pragma once

#include <cstdint>

namespace kernel::cpu {

// Lire/Écrire les MSR
uint64_t read_msr(uint32_t msr);
void write_msr(uint32_t msr, uint64_t value);

// Lire/Écrire les registres de contrôle
uint64_t read_cr0();
void write_cr0(uint64_t value);

// Initialisation du CPU
void init();

} // namespace kernel::cpu
