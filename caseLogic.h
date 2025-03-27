#ifndef CASELOGIC_H
#define CASELOGIC_H

#include "structure.h"

typedef struct {
    string namaKota;
    List* pKota;
} daftarKota;

void initDaftarKota(daftarKota arrKota[], int size);
void addKota(daftarKota arrKota[], int size);
void delKota(daftarKota arrKota[], int index);
void addNama(List* list);
void addNamaMenu(List* list);
void removeNama(List* list);
void removeNamaMenu(List* list);
void searchNama(List* list);
void printData(daftarKota arrKota[], int size);
void printDataTotal(daftarKota arrKota[], int size);

#endif
