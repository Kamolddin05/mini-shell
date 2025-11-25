# Mini O'zbekcha Shell uchun Makefile

# Compiler
CC = gcc

# Fayllar
SRC = main.c commands.c utils.c

# Natija fayl nomi
OUT = mini-os.exe

# Kompilyatsiya qoidasi
all:
	$(CC) $(SRC) -o $(OUT)

# Tozalash
clean:
	del $(OUT)
