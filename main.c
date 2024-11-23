#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int stock;
} Item;

Item store[MAX_ITEMS];
int itemCount = 0;

// Fungsi login
int login() {
    char username[100];
    char password[100];

    printf("Masukkan username Anda: ");
    scanf("%s", username);

    printf("Masukkan password Anda: ");
    scanf("%s", password);

    if ((strcmp(username, "kelompok4") == 0) && (strcmp(password, "admin123") == 0)) {
        printf("Selamat, Anda berhasil login!\n\n");
        return 1;
    } else {
        printf("Maaf, username atau password Anda salah.\n");
        return 0;
    }
}

// Menampilkan semua barang
void tampilanbarang() {
    printf("\nDaftar Barang di Toko:\n");
    if (itemCount == 0) {
        printf("Belum ada barang di toko.\n");
    } else {
        for (int i = 0; i < itemCount; i++) {
            printf("%d. %s - Stok: %d\n", i + 1, store[i].name, store[i].stock);
        }
    }
    printf("\n");
}

// Menambahkan barang baru
void tambahbarang() {
    if (itemCount >= MAX_ITEMS) {
        printf("Toko penuh, tidak bisa menambah barang baru.\n");
        return;
    }

    char name[50];
    int stock;
    printf("Masukkan nama barang: ");
    scanf(" %[^\n]", name);
    printf("Masukkan jumlah stok awal: ");
    scanf("%d", &stock);

    strcpy(store[itemCount].name, name);
    store[itemCount].stock = stock;
    itemCount++;

    printf("Barang berhasil ditambahkan!\n");
}

// Menghapus barang
void hapusbarang() {
    int index;
    tampilanbarang();
    printf("Masukkan nomor barang yang ingin dihapus: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    // Menggeser barang ke atas
    for (int i = index - 1; i < itemCount - 1; i++) {
        store[i] = store[i + 1];
    }
    itemCount--;

    printf("Barang berhasil dihapus!\n");
}

// Menambah stok barang
void tambahstock() {
    int index, additionalStock;
    tampilanbarang();
    printf("Masukkan nomor barang yang ingin ditambah stoknya: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah stok yang ingin ditambahkan: ");
    scanf("%d", &additionalStock);

    store[index - 1].stock += additionalStock;
    printf("Stok berhasil ditambahkan!\n");
}

// Menu utama
void menu() {
    int choice;

    while (1) {
        printf("\nMenu Toko:\n");
        printf("1. Tampilkan Barang\n");
        printf("2. Tambah Barang Baru\n");
        printf("3. Hapus Barang\n");
        printf("4. Tambah Stok Barang\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                tampilanbarang();
                break;
            case 2:
                tambahbarang();
                break;
            case 3:
                hapusbarang();
                break;
            case 4:
                tambahstock();
                break;
            case 5:
                printf("Terima kasih telah menggunakan program ini!\n");
                return;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    }
}

int main() {
    if (login()) {
        menu();
    }
    return 0;
}
