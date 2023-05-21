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

// Sistem quiz
int quiz_15_soal()
{
    char peringkat_uang[15][15] = {
        "Rp 100.000",
        "Rp 200.000",
        "Rp 300.000",
        "Rp 500.000",
        "Rp 1.000.000",
        "Rp 2.000.000",
        "Rp 4.000.000",
        "Rp 8.000.000",
        "Rp 16.000.000",
        "Rp 32.000.000",
        "Rp 64.000.000",
        "Rp 125.000.000",
        "Rp 250.000.000",
        "Rp 500.000.000",
        "Rp 1000000000"};

    
    struct Soal soal_soal[15] = {
        {"Siapa pendiri Partai Komunis Indonesia (PKI)?", "Tan Malaka", "Sukarno", "Aidit", "Musso", 'D'},
        {"Kapan PKI didirikan?", "1945", "1920", "1949", "1965", 'B'},
        {"Apa tujuan utama PKI pada awal berdirinya?", "Mempertahankan keberadaan kolonial Belanda", "Menggalang persatuan dan kesatuan bangsa Indonesia", "Mewujudkan sistem kapitalis di Indonesia", "Menegakkan paham komunisme di Indonesia", 'B'},
        {"Apa yang menjadi alasan pemerintah Indonesia membubarkan PKI pada tahun 1965?", "Terlibat dalam kegiatan terorisme", "Melanggar hukum internasional", "Diduga terlibat dalam percobaan kudeta", "Memiliki persaingan politik yang ketat dengan pemerintah", 'C'},
        {"Apa nama konferensi  pada tahun 1965 yang diduga sebagai pemicu pembubaran PKI?", "Konferensi Bandung", "Konferensi Yogyakarta", "Konferensi Lubang Buaya", "Konferensi Malino", 'C'},
        {"Bagaimana kondisi PKI setelah pembubaran pada tahun 1965?", "Tetap beroperasi secara terbuka", "Beralih ke kegiatan gerilya", "Membubarkan diri secara sukarela", "Menjadi partai oposisi legal", 'B'},
        {"Apa yang menjadi dampak pembubaran PKI terhadap anggota dan simpatisannya?", "Penahanan massal", "Pembunuhan massal", "Pengasingan massal", "Semua jawaban di atas benar", 'D'},
        {"Pada tahun berapakah PKI dinyatakan sebagai organisasi terlarang di Indonesia?", "1965", "1978", "1998", "2004", 'A'},
        {"Apa yang menjadi lambang resmi PKI?", "Palu dan arit", "Burung Garuda", "Bintang Merah", "Pohon Beringin", 'A'},
        {"Apa yang menjadi pandangan PKI terhadap sistem kapitalis?", "Menentangnya sepenuhnya", "Menerima dengan syarat tertentu", "Netral", "Tidak ada jawaban yang benar", 'A'},
        {"Apa nama tokoh PKI yang terkenal sebagai pemimpin dalam pemberontakan Madiun pada tahun 1948?", "Sukarno", "Tan Malaka", "Aidit", "Musso", 'D'},
        {"Apa alasan PKI mengalami kejatuhan popularitas di Indonesia sebelum pembubaran pada tahun 1965?", "Terlibat dalam skandal korupsi", "Keberhasilan pemerintah dalam membangun ekonomi", "Perpecahan internal di dalam partai", "Semua jawaban di atas benar", 'B'},
        {"Apa yang menjadi pandangan PKI terhadap agama?", "Menentang agama secara total", "Mengakui keberadaan agama sebagai urusan pribadi", "Menganjurkan agama sebagai landasan moral", "Tidak ada jawaban yang benar", 'B'},
        {"Apa nama rezim pemerintahan yang didirikan oleh PKI di Madiun pada tahun 1948?", "Republik Indonesia", "Negara Indonesia Timur", "Republik Rakyat Indonesia", "Negara Indonesia Serikat", 'C'},
        {"Bagaimana hubungan antara PKI dengan Gerakan 30 September (G30S) pada tahun 1965?", "PKI terlibat langsung dalam G30S", "PKI tidak memiliki keterlibatan dalam G30S", "PKI memberikan dukungan moral kepada G30S", "Hubungan antara PKI dan G30S masih diperdebatkan hingga saat ini", 'A'}};

    for (int i = 0; i < sizeof soal_soal / sizeof soal_soal[0]; i++)
    {
        menampilkan_level(peringkat_uang, i, sizeof(peringkat_uang) / sizeof(peringkat_uang[0]));

        printf("\x001b[33mLEVEL %d\x001b[00m\n\n", i + 1);

        // menampung nilai A B C D
        char jawaban_user;

        //  berisi y atau T
        char ingin_melanjutkan;

        // menyimpan apakah benar atau tidak
        bool apakah_benar;

        // mengambil soal berdasarkan index
        struct Soal soal_saat_ini = soal_soal[i];

        //  menampilkan soal
        print_per_soal(soal_saat_ini);
        printf(":> ");

        // mengambil jawaban dari user
        scanf("%s", &jawaban_user);

        // pengecekan jawaban
        apakah_benar = mengecek_jawaban(soal_saat_ini, jawaban_user);

        if (!apakah_benar)
        {
            printf("\x001b[31mMAAF JAWABAN ANDA KURANG TEPAT\x001b[00m\nSAYANGNYA UANG ANDA TELAH HANGUS\n");
            break;
        }
        else
        {
            if (i == (sizeof peringkat_uang / sizeof peringkat_uang[0]) - 1)
            {
                printf("\x001B[H\x001B[2J");
                printf("\nSELAMAT ANDA MENDAPATKAN HADIAH SEBESAR \x001b[32m%s\x001b[00m\n\n", peringkat_uang[i]);
                break;
            }

            printf("~~{ SELAMAT JAWABAN ANDA TEPAT }~~\nUANG ANDA SAAT INI ADALAH \x001b[32m%s\x001b[00m\n", peringkat_uang[i]);
            printf("Apakah anda ingin melanjutkan?(Y/T) ");
            scanf("%s", &ingin_melanjutkan);

            if (ingin_melanjutkan == 't' || ingin_melanjutkan == 'y')
            {
                if (ingin_melanjutkan == 't')
                {
                    printf("\x001B[H\x001B[2J");
                    printf("\n\x1b[5mSELAMAT ANDA MENDAPATKAN HADIAH SEBESAR \x001b[32m%s\x001b[00m\n\n", peringkat_uang[i]);
                    break;
                }
            }
            else
            {
                return 1;
            }
            // untuk membersihkan terminal
            printf("\x001B[H");
            // untuk memindahkan cursor ke bagian paling atas dari terminal
            printf("\x001B[2J");
        }
    }
    return 0;
}

