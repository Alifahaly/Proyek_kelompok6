#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>


struct User {
    char username[50];
    char password[50];
};

bool isLoginValid(const char *username, const char *password)
{
    // Ubah lokasi file login.txt sesuai dengan kebutuhan Anda
    FILE *file = fopen("lpala.txt", "r");
    if (file == NULL) {
        printf("File login.txt tidak ditemukan.\n");
        return false;
    }

    struct User user;
    while (fread(&user, sizeof(struct User), 1, file)) {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}

bool login(const char *username, const char *password)
{
    if (isLoginValid(username, password)) {
        printf("Login berhasil!\n");
        return true;
    } else {
        printf("Login gagal. Username atau password salah.\n");
        return false;
    }
}


// Type data untuk menampung soal
struct Soal
{
    char pertanyaan[100];
    char pilihan1[150];
    char pilihan2[150];
    char pilihan3[150];
    char pilihan4[150];
    char pilihanBenar;
};

// Untuk mengecek jawaban
bool mengecek_jawaban(struct Soal soal, char pilihan)
{
    return soal.pilihanBenar == toupper(pilihan);
}

// Untuk menampilkan level
void menampilkan_level(char levels[][15], char level_saat_ini, int jml_level)
{
    for (int i = 0; i < jml_level; i++)
    {
        if (i == level_saat_ini)
        {
            printf("\x001b[31m[%s]\x001b[00m ", levels[i]);
            continue;
        }

        printf("%s ", levels[i]);
    }

    printf("\n");
}

// Menampilkan soal
void print_per_soal(struct Soal soal)
{
    printf("%s\n", soal.pertanyaan);
    printf("A. %s\n", soal.pilihan1);
    printf("B. %s\n", soal.pilihan2);
    printf("C. %s\n", soal.pilihan3);
    printf("D. %s\n", soal.pilihan4);
}

// Menampilkan tutorial
void print_tutorial()
{
    printf("Selamat datang di Milioner CLI!\n\n");
    printf("1. Anda akan diberikan 15 pertanyaan untuk memenangkan hadiah utama.\n");
    printf("2. Setiap soal memiliki satu jawaban yang benar (A/B/C/D)\n");
    printf("3. Jika jawaban anda benar, maka hadiah anda akan bertambah. Jika jawaban salah, permainan berakhir dan Anda kehilangan semua hadiah.\n\n");
}
