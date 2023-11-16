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