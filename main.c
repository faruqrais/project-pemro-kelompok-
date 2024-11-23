#include <stdio.h>
#include <string.h>                                                                            // Untuk strcmp

int main() {
    char username[100];
    char password[100];

    printf("Masukkan username Anda: ");
    scanf("%s", username); 

    printf("Masukkan password Anda: ");
    scanf("%s", password);                                                                    // Membaca password

    
    if ((strcmp(username, "kelompok") == 0) && (strcmp(password, "admin123") == 0)) {
        printf("Selamat Anda berhasil login\n");
    } else {
        printf("Maaf, username atau password Anda salah\n");
    }

    return 0;
}
