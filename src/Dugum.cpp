#include "Dugum.hpp"
#include <string>
#include "Sayi.hpp"

Dugum::Dugum(int veri) : veri(veri), sonraki(nullptr) {
   
    int temp = veri;
    while (temp > 0) {
        sayi.ekle(temp % 10);
        temp /= 10;
    }
}

Dugum::~Dugum() {
 
}


void Dugum::tersCevir() {

    int temp = veri;
    int tersVeri = 0;
    while (temp > 0) {
        tersVeri = tersVeri * 10 + temp % 10;
        temp /= 10;
    }
    veri = tersVeri;
}

void Dugum::tekBasaAl() {
    int temp = veri;
    int tersVeri = 0;
    int basamakSayisi = 0;

    while (temp > 0) {
        tersVeri = tersVeri * 10 + temp % 10;
        basamakSayisi++;
        temp /= 10;
    }

    int basamaklar[basamakSayisi];
    int index = 0;

    temp = tersVeri;
    while (temp > 0) {
        int basamak = temp % 10;
        temp /= 10;

        basamaklar[index] = basamak;
        index++;
    }

    temp = 0;
    for (int i = basamakSayisi - 1; i >= 0; i--) {
        if (basamaklar[i] % 2 != 0) {
            temp = temp * 10 + basamaklar[i];
        }
    }

    for (int i = basamakSayisi - 1; i >= 0; i--) {
        if (basamaklar[i] % 2 == 0) {
            temp = temp * 10 + basamaklar[i];
        }
    }

    veri = temp;
}

void Dugum::tersCevirBasamaklar() {
    sayi.tekBasamaklariBasaAl(); 
}


void Dugum::enBuyukRakamiSil() {
    sayi.silEnBuyukRakam();
}

void Dugum::enBuyukRakamSil() {
    int temp = veri;
    int enBuyuk = 0;

    // En büyük rakamı bul
    while (temp > 0) {
        int basamak = temp % 10;
        if (basamak > enBuyuk) {
            enBuyuk = basamak;
        }
        temp /= 10;
    }

    // En büyük rakamı içeren basamağı sil
    temp = veri;
    int yeniVeri = 0;
    int basamakPozisyon = 1;

    while (temp > 0) {
        int basamak = temp % 10;
        if (basamak == enBuyuk) {
            // En büyük rakamı bulduğumuzda, bu basamağı atlayarak devam et
            temp /= 10;
            continue;
        }

        yeniVeri += basamak * basamakPozisyon;
        basamakPozisyon *= 10;
        temp /= 10;
    }

    veri = yeniVeri;
}