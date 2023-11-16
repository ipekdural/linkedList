//sayilarListesi.cpp
#include "SayilarListesi.hpp"
#include <iostream>
#include <iomanip>
#include "Sayi.hpp"
#include "Dugum.hpp"
#include "Basamak.hpp"
#include <fstream>
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
void SayilarListesi::ekle(int veri) {
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


void SayilarListesi::enBuyukRakamiSil() {
    Dugum* tmp = ilk;

    // Her düğüm için en büyük rakamı sil
    while (tmp != nullptr) {
        tmp->enBuyukRakamiSil();
        tmp = tmp->sonraki;
    }
}
//sayilarlistesi.hpp
#ifndef SayilarListesi_hpp
#define SayilarListesi_hpp
#include "Dugum.hpp"

class SayilarListesi
{
public:
    SayilarListesi();
    ~SayilarListesi();
    void ekle(int veri);
    void basamaklariTersCevir();
    void tersBasamaklariBasaAl();
    void yazdir();
    void enBuyukRakamiSil();
   

private:
    Dugum* ilk;  // Dugum sınıfından bir pointer.
};

#endif

//sayi.cpp
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
void Sayi::ekle(int veri)
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


//sayi.hpp
#ifndef Sayi_hpp
#define Sayi_hpp
#include "Basamak.hpp"
class Sayi
{
	public:
		Sayi();
		~Sayi();
		void ekle(int veri);
		void yazdirAdres();
		void yazdirDeger();
		int basamakSayisi();
		void basamaklariTersCevir();
		void tekBasamaklariBasaAl();
		void tersBasamaklariBasaAl();
		void silEnBuyukRakam();
		Basamak* getFirst() const {
        return first;
    }



		
	private:
	
		Basamak* first;
		
};

#endif

//dugum
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


void Dugum::enBuyukRakamiSil() {
    sayi.silEnBuyukRakam();
}
#ifndef Dugum_hpp
#define Dugum_hpp
#include "Sayi.hpp"
class Dugum
{
	public:
		Dugum(int veri);
		~Dugum(); 
		int veri;
		Dugum* sonraki;
		Sayi sayi;
		void tersCevirBasamaklar();
		void tersCevir();
		void tekBasaAl();
		void enBuyukRakamiSil();
		

		
};




#endif

//basamak
#include "Basamak.hpp"
#include <iostream>
using namespace std;
Basamak::Basamak(int veri)
{
	this->veri=veri;
	this->sonraki=0;
}
Basamak::~Basamak()
{
}
#ifndef Basamak_hpp
#define Basamak_hpp
class Basamak
{
	public:
		Basamak(int veri);
		~Basamak(); 
		int veri;
		Basamak* sonraki;
	
		
		
		
};





#endif