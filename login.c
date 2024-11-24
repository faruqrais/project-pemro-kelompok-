#include <stdio.h>
#include <string.h>

// Fungsi login
int login() {
    char username[100];
    char password[100];

    printf("Masukkan username Anda: ");
    scanf("%s", username);
    printf("Masukkan password Anda: ");
    scanf("%s", password);

    if ((strcmp(username, "kelompok") == 0) && (strcmp(password, "empat") == 0)) {
        printf("Selamat, Anda berhasil login!\n\n");
        return 1;
    } else {
        printf("Maaf, username atau password Anda salah.\n");
        return 0;
    }
}

int main() {
    if (login()) {
        printf("Anda telah masuk ke sistem.\n");
    } else {
        printf("Gagal login. Program selesai.\n");
    }
    return 0;
}