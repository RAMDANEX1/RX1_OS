# Architecture RX1_OS

## Vue d'ensemble

RX1_OS est un système d'exploitation minimal conçu pour exécuter sur architecture x86-64.

```
+------------------+
|   Applications   |
+------------------+
|   Shell / Shell  |
+------------------+
|  Kernel (64-bit) |
| - Core           |
| - Memory         |
| - Interrupts     |
+------------------+
|   Drivers        |
| - VGA, Keyboard  |
| - Disk (ATA)     |
+------------------+
|   Bootloader     |
| - Real Mode      |
| - Protected Mode |
+------------------+
|   Hardware       |
+------------------+
```

## Phases de démarrage

### Phase 1: Bootloader (Mode Réel)
1. BIOS charge le bootloader à 0x7C00
2. Initialisation du stack
3. Affichage du message de démarrage
4. Chargement du kernel depuis le disque

### Phase 2: Mode Protégé (32-bit)
1. Désactiver les interruptions
2. Charger la GDT (Global Descriptor Table)
3. Passer en mode protégé (CR0.PE = 1)
4. Sauter vers le code du kernel

### Phase 3: Mode Long (64-bit)
1. Configurer la pagination
2. Configurer la table des pages (PML4, PDPT, PDT, PT)
3. Charger la CR3 avec l'adresse de PML4
4. Passer en mode long (EFER.LME = 1, CR0.PG = 1)
5. Appeler kmain()

## Gestion mémoire

### Virtual Memory Layout (64-bit)
```
0xFFFF800000000000 - Kernel Space
0x00007FFFFFFFFFFF - User Space
0x0000000000000000
```

### Paging Structure
- PML4 (Page Map Level 4): 512 entrées (niveau 4)
- PDPT (Page Directory Pointer Table): 512 entrées (niveau 3)
- PDT (Page Directory Table): 512 entrées (niveau 2)
- PT (Page Table): 512 entrées (niveau 1)

## Gestion des interruptions

### Exceptions (0-31)
- 0: Divide by Zero
- 1: Debug
- ...
- 14: Page Fault
- 15: Reserved
- ...
- 31: Reserved

### IRQs (32-47)
- 32-33: Timer, Keyboard
- 34-43: Parallel Port, Coprocessor, ATA Disk
- 44-47: Reserved

## Tâches futures

- [ ] Implémentation complète du bootloader (real mode -> long mode)
- [ ] Système de fichiers (ext2)
- [ ] Ordonnanceur de tâches
- [ ] Gestion des processus
- [ ] Shell simple
- [ ] Drivers (clavier, disque, vidéo)
- [ ] Bibliothèques standard (libc)
- [ ] Tests

