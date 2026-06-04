# RX1_OS - Système d'Exploitation

> Un système d'exploitation minimal et éducatif conçu pour architecture x86-64, développé en C++ et assembleur.

[![Build Status](https://img.shields.io/badge/build-in%20progress-yellow)](#)
[![Language](https://img.shields.io/badge/language-C%2B%2B-blue)](#)
[![Standard](https://img.shields.io/badge/standard-C%2B%2B20-blue)](#)
[![License](https://img.shields.io/badge/license-MIT-green)](#)

## 🎯 Objectifs

- [x] Structure de base du projet
- [ ] Bootloader complet (Real Mode → Protected Mode → Long Mode)
- [ ] Kernel 64-bit fonctionnel
- [ ] Gestion mémoire (pagination, allocation dynamique)
- [ ] Système d'interruptions
- [ ] Drivers essentiels (VGA, clavier, disque)
- [ ] Système de fichiers
- [ ] Shell simple

## ⚡ Démarrage rapide

```bash
# Cloner et configurer!
git clone <repository>   .
cd RX1_OS

# Compiler
mkdir build && cd build
cmake ..
make

# Nettoyer
make clean_all
```

## 📁 Structure du Projet

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

## 📦 Prérequis

| Composant | Version | Note |
|-----------|---------|------|
| CMake | 3.20+ | Système de compilation |
| GCC/Clang | Latest | Support x86-64 requis |
| NASM | 2.14+ | Assembleur x86 |
| Make/Ninja | Latest | Build tool |

**Installation (Windows):**
```bash
# Via Chocolatey
choco install cmake gcc nasm make
```

**Installation (Linux/macOS):**
```bash
# Ubuntu/Debian
sudo apt-get install cmake gcc g++ nasm make

# macOS
brew install cmake gcc nasm make
```

## 🔧 Composants Principaux

### Bootloader
Première étape du démarrage du système
- ✅ Initialisation du matériel
- ✅ Passage Mode Réel → Mode Protégé (32-bit)  
- ✅ Passage Mode Protégé → Mode Long (64-bit)
- **Statut:** En cours de développement

### Kernel
Cœur du système d'exploitation
- **Core:** Gestion CPU, registres, instructions spéciales
- **Memory:** Paging (PML4/PDPT/PDT/PT), heap, allocation dynamique
- **Interrupt:** IDT, gestion des exceptions et IRQs
- **Statut:** Structure de base complète

### Drivers
Pilotes matériel essentiels
- 📺 Affichage vidéo (VGA)
- ⌨️ Clavier
- 💾 Disque dur (ATA/SATA)
- 🖱️ Souris
- **Statut:** À implémenter

### Filesystem
Système de fichiers virtuel
- Support ext2 ou VFS simple
- Gestion des inodes et répertoires
- **Statut:** À implémenter

### Libraries
Bibliothèques standard essentielles
- **String:** strlen, strcpy, strcmp, memcpy, memset
- **Memory:** malloc, free, calloc
- **I/O:** Fonctions d'entrée/sortie
- **Statut:** Partiellement implémenté

## 📚 Documentation

| Document | Description |
|----------|-------------|
| [ARCHITECTURE.md](docs/ARCHITECTURE.md) | Vue d'ensemble technique et phases de démarrage |
| [Bootloader](bootloader/) | Code de démarrage x86 |
| [Kernel](kernel/) | Noyau du système |

## 🚀 Phases de Démarrage

```
┌─────────────────────┐
│   Applications      │
└─────────────────────┘
         ↓
┌─────────────────────┐
│   Kernel (64-bit)   │
│ • Core, Memory      │
│ • Interrupts        │
└─────────────────────┘
         ↓
┌─────────────────────┐
│   Mode Long (64)    │
│   Paging activée    │
└─────────────────────┘
         ↓
┌─────────────────────┐
│   Mode Protégé(32)  │
│   GDT chargée       │
└─────────────────────┘
         ↓
┌─────────────────────┐
│   Bootloader        │
│   Real Mode (16)    │
└─────────────────────┘
         ↓
┌─────────────────────┐
│   Hardware BIOS     │
└─────────────────────┘
```

## 📋 Roadmap

**Phase 1 (Actuelle):** Foundation
- [x] Structure du projet
- [x] Bootloader basique
- [x] Kernel framework
- [ ] Compilation réussie

**Phase 2:** Core Features
- [ ] Bootloader complet (mode switching)
- [ ] Gestion mémoire opérationnelle
- [ ] IDT et interruptions
- [ ] Premier message de démarrage

**Phase 3:** System Features
- [ ] Drivers matériel
- [ ] Système de fichiers
- [ ] Ordonnanceur simple
- [ ] Shell minimal

**Phase 4:** Advanced
- [ ] Multitâche
- [ ] Processus utilisateur
- [ ] Gestion avancée des permissions
- [ ] Système de fichiers complet

## 🤝 Contribution

Les contributions sont les bienvenues ! Pour contribuer :

1. Fork le projet
2. Créer une branche (`git checkout -b feature/amazing-feature`)
3. Commit vos changements (`git commit -m 'Add amazing feature'`)
4. Push vers la branche (`git push origin feature/amazing-feature`)
5. Ouvrir une Pull Request

## 📝 Licences et Auteurs

- **Créé:** 2026
- **Auteur:** RAMDANEX1
- **Licence:** MIT

## 🔗 Ressources Utiles

- [OSDev.org](https://wiki.osdev.org/) - Wiki complet sur le développement OS
- [Intel x86 Manual](https://www.intel.com/content/dam/www/public/us/en/documents/manuals/64-ia-32-architectures-software-developer-manual-combined-volumes-1-2a-2b-2c-2d-3a-3b-3c-3d.pdf)
- [x86_64 ABI](https://refspecs.linuxbase.org/elf/x86_64-abi-0.99.pdf)
- [GNU GCC Documentation](https://gcc.gnu.org/onlinedocs/)

## 📞 Support

Pour toute question ou problème, ouvrez une [issue](../../issues) sur GitHub.

---

**État du projet:** 🟡 En cours de développement  
**Dernière mise à jour:** Mai 2026
