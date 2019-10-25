void design(int d)
{
	setcolor(56);
	setlinestyle(0,2,3);
	line(200,37,423,37);
	setlinestyle(0,0,3);
	rectangle(2,2,637,50);
	rectangle(2,2,638,348);
	setcolor(63);
	settextstyle(1,0,5);
	outtextxy(200,-8,"Metal Corp.");
	setlinestyle(0,SOLID_FILL,1);
	if(d==1)
	settextstyle(1,0,3);
	if(d==2)
		settextstyle(2,0,5);
}

						/*************[Function for adding item]***********/

void additem()
{  
	cleardevice();
	design();
	item t;
	fstream item("ITEM.DAT",ios::in|ios::out|ios::binary|ios::ate);
	
	if(!item)
	{
		outtextxy(130,150,"Sorry File Doesn't Exist!!...");
		return;
	}
	long itc;
	
	if(item.tellg()==0)
		itc=99;
	else
	{
		item.seekg(item.tellg()-sizeof(t));
		item.read((char*)&t,sizeof(t));
		itc=t.getcode();
	}
	char c='y';
	do
	{
		itc+=1;
		t.get_details(itc);
		item.write((char*)&t,sizeof(t));
		outtextxy(101,263,"Do you want to add more(y/n): ");
		gotoxy(42,20);cin>>c;
	}while(c=='y'||c=='Y');
	getch();
	item.close();
}
						/*************[Function for deleting item]***********/

void delitem()
{
	cleardevice();
	design();
	item T;
	ifstream ditem("ITEM.DAT",ios::in|ios::binary);
	ofstream dtemp("TEMP.DAT",ios::out|ios::binary);
	
	int code;
	char found='n',confirm='n';
	
	outtextxy(50,110,"Enter the item code of the item to be deleted: ");
	gotoxy(57,9);cin>>code;
	
	while(ditem.read((char*)&T,sizeof(T)))
	{
		if(code==T.getcode())
		{
			found='y';
			T.ind_details();
			found='y';
			outtextxy(100,305,"Conferm(y/n): ");
			gotoxy(26,23);cin>>confirm;
			if(confirm=='n'||confirm=='N')
				dtemp.write((char*)&T,sizeof(T));
		}
		else
			dtemp.write((char*)&T,sizeof(T));
	}
	if(found=='n')
	{
		cleardevice();
		design(1);
		outtextxy(100,139,"Record not found");
		getch();
	}
	ditem.close();
	dtemp.close();
	remove("ITEM.DAT");
	rename("TEMP.DAT","ITEM.DAT");
	
	ditem.open("ITEM.DAT",ios::in);
	cleardevice();
	design();
	outtextxy(90,90,"File now contains: ");
	getch();
	cleardevice();
	design();
	line(13,85,623,85);
	rectangle(11,68,625,345);	//outer
	rectangle(13,70,53,343);	//code
	rectangle(53,70,164,345);	//name
	rectangle(164,70,236,345);	//qantity
	rectangle(236,70,322,345);	//quality
	rectangle(322,70,410,345);	//price
	rectangle(410,70,623,345);	//description
	outtextxy(16,69,"CODE");
	outtextxy(55,69,"NAME");
	outtextxy(166,69,"QUANTITY");
	outtextxy(238,69,"QUALITY");
	outtextxy(324,69,"PRICE");
	outtextxy(412,69,"DESCRIPTION");
	while(ditem.read((char*)&T,sizeof(T)))
	{
		T.disp_details();
	}
	ditem.close();
}

						/*************[Function for modifying item]***********/

