
						/*************[class for item]***********/

class item
{
	private:
		long itcode;
		char itname[15];
		long itqty;
		long itprice;
		char itdeta[50],itqality[15];
	public:
		char *getname()
		{return itname;}
		long int getcode()
		{return itcode;}
		long getqty(int c,int b=1)
		{
			if(b==1)
				return itqty;
			else
			{
				char sitqty[8];
				ltoa(itqty,sitqty,10);
				setcolor(56);
				outtextxy(c,b,sitqty);
			}
		}
		long getprice()
		{return itprice;}
		char *getqality()
		{return itqality;}
		char *getdet()
		{return itdeta;}
		void get_details(long int ic);
		void mod_stk(int ,long );
		void modify();
		void disp_details()      //to display all item
		{
			char sitcode[6],sitqty[8],sitprice[7];
			//ltoa(a,string,2);
			ltoa(itcode,sitcode,10);
			outtextxy(16,87+a,sitcode);
			outtextxy(55,87+a,itname);
			ltoa(itqty,sitqty,10);
			outtextxy(166,87+a,sitqty);
			outtextxy(238,87+a,itqality);
			ltoa(itprice,sitprice,10);
			outtextxy(327,87+a,sitprice);
			outtextxy(412,87+a,itdeta);
			a+=20;
			getch();
		}
		void ind_details()   //to display specific item
		{
			char sitcode[6],sitqty[8],sitprice[7];
			ltoa(itcode,sitcode,10);
			ltoa(itprice,sitprice,10);
			ltoa(itqty,sitqty,10);
			outtextxy(100,137,"code       :");outtextxy(193,137,sitcode);
			outtextxy(100,164,"Name       :");outtextxy(193,164,itname);
			outtextxy(100,191,"Qty        :");outtextxy(193,191,sitqty);
			outtextxy(100,218,"Quality    : ");outtextxy(193,218,itqality);
			outtextxy(100,245,"Price      :");outtextxy(193,245,sitprice);
			outtextxy(100,272,"Description:");outtextxy(193,272,itdeta);
			getch();
		}
		void get_details();
};
void item::get_details(long int ic)//entering details
{
	cleardevice();
	design(2);
	itcode=ic;
	char sitcode[6];
	outtextxy(100,80,"Enter the details");
	ltoa(itcode,sitcode,10);
	outtextxy(100,100,"Item Code: ");setcolor(56);outtextxy(176,100,sitcode);
	setcolor(63);
	outtextxy(100,125,"Item Name: ");
	gotoxy(25,10);gets(itname);
	outtextxy(100,152,"Quantity : ");
	gotoxy(25,12);cin>>itqty;
	outtextxy(100,179,"Quality: ");
	gotoxy(25,14);gets(itqality);
	outtextxy(100,206,"Price : ");
	gotoxy(25,16);cin>>itprice;
	outtextxy(100,235,"Description:");
	gotoxy(25,18);gets(itdeta);
}

void item::mod_stk(int c,long qt)
{
	switch(c)
	{
		case 1:
			itqty+=qt;//arrival/administator
			break;
		case 2:
			itqty-=qt;//customer
			break;
	}
}

void item::modify()
{
	
	int choice;
	char c='n';
	do
	{
		cleardevice();
		design(1);
		outtextxy(170,65,"Modification menu");
		design(2);
		outtextxy(140,125,"1.Item Price");
		outtextxy(140,137,"2.Description");
		outtextxy(140,166,"Enter your choice: ");
		gotoxy(36,13);cin>>choice;
		switch(choice)
		{
			case 1:
				cleardevice();
				design(1);
				outtextxy(170,65,"Price Modification");
				design(2);
				char sitprice[7];
				ltoa(itprice,sitprice,10);
				outtextxy(110,110,"Current price: ");setcolor(56);outtextxy(249,110,sitprice);
				setcolor(63);
				outtextxy(110,125,"Enter the new price: ");
				gotoxy(35,10);cin>>itprice;
				break;
			case 2:
				cleardevice();
				design(1);
				outtextxy(170,65,"Description Modification");
				design(2);
				outtextxy(110,110,"Current description:");setcolor(56);outtextxy(289,110,itdeta);
				setcolor(63);
				outtextxy(110,125,"Enter the new description: ");
				gotoxy(40,10);gets(itdeta);
				
				break;
		}
		outtextxy(100,166,"Do you want to continue(y/n):");
		gotoxy(41,13);cin>>c;
	}while(c=='y'||c=='Y');
}

						/*************[class for customer]***********/
