//@Ankush9954
//C++ for travel management system
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<dos.h>
  class travel
    {
      int tcode;
      char from[50];
      char to[50];
      int distance;
      float fare;
      public:
      void getdata()
	{
	  gotoxy(25,10);
	  cout<<"Enter Travel_Code:";
	  cin>>tcode;
	  gotoxy(25,11);
	  cout<<"Enter Departure_Place:";
	  gets(from);
	  gotoxy(25,12);
	  cout<<"Enter Destination_Place:";
	  gets(to);
	  gotoxy(25,13);
	  cout<<"Enter Distance_Travelled:";
	  cin>>distance;
	  gotoxy(25,14);
	  cout<<"Enter Total Fare:";
	  cin>>fare;
	}
      void dispdata()
	{
	  gotoxy(25,11);
	  cout<<"Travel_Code = "<<tcode<<endl;
	  gotoxy(25,12);
	  cout<<"Departure_Place = "<<from<<endl;
	  gotoxy(25,13);
	  cout<<"Destination_Place = "<<to<<endl;
	  gotoxy(25,14);
	  cout<<"Distance_Travelled = "<<distance<<endl;
	  gotoxy(25,15);
	  cout<<"Fare = "<<fare<<endl;
	}
      int ret_tcode()
	{
	  return(tcode);
	}
      int cmpname( char nm[50])
	{
	  if(strcmp(to,nm)==0)
	      return 0;
	  else
	      return -1;
	}
      void modify();
    }T;
  void travel::modify()
    {
      gotoxy(20,1);
      cout<<"Travel_Code:"<<tcode<<endl;
      gotoxy(20,2);
      cout<<"Departure_Place:"<<from<<endl;
      gotoxy(20,3);
      cout<<"Destination_Place:"<<to<<endl;
      gotoxy(20,4);
      cout<<"Distance_Travelled:"<<distance<<endl;
      gotoxy(20,5);
      cout<<"Fare:"<<fare<<endl;
      gotoxy(20,6);
      cout<<"Enter new details"<<endl;
      char fm[20]=" ";
      char t[20]=" ";
      float fr;
      gotoxy(20,7);
      cout<<"New Departure_Place:(Enter '.' to retain old one)"; cin>>fm;
      gotoxy(20,8);
      cout<<"New Destination_Place:(Enter '.' to retain old one)"; cin>>t;
      gotoxy(20,9);
      cout<<"New fare:(Press -1 to retain old one)"; cin>>fr;
      if(strcmp(fm,".")!=0)
	  strcpy(from,fm);
      if(strcmp(t,".")!=0)
	  strcpy(to,t);
      if(fr!=-1)
	  fare=fr;
    }
  void Write();
  void Read();
  void Modify();
  void Search();
  void box()
    {
      int n;
      for(n=18;n<59;n++)
	{
	  delay(30);
	  gotoxy(n,7);
	  cout<<"*";
	}
      for(n=7;n<24;n++)
	{
	  delay(30);
	  gotoxy(59,n);
	  cout<<"*";
	}
      for(n=59;n>17;n--)
	{
	  delay(30);
	  gotoxy(n,23);
	  cout<<"*";
	}
      for(n=23;n>6;n--)
	{
	  delay(30);
	  gotoxy(17,n);
	  cout<<"*";
	}
    }
  void main()
    {
      textcolor(BLACK);
      textbackground(RED);
      char con;
      clrscr();
      box();
      gotoxy(25,11);
      cout<<"WELCOME TO MY PROJECT"<<endl;
      gotoxy(25,12);
      cout<<"PROJECT ON FILE HANDLING"<<endl;
      gotoxy(30,16);
      cout<<"SUBMITTED BY :"<<endl;
      gotoxy(30,17);
      cout<<"ANKUSH THAKUR"<<endl<<endl;
      gotoxy(30,18);
      cout<<"ROLL NO.-3625091";
      gotoxy(25,19);
      cout<<"Press 'c' key to continue:";
      gotoxy(51,19);
      cin>>con;
      if(con=='c')
	{
	  int a,b;
	  char ans='y';
	  while(ans=='y'||ans=='Y')
	    {
	      clrscr();
	      box();
	      gotoxy(30,10);
	      cout<<"!!!!!! MAIN MENU !!!!!!"<<endl;
	      gotoxy(25,11);
	      cout<<"1.WRITE Information to the file"<<endl;
	      gotoxy(25,12);
	      cout<<"2.READ Information from the file"<<endl;
	      gotoxy(25,13);
	      cout<<"3.SEARCH the file"<<endl;
	      gotoxy(25,14);
	      cout<<"4.MODIFY a Record from the file"<<endl;
	      gotoxy(25,15);
	      cout<<"5.EXIT to MAIN MENU"<<endl;
	      gotoxy(25,16);
	      cout<<"Enter Choice:";
	      cin>>b;
	      switch(b)
		{
		  case 1:
		    {
		      textbackground(BLUE);
		      clrscr();
		      Write();

		      break;
		    }
		  case 2:
		    {
		      textbackground(YELLOW);
		      clrscr();
		      Read();

		      break;
		    }
		  case 3:
		    {
		      textbackground(CYAN);
		      clrscr();
		      Search();

		      break;
		    }
		  case 4:
		    {
		      textbackground(WHITE);
		      clrscr();
		      Modify();

		      break;
		    }
		  default:
		    {
		      gotoxy(20,10);
		      cout<<"WRONG CHOICE!!!!!";
		      exit(0);

		      break;
		    }
		}
	      gotoxy(25,21);
	      cout<<"Want to go back to MAIN MENU (y/n)...";
	      cin>>ans;
	    }
	  if(ans=='n')
	      exit(0);

	  getch();
	}
    }
  void Write()
    {
      char ch='y';
      fstream finout;
      finout.open("tra.DAT",ios::binary|ios::in|ios::out);
      while (ch=='y'|| ch=='Y')
	{
	  clrscr();
	  T.getdata();
	  finout.write((char*)&T,sizeof(T));
	  gotoxy(25,20);
	  cout<<"Want to enter more records?(y/n)....";
	  cin>>ch;
	}
      finout.close();
    }
  void Read()
    {
      fstream finout;
      finout.open("tra.DAT",ios::in|ios::binary);
      if(!finout)
	  {
	    cout<<"File not found!!!!";
	    exit(0);
	  }
      else
	  {
	    while(finout.read((char*)&T,sizeof(T)))
	      {
		T.dispdata();
		gotoxy(25,20);
		cout<<"Enter any key..for next record..."<<endl;
		getch();
	      }
	  }
      finout.close();
    }
  void Modify()
    {
      fstream finout;
      int tcode; long pos; char found='f';
      gotoxy(25,15);
      cout<<"Enter the Travel_Code to be modified :";
      cin>>tcode;
      finout.open("tra.DAT",ios::in|ios::binary|ios::out);
      while(!finout.eof())
	{
	  clrscr();
	  pos=finout.tellg()	;
	  finout.read((char*)&T,sizeof(T));
	  if(T.ret_tcode()==tcode)
	      {
		T.modify();
		finout.seekg(pos);
		finout.write((char*)&T,sizeof(T));
		found='t';

		break;
	      }
	}
      if(found=='f')
	  cout<<"Record not found!!!\n";
      finout.seekg(0);
      gotoxy(20,10);
      cout<<"Now the file contains :-\n";
      while(!finout.eof())
	{
	  finout.read((char*)&T,sizeof(T));
	  T.dispdata();
	}
      finout.close();
    }
  void Search()
    {
      clrscr();
      fstream finout;
      int t;
      char found='n';
      int h;
      char to[50];
      gotoxy(20,3);
      cout<<"Choose the medium to search :-"<<endl;
      gotoxy(20,4);
      cout<<"1.Search by Travel_Code"<<endl;
      gotoxy(20,5);
      cout<<"2.Search by Destination_Place"<<endl;
      gotoxy(20,6);
      cout<<"Enter choice : ";
      cin>>h;
      switch(h)
	  {
	    case 1:
	      {
		finout.open("tra.dat",ios::binary|ios::in|ios::out);
		gotoxy(20,8);
		cout<<"Enter the Travel_Code to be searched:";
		cin>>t;
		while(!finout.eof())
		  {
		    finout.read((char*)&T,sizeof(T));
		    if(T.ret_tcode()==t)
			{
			  T.dispdata();
			  found='y';

			  break;
			}
		  }
		if(found=='n')
		    {
		      gotoxy(20,17);
		      cout<<"Travel_Code not found in file!!"<<endl;
		    }
		finout.close();

		break;
	      }
	    case 2:
	      {
		finout.open("tra.dat",ios::binary|ios::in|ios::out);
		gotoxy(20,8);
		cout<<"Enter the Destination_Place to be searched:";
		gets(to);
		while(!finout.eof())
		  {
		    finout.read((char*)&T,sizeof(T));
		    if(T.cmpname(to)==0)
			{
			  T.dispdata();
			  found='y';

			  break;
			}
		  }
		if(found=='n')
		    {
		      gotoxy(20,17);
		      cout<<"Destination_Place not found in file!!"<<endl;
		    }
		finout.close();

		break;
	      }
	  }
    }