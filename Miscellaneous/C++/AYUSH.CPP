//@Ankush9954
//Bus Travel management system
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<dos.h>
class bus
{ int bno,fare;
  char from[30],to[50];
  int capacity ;
 public:
  void getdata()
  { int i=12;
    gotoxy(29,9);
    cout<<"ENTER THE DETAILS OF THE BUS";
    gotoxy(26,i++);
    cout<<"Enter bus no of the bus: ";
    cin>>bno;
    gotoxy(26,i++);
    cout<<"Enter from(place) of the bus: ";
    gets(from);
    gotoxy(26,i++);
    cout<<"Enter to(place) of the bus: ";
    gets(to);
    gotoxy(26,i++);
    cout<<"Enter capacity of the bus: ";
    cin>>capacity;
    gotoxy(26,i++);
    cout<<"Enter fare of the bus: ";
    cin>>fare;

  }
  void dispdata()
  { int i=12;
    gotoxy(26,i++);
    cout<<" Bus no of the bus: "<<bno;
    gotoxy(26,i++);
    cout<<" From(place) of the bus: "<<from;
     gotoxy(26,i++);
    cout<<" To(place) of the bus: "<<to;
     gotoxy(26,i++);
    cout<<" Capacity of the bus: "<<capacity;
     gotoxy(26,i++);
    cout<<" Fare of the item: "<<fare<<endl;
  }
  int ret_bno()
  {
    return (bno);
  }
  int ret_capacity()
  {
    return(capacity);
  }
  int ret_fare()
  {
    return(fare);
  }
  int cmpfrom(char cmp[40])
  {if(strcmp(from,cmp)==0)
      return 0;
    else
      return 1;
    }
 int cmpto(char mp[40])
   {if(strcmp(to,mp)==0)
      return 0;
     else
      return 1;
    }
   }s;
 void Write();
 void Read();
 void Modify();
 void Search();
 void box()
    {
      int n,m;
      for(n=18,m=18;n<59,m<59;n++,m++)
	{
	  delay(40);
	  gotoxy(n,7);
	  cout<<"*";
	  gotoxy(m,23);
	  cout<<"*";
	}
      for(n=7,m=7;n<24,m<24;n++,m++)
	{
	  delay(40);
	  gotoxy(59,n);
	  cout<<"*";
	  gotoxy(18,m);
	  cout<<"*";
	}
    }
 void main()
{
  clrscr();
  char ch='y';
  while(ch=='y'||ch=='Y')
 {
  textcolor(BLACK);
  textbackground(RED);
  clrscr();
  box();
  gotoxy(30,10);
  cout<<"!!MAIN MENU!!"<<endl;
  gotoxy(25,11);
  cout<<"1.Write to the file"<<endl;
   gotoxy(25,12);
  cout<<"2.Read from the file"<<endl;
   gotoxy(25,13);
  cout<<"3.Modify a record from the file"<<endl;
   gotoxy(25,14);
  cout<<"4.Search for a item from the file"<<endl;
   gotoxy(25,15);
  cout<<"5.exit from the main menu";
   gotoxy(25,16);
  int c;
  cout<<"Enter Choice:";
  cin>>c;
  switch(c)
  {
  case 1:     textcolor(BLACK);
	      textbackground(BLUE);
	      clrscr();
	      Write();
	      break;

    case 2:  textcolor(BLACK);
	     textbackground(WHITE);
	     clrscr();
	     Read();
	     break;

    case 3:   textcolor(BLACK);
	      textbackground(GREEN);
	      clrscr();
	      Modify();
	      break;

    case 4:   textcolor(BLACK);
	      textbackground(CYAN);
	      clrscr();
	      Search();
	      break;

    case 5:  exit(0);
	       break;

   default:
	      cout<<"Wrong Choice:";
	      break;

   }
   gotoxy(23,18);
  cout<<"DO YOU WANT TO RETURN TO MAIN MENU(Y/N)";
  cin>>ch;
  }
  getch();
}

 void Write()
  { char ch='y';
    fstream finout;
    finout.open("stu.DAT",ios::binary|ios::in|ios::out);
    while (ch=='y'|| ch=='Y')
    {
     s.getdata();
     finout.write((char*)&s,sizeof(s));
     gotoxy(25,17);
     cout<<"Want to enter more records?(y/n)....";
     cin>>ch;
     clrscr();
    }
    finout.close();
  }
  void Read()
  {  fstream finout;
    finout.open("stu.DAT",ios::in|ios::out|ios::binary);
    if(!finout)
    {
      cout<<"File not found";
      exit(0);
    }
   else
   {
    finout.read((char*)&s,sizeof(s));
    while(!finout.eof())
    {clrscr();
     s.dispdata();

     cout<<endl<<endl;
      gotoxy(27,17);
     cout<<"press any key for next record";
     getch();
     finout.read((char*)&s,sizeof(s));

    }
   }
    finout.close();
  }
 void Modify()
 {clrscr();
  fstream fin;
  gotoxy(26,14);
  cout<<"1.modify bus no"<<endl;
  gotoxy(26,15);
  cout<<"2.modify fare"<<endl;
  gotoxy(26,16);
  cout<<"3.modify capacity"<<endl;
  int ch;
  gotoxy(26,17);
  cout<<"enter your choice";
  cin>>ch;
  char found='f';
  switch(ch)
  {
      case 1: { clrscr();
		int bn; float pos;
		gotoxy(26,8);
		cout<<"Enter the bus no to be modified :";
			cin>>bn;
		fin.open("stu.DAT",ios::in|ios::binary|ios::out);
		while(!fin.eof())
		{
		    pos=fin.tellg()	;
		    fin.read((char*)&s,sizeof(s));
		     if(s.ret_bno()==bn)
		      {
			s.getdata();
			fin.seekg(pos);
			fin.write((char*)&s,sizeof(s));
			found='t';
			break;
		      }
		}
		}
		break;

     case 2: { clrscr();
	       int f;
	       float pos;
	       gotoxy(24,10);
		cout<<"Enter the fare to be modified :";
			cin>>f;
		fin.open("stu.DAT",ios::in|ios::binary|ios::out);
		while(!fin.eof())
		{
		    pos=fin.tellg()	;
		    fin.read((char*)&s,sizeof(s));
		     if(s.ret_fare()==f)
		      {
			s.getdata();
			fin.seekg(pos);
			fin.write((char*)&s,sizeof(s));
			found='t';
			break;
		      }
		}
	       }
		break;
      case 3: { clrscr();
		int cap;
		float pos;
		gotoxy(26,10);
		cout<<"Enter the capacity to be modified :";
		cin>>cap;
		fin.open("stu.DAT",ios::in|ios::binary|ios::out);
		while(!fin.eof())
		{
		    pos=fin.tellg()	;
		    fin.read((char*)&s,sizeof(s));
		     if(s.ret_capacity()==cap)
		      {
			s.getdata();
			fin.seekg(pos);
			fin.write((char*)&s,sizeof(s));
			found='t';
			break;
		      }
		}
	      }
		break;
     default:gotoxy(26,10);
	     cout<<"wrong choice";
    }
  if(found=='f')
   { gotoxy(26,10);
     cout<<"Record not found!!!\n";
     fin.seekg(0);
   }
  }


 void Search()
 {
  fstream finout;
  int rn;
  char found='n';
  int ch;
  char nm[50];
  cout<<"Choose the medium to search in the file "<<endl;
  cout<<"1. search the file by bus no "<<endl;
  cout<<"2. search the file by from "<<endl;
  cout<<"enter choice ";
  cin>>ch;
  switch(ch)
   {case 1:{clrscr();
	    finout.open("stu.dat",ios::binary|ios::in|ios::out);
	    cout<<"Enter the bus no to be searched:";
	    cin>>rn;
	    while(!finout.eof())
	  {
	    finout.read((char*)&s,sizeof(s));
	    if(s.ret_bno()==rn)
	     {
	       s.dispdata();
	       found='y';
	       break;
	     }
	    }
	    if(found=='n')
	    cout<<"bus no not found in file!!"<<endl;
	    finout.close();
	    }
	     break;
  case 2:   {
	      finout.open("stu.dat",ios::binary|ios::in|ios::out);
	       cout<<"Enter the from to be searched:";
	       gets(nm);
	       while(!finout.eof())
	       {
		finout.read((char*)&s,sizeof(s));
		if(s.cmpfrom(nm)==0)
		 {
		  s.dispdata();
		  found='y';
		  break;
		 }
	       }
	      if(found=='n')
	      cout<<"From not found in file!!"<<endl;
	      finout.close();
	     }
	      break;

   default:cout<<"wrong choice"<<endl;
   }

 }


