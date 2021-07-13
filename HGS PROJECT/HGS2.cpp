#include<iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;

#include "HGS2.h"



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
void OGS::enter_inform(){
	start:
	cout<<endl<<"Plese enter license plate"<<endl;
    cin>>license_plate;
    cout<<endl<<"please enter vehicle's class: "<<endl;
    cin>>classs;
	try{
		if(classs>7 || classs<=0) throw 1;
	}	
	catch(int i){
		if(i==1){
			cout<<endl<<"\nIncorrect class information"<<endl;
			goto start;
		}
		
	}
	cout<<endl<<"Please enter kilometer: "<<endl;
    cin>>kilometer;
    cout<<endl<<"Please enter hour: "<<endl;
    cin>>hour;
}



double HGS::ucret_hesapla(int a,double b){
    birim_fiyat=b;
    kilometre=a;
    ucret=a*b;
    
    return ucret; }
double OGS::wage_calc(int a,double b){
	unit_price=b;
	kilometer=a;
	price=a*b;
	return price; }



int para_yukleme(HGS &x){
	
	cout<<endl<<"Mevcut Bakiyeniz: "<<x.bakiye<<"tl."<<endl;
	cout<<endl<<"Yuklemek istediginiz tutari giriniz."; cin>>x.para;

 return 0;	
}
int load_money(OGS &x){
	
	cout<<endl<<"Your balance: "<<x.balance<<endl;
	cout<<endl<<"The amount of money you want to load? "; cin>>x.money;

	
	return 0;
}



