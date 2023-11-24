#include "Sayi.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Basamak.hpp"
using namespace std;
Sayi::Sayi()
{
	first=0;
}
Sayi::~Sayi()
{
	Basamak* temp =first;
	while(temp!=0)
	{
		Basamak* sil =temp;
		temp=temp->sonraki;
		delete sil;
        

	}
	
}
void Sayi::ekle(const int veri)
{
	 Basamak* yeni = new Basamak(veri);
    yeni->sonraki = first; // yrni basamagin sonraki referansını ilk dugume bagladin
    first = yeni; 

}

void Sayi::yazdirAdres()
{
	Basamak* tmp=first;
	

	
	while (tmp!=0)
		{
			
			   
				std::stringstream ss;
				ss << std::hex << tmp;
				std::string tmpStr = ss.str();
				std::string sonUcKarakter = tmpStr.substr(tmpStr.length() - 3);
				cout<<"* "<<setw(3)<<sonUcKarakter<<" * ";
		
			
			tmp=tmp->sonraki;
			
			
		}
		
 
}
void Sayi::yazdirDeger()
{
	Basamak* tmp=first;
	while (tmp!=0)
		{
			
				cout<<"*"<<setw(4)<<tmp->veri<<" * ";
			
			tmp=tmp->sonraki;
			
			
		}

}
int Sayi::basamakSayisi()
{
	Basamak* tmp=first;
	int basamak_sayisi=0;
	while (tmp!=0)
		{
			basamak_sayisi++;
			
			tmp=tmp->sonraki;
		}
		return basamak_sayisi;
}
void Sayi::basamaklariTersCevir() {
    Basamak* onceki = nullptr;
    Basamak* suanki = first;
    Basamak* sonraki = nullptr;

    while (suanki != nullptr) {
        sonraki = suanki->sonraki;
        suanki->sonraki = onceki;
        onceki = suanki;
        suanki = sonraki;
    }

    first = onceki; 
}




void Sayi::tekBasamaklariBasaAl() {
    Basamak* tmp = first;
    Basamak* basaAlinan = nullptr;
    Basamak* sonaEklenecekler = nullptr;

    while (tmp != nullptr) {
        Basamak* aktif = tmp;
        tmp = tmp->sonraki;

        if (aktif->veri % 2 != 0) {
            aktif->sonraki = basaAlinan;
            basaAlinan = aktif;
        } else {
            aktif->sonraki = sonaEklenecekler;
            sonaEklenecekler = aktif;
        }
    }

  
    if (basaAlinan == nullptr) {
        first = sonaEklenecekler;
    } else {
        Basamak* son = basaAlinan;
        while (son->sonraki != nullptr) {
            son = son->sonraki;
        }
        son->sonraki = sonaEklenecekler;
        first = basaAlinan;
    }
}

void Sayi::tersBasamaklariBasaAl() {
    tekBasamaklariBasaAl();
    Basamak* tmp = first;
    Basamak* basaAlinan = nullptr;
    Basamak* sonaEklenecekler = nullptr;

    while (tmp != nullptr) {
        Basamak* aktif = tmp;
        tmp = tmp->sonraki;

        if (aktif->veri % 2 == 0) {
            aktif->sonraki = sonaEklenecekler;
            sonaEklenecekler = aktif;
        } else {
            aktif->sonraki = basaAlinan;
            basaAlinan = aktif;
        }
    }

 
    tmp = first;
    while (tmp != nullptr) {
        Basamak* sil = tmp;
        tmp = tmp->sonraki;
        delete sil;
    }

    first = basaAlinan;
}

void Sayi::silEnBuyukRakam() {
    Basamak* tmp = first;
    Basamak* enBuyukRakam = nullptr;

    // En büyük rakamı bul
    while (tmp != nullptr) {
        if (enBuyukRakam == nullptr || tmp->veri > enBuyukRakam->veri) {
            enBuyukRakam = tmp;
        }
        tmp = tmp->sonraki;
    }

    // En büyük rakamı içeren basamağı sil
    if (enBuyukRakam != nullptr) {
        Basamak* prev = nullptr;
        tmp = first;
        while (tmp != enBuyukRakam) {
            prev = tmp;
            tmp = tmp->sonraki;
        }

        if (prev == nullptr) {
            first = enBuyukRakam->sonraki;
        } else {
            prev->sonraki = enBuyukRakam->sonraki;
        }

        delete enBuyukRakam;
    }
}

