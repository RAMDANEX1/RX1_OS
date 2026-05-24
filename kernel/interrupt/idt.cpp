#include "idt.h"

namespace kernel::interrupt {

// Table d'interruptions (IDT - Interrupt Descriptor Table)
IDTEntry g_idt[256];
IDTRegister g_idt_register;

void set_idt_entry(uint8_t index, uint64_t handler, uint8_t type, uint8_t dpl) {
    IDTEntry& entry = g_idt[index];
    entry.offset_low = (uint16_t)(handler & 0xFFFF);
    entry.selector = 0x08;  // Kernel code segment
    entry.ist = 0;
    entry.type_and_attr = (dpl << 5) | type;
    entry.offset_mid = (uint16_t)((handler >> 16) & 0xFFFF);
    entry.offset_high = (uint32_t)((handler >> 32) & 0xFFFFFFFF);
    entry.reserved = 0;
}

void load_idt() {
    g_idt_register.limit = (sizeof(IDTEntry) * 256) - 1;
    g_idt_register.offset = (uint64_t)&g_idt[0];
    
    asm volatile("lidt %0" : : "m"(g_idt_register));
}

void init_idt() {
    // TODO: Initialiser tous les handlers d'interruptions
    // TODO: Exception handlers (0-31)
    // TODO: IRQ handlers (32-47)
    // TODO: Charger l'IDT
    load_idt();
}

} // namespace kernel::interrupt
