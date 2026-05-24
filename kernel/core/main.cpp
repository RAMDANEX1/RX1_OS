#include <cstdint>

// Point d'entrée du kernel
extern "C" void kmain() {
    // Initialisation du kernel
    
    // TODO: Initialiser la gestion mémoire
    // TODO: Initialiser la table d'interruptions (IDT)
    // TODO: Initialiser les drivers essentiels
    // TODO: Démarrer l'ordonnanceur de tâches
    
    // Boucle infinie
    while (true) {
        asm volatile("hlt");
    }
}

// Fonction pour arrêter le système
extern "C" void panic(const char* message) {
    // TODO: Afficher le message d'erreur
    // TODO: Arrêter le système
    while (true) {
        asm volatile("hlt");
    }
}