void m_item()
{
	cleardevice();
	design();
	fstream mi("ITEM.DAT",ios::binary|ios::in|ios::out);
	long int code;
	char found='n',conf='n';
	cleardevice();
	design();
	outtextxy(30,110,"Enter the item code which is to be modified: ");
	gotoxy(47,9);cin>>code;
	item T1;
	mi.seekp(0,ios::beg);
	while(mi.read((char*)&T1,sizeof(T1)))
	{
		if(T1.getcode()==code)
		{
			found='y';
			outtextxy(30,139,"Do you want to over write(y/n): ");
			gotoxy(35,11);cin>>conf;
			if(conf=='y'||conf=='Y')
			{
				cleardevice();
				design();
				T1.modify();
				mi.seekp(mi.tellg()-sizeof(T1));
				mi.write((char*)&T1,sizeof(T1));
				break;
			}
		}
	}
	if(found=='n'||found=='N')
		outtextxy(150,130,"This item doesn't exist");
	getch();
	mi.close();
}

						/*************[Function for updating stock]***********/
						
void fact_arr()
{
	cleardevice();
	design();
	item T2;
	long int qty;
	fstream IT("ITEM.DAT",ios::binary|ios::in|ios::out);
	
	if(!IT)
	{
		cleardevice();
		design();
		outtextxy(200,200,"Error!!!!!!!!!");
		getch();
		return;
	}
	cleardevice();
	design(1);
	outtextxy(170,65,"Stock Menu");
	char found='n';
	long int code;
	design();
	outtextxy(110,110,"Enter the item code    :");
	gotoxy(39,9);cin>>code;
	
	while(IT.read((char*)&T2,sizeof(T2)))
	{
		if(T2.getcode()==code)
		{
			found='y';
			outtextxy(110,130,"Current stock         :");
			T2.getqty(305,130);
			setcolor(63);
			outtextxy(110,152,"Enter the stock arrived:");
			gotoxy(39,12);cin>>qty;
			T2.mod_stk(1,qty);
			IT.seekp(IT.tellg()-sizeof(T2));
			IT.write((char*)&T2,sizeof(T2));
		}
	}
	if(found=='n')
	{
		outtextxy(50,140,"wrong item code");//if no modification done
		getch();
	}
	IT.close();
}

						/*************[Function for viewing customer details]***********/

void vcust_detils()
{
	customer C;
	
	ifstream VC("CUST.DAT",ios::binary|ios::in);
	
	if(!VC)
	{
		cleardevice();
		design();
		outtextxy(100,100,"ERROR!!!");
		getch();
		return;
	}
	int v_choice;        //varible for enter choice 
	cleardevice();
	design(1);
	outtextxy(200,45,"Search Menu");
	a=0;
	design();
	outtextxy(100,100,"1.All customer details ");
	outtextxy(100,120,"2.search by ID");
	outtextxy(100,140,"3.Back");
	outtextxy(90,164,"Enter choice: ");
	gotoxy(27,13);cin>>v_choice;
	switch(v_choice)
	{
		case 1:
			cleardevice();
			design();
			
			line(13,85,497,85);
			rectangle(11,68,500,345);	//outer
			rectangle(13,70,94,343);	//id
			rectangle(94,70,223,343);	//name
			rectangle(223,70,390,343);	//address
			rectangle(390,70,497,343);	//ph.no
			
			outtextxy(16,69,"ID");
			outtextxy(96,69,"NAME");
			outtextxy(226,69,"ADDRESS");
			outtextxy(393,69,"PHONE.NO");
			while(VC.read((char *)&C,sizeof(C)))
			{
				C.disp_cust();
			}
			getch();
			break;
		case 2:
			cleardevice();
			design(1);
			outtextxy(200,45,"Search");
			design();
			long int ID;
			outtextxy(110,110,"Enter the customer ID:");
			gotoxy(40,9);cin>>ID;
			VC.seekg(0,ios::beg);
			while(VC.read((char*)&C,sizeof(C)))
				if(C.get_id()==ID)
				{
					C.ind_cust();
					getch();
				}
			break;	
	}
	VC.close();
}


						/*************[Function for seaching item]***********/

