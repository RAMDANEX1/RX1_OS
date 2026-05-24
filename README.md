# RX1_OS - Système d'Exploitation

Un système d'exploitation minimal développé en C++ avec support x86-64.

## Structure du Projet

```
RX1_OS/
├── bootloader/       # Code de démarrage (ASM)
├── kernel/           # Noyau du système
│   ├── core/        # Gestion du CPU, ordonnanceur
│   ├── memory/      # Gestion mémoire (paging, allocation)
│   └── interrupt/   # Gestion des interruptions (IDT, IRQ)
├── drivers/         # Pilotes (disque, clavier, etc.)
├── filesystem/      # Système de fichiers
├── libs/            # Bibliothèques utilitaires
├── tools/           # Outils de compilation
└── build/           # Répertoire de compilation (CMake)
```

## Prérequis

- CMake 3.20+
- GCC/Clang avec support x86-64
- NASM (pour l'assembleur)
- GNU Make ou Ninja

## Compilation

```bash
mkdir build
cd build
cmake ..
make
```

## Composants Principaux

### 1. Bootloader
- Initialisation du matériel
- Passage du mode réel au mode protégé (32-bit)
- Passage au mode long (64-bit)

### 2. Kernel
- **Core**: Gestion CPU, ordonnanceur de processus
- **Memory**: Paging, heap, allocation dynamique
- **Interrupt**: Gestion des exceptions et interruptions

### 3. Drivers
- Clavier, souris
- Disque dur (ATA/SATA)
- Affichage vidéo

### 4. Filesystem
- Système de fichiers simple ou ext2
- Gestion des inodes et des répertoires

### 5. Libraries
- Fonctions standard (stdio, stdlib, string)
- Utilitaires mathématiques

## Documentation

Voir le répertoire `docs/` pour la documentation technique.

## Licences et Auteurs

Créé en 2026.
