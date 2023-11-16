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
		void enBuyukRakamSil();

		
};





#endif