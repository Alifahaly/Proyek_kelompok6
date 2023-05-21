#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

// Fungsi untuk memeriksa apakah username dan password valid
bool isLoginValid(const char *username, const char *password)
{
    // Cek apakah username dan password sesuai dengan data yang valid
    const char *username_benar = "kelompok6";
    const char *password_benar = "pastijuara";

    if (strcmp(username, username_benar) == 0 && strcmp(password, password_benar) == 0)
        return true;
    else
        return false;
}

// Fungsi untuk melakukan login
bool login()
{
    char username[50];
    char password[50];

    printf("Masukkan username: ");
    scanf("%s", username);

    printf("Masukkan password: ");
    scanf("%s", password);

    if (isLoginValid(username, password))
    {
        printf("Login berhasil!\n");
        return true;
    }
    else
    {
        printf("Login gagal. Username atau password salah.\n");
        return false;
    }
};
// type data untuk menampung soal
struct Soal
{
    char pertanyaan[100];
    char pilihan1[150];
    char pilihan2[150];
    char pilihan3[150];
    char pilihan4[150];
    char pilihanBenar;
};

// untuk mengecek jawaban
bool mengecek_jawaban(struct Soal soal, char pilihan)
{
    return soal.pilihanBenar == toupper(pilihan);
}

//  untuk menampilkan level
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

// menampikan soal
void print_per_soal(struct Soal soal)
{
    printf("%s\n", soal.pertanyaan);
    printf("A. %s\n", soal.pilihan1);
    printf("B. %s\n", soal.pilihan2);
    printf("C. %s\n", soal.pilihan3);
    printf("D. %s\n", soal.pilihan4);
}

// untuk menampilkan tutorial
void print_tutorial()
{
    printf("Selamat datang di Milioner CLI!\n\n");
    printf("1. Anda akan diberikan 15 pertanyaan untuk memenangkan hadiah utama.\n");
    printf("2. Setiap soal memiliki satu jawaban yang benar (A/B/C/D)\n");
    printf("3. Jika jawaban anda benar, maka hadiah anda akan bertambah. Jika jawaban salah, permainan berakhir dan Anda kehilangan semua hadiah.\n\n");
}
