#include "cpu.h"

// Gestion du CPU
namespace kernel::cpu {

// Lire le MSR (Model Specific Register)
uint64_t read_msr(uint32_t msr) {
    uint32_t low, high;
    asm volatile("rdmsr" : "=a"(low), "=d"(high) : "c"(msr));
    return ((uint64_t)high << 32) | low;
}

// Écrire dans le MSR
void write_msr(uint32_t msr, uint64_t value) {
    uint32_t low = value & 0xFFFFFFFF;
    uint32_t high = (value >> 32) & 0xFFFFFFFF;
    asm volatile("wrmsr" : : "a"(low), "d"(high), "c"(msr));
}

// Lire le registre CR0
uint64_t read_cr0() {
    uint64_t value;
    asm volatile("mov %%cr0, %0" : "=r"(value));
    return value;
}

// Écrire dans CR0
void write_cr0(uint64_t value) {
    asm volatile("mov %0, %%cr0" : : "r"(value));
}

// Initialiser le CPU
void init() {
    // TODO: Configurer les registres de protection (CR0, CR4)
    // TODO: Configurer APIC (Advanced Programmable Interrupt Controller)
    // TODO: Configurer les features du CPU
}

} // namespace kernel::cpu