void search_it(int cho=1)
{
	
	item T;
	ifstream SI("ITEM.DAT",ios::in|ios::binary);

	if(!SI)
	{
		cleardevice();
		design();
		outtextxy(100,100,"Sorry File Doesn't Exist!!...");
		getch();
		return;
	}
	if(cho==1)
	{
		cleardevice();
		design(1);
		outtextxy(170,50,"Search Menu");
		design();
		outtextxy(100,80,"1.Specific Search ");
		outtextxy(100,100,"2.All Items ");
		outtextxy(100,137,"Enter Your Choice:");
		gotoxy(32,11);cin>>cho;
	}
	switch(cho)
	{
		case 1:
				cleardevice();
				design();
				int ch;
				design(1);
				outtextxy(170,50,"Specific Search Menu");
				design();
				outtextxy(100,100,"1.Name");
				outtextxy(100,120,"2.Item Code");
				outtextxy(100,152,"Enter Your Choice:");
				gotoxy(32,12);cin>>ch;
				switch(ch)
				{
					case 1:
					int f=0;
					cleardevice();
					design(1);
					char prod[20];
					outtextxy(170,50,"Name Based Search");
					design();
					outtextxy(100,110,"Enter the name of product required:");
					gotoxy(47,9);gets(prod);
					while(SI.read((char*)&T,sizeof(T)))
					{
						if(strcmpi(T.getname(),prod)==0)
							
							T.ind_details();
					}
					break;
					case 2:
					cleardevice();
					design(1);
					long itemCode;
					outtextxy(170,50,"Item Code Based Search");
					design();
					outtextxy(140,110,"Enter the item code of the product:");
					gotoxy(52,9);cin>>itemCode;
					while(SI.read((char*)&T,sizeof(T)))
					{
						if(itemCode==T.getcode())
						{
							f=1;
							T.ind_details();
						}
					}
					if(f==0)
					{
						design();
						outtextxy(100,130,"Item Doesn't Exist!!...");
						getch();
						return;
					}
					break;
				}
						
		case 2:
			a=0;
			cleardevice();
			design();
			line(13,85,623,85);
			rectangle(11,68,625,345);	//outer
			rectangle(13,70,53,343);	//code
			rectangle(53,70,164,345);	//name
			rectangle(164,70,236,345);	//qantity
			rectangle(236,70,322,345);	//quality
			rectangle(322,70,410,345);	//price
			rectangle(410,70,623,345);	//description
			outtextxy(16,69,"CODE");
			outtextxy(55,69,"NAME");
			outtextxy(166,69,"QUANTITY");
			outtextxy(238,69,"QUALITY");
			outtextxy(324,69,"PRICE");
			outtextxy(412,69,"DESCRIPTION");
			while(SI.read((char*)&T,sizeof(T)))
			{
				T.disp_details();
			}
			a=0;
			break;		
	}
	SI.close();
}

						/*************[Function for placing customer orders]***********/
