#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;

#include "HGS.h"

void HGS::bilgi_gir(){
	baslangic_noktasi:
    cout<<endl<<"lutfen plaka bilgisi giriniz: "<<endl;
    cin>>plaka;
    cout<<endl<<"lutfen sinif bilgisini giriniz: "<<endl;
    cin>>sinif_bilgisi;
    try
    {
        if(sinif_bilgisi>7 || sinif_bilgisi<=0) throw 1;

    }
    catch(int i)
    {
        if(i==1){
            cout<<endl<<"\nEslesen sinif bilgisi bulunamadi\n"<<endl;
            goto baslangic_noktasi;
        }

    }
    cout<<endl<<"lutfen kilometre bilgisini giriniz: "<<endl;
    cin>>kilometre;
    cout<<endl<<"lutfen saat bilgisini giriniz: "<<endl;
    cin>>saat;
    
}

double HGS::ucret_hesapla(int a,double b){
    birim_fiyat=b;
    kilometre=a;
    ucret=a*b;
    return ucret;                                  
}

int para_yukleme(HGS &x){
	
	cout<<endl<<"Mevcut Bakiyeniz: "<<x.bakiye<<"tl."<<endl;
	cout<<endl<<"Yuklemek istediginiz tutari giriniz."; cin>>x.para;

 return 0;	
}

double HGS::bakiye_sorgula(){
	
    bakiye+=para;
    cout<<endl<<endl<<"Bakiyeniz: "<<bakiye<<"tl"<<endl;
  
    return 0;
}



void HGS::dekont(){
	int a;
    string metin,tarih;
    cout<<endl<<"tarih bilgisini giriniz. ";
    cin>>tarih;
    cout<<endl<<"lutfen plaka bilgisini giriniz. ";
    cin>>plaka;
    ofstream dosya("islemozeti.txt");
    dosya<<"\n..\n"<<plaka<<" plakali araca "<<tarih<<" tarihinde "<<para<< "tl tutarinda para yukleme islemi \nbasariyla  gerceklestirilmistir"<<endl;
	a=bakiye+para;
	dosya<<"Mevcut bakiye: "<<a<<"tl."<<endl<<"..";
	
    dosya.close();
    ifstream dosyaokuma("islemozeti.txt");
    while(getline(dosyaokuma,metin)){
        cout<<metin<<endl;
    }
}


void HGS::ceza(double ucret,int saat){
    this->ucret=ucret;
    this->saat=saat;
   
    if(bakiye==0 || saat>24){
        
		cout<<endl<<"\a!!! Bilgilendirme: 24 saati gectigi icin 30 tl para cezasi kesilmistir.!!!"<<endl;
		cout<<endl<<"Net ucret= "<<ucret+30<<"tl"<<endl;    
        
    }
    else{
         cout<<endl<<"***Basarili gecis***"<<endl;
    }
    
}


void HGS::yazdir(){
    
    cout<<endl<<endl<<"~~~~~";
    cout<<endl<<endl<<"Arac plakasi: "<<plaka<<".\n\n"<<"Gidilen yol: "<<kilometre<<"km ve "<<saat<<"saat."<<endl;
}



class Sinif1:public HGS{
    public:
    double birim_fiyat;
    Sinif1():HGS(){
    	birim_fiyat=0.25;
        cout<<"1. sinif arac turu: otomobil/kamyonet/minibus"<<endl;
        cout<<"aks adedi:2 "<<endl;
    }
};

class Sinif2:public HGS{
    public:
    double birim_fiyat;
    Sinif2():HGS(){
    	birim_fiyat=0.45;
        cout<<"2. sinif arac turu: minibus/kamyonet/otobus"<<endl;
        cout<<"aks adedi: 2"<<endl;
    }
};

class Sinif3:public HGS{
    public:
    double birim_fiyat;
    Sinif3():HGS(){
    	birim_fiyat=0.50;
        cout<<"3. sinif arac turu: yolcu otobüsü"<<endl; 
        cout<<"aks adedi: 3"<<endl;     
    }
};

class Sinif4:public HGS{
    public:
    double birim_fiyat;
    Sinif4():HGS(){
    	birim_fiyat=0.65;
        cout<<"4. sinif arac turu: dorseli tir"<<endl;
        cout<<"aks adedi: 4/5"<<endl;
    }
};

