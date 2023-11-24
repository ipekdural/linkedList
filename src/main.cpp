#include <iostream>
#include <fstream>
#include <cmath>
#include "Dugum.hpp"
#include <limits>
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
    const char* dosya_ismi = "Sayilar.txt";
    ifstream dosya(dosya_ismi);
    if (!dosya.is_open()) 
    {
        cerr << "Dosya acilamadi: " << dosya_ismi << endl;
        return 1; 
    }


    int number;
    SayilarListesi* number_list =new SayilarListesi;

    while (dosya >> number)
    {
        int temp = number;
  
        number_list->ekle(number);
       

        


        
    }   
    bool devam_mi=true;      
    while(devam_mi)
    { 
       
        number_list->yazdir();
        menu();
        string _choice;
        cin>>_choice;
        if(_choice=="1" || _choice=="2" || _choice=="3" || _choice=="4" )
    {      if(_choice=="1")
            {
                number_list->basamaklariTersCevir();
                number_list->tersBasamaklariBasaAl();
        
            }
            else if(_choice=="2")
            {
                number_list->basamaklariTersCevir();
    
            }
            else if(_choice=="3")
            {
                number_list->enBuyukRakamiSil();
            }
            else if(_choice=="4")
            {
                cout<<"Cikis yapiliyor...";
                devam_mi=false;
            }}
        else{
              cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Tamponu temizle
            string kullanici_girisi;

            cout << "Gecersiz islem. Devam etmek icin 'y' ye basiniz."<<endl<<"Cikmak icin herhangi bir tusa basiniz.";
            cin>>kullanici_girisi;

            if (kullanici_girisi == "y" || kullanici_girisi=="n") {
                devam_mi = true;
            }
            else{
                cout<<"Cikis yapiliyor...";
                devam_mi=false;
            }

        }
    

    }


 
    delete number_list;

    dosya.close();


 
}