void purchase(long int cus_id)
{
	
	char name[15];
	char p='y';
	int ch;
	long cqty;
	long price;
	long new_total=0;
	long int it_id;
	long c;
	char stotal[8],sc[8];
	cust_purchase f;         //object for fist quality
	cust_purchase s;         //object for second quality
	item T1;				//object of class item

	fstream fp("FIRST.DAT",ios::in|ios::out|ios::binary);
	fstream fin("SECOND.DAT",ios::in|ios::out|ios::binary);
	ifstream cusread("CUST.DAT",ios::in|ios::binary);
	fstream itread("ITEM.DAT",ios::out|ios::in|ios::binary);
	long int pfc;				//for storing the billno of first quality 

	if(fp.tellg()==0)
		pfc=2017;
	else
	{
		fp.seekg(fp.tellg()-sizeof(f));
		fp.read((char*)&f,sizeof(f));
		pfc=f.get_B_ID();
	}


	long int psc;					//for storing the billno of second quality

	if(fin.tellg()==0)
		psc=99;
	else
	{
		fin.seekg(fin.tellg()-sizeof(s));
		fin.read((char*)&s,sizeof(s));
		psc=s.get_B_ID();
	}
	int number=0;
	float total=0;
	int found=0;
	do
	{
		cleardevice();
		design(1);
		outtextxy(170,45,"Purchase Menu");
		design();
		outtextxy(100,82,"Do you want to purchase :");
		outtextxy(110,104,"1. First quality metals");
		outtextxy(110,128,"2. Second quality metals");
		outtextxy(110,148,"3.Exit");
		gotoxy(38,7);cin>>ch;
		switch(ch)
		{
			case 1:
				pfc++;														//first quality
				cleardevice();
				design(1);
				outtextxy(170,45,"Purchase Menu");
				design();
				outtextxy(110,110,"Enter the item code:");
				gotoxy(55,9);cin>>it_id;
				itread.seekg(0,ios::beg);
				while(itread.read((char*)&T1,sizeof(T1)))	
				{
					
					if(it_id==T1.getcode())
					{
						if(strcmpi(T1.getqality(),"2nd quality")==0)
							break;
						found=1;
						strcpy(name,T1.getname());
						outtextxy(110,125,"Item Name           :");setcolor(56);outtextxy(435,125,name);
						setcolor(63);
						outtextxy(110,137,"Enter the quantity  :");
						gotoxy(55,11);cin>>cqty;
						if(cqty>T1.getqty(0))
						{
							T1.getqty(435,164);
							outtextxy(110,152,"Required  quantity not available");
							outtextxy(110,164,"Available:");
							getch();
							return;
						}
						else
						{
							T1.mod_stk(2,cqty);
							itread.seekp(itread.tellg()-sizeof(T1));
							itread.write((char*)&T1,sizeof(T1));
							price=T1.getprice();
							char sprice[8];
							ltoa(price,sprice,10);
							outtextxy(110,152,"Price                                  :");setcolor(56);outtextxy(435,152,sprice);
							setcolor(63);
							f.getdetails(pfc,cus_id,cqty,price,name);
							new_total+=(price*cqty);
							if(new_total>100000)
							{	
								total=new_total-(new_total*0.05);
							}
							else
								total=new_total;
						}
						fp.write((char *)&f,sizeof(f));
						number=fp.tellg();
					
					}
				}
				if(found==0)
				{
					cleardevice();
					design(1);
					outtextxy(230,50,"Purchase Menu");					
					outtextxy(20,100,"ITEM NOT FOUND !!!");
					design();
					getch();
					return;
				}								
			    cleardevice();
				design(1);
				outtextxy(170,45,"Purchase Menu");
				design();
				c=new_total-total;
				ltoa(total,stotal,10);
				ltoa(c,sc,10);
				outtextxy(110,125,"You have to pay :");outtextxy(240,125,stotal);
				outtextxy(110,137,"You saved Rs.");outtextxy(220,137,sc);outtextxy(300,137," in the purchase");
				getch();
				f.gettotal(total);
				fp.write((char *)&f,sizeof(f));
				fp.close();
				fp.open("FIRST.DAT",ios::in|ios::binary);
				fp.seekg(number,ios::beg);

				while(fp.read((char *)&f,sizeof(f)))
					f.disp_bill();

				getch();
				break;
				break;
			case 2:										 //second quality
				psc++;
				itread.seekg(0,ios::beg);
				cleardevice();
				design(1);
				outtextxy(170,45,"Purchase Menu");
				design();
				outtextxy(110,110,"Enter the item code you want to purchase :");
				gotoxy(55,9);cin>>it_id;
				while(itread.read((char*)&T1,sizeof(T1)))
				{
					if(it_id==T1.getcode())
					{
						if(strcmpi(T1.getqality(),"1st quality")==0)
							break;
						found=1;
						strcpy(name,T1.getname());
						outtextxy(350,125,"Item Name:");setcolor(56);outtextxy(435,125,name);
						setcolor(63);
						outtextxy(110,137,"Enter the quantity you want to purchase :");
						gotoxy(55,11);cin>>cqty;
						if(cqty>T1.getqty(0))
						{
							T1.getqty(170,164);
							outtextxy(110,152,"Required  quantity not available");
							outtextxy(110,164,"Available:");
						}
						else
						{
							T1.mod_stk(2,cqty);
							itread.seekp(itread.tellg()-sizeof(T1));
							itread.write((char*)&T1,sizeof(T1));
							price=T1.getprice();
							char sprice[8];
							ltoa(price,sprice,10);
							outtextxy(110,152,"Price                   :");setcolor(56);outtextxy(435,152,sprice);
							setcolor(63);
							f.getdetails(pfc,cus_id,cqty,price,name);
							new_total+=(price*cqty);
							if(new_total>100000)
							{
								total=new_total-(new_total*0.05);
							}
							else
								total=new_total;
						}
						fin.write((char *)&f,sizeof(f));
						number=fin.tellg();
					}
				}
				if(found==0)
				{
					cleardevice();
					design(1);
					outtextxy(170,45,"Purchase Menu");
					outtextxy(20,100,"ITEM NOT FOUND !!!");
					getch();
					return;
				}
				cleardevice();
				design(1);
				outtextxy(170,45,"Purchase Menu");
				design();
				c=total-new_total;
				ltoa(total,stotal,10);
				ltoa(c,sc,10);
				outtextxy(110,125,"You have to pay :");outtextxy(240,125,stotal);
				outtextxy(110,137,"You saved Rs.");outtextxy(220,137,sc);outtextxy(300,137," in the purchase");
				getch();
				s.gettotal(total);
				fin.write((char *)&f,sizeof(f));
				fin.close();
				fin.open("SECOND.DAT",ios::in|ios::binary);
				fin.seekg(number,ios::beg);
			
				while(fin.read((char *)&s,sizeof(s)))
					s.disp_bill();
				getch();
				break;
	}
	}while(ch!=3);
}

