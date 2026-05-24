#pragma once

#include <cstdint>

namespace kernel::interrupt {

// Type pour un handler d'IRQ
using IRQHandler = void (*)(uint8_t);

extern IRQHandler g_irq_handlers[16];

// Fonctions
void register_irq_handler(uint8_t irq, IRQHandler handler);
void handle_irq(uint8_t irq);
void init_irq();

} // namespace kernel::interrupt