class Sinif5:public HGS{
    public:
    double birim_fiyat;
    Sinif5():HGS(){
    	birim_fiyat=0.80;
        cout<<"5. sinif arac turu: kamyon treyler vb."<<endl;
        cout<<"aks adedi: 6 ve daha fazlasi"<<endl;
    }
};

class Sinif6:public HGS{
    public:
    double birim_fiyat;
    Sinif6():HGS(){
    	birim_fiyat=1.05;
        cout<<"6. sinif arac turu: motosiklet"<<endl;
        cout<<"aks adedi: 2"<<endl;
    }
};



int main()
{
	HGS arac;
	
	int secim;
	string cevap="evet";
	string plaka;
	
	
	
	while(cevap=="evet"){
		
	
	cout<<endl<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<".......HIZLI GECIS SISTEMINE HOSGELDINIZ........\n";
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	cout<<"ISLEMLER:"<<endl;
	cout<<endl<<"1::Ucret Hesaplama"<<endl;
	cout<<endl<<"2::Bakiye Sorgulama"<<endl;
	cout<<endl<<"3::Bakiyeye para Yukleme"<<endl;
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	
	cout<<"\n\nYapmak istediginiz islemi seciniz: ";
	cin>>secim;
	
    switch(secim){
    	
    	case 1:
    		
	    arac.bilgi_gir();
	    arac.yazdir();
	    
	    if(arac.sinif_bilgisi==1){
	        Sinif1 arac1;
	        arac1.kilometre=arac.kilometre;
	        cout<<endl<<"ucret= "<<arac1.ucret_hesapla(arac1.kilometre,arac1.birim_fiyat)<<endl;
			arac1.saat=arac.saat;
			arac1.ceza(arac1.ucret,arac1.saat);
		
	    }
	    
	    else if(arac.sinif_bilgisi==2){
	        Sinif2 arac2;
	        arac2.kilometre=arac.kilometre;
	        cout<<endl<<"ucret= "<<arac2.ucret_hesapla(arac2.kilometre,arac2.birim_fiyat)<<endl;
	        
			arac2.saat=arac.saat;
			arac2.ceza(arac2.ucret,arac2.saat);
	    }
	    else if(arac.sinif_bilgisi==3){
	        Sinif3 arac3;
	        arac3.kilometre=arac.kilometre;
	        cout<<endl<<"ucret= "<<arac3.ucret_hesapla(arac3.kilometre,arac3.birim_fiyat)<<endl;
	        
			arac3.saat=arac.saat;
			arac3.ceza(arac3.ucret,arac3.saat);
	    }
	    else if(arac.sinif_bilgisi==4){
	        Sinif4 arac4;
	        arac4.kilometre=arac.kilometre;
	        cout<<endl<<"ucret= "<<arac4.ucret_hesapla(arac4.kilometre,arac4.birim_fiyat)<<endl;
	        
			arac4.saat=arac.saat;
			arac4.ceza(arac4.ucret,arac4.saat);
	    }
	    else if(arac.sinif_bilgisi==5){
	        Sinif5 arac5;
	        arac5.kilometre=arac.kilometre;
	        cout<<endl<<"ucret= "<<arac5.ucret_hesapla(arac5.kilometre,arac5.birim_fiyat)<<endl;
	        
			arac5.saat=arac.saat;
			arac5.ceza(arac5.ucret,arac5.saat);	
	    }
	    else if(arac.sinif_bilgisi==6){
	        Sinif6 arac6;
	        arac6.kilometre=arac.kilometre;
	        cout<<endl<<"ucret= "<<arac6.ucret_hesapla(arac6.kilometre,arac6.birim_fiyat)<<endl;
	        
			arac6.saat=arac.saat;
			arac6.ceza(arac6.ucret,arac6.saat);	
	    }

    	break;
    	
    	case 2:
    	 
		 cout<<endl<<"Lutfen Plaka Bilgisi Giriniz: "<<endl;
		 cin>>plaka;
		 arac.bakiye_sorgula();
		break;
		
		case 3:	
    	
    	para_yukleme(arac);
        arac.dekont();
    
    	break;
    	
		default:
    	cout<<"Gecersiz islem.";
	}
	
	cout<<endl<<"Devam etmek ister misin? evet veya hayir giriniz..";
	cin>>cevap;

}
return 0;
}
