

/*******************[Function to enter the password]********************************/

void password()
{
	customer c;
	/*char *password,*sub;
	char ch;
	int i=0,n=0,m;
	sub=password;
	int b=10;
	ch=getch();
	do
	{
		
		if(ch!='\b')
		{
			setcolor(7);
			outtextxy(260+b,100,"*");
			n++;
			*password=ch;
			i++;
			password++;
		}
		else if(ch=='\b')
		{
			if(password!=sub)
			{
				setcolor(7);
				password--;
				i--;
				m=n;
				n--;
				for(;m>1;m--)
					outtextxy(260+b,100,"*");
			}
		}
		b+=10;
		ch=getch();
	}while(ch!='\r');
	*password='\0';
	b=10;
	for(;i>0;i--)
		password--;
	return password;*/
	char h[12]={""};
	char a[12]={""};
	int i=0;
	while(!kbhit())
	{
		h[i]=getch();
		a[i]='*';
		if(h[i]==8)
		{
			outtextxy(270,100,a);
			
			a[--i]='\0';
			h[i--]='\0';
			outtextxy(270,100,a);
		}
		if(h[i]=='\r')
		       return;
		outtextxy(270,100,a);
		i++;
		if(i<0)
			i++;
		if(i>10)
		      return;
	}
	c.getpass(h);
}

struct ADMIN
{
	char password[15];
	char name[25];
}p;



/********************************[Function for admin sign in]**********************************************/

int signin()
{
	ifstream fin("ADMIN.DAT",ios::in|ios::binary);

	char name[25],pass[15];
	outtextxy(43,40,"user name:");
	outtextxy(70,40,"password:");
	gotoxy(10,10);gets(name);
	while(fin.read((char*)&p,sizeof(p)))
	{
		if((strcmpi(name,p.name)==0))
			return 1;
	}
	fin.close();
	return 0;
}
