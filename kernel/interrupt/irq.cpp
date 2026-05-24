#include "irq.h"

namespace kernel::interrupt {

// Gestionnaire des IRQ
IRQHandler g_irq_handlers[16];

void register_irq_handler(uint8_t irq, IRQHandler handler) {
    if (irq < 16) {
        g_irq_handlers[irq] = handler;
    }
}

void handle_irq(uint8_t irq) {
    if (irq < 16 && g_irq_handlers[irq]) {
        g_irq_handlers[irq](irq);
    }
    
    // TODO: Envoyer EOI (End Of Interrupt) au PIC
}

void init_irq() {
    // TODO: Initialiser le PIC (Programmable Interrupt Controller)
    // TODO: Initialiser les vecteurs d'interruptions pour les IRQ
}

} // namespace kernel::interrupt
