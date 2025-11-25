#include "commands.h"
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <windows.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>

// ==============================
// 1) Fayl va papka komandalar
// ==============================
void cmd_royxat(char *args) { system("dir"); }

void cmd_ochish(char *path) {
    if (!path) { printf("Xatolik: papka nomi kerak.\n"); return; }
    if (_chdir(path) == 0) printf("Papkaga o'tildi: %s\n", path);
    else printf("Xatolik: papka topilmadi.\n");
}

void cmd_katalog(char *args) {
    char buf[260];
    _getcwd(buf, 260);
    printf("Joriy papka: %s\n", buf);
}

void cmd_yarat(char *f) {
    if (!f) { printf("Xatolik: fayl nomi kerak.\n"); return; }
    FILE *fp = fopen(f, "w");
    if (!fp) { printf("Xatolik: fayl yaratilmaydi.\n"); return; }
    fclose(fp);
    printf("Fayl yaratildi: %s\n", f);
}

void cmd_och(char *f) {
    if (!f) { printf("Xatolik: fayl nomi kerak.\n"); return; }
    char cmd[300]; sprintf(cmd, "notepad %s", f); system(cmd);
}

void cmd_ochir(char *f) {
    if (!f) { printf("Xatolik: fayl nomi kerak.\n"); return; }
    if (remove(f) == 0) printf("Fayl o'chirildi: %s\n", f);
    else printf("Xatolik: fayl o'chirilmadi.\n");
}

void cmd_kopiya(char *args) {
    if (!args) { printf("Format: kopiya manba yangi\n"); return; }
    char src[100], dst[100];
    sscanf(args, "%s %s", src, dst);

    FILE *in = fopen(src, "rb"); 
    if (!in) { printf("Xatolik: %s topilmadi\n", src); return; }
    FILE *out = fopen(dst, "wb");

    char buf[1024]; 
    int size;
    while ((size = fread(buf, 1, 1024, in)) > 0) fwrite(buf, 1, size, out);

    fclose(in); fclose(out);
    printf("Nusxa olindi: %s -> %s\n", src, dst);
}

void cmd_kochirish(char *args) {
    char a[100], b[100];
    if (!args) { printf("Format: kochirish eski yangi\n"); return; }
    sscanf(args, "%s %s", a, b);
    if (rename(a, b) == 0) printf("Ko‘chirildi: %s -> %s\n", a, b);
    else printf("Xatolik: ko‘chirilmadi\n");
}

void cmd_nomlash(char *args) {
    char a[100], b[100];
    if (!args) { printf("Format: nomlash eski yangi\n"); return; }
    sscanf(args, "%s %s", a, b);
    if (rename(a, b) == 0) printf("Nomlandi: %s -> %s\n", a, b);
    else printf("Xatolik: nomlash imkonsiz\n");
}

void cmd_korsat(char *f) {
    if (!f) { printf("Fayl nomi kiriting.\n"); return; }
    FILE *fp = fopen(f, "r");
    if (!fp) { printf("Xatolik: fayl topilmadi.\n"); return; }
    char ch; 
    while ((ch = fgetc(fp)) != EOF) putchar(ch);
    fclose(fp);
}

// ==============================
// 2) Tizim komandalar
// ==============================

void cmd_vaqt(char *args) { 
    time_t t = time(NULL);
    printf("Vaqt: %s", ctime(&t));
}

void cmd_sana(char *args) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    printf("Sana: %02d-%02d-%04d\n", tm_info->tm_mday, tm_info->tm_mon+1, tm_info->tm_year+1900);
}

void cmd_qurilmalar(char *args) {
    SYSTEM_INFO si; 
    GetSystemInfo(&si);
    printf("CPU soni: %u\n", si.dwNumberOfProcessors);
}

void cmd_men_kim(char *args) {
    char username[256]; 
    DWORD size = 256;
    GetUserName(username, &size);
    printf("Foydalanuvchi: %s\n", username);
}

void cmd_tozalash(char *args) { system("cls"); }

void cmd_echo(char *txt) { if (!txt) printf("\n"); else printf("%s\n", txt); }

