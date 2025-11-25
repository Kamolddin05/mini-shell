#ifndef COMMANDS_H
#define COMMANDS_H

// Komanda funksiya turi
typedef void (*CommandFunc)(char *args);

// Komanda strukturasi
typedef struct {
    char *name;
    CommandFunc func;
} Command;

// Barcha komandalarni qaytaradi
Command* get_commands(int *count);

// === Fayl/papka komandalar ===
void cmd_royxat(char *args);
void cmd_ochish(char *args);
void cmd_katalog(char *args);
void cmd_yarat(char *args);
void cmd_och(char *args);
void cmd_ochir(char *args);
void cmd_kopiya(char *args);
void cmd_kochirish(char *args);
void cmd_nomlash(char *args);
void cmd_korsat(char *args);

// === Tizim komandalar ===
void cmd_vaqt(char *args);
void cmd_sana(char *args);
void cmd_qurilmalar(char *args);
void cmd_men_kim(char *args);
void cmd_tozalash(char *args);
void cmd_echo(char *args);
void cmd_yordam(char *args);
void cmd_chiqish(char *args);

// === Qo‘shimcha komandalar ===
void cmd_tasodif(char *args);
void cmd_hisobla(char *args);
void cmd_hisob_soz(char *args);
void cmd_kichik(char *args);
void cmd_katta(char *args);
void cmd_teskari(char *args);
void cmd_kut(char *args);
void cmd_qidir(char *args);

#endif