class customer
{
	long cust_id;
	char cust_name[25];
	char address[30],cpassword[15];
	char ph_no[10];

	public:
		long int get_id()
		{
			return cust_id;
		}
		char* get_name()
		{
			return cust_name;
		}
		void getpass(char pass[])
		{
			strcpy(cpassword,pass);
		}
		void disp_cust()      //to display all customer details in tabular form
		{
			char ccust_id[10];
			ltoa(cust_id,ccust_id,10);
			outtextxy(16,87+a,ccust_id);
			outtextxy(100,87+a,cust_name);
			outtextxy(226,87+a,address);
			outtextxy(393,87+a,ph_no);
			a+=20;
		}
		void ind_cust()   //to display specific customer
		{
			char scust_id[10];
			ltoa(cust_id,scust_id,10);
			outtextxy(110,125,"ID          :");outtextxy(210,125,scust_id);
			outtextxy(110,137,"NAME        :");outtextxy(210,137,cust_name);
			outtextxy(110,152,"ADDRESS     :");outtextxy(210,152,address);
			outtextxy(110,164,"PHONE NUMBER:");outtextxy(210,164,ph_no);
			getch();
		}
		void putdata(long );
		void Cust_signup();
};
void customer::putdata(long tcusid)
{
		cleardevice();
		design(2);
		cust_id=tcusid;
		char ccust_id[10];
		ltoa(cust_id,ccust_id,10);
		outtextxy(60,90,"Enter the details");		//entering customer details 
		outtextxy(60,75,"Customer ID     :");setcolor(56);outtextxy(190,75,ccust_id);
		setcolor(63);
		outtextxy(60,110,"Name            :");
		gotoxy(25,9);gets(cust_name);
		outtextxy(60,125,"Address         :");
		gotoxy(25,10);gets(address);
		outtextxy(60,137,"Phone Number    :");
		gotoxy(25,11);gets(ph_no);
		Cust_signup();
}

void customer::Cust_signup()
{
		cleardevice();
		design(1);
		char ccust_id[10];
		ltoa(cust_id,ccust_id,10);
		outtextxy(30,100,"Sigining in.....");
		delay(500);
		cleardevice();
		design(2);
		outtextxy(200,83,"Customer ID:");outtextxy(290,83,ccust_id);
		outtextxy(200,100,"PASSWORD:");
		password();	
}
					/**************[CLASS FOR ORDER]************/

class cust_purchase
{
	long billno;
	long id;			//CUSTOMER ID
	char name[15];
	long price;
	long qty;
	long total;

	public:
		cust_purchase()
		{
			billno=id=price=qty=total=0;
		}
		void gettotal(long tot)
		{total=tot;}
		long int get_B_ID()
		{
			return id;
		}
		void getdetails(long ,long ,long ,long ,char []);
		void disp_bill();
};

void cust_purchase::getdetails(long no,long int gid,long c,long mrp,char na[])
{
	id=gid;
	qty=c;
	billno=no;
	price=mrp;
	strcpy(name,na);
}

void cust_purchase::disp_bill()
{
	cleardevice();
	design(1);
	outtextxy(200,50,"BILL RECIEPT");
	design();
	outtextxy(50,110,"BILL NUMBER:");
	outtextxy(50,125,"ID         :");
	outtextxy(50,137,"Name       :");
	outtextxy(50,152,"Unit Price :");
	outtextxy(50,164,"Quantity   :");
	outtextxy(50,179,"Amount     :");
	
	char sbillno[10],sid[8];
	ltoa(billno,sbillno,10);
	ltoa(id,sid,10);
	outtextxy(150,110,sbillno);
	outtextxy(150,125,sid);
		
	char sqty[10],sprice[10];
    ltoa(price,sprice,10);
	ltoa(qty,sqty,10);
	outtextxy(150,137,name);
	outtextxy(150,152,sprice);
	outtextxy(150,164,sqty);
	long ni;
	ni=price*qty;
	char sni[8];
	ltoa(ni,sni,10);
	outtextxy(150,179,sni);
	char stotal[8];
	ltoa(total,stotal,10);
	outtextxy(110,206,"TOTAL AMOUNT :");outtextxy(267,206,stotal);		
}