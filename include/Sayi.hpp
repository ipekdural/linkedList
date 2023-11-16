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