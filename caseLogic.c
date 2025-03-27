#include "caseLogic.h"

void initDaftarKota(daftarKota arrKota[], int size) {
    char buffer[256];
    for (int i = 0; i < size; i++) {
        printf("Masukkan nama kota ke-%d: ", i + 1);
        fgets(buffer, 256, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        arrKota[i].namaKota = strdup(buffer);
        arrKota[i].pKota = (List*)malloc(sizeof(List));
        createList(arrKota[i].pKota);
    }
}

void addKota(daftarKota arrKota[], int size) {
    char buffer[256];
    for (int i = 0; i < size; i++) {
        if (arrKota[i].namaKota == NULL) {
            printf("Masukkan nama kota ke-%d: ", i + 1);
            fgets(buffer, 256, stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            arrKota[i].namaKota = strdup(buffer);
            createList(arrKota[i].pKota);
            return;
        }
    }
    printf("Semua slot kota sudah terisi.\n");
}

void delKota(daftarKota arrKota[], int index) {
    if (index < 0 || index >= 5) {
        printf("Indeks tidak valid.\n");
        return;
    }
    if (arrKota[index].namaKota == NULL) {
        printf("Kota pada indeks %d tidak ada.\n", index);
        return;
    }
    deleteList(arrKota[index].pKota);
    free(arrKota[index].namaKota);
    arrKota[index].namaKota = NULL;
}

void addNama(List* list) {
    char buffer[256];
    printf("Masukkan nama: ");
    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    elmtAddress newNode = allocate(buffer);
    if (newNode == NULL) {
        printf("Alokasi gagal.\n");
        return;
    }
    insRear(list, newNode);
}

void addNamaMenu(List* list) {
    int choice;
    char buffer[256];
    unsigned int pos;
    printf("1. Tambah di depan\n2. Tambah di belakang\n3. Tambah manual\nPilih: ");
    scanf("%d", &choice);
    getchar();
    printf("Masukkan nama: ");
    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    elmtAddress newNode = allocate(buffer);
    if (newNode == NULL) {
        printf("Alokasi gagal.\n");
        return;
    }
    switch (choice) {
        case 1: insFront(list, newNode); break;
        case 2: insRear(list, newNode); break;
        case 3:
            printf("Masukkan posisi: ");
            scanf("%u", &pos);
            getchar();
            insManual(list, newNode, pos);
            break;
        default: printf("Pilihan tidak valid.\n");
    }
}

void removeNama(List* list) {
    if (listEmpty(*list)) {
        printf("List kosong.\n");
        return;
    }
    delRear(list);
}

void removeNamaMenu(List* list) {
    int choice;
    unsigned int pos;
    printf("1. Hapus di depan\n2. Hapus di belakang\n3. Hapus manual\nPilih: ");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
        case 1: delFront(list); break;
        case 2: delRear(list); break;
        case 3:
            printf("Masukkan posisi: ");
            scanf("%u", &pos);
            getchar();
            delManual(list, pos);
            break;
        default: printf("Pilihan tidak valid.\n");
    }
}

void searchNama(List* list) {
    char buffer[256];
    printf("Masukkan nama yang dicari: ");
    fgets(buffer, 256, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    elmtAddress result = searchList(*list, buffer);
    if (result != NULL)
        printf("Ditemukan: %s\n", result->nama);
    else
        printf("Tidak ditemukan.\n");
}

void printData(daftarKota arrKota[], int size) {
    for (int i = 0; i < size; i++) {
        if (arrKota[i].namaKota != NULL) {
            printf("Kota: %s\n", arrKota[i].namaKota);
            printList(*(arrKota[i].pKota));
            printf("\n");
        }
    }
}

void printDataTotal(daftarKota arrKota[], int size) {
    int totalKota = 0, totalNama = 0;
    for (int i = 0; i < size; i++) {
        if (arrKota[i].namaKota != NULL) {
            totalKota++;
            int count = getTotalElmt(*(arrKota[i].pKota));
            totalNama += count;
            printf("%s: %d nama\n", arrKota[i].namaKota, count);
        }
    }
    printf("Total kota: %d\n", totalKota);
    printf("Total nama: %d\n", totalNama);
}
