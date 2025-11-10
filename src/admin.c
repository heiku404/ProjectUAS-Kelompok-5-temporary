#include "../include/utils.h"


void tampilkan_alat(){
    FILE *file = fopen("../data/alat.txt", "r");
    if (!file) {
        printf("Belum ada data ../data/alat.txt\n");
        return;
    }

    Alat alat; 
    printf("\n================= Daftar Alat Lab =================\n");
    
    while (fscanf(file, "%u;%99[^;];%99[^;];%99[^;];%u;%u;%u\n", 
                &alat.id, alat.nama, alat.merek, alat.model, 
                &alat.tahunProduksi, &alat.jumlahUnit, &alat.tersedia) == 7) {
        printf("ID      : %u\n", alat.id);
        printf("Nama    : %s\n", alat.nama);
        printf("Merek   : %s\n", alat.merek);
        printf("Model   : %s\n", alat.model);
        printf("Tahun   : %u\n", alat.tahunProduksi);
        printf("Jumlah  : %u\n", alat.jumlahUnit);
        printf("Tersedia: %u\n", alat.tersedia);
        printf("----------------------------------------\n");
    }
    fclose(file);
}

void tambah_alat(){
    FILE *file = fopen("../data/alat.txt", "a");
    if (!file) {
        printf("Gagal membuka ../data/alat.txt\n");
        return;
    }

    Alat alat; 
    printf("Masukkan ID Alat: ");
    scanf("%u", &alat.id);
    printf("Masukkan Nama Alat: ");
    scanf(" %99[^\n]", alat.nama);
    printf("Masukkan Merek Alat: ");
    scanf(" %99[^\n]", alat.merek);
    printf("Masukkan Model Alat: ");
    scanf(" %99[^\n]", alat.model);
    printf("Masukkan Tahun Produksi Alat: ");
    scanf("%u", &alat.tahunProduksi);
    printf("Masukkan Jumlah Unit Alat: ");
    scanf("%u", &alat.jumlahUnit);
    
    alat.tersedia = alat.jumlahUnit; 

    fprintf(file, "%u;%s;%s;%s;%u;%u;%u\n", 
            alat.id, alat.nama, alat.merek, alat.model, 
            alat.tahunProduksi, alat.jumlahUnit, alat.tersedia);
    
    fclose(file);
    printf("Data alat berhasil ditambahkan.\n");
}

void edit_alat(){
    FILE *file = fopen("../data/alat.txt", "r");
    FILE *temp = fopen("../data/temp.txt", "w");
    if (!file || !temp) {
        printf("Gagal membuka file (data/alat.txt atau data/temp.txt)\n");
        if(file) fclose(file);
        if(temp) fclose(temp);
        return;
    }

    unsigned int id;
    Alat alat; // Menggunakan struct Alat
    int found = 0;

    printf("Masukkan ID Alat yang akan diedit: ");
    scanf("%u", &id);
    
    // PERBAIKAN: Format fscanf diubah ke ; dan 7 kolom
    while (fscanf(file, "%u;%99[^;];%99[^;];%99[^;];%u;%u;%u\n", 
                &alat.id, alat.nama, alat.merek, alat.model, 
                &alat.tahunProduksi, &alat.jumlahUnit, &alat.tersedia) == 7) {
        
        if (alat.id == id) {
            found = 1;
            printf("Data ditemukan. Masukkan data baru.\n");
            printf("Masukkan Nama Alat: ");
            scanf(" %99[^\n]", alat.nama);
            printf("Masukkan Merek Alat: ");
            scanf(" %99[^\n]", alat.merek);
            printf("Masukkan Model Alat: ");
            scanf(" %99[^\n]", alat.model);
            printf("Masukkan Tahun Produksi Alat: ");
            scanf("%u", &alat.tahunProduksi);
            printf("Masukkan Jumlah Unit Alat: ");
            scanf("%u", &alat.jumlahUnit);
            
            printf("Jumlah tersedia direset ke %u\n", alat.jumlahUnit);
            alat.tersedia = alat.jumlahUnit;
        }
        
        fprintf(temp, "%u;%s;%s;%s;%u;%u;%u\n", 
                alat.id, alat.nama, alat.merek, alat.model, 
                alat.tahunProduksi, alat.jumlahUnit, alat.tersedia);
    }
    fclose(file);
    fclose(temp);

    if (found) {
        remove("../data/alat.txt");
        rename("../data/temp.txt", "../data/alat.txt");
        printf("Data alat berhasil diupdate.\n");
    } else {
        remove("../data/temp.txt");
        printf("Data dengan ID %u tidak ditemukan.\n", id);
    }
}

void hapus_alat(){
    FILE *file = fopen("../data/alat.txt", "r");
    FILE *temp = fopen("../data/temp.txt", "w");
    if (!file || !temp) {
        printf("Gagal membuka file.\n");
        if(file) fclose(file);
        if(temp) fclose(temp);
        return;
    }

    unsigned int id;
    Alat alat; 
    int found = 0;

    printf("Masukkan ID Alat yang akan dihapus: ");
    scanf("%u", &id);

    while (fscanf(file, "%u;%99[^;];%99[^;];%99[^;];%u;%u;%u\n", 
                &alat.id, alat.nama, alat.merek, alat.model, 
                &alat.tahunProduksi, &alat.jumlahUnit, &alat.tersedia) == 7) {
        
        if (alat.id == id) {
            found = 1;
            continue; 
        }
        
        fprintf(temp, "%u;%s;%s;%s;%u;%u;%u\n", 
                alat.id, alat.nama, alat.merek, alat.model, 
                alat.tahunProduksi, alat.jumlahUnit, alat.tersedia);
    }
    fclose(file);
    fclose(temp);

    if (found) {
        remove("../data/alat.txt");
        rename("../data/temp.txt", "../data/alat.txt");
        printf("Data alat berhasil dihapus.\n");
    } else {
        remove("../data/temp.txt");
        printf("Data dengan ID %u tidak ditemukan.\n", id);
    }
}

void menu_admin(){
    int pilihan;
    do {
        printf("\n===== Menu Admin =====\n");
        printf("1. Tampilkan Alat\n");
        printf("2. Tambah Alat\n");
        printf("3. Edit Alat\n");
        printf("4. Hapus Alat\n");
        printf("5. Keluar ke Login Utama\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        
        // Membersihkan buffer stdin
        while(getchar() != '\n'); 

        switch (pilihan) {
            case 1: tampilkan_alat(); break;
            case 2: tambah_alat(); break;
            case 3: edit_alat(); break;
            case 4: hapus_alat(); break;
            case 5: printf("Keluar dari menu admin...\n"); break;
            default: printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 5);
}