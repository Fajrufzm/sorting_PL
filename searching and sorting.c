#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 100

struct Mahasiswa {
    char npm[15];
    char nama[50];
    char prodi[30];
    float ipk;
};

struct Mahasiswa data[MAX_MAHASISWA];
int jumlah_mahasiswa = 0;

void tambahMahasiswa() {
    if (jumlah_mahasiswa >= MAX_MAHASISWA) {
        printf("Kapasitas data mahasiswa penuh!\n");
        return;
    }

    printf("Masukkan NPM: ");
    scanf("%s", data[jumlah_mahasiswa].npm);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", data[jumlah_mahasiswa].nama);
    printf("Masukkan Program Studi: ");
    scanf(" %[^\n]s", data[jumlah_mahasiswa].prodi);
    printf("Masukkan IPK: ");
    scanf("%f", &data[jumlah_mahasiswa].ipk);

    jumlah_mahasiswa++;
    printf("Data mahasiswa berhasil ditambahkan!\n");
}

void tampilkanData() {
    printf("\nData Mahasiswa:\n");
    printf("-------------------------------------------------\n");
    printf("| NPM         | Nama               | Prodi       | IPK |\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < jumlah_mahasiswa; i++) {
        printf("| %-11s | %-18s | %-10s | %.2f |\n",
               data[i].npm, data[i].nama, data[i].prodi, data[i].ipk);
    }
    printf("-------------------------------------------------\n");
}

// Sorting NPM
void urutkanBerdasarkanNPM() {
    struct Mahasiswa temp;
    for (int i = 0; i < jumlah_mahasiswa - 1; i++) {
        for (int j = i + 1; j < jumlah_mahasiswa; j++) {
            if (strcmp(data[i].npm, data[j].npm) > 0) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

// Sorting nama
void urutkanBerdasarkanNama() {
    struct Mahasiswa temp;
    for (int i = 0; i < jumlah_mahasiswa - 1; i++) {
        for (int j = i + 1; j < jumlah_mahasiswa; j++) {
            if (strcmp(data[i].nama, data[j].nama) > 0) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

// Sorting IPK
void urutkanBerdasarkanIPK() {
    struct Mahasiswa temp;
    for (int i = 0; i < jumlah_mahasiswa - 1; i++) {
        for (int j = i + 1; j < jumlah_mahasiswa; j++) {
            if (data[i].ipk < data[j].ipk) {  // Mengurutkan dari IPK tertinggi
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void urutkanData() {
    int pilihan;
    printf("\nPilih metode pengurutan:\n");
    printf("1. Urutkan berdasarkan NPM\n");
    printf("2. Urutkan berdasarkan Nama\n");
    printf("3. Urutkan berdasarkan IPK\n");
    printf("Pilihan: ");
    scanf("%d", &pilihan);

    switch (pilihan) {
        case 1:
            urutkanBerdasarkanNPM();
            printf("Data berhasil diurutkan berdasarkan NPM.\n");
            break;
        case 2:
            urutkanBerdasarkanNama();
            printf("Data berhasil diurutkan berdasarkan Nama.\n");
            break;
        case 3:
            urutkanBerdasarkanIPK();
            printf("Data berhasil diurutkan berdasarkan IPK.\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
    }
}

void tampilkanMenu() {
    int pilihan;
    do {
        printf("\nMenu Manajemen Data Mahasiswa:\n");
        printf("1. Tambah Data Mahasiswa\n");
        printf("2. Tampilkan Data Mahasiswa\n");
        printf("3. Urutkan Data Mahasiswa\n");
        printf("4. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                urutkanData();
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 4);
}

int main() {
    tampilkanMenu();
    return 0;
}
