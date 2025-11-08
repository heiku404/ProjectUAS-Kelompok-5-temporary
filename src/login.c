#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char username[20];
    char password[20];

    // Jika username dan password dimasukkan lewat terminal
    if (argc == 3) {
        strcpy(username, argv[1]);
        strcpy(password, argv[2]);
    } 
    // Jika tidak, minta input langsung
    else {
        printf("=== LOGIN SISTEM PEMINJAMAN ALAT LAB ===\n");
        printf("Masukkan username: ");
        scanf("%s", username);
        printf("Masukkan password: ");
        scanf("%s", password);
    }

    // Username dan password yang benar
    char user_benar[] = "admin";
    char pass_benar[] = "12345";
    // Mengecek apakah sesuai
    if (strcmp(username, user_benar) == 0 && strcmp(password, pass_benar) == 0) {
        printf("Login berhasil! Selamat datang, %s.\n", username);
    } else {
        printf("Login gagal! Username atau password salah.\n");
    }

    return 0;
}
