#include <iostream>
#include <fstream>
#include <cmath>
#include "Dugum.hpp"
#include "Basamak.hpp"
#include "Sayi.hpp"
#include "SayilarListesi.hpp"
using namespace std;
void menu(){
    	cout<<endl<<endl;
	cout<<"*********************************"<<endl
	    <<"* 1-Tek basamaklari Basa Al.    *"<<endl
		<<"* 2-Basamaklari Tersle.         *"<<endl
		<<"* 3-En Buyuk Cikar.             *"<<endl
		<<"* 4-cikis                       *"<<endl
		<<"*********************************"<<endl<<endl;
}

int main() {
    //dosyadan sayilari cekme
    const char* dosyaAdi = "Sayilar.txt";
    ifstream dosya(dosyaAdi);
    if (!dosya.is_open()) 
    {
        cerr << "Dosya acilamadi: " << dosyaAdi << endl;
        return 1; 
    }


    int number;
    SayilarListesi* sayilar =new SayilarListesi;

    while (dosya >> number)
    {
        int temp = number;
  
        sayilar->ekle(number);
       

        


        
    }         
    while(true)
    { 
       
        sayilar->yazdir();
        menu();
        int choice;
        cin>>choice;
        if(choice==1)
        {
            sayilar->basamaklariTersCevir();
            sayilar->tersBasamaklariBasaAl();
     
        }
        else if(choice==2)
        {
            sayilar->basamaklariTersCevir();
   
        }
        else if(choice==3)
        {
            sayilar->enBuyukRakamiSil();
        }
        else if(choice==4)
        {
            break;
        }
    

    }


 
    delete sayilar;

    dosya.close();


    return 0; 
}
