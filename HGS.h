o#ifndef HGS_H
#define HGS_H
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
#endif

