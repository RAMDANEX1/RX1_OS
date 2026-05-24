#pragma once

#include <cstdint>

namespace kernel::interrupt {

// Interrupt Descriptor Table Entry (64-bit)
struct IDTEntry {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;
    uint8_t type_and_attr;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t reserved;
};

// IDT Register
struct IDTRegister {
    uint16_t limit;
    uint64_t offset;
} __attribute__((packed));

extern IDTEntry g_idt[256];
extern IDTRegister g_idt_register;

// Fonctions
void set_idt_entry(uint8_t index, uint64_t handler, uint8_t type, uint8_t dpl);
void load_idt();
void init_idt();

} // namespace kernel::interrupt
