#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_TRANSAKSI 100

typedef struct {
    char name[50];
    int stock;
    char category[50]; // Kategori barang (misal: Elektronik, Pakaian, dll)
    float price;  // Harga barang
} Item;

Item store[MAX_ITEMS];
int itemCount = 0;

typedef struct {
    char itemName[50];
    int quantity;
    float totalPrice;
    float diskon;
    float totalSetelahDiskon;
} Laporan;

Laporan laporan[MAX_TRANSAKSI];
int transaksiCount = 0;

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

// Menampilkan semua barang
void tampilanbarang() {
    printf("\nDaftar Barang di Toko:\n");
    if (itemCount == 0) {
        printf("Belum ada barang di toko.\n");
    } else {
        for (int i = 0; i < itemCount; i++) {
            printf("%d. %s - Kategori: %s - Harga: %.2f - Stok: %d\n", i + 1, store[i].name, store[i].category, store[i].price, store[i].stock);
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
    char category[50];
    int stock;
    float price;

    printf("Masukkan nama barang: ");
    scanf(" %[^\n]", name);

    printf("Masukkan kategori barang: ");
    scanf(" %[^\n]", category);

    printf("Masukkan harga barang: ");
    scanf("%f", &price);

    printf("Masukkan jumlah stok awal: ");
    scanf("%d", &stock);

    strcpy(store[itemCount].name, name);
    strcpy(store[itemCount].category, category);
    store[itemCount].price = price;
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

// Fungsi untuk mengurangi stok barang
void kurangiStock() {
    int index, quantityToReduce;

    tampilanbarang();  // Menampilkan semua barang yang ada di toko

    printf("Masukkan nomor barang yang ingin dikurangi stoknya: ");
    scanf("%d", &index);

    if (index < 1 || index > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah stok yang ingin dikurangi: ");
    scanf("%d", &quantityToReduce);

    if (quantityToReduce > store[index - 1].stock) {
        printf("Jumlah pengurangan stok melebihi stok yang ada. Stok saat ini: %d\n", store[index - 1].stock);
        return;
    }

    store[index - 1].stock -= quantityToReduce;
    printf("Stok barang berhasil dikurangi. Stok tersisa: %d\n", store[index - 1].stock);
}

// Fungsi untuk menghitung dan menampilkan poin member
void memberInfo() {
    char nama[50];
    float totalbelanja, PoinMember;
    int notelp;

    printf("=====MASUKKAN MEMBER=====\n");

    getchar();
    printf("\nMasukkan nama anda: ");
    fgets(nama, sizeof(nama), stdin);  // Menggunakan fgets untuk input nama (termasuk spasi)

    printf("\nMasukkan No HP: ");
    scanf("%d", &notelp);

    printf("Masukkan Total Belanja: ");
    scanf("%f", &totalbelanja);

    // Menghitung poin member berdasarkan total belanja
    if (totalbelanja < 50000) {
        PoinMember = 0;
    } else {
        PoinMember = totalbelanja / 50000; 
    }

    printf("=====SELAMAT DATANG MEMBER=====\n");
    printf("Nama            : %s", nama);
    printf("No HP           : %d\n", notelp);
    printf("Total Belanja   : %.2f\n", totalbelanja); 
    printf("Poin Member     : %.0f\n", PoinMember); 
    printf("================================\n");  
}

// Fungsi untuk menghitung pembayaran
void pembayaran() {
    int itemIndex, quantity;
    float totalBayar = 0, diskon = 0, totalSetelahDiskon;

    printf("\n===== PROSES PEMBAYARAN =====\n");
    tampilanbarang();  // Menampilkan daftar barang yang tersedia

    printf("Masukkan nomor barang yang ingin dibeli: ");
    scanf("%d", &itemIndex);

    if (itemIndex < 1 || itemIndex > itemCount) {
        printf("Nomor barang tidak valid.\n");
        return;
    }

    printf("Masukkan jumlah barang yang ingin dibeli: ");
    scanf("%d", &quantity);

    // Memeriksa apakah stok cukup
    if (quantity > store[itemIndex - 1].stock) {
        printf("Stok tidak cukup. Stok saat ini: %d\n", store[itemIndex - 1].stock);
        return;
    }

    // Menghitung total harga
    totalBayar = store[itemIndex - 1].price * quantity;
    printf("Total harga untuk %d %s adalah: %.2f\n", quantity, store[itemIndex - 1].name, totalBayar);

    // Cek diskon jika total pembelian memenuhi syarat
    if (totalBayar >= 200000) {
        diskon = 0.10 * totalBayar;  // Diskon 10%
        totalSetelahDiskon = totalBayar - diskon;
        printf("Anda mendapatkan diskon 10%%: -%.2f\n", diskon);
        printf("Total setelah diskon: %.2f\n", totalSetelahDiskon);
    } else {
        totalSetelahDiskon = totalBayar;
    }

    // Mengurangi stok barang sesuai dengan jumlah yang dibeli
    store[itemIndex - 1].stock -= quantity;

    // Mencatat laporan penjualan
    strcpy(laporan[transaksiCount].itemName, store[itemIndex - 1].name);
    laporan[transaksiCount].quantity = quantity;
    laporan[transaksiCount].totalPrice = totalBayar;
    laporan[transaksiCount].diskon = diskon;
    laporan[transaksiCount].totalSetelahDiskon = totalSetelahDiskon;
    transaksiCount++;

    printf("Pembayaran berhasil! Stok barang yang tersisa: %d\n", store[itemIndex - 1].stock);
    printf("Total yang harus dibayar: %.2f\n", totalSetelahDiskon);
}

// Fungsi untuk menampilkan laporan penjualan
void tampilkanLaporanPenjualan() {
    printf("\n===== LAPORAN PENJUALAN =====\n");
    if (transaksiCount == 0) {
        printf("Belum ada transaksi.\n");
    } else {
        for (int i = 0; i < transaksiCount; i++) {
            printf("Barang: %s\n", laporan[i].itemName);
            printf("Jumlah: %d\n", laporan[i].quantity);
            printf("Total Harga: %.2f\n", laporan[i].totalPrice);
            printf("Diskon: %.2f\n", laporan[i].diskon);
            printf("Total Setelah Diskon: %.2f\n", laporan[i].totalSetelahDiskon);
            printf("---------------------------\n");
        }
    }
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
        printf("5. Mengurangi Stok Barang\n");
        printf("6. Masukkan Member\n");
        printf("7. Proses Pembayaran\n");
        printf("8. Laporan Penjualan\n");
        printf("9. Keluar\n");
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
                kurangiStock();
                break;
            case 6:
                memberInfo();
                break;
            case 7:
                pembayaran();
                break;
            case 8:
                tampilkanLaporanPenjualan(); // Menampilkan laporan penjualan
                break;
            case 9:
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