void cust_menu(long int);

						/*************[Function for Custumer signin]***********/

void Cust_signin()
{
	cleardevice();
	design();
	ifstream fin;
	fin.open("CUST.DAT",ios::binary|ios::in);
	customer C;
	char pass[15];
	long int custid;
	char name[25];
	settextstyle(2,0,5);
	outtextxy(200,83,"CUSTOMER ID:");
	gotoxy(38,7);cin>>custid;
	outtextxy(200,100,"PASSWORD:");
	password();
	while(fin.read((char*)&C,sizeof(C)))
	{
		if(custid,C.get_id())
		{
			cleardevice();
			design(1);			
			outtextxy(270,150,"WELCOME");
			outtextxy(240,190,C.get_name());   //for displaying customer name 
			getch();
			cust_menu(custid);
		}
	}
	fin.close();
	
}

						/*************[Function for customer registration]***********/
void newcust()
{
	cleardevice();
	design();
	customer c;
	long n=0;
	fstream CUSTOMER("CUST.DAT",ios::out|ios::in|ios::binary|ios::ate);
	
	if(!CUSTOMER)
	{
		cleardevice();
		design();
		outtextxy(30,30,"Error.....");
		getch();
		return;
	}
	cleardevice();
	design();
	long co;
	
	if(CUSTOMER.tellg()==0)					//assigning Id for 1st customer 
		co=999;						
	else									//for rest 
	{
		CUSTOMER.seekg(CUSTOMER.tellg()-sizeof(c));
		CUSTOMER.read((char*)&c,sizeof(c));
		co=c.get_id();
	}
	cleardevice();
	design();
	co+=1;
	c.putdata(co);							//calling member function of class customer to assing the details of customer 
	CUSTOMER.write((char*)&c,sizeof(c));//writing the details to the file
	CUSTOMER.close();
	setcolor(63);	
	outtextxy(100,190,"Successfuly Registered");
	getch();
	cust_menu(co);								//to customer menu
}