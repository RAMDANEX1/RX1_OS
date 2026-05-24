; RX1_OS Bootloader
; Boot sector: 512 bytes
; Mode réel (x86) -> Mode protégé

[BITS 16]
[ORG 0x7C00]

start:
    ; Initialisation du stack
    mov ax, 0x0000
    mov ss, ax
    mov sp, 0x7C00

    ; Désactiver les interruptions
    cli

    ; Message de démarrage
    mov si, boot_msg
    call print_string

    ; TODO: Charger le kernel
    ; TODO: Passer en mode protégé (32-bit)
    ; TODO: Passer en mode long (64-bit)

    ; Boucle infinie
    hlt
    jmp $

; Fonction d'affichage de chaîne de caractères
print_string:
    mov ah, 0x0E
.loop:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .loop
.done:
    ret

; Message de démarrage
boot_msg:
    db "RX1_OS Bootloader v1.0", 0x0D, 0x0A
    db "Starting system...", 0x0D, 0x0A, 0

; Padding et signature de boot
times 510 - ($ - $$) db 0
dw 0xAA55  ; Boot sector signature
