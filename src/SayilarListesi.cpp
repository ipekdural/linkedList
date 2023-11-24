#include "SayilarListesi.hpp"
#include <iostream>
#include <iomanip>
#include "Sayi.hpp"
#include "Dugum.hpp"
#include "Basamak.hpp"
#include <fstream>
#include <list>
using namespace std;
SayilarListesi::SayilarListesi()
{
	ilk=0;
}
SayilarListesi::~SayilarListesi()
{
	Dugum* temp =ilk;
	while(temp!=0)
	{
		Dugum* sil =temp;
		temp=temp->sonraki;
		delete sil;

	}
	
}
void SayilarListesi::ekle(const int veri) {
    Dugum* yeni = new Dugum(veri);
    if (ilk == 0) {
        ilk = yeni;
    } else {
        Dugum* tmp = ilk;
        while (tmp->sonraki != 0) {
            tmp = tmp->sonraki;
        }
        tmp->sonraki = yeni;
    }
}

void SayilarListesi::yazdir() {
    Dugum* gec = ilk;
    while (gec != nullptr) {
        // cout<<"dongu1";
        cout << "###########   ";
        for (int i = 0; i < gec->sayi.basamakSayisi(); i++) {
            cout << "******* ";
            // cout<<"dongu2";
        }
        cout << endl;
        cout << "#" << setw(9) << gec << "#   ";
        gec->sayi.yazdirAdres();
        cout << endl;
        cout << "#---------#   ";
        for (int i = 0; i < gec->sayi.basamakSayisi(); i++) {
            cout << "******* ";
        }
        cout << endl;
        cout << "#" << setw(9) << gec->veri << "#   ";
        gec->sayi.yazdirDeger();
        cout << endl;
        cout << "###########   ";
        for (int i = 0; i < gec->sayi.basamakSayisi(); i++) {
            cout << "******* ";
        }
        cout << endl << endl;

        gec = gec->sonraki;
    }
}




void SayilarListesi::basamaklariTersCevir() {
    Dugum* gec = ilk;
    while (gec != nullptr) {
        gec->tersCevir();
        gec->sayi.basamaklariTersCevir();
        gec = gec->sonraki;
    }
}

void SayilarListesi::tersBasamaklariBasaAl() {

    Dugum* gec = ilk;
    while (gec != nullptr) {
        gec->tekBasaAl();
        gec->tersCevirBasamaklar();
        gec = gec->sonraki;
    }
}
void SayilarListesi::enBuyukRakamiSil() {
    Dugum* tmp = ilk;

    // Her düğüm için en büyük rakamı sil
    while (tmp != nullptr) {
        tmp->enBuyukRakamSil();
        tmp->enBuyukRakamiSil();
        tmp = tmp->sonraki;
    }
}