void cmd_yordam(char *args) {
    printf("=== Komandalar ro'yxati va vazifalari ===\n");

    // Fayl/papka komandalar
    printf("royxat       - joriy papkadagi fayllar ro'yxati\n");
    printf("ochish       - papkani ochish\n");
    printf("katalog      - joriy papkani ko'rsatish\n");
    printf("yarat        - yangi fayl yaratish\n");
    printf("och          - faylni ochish\n");
    printf("ochir        - faylni o'chirish\n");
    printf("kopiya       - fayl nusxasini olish\n");
    printf("kochirish    - faylni ko'chirish\n");
    printf("nomlash      - fayl nomini o'zgartirish\n");
    printf("korsat       - fayl ichini ko'rsatish\n");

    // Tizim komandalar
    printf("vaqt         - hozirgi vaqtni ko'rsatish\n");
    printf("sana         - hozirgi sanani ko'rsatish\n");
    printf("qurilmalar   - tizim qurilmalari haqida\n");
    printf("men_kim      - foydalanuvchi nomi\n");
    printf("tozalash     - ekranni tozalash\n");
    printf("echo         - matn chiqarish\n");
    printf("yordam       - komandalar ro'yxati\n");
    printf("chiqish      - shelldan chiqish\n");

    // Qo‘shimcha komandalar
    printf("tasodif      - tasodifiy son chiqarish\n");
    printf("hisobla      - arifmetik amal bajarish\n");
    printf("hisob_soz    - matndagi so'zlarni hisoblash\n");
    printf("kichik       - matnni kichik harflarga aylantirish\n");
    printf("katta        - matnni katta harflarga aylantirish\n");
    printf("teskari      - matnni teskari chiqarish\n");
    printf("kut          - kutish funksiyasi (ms)\n");
    printf("qidir        - qidirish funksiyasi\n");
}

void cmd_chiqish(char *args) { 
    printf("Chiqildi.\n");
    exit(0);
}

// ==============================
// 3) Qo‘shimcha komandalar
// ==============================

void cmd_tasodif(char *args) { printf("Tasodifiy son: %d\n", rand() % 1000); }

void cmd_hisobla(char *args) {
    double a, b; 
    char op;
    printf("Misol kiriting: ");
    scanf("%lf %c %lf", &a, &op, &b);
    getchar();

    switch (op) {
        case '+': printf("Natija: %.2lf\n", a+b); break;
        case '-': printf("Natija: %.2lf\n", a-b); break;
        case '*': printf("Natija: %.2lf\n", a*b); break;
        case '/': printf("Natija: %.2lf\n", b!=0?a/b:0); break;
        default: printf("Xato amal.\n");
    }
}

void cmd_hisob_soz(char *txt) {
    if (!txt) { printf("Matn kiriting.\n"); return; }
    int count = 1;
    for (int i=0; txt[i]; i++) if (txt[i]==' ') count++;
    printf("So‘zlar soni: %d\n", count);
}

void cmd_kichik(char *txt) { 
    if (!txt) return;
    for (int i=0; txt[i]; i++) putchar(tolower(txt[i]));
    printf("\n");
}

void cmd_katta(char *txt) {
    if (!txt) return;
    for (int i=0; txt[i]; i++) putchar(toupper(txt[i]));
    printf("\n");
}

void cmd_teskari(char *txt) {
    if (!txt) return;
    int len = strlen(txt);
    for (int i=len-1; i>=0; i--) putchar(txt[i]);
    printf("\n");
}

void cmd_kut(char *txt) {
    if (!txt) { printf("ms kiriting.\n"); return; }
    int ms = atoi(txt);
    Sleep(ms);
    printf("%d ms kutildi.\n", ms);
}

void cmd_qidir(char *txt) { printf("Qidirish funksiyasi keyin qo‘shiladi.\n"); }

// ===================================
// Komandalar ro‘yxati
// ===================================
Command *get_commands(int *count) {
    static Command cmds[] = {
        {"royxat", cmd_royxat},
        {"ochish", cmd_ochish},
        {"katalog", cmd_katalog},
        {"yarat", cmd_yarat},
        {"och", cmd_och},
        {"ochir", cmd_ochir},
        {"kopiya", cmd_kopiya},
        {"kochirish", cmd_kochirish},
        {"nomlash", cmd_nomlash},
        {"korsat", cmd_korsat},
        {"vaqt", cmd_vaqt},
        {"sana", cmd_sana},
        {"qurilmalar", cmd_qurilmalar},
        {"men_kim", cmd_men_kim},
        {"tozalash", cmd_tozalash},
        {"echo", cmd_echo},
        {"yordam", cmd_yordam},
        {"chiqish", cmd_chiqish},
        {"tasodif", cmd_tasodif},
        {"hisobla", cmd_hisobla},
        {"hisob_soz", cmd_hisob_soz},
        {"kichik", cmd_kichik},
        {"katta", cmd_katta},
        {"teskari", cmd_teskari},
        {"kut", cmd_kut},
        {"qidir", cmd_qidir},
    };
    *count = sizeof(cmds)/sizeof(cmds[0]);
    return cmds;
}
