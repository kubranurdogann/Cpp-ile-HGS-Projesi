#ifndef HGS2_H
#define HGS2_H
class HGS{
	
    public:
    int kilometre;
    int saat;
    int sinif_bilgisi;
    int para;
    double ucret,bakiye;
    
    HGS(){
    	
    	ucret=0;
    	para=0;
      	srand(time(NULL));
        bakiye=rand()%500;
	}
    
	void bilgi_gir();
    void yazdir();
    double ucret_hesapla(int,double);
    double bakiye_sorgula();
    friend int para_yukleme(HGS &x);
    void ceza(double, int);
    void dekont();
	double birim_fiyat;
	
	
	private:
    string plaka;
};


class OGS {
      
      public:
      	int kilometer;
	    int hour;
	    int classs;
	    int money;
	    double price,balance;

      OGS(){
    	
    	price=0;
    	money=0;
      	srand(time(NULL));
        balance=rand()%500;
	   }
	   
	   
	   void enter_inform();
       void print();
       double wage_calc(int,double);
       double balance_inquiry();
       friend int load_money(OGS &x);
       void punishment(double, int);
       void receipt();
	   double unit_price;
	
	
	   private:
       string license_plate;

};

#endif

