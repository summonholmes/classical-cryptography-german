#include <stdio.h>
#include <math.h>
#include "PreProcess_German.h"
#include "ASCII_30_Add.h"
#include "EncryptAffine_German.h"
#include "ASCII_Enc_German.h"
#include "ASCII_Dec_German.h"
#include "ExtendedEuclidean.h"
#include "DecryptAffine_German.h"
#include "ASCII_30_Del.h"

void PreProcess_German(char *,char *);
void ASCII_30_Add(int *, int *, int *);
void EncryptAffine_German(int *, int *, int *, int *, int *);
void ASCII_Enc_German(int *, int *, int *);
void ASCII_Dec_German(int *, int *, int *);
void ExtendedEuclidean(int *, int *, int *);
void DecryptAffine_German(int *, int *, int *, int *, int *, int *, int *);
void ASCII_30_Del(int *, int *, int *);

int main()
{
    FILE *f;
    int array_len_raw = 3442; int array_len = 2745;
    char rawtext[array_len_raw]; char plaintext[array_len];
    int a = 7; int b = 5; int k = 30; int z[3];
    int plaintext_ascii[array_len];
    int plaintext_ascii_30[array_len];
    int ciphertext_ascii_30[array_len];
    int ciphertext_ascii[array_len];
    int ciphertext_ascii_dec_30[array_len];
    int dectext_ascii_30[array_len];
    int dectext_ascii[array_len];
    
    f = fopen("nachtlied-utf-8.txt", "r");
    if (!f) {printf("File not found!"); return 1;}
    fread(rawtext, 1, array_len_raw, f);
    fclose(f);
    
    PreProcess_German(rawtext, plaintext);
    for (int i = 0; i < array_len; i++) {plaintext_ascii[i] = plaintext[i];}

    ASCII_30_Add(plaintext_ascii, &array_len, plaintext_ascii_30);
    EncryptAffine_German(plaintext_ascii_30, &a, &b, &array_len, ciphertext_ascii_30);
    ASCII_Enc_German(ciphertext_ascii_30, &array_len, ciphertext_ascii);
    ASCII_Dec_German(ciphertext_ascii, &array_len, ciphertext_ascii_dec_30);
    DecryptAffine_German(ciphertext_ascii_dec_30, &a, &b, &k, z, &array_len, dectext_ascii_30);
    ASCII_30_Del(dectext_ascii_30, &array_len, dectext_ascii);
    
    for (int i = 300; i < 400; i++) {printf("%c", plaintext[i]);} printf("\n");
    for (int i = 396; i < 501; i++) {printf("%c", ciphertext_ascii[i]);} printf("\n");
    for (int i = 300; i < 400; i++) {printf("%c", dectext_ascii[i]);} printf("\n");

    return 0;
}