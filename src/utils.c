#include <stdio.h>
#include "utils.h"
int fileKosong (const char*namaFile){
    FILE *fp = fopen ("alat.txt", "r");
    if (fp == NULL){
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);

    if (size == 0)
        return 1;  // kosong
    else
        return 0;  // ada isi
}

int cariAlatById(unsigned int id, Alat *out) {
    FILE *fp = fopen("alat.txt", "r");
    if (fp == NULL){
        printf("file tidak ditemukan");
        return 0;
    }
    char line[256];
    while(fgets(line,sizeof(line), fp)!= NULL){
        unsigned int tid, ttahun, tjumlah;
        char tnama[50], tmerek[30], tmodel[30];

        int parsed = sscanf(line, %u|%49[^|]|%29[^|]|%29[^|]|%u|%u"
    }