// untuk menampilkan menu utama
void print_menu_utama()
{
    printf("\x001b[36m");
    printf("+=====================================+\n");
    printf("|          SELAMAT DATANG DI          |\n");
    printf("|       TES WAWASAN KEBANGSAAN        |\n");
    printf("|              KELOMPOK 6             |\n");
    printf("+=====================================+\n");
    printf("1. mulai\n");
    printf("2. tutorial\n");
    printf("3. keluar\n: ");
    printf("\x001b[00m");
}

// main function
int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Argumen tidak valid. Gunakan: ./program <username> <password>\n");
        return 1;
    }

    char *username = argv[1];
    char *password = argv[2];

    login(username, password);

    while (1) {
        printf("\x001B[H\x001B[2J");

        int yang_dipilihan;
        char apakah_ingin_melanjutkan;

        print_menu_utama();
        scanf("%d", &yang_dipilihan);
        printf("\x001B[H\x001B[2J");
        if (yang_dipilihan == 1)
        {
            quiz_15_soal();
            printf("\nApakah anda ingin kembali ke menu utama?(Y/T)");
            scanf(" %c", &apakah_ingin_melanjutkan);
            if (tolower(apakah_ingin_melanjutkan) == 'y')
            {
                continue;
            }
            break;
        }
        else if (yang_dipilihan == 2)
        {
            print_tutorial();
            printf("Tekan tombol Enter untuk melanjutkan...\n");
            fflush(stdin);
            getchar();
            while (1)
            {
                if (getchar() != '\n')
                {
                    continue;
                }
                break;
            }
        }
        else
        {
            return 0;
        }
        printf("\x001B[H\x001B[2J");
    }

    return 0;
}
