@echo off
cls
echo ===============================
echo   MINI-OS: Kompilyatsiya boshlanmoqda
echo ===============================

REM --- Fayllarni tekshirish ---
if not exist main.c (
    echo Xatolik: main.c topilmadi!
    pause
    exit /b
)

if not exist commands.c (
    echo Xatolik: commands.c topilmadi!
    pause
    exit /b
)

if not exist utils.c (
    echo Xatolik: utils.c topilmadi!
    pause
    exit /b
)

echo Fayllar topildi. Kompilyatsiya qilinmoqda...

REM --- Kompilyatsiya ---
gcc main.c commands.c utils.c -o mini-os.exe

if errorlevel 1 (
    echo ===============================
    echo    XATOLIK: Kompilyatsiya muvaffaqiyatsiz!
    echo ===============================
    pause
    exit /b
)

echo ===============================
echo     Kompilyatsiya muvaffaqiyatli!
echo ===============================
echo Natija: mini-os.exe tayyor
echo.

REM --- Dastur ishga tushirish ---
echo Dastur ishga tushirilmoqda...
echo -------------------------------
mini-os.exe

pause
