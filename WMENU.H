void admn_menu()
{
	cleardevice();
	design();
	//if(a_signin()==1)
	//{
		int choice;
		do
		{
			cleardevice();
			setcolor(4);
	        design(2);
			a=0;
			rectangle(80,70,450,310);
			outtextxy(100,80,"1.Add New Item");
	        outtextxy(100,100,"2.Modify item");
			outtextxy(100,120,"3.Delete item");
			outtextxy(100,140,"4.View items");
			outtextxy(100,160,"5.Stock renuwal");
			outtextxy(100,180,"6.View customer details");
			outtextxy(100,200,"7.Exit");
			outtextxy(160,290,"Enter your choice:");
			gotoxy(39,22);cin>>choice;
			switch(choice)
			{
				case 1:
					    additem();//func to add item to file
						break;
				case 2:
						m_item();// fun to modify items
						break;
				case 3:
						delitem();//func to delete item from file
						break;
				case 4:
						search_it(2);//func to view item details
	                    break;
		    	case 5:
	                    fact_arr();// func to order items
						break;
				case 6:
					   vcust_detils();//func to view customer details
					   break;
				case 7:
						cleardevice();
						design(1);
						outtextxy(270,100,"Thank You Visit Again");
						getch();
						break;
				default:
						outtextxy(20,30,"Wrong choice");
			  }
		}while(choice!=7);
	//}
	//else
		//cleardevice();
		//outtextxy(20,30,"\nWRONG USERNAME OR PASSWORD";
}

void cust_menu(long int id)
{
	cleardevice();
	design();
	
		int choice;
		do
		{	
			cleardevice();
			design(1);
			outtextxy(200,50,"CUSTOMER MENU");
			design(2);
			outtextxy(110,100,"1.Search Item");
			outtextxy(110,120,"2.Shop");
			outtextxy(110,140,"3.Exit");
			outtextxy(110,250,"Enter your choice: ");
			gotoxy(33,19);cin>>choice;
			switch(choice)
			{
				case 1:search_it();break;
			    case 2:purchase(id);break;
				case 3:cleardevice();
						design(1);
						outtextxy(270,100,"Thank You Visit Again");
						getch();
						break;
				default:
						outtextxy(20,30,"Wrong Choice");
			}
		}while(choice!=3);
}
void cust()
{
	cleardevice();
	design(1);
	int cho;
	settextstyle(1,0,1);
	outtextxy(280,150,"1.Sign up");
	outtextxy(280,180,"2.Sign in");
	gotoxy(40,16);cin>>cho;
	switch(cho)
	{
		case 1:
			newcust();
			break;
		case 2:
			Cust_signin();
			break;
	}
}