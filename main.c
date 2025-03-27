#include "caseLogic.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    daftarKota arrKota[5];
    for (int i = 0; i < 5; i++) {
        arrKota[i].namaKota = NULL;
        arrKota[i].pKota = (List*)malloc(sizeof(List));
        createList(arrKota[i].pKota);
    }
    initDaftarKota(arrKota, 5);

    int choice, index;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Nama\n2. Hapus Nama\n3. Cari Nama\n");
        printf("4. Tampilkan Jumlah per Kota\n5. Tampilkan Total Data\n6. Keluar\nPilih: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Pilih kota (1-5): ");
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > 5 || arrKota[index-1].namaKota == NULL) {
                    printf("Kota tidak valid.\n");
                    break;
                }
                addNamaMenu(arrKota[index-1].pKota);
                break;
            case 2:
                printf("Pilih kota (1-5): ");
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > 5 || arrKota[index-1].namaKota == NULL) {
                    printf("Kota tidak valid.\n");
                    break;
                }
                removeNamaMenu(arrKota[index-1].pKota);
                break;
            case 3:
                printf("Pilih kota (1-5): ");
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > 5 || arrKota[index-1].namaKota == NULL) {
                    printf("Kota tidak valid.\n");
                    break;
                }
                searchNama(arrKota[index-1].pKota);
                break;
            case 4:
                printData(arrKota, 5);
                break;
            case 5:
                printDataTotal(arrKota, 5);
                break;
            case 6:
                for (int i = 0; i < 5; i++) {
                    if (arrKota[i].namaKota != NULL) {
                        deleteList(arrKota[i].pKota);
                        free(arrKota[i].namaKota);
                    }
                    free(arrKota[i].pKota);
                }
                exit(0);
            default:
                printf("Pilihan tidak valid.\n");
        }
    }
    return 0;
}
