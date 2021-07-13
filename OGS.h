#ifndef OGS_H
#define OGS_H

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