double HGS::bakiye_sorgula(){
	
    bakiye+=para;
    cout<<endl<<endl<<"Bakiyeniz: "<<bakiye<<"tl"<<endl;
  
    return 0;
}
double OGS::balance_inquiry(){
	
	balance+=money;
	 cout<<endl<<endl<<"Your balance: "<<balance<<endl;
  
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
void OGS::receipt(){
	int a;
    string text,date;
    cout<<endl<<"What is the date? ";
    cin>>date;
    cout<<endl<<"Plese enter license plate. ";
    cin>>license_plate;
    ofstream dosya("transaction.txt");
    dosya<<"\n..\n"<<money<<"money was loaded on the vehicle with "<<license_plate<<"plate on "<<date<<endl;
	a=balance+money;
	dosya<<"Your balance: "<<a<<endl<<" ..";
	
    dosya.close();
    ifstream dosyaokuma("transaction.txt");
    while(getline(dosyaokuma,text)){
        cout<<text<<endl;
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

void OGS::punishment(double price, int hour){
	this->price=price;
	this->hour=hour;
	
	if(price==0 || hour>24){
		
		cout<<endl<<"\a!!! If it exceeds 24 hours, a fine of 30 TL was given..!!!"<<endl;
		cout<<endl<<"Your Price= "<<price+30<<endl;
		
	}
	else{
         cout<<endl<<"***The transition is successful.***"<<endl;
    }
	
}



void HGS::yazdir(){
    
    cout<<endl<<endl<<"~~~~~";
    cout<<endl<<endl<<"Arac plakasi: "<<plaka<<".\n\n"<<"Gidilen yol: "<<kilometre<<"km ve "<<saat<<"saat."<<endl;
}
void OGS::print(){

	 cout<<endl<<endl<<"~~~~~";
    cout<<endl<<endl<<"Vehicle's license plate: "<<license_plate<<".\n\n"<<kilometer<<"kilometer and "<<hour<<"hour..."<<endl;
	
}




//TURETÝLMÝÞ CLASSLAR
class Sinif1:public HGS{
    public:
    Sinif1():HGS(){
    	birim_fiyat=0.25;
        cout<<"1. sinif arac turu: otomobil/kamyonet/minibus"<<endl;
        cout<<"aks adedi:2 "<<endl;
    }
};


class Sinif2:public HGS{
    public:
    Sinif2():HGS(){
    	birim_fiyat=0.45;
        cout<<"2. sinif arac turu: minibus/kamyonet/otobus"<<endl;
        cout<<"aks adedi: 2"<<endl;
    }
};

class Sinif3:public HGS{
    public:
    Sinif3():HGS(){
    	birim_fiyat=0.50;
        cout<<"3. sinif arac turu: yolcu otobüsü"<<endl; 
        cout<<"aks adedi: 3"<<endl;     
    }
};

class Sinif4:public HGS{
    public:
    Sinif4():HGS(){
    	birim_fiyat=0.65;
        cout<<"4. sinif arac turu: dorseli tir"<<endl;
        cout<<"aks adedi: 4/5"<<endl;
    }
};

class Sinif5:public HGS{
    public:
    Sinif5():HGS(){
    	birim_fiyat=0.80;
        cout<<"5. sinif arac turu: kamyon treyler vb."<<endl;
        cout<<"aks adedi: 6 ve daha fazlasi"<<endl;
    }
};

class Sinif6:public HGS{
    public:
    Sinif6():HGS(){
    	birim_fiyat=1.05;
        cout<<"6. sinif arac turu: motosiklet"<<endl;
        cout<<"aks adedi: 2"<<endl;
    }
};




//DERÝVED CLASSES
class Class1vehicles:public OGS{
	public:
    Class1vehicles():OGS(){
    	unit_price=0.25;
        cout<<"Vehicles with a wheelbase shorter than 3.20 metre are Class 1 vehicles."<<endl;

    }	
};
class Class2vehicles:public OGS{
	public:
    Class2vehicles():OGS(){
    	unit_price=0.45;
        cout<<"All vehicles with 3.20 metre or longer wheelbase and 2 axles are Class 2 vehicles."<<endl;

    }	
};
class Class3vehicles:public OGS{
	public:
    Class3vehicles():OGS(){
    	unit_price=0.50;
        cout<<"All vehicles with 3 axles are Class 3 vehicles."<<endl;
 
    }	
};
class Class4vehicles:public OGS{
	public:
    Class4vehicles():OGS(){
    	unit_price=0.65;
        cout<<"All vehicles with 4 and 5 axles are Class 4 vehicles."<<endl;

    }	
};
class Class5vehicles:public OGS{
	public:
    Class5vehicles():OGS(){
    	unit_price=0.80;
        cout<<"Vehicles such as lorries, trailers etc. With 6 or more axles are Class 5 vehicles."<<endl;
        
    }	
};
class Class6vehicles:public OGS{
	public:
    Class6vehicles():OGS(){
    	unit_price=1.05;
        cout<<"Vehicles such as lorries, trailers etc. With 6 or more axles are Class 5 vehicles."<<endl;

    }	
};





int main()
{
	
	int lang;
	start:
	cout<<"\n\t\t\tChoose your language - Dilini sec: "<<endl;
	cout<<"\t\t\t1- English-Ingilizce\n\t\t\t2- Turkish-Turkce"<<endl;
	
	cin>>lang;
	
	if(lang==1){
		
	OGS vehicle;	
		
	int select;
	string answer="yes";	
	string license_plate;
	start2:
	
	while(answer=="yes"){
		
		cout<<endl<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<".......WELCOME........\n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		cout<<"OPTIONS:"<<endl;
		cout<<endl<<"1::Wage calculation"<<endl;
		cout<<endl<<"2::Balance inquiry"<<endl;
		cout<<endl<<"3::Loading money to the balance"<<endl;
		cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		
		cout<<"\n\nSelect you want to do: ";
		cin>>select;
				
		switch(select){
			
		case 1:
			
			vehicle.enter_inform();
		    vehicle.print();
		    
		    if(vehicle.classs==1){
		        Class1vehicles vehicle1;
		        vehicle1.kilometer=vehicle.kilometer;
		        cout<<endl<<"Price= "<<vehicle1.wage_calc(vehicle1.kilometer,vehicle1.unit_price)<<endl;
				vehicle1.hour=vehicle.hour;
				vehicle1.punishment(vehicle1.price,vehicle1.hour);
			
		    }
		    
		    else if(vehicle.classs==2){
		        Class2vehicles vehicle2;
		        vehicle2.kilometer=vehicle.kilometer;
		        cout<<endl<<"Price= "<<vehicle2.wage_calc(vehicle2.kilometer,vehicle2.unit_price)<<endl;
				vehicle2.hour=vehicle.hour;
				vehicle2.punishment(vehicle2.price,vehicle2.hour);
			
		    }
		    else if(vehicle.classs==3){
		        Class3vehicles vehicle3;
		        vehicle3.kilometer=vehicle.kilometer;
		        cout<<endl<<"Price= "<<vehicle3.wage_calc(vehicle3.kilometer,vehicle3.unit_price)<<endl;
				vehicle3.hour=vehicle.hour;
				vehicle3.punishment(vehicle3.price,vehicle3.hour);
			
		    }
		    else if(vehicle.classs==4){
		        Class4vehicles vehicle4;
		        vehicle4.kilometer=vehicle.kilometer;
		        cout<<endl<<"Price= "<<vehicle4.wage_calc(vehicle4.kilometer,vehicle4.unit_price)<<endl;
				vehicle4.hour=vehicle.hour;
				vehicle4.punishment(vehicle4.price,vehicle4.hour);
			
		    }
		    else if(vehicle.classs==5){
		        Class5vehicles vehicle5;
		        vehicle5.kilometer=vehicle.kilometer;
		        cout<<endl<<"Price= "<<vehicle5.wage_calc(vehicle5.kilometer,vehicle5.unit_price)<<endl;
				vehicle5.hour=vehicle.hour;
				vehicle5.punishment(vehicle5.price,vehicle5.hour);
				
		    }
		    else if(vehicle.classs==6){
		        Class6vehicles vehicle6;
		        vehicle6.kilometer=vehicle.kilometer;
		        cout<<endl<<"Price= "<<vehicle6.wage_calc(vehicle6.kilometer,vehicle6.unit_price)<<endl;
				vehicle6.hour=vehicle.hour;
				vehicle6.punishment(vehicle6.price,vehicle6.hour);
			
		    }

    	break;
		case 2:
			 cout<<endl<<"Pls enter the license plate: "<<endl;
		     cin>>license_plate;
		     vehicle.balance_inquiry();
		break;
		case 3:
			load_money(vehicle);
            vehicle.receipt();
    
    	break;
    	
		default:  cout<<"invalid operation. try again..";
		goto start2;	
		}	
		
	cout<<endl<<"Do you want to continue? yes or no..";
	cin>>answer;
		
	}
	
		
	}
	
	else if(lang==2){
	
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

   } }
   
return 0;
}
