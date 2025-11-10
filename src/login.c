#include "../include/utils.h"

int login(char *username, char *password)
{
    char temp_username[maxSize];
    char temp_password[maxSize];

    FILE *fptr;
    // PERBAIKAN: Path file sekarang benar
    fptr = fopen("../data/admin.txt", "r");

    if (fptr == NULL)
    {
        printf("Error : file ../data/admin.txt tidak ditemukan\n");
        return 0;
    }

    while (fscanf(fptr, "%s %s", temp_username, temp_password) == 2)
    {
        if (strcmp(username, temp_username) == 0 && strcmp(password, temp_password) == 0)
        {
            fclose(fptr);
            return 1; // 1 untuk Admin
        }
    }

    fclose(fptr);

    // PERBAIKAN: Path file sekarang benar
    fptr = fopen("../data/user.txt", "r");

    if (fptr == NULL)
    {
        // PERBAIKAN: Pesan error ini salah, sekarang sudah benar
        printf("Error : file ../data/user.txt tidak ditemukan\n");
        return 0;   
    }

    while (fscanf(fptr, "%s %s", temp_username, temp_password) == 2)
    {
        if (strcmp(username, temp_username) == 0 && strcmp(password, temp_password) == 0)
        {
            fclose(fptr);
            return 2; // 2 untuk User
        }
    }
    fclose(fptr);

    printf("Login failed. Username atau password salah.\n");
    return 0; // 0 untuk Gagal
}