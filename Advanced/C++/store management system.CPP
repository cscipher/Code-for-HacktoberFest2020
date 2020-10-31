// @sidhartha8011
// c++ program for store management system


#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<process.h>
#include<dos.h>
class item
{ int barcode,price;
  char name[30],category[50];
  int modelno ;
 public:
  void getdata()
  { int i=12;
    gotoxy(29,10);
    cout<<"ENTER THE DETAILS OF THE ITEM";
    gotoxy(26,i++);
    cout<<"Enter category of the item: ";
    gets(category);
    gotoxy(26,i++);
    cout<<"Enter barcode of the item: ";
    cin>>barcode;
    gotoxy(26,i++);
    cout<<"Enter Name of the item: ";
    gets(name);
    gotoxy(26,i++);
    cout<<"Enter modelno of the item: ";
    cin>>modelno;
    gotoxy(26,i++);
    cout<<"Enter price of the item: ";
    cin>>price;

  }
  void dispdata()
  { int i=12;
    gotoxy(26,i++);
    cout<<" category of the item: "<<category;
    gotoxy(26,i++);
    cout<<" barcode of the item: "<<barcode;
     gotoxy(26,i++);
    cout<<" EName of the item: "<<name;
     gotoxy(26,i++);
    cout<<" modelno of the item: "<<modelno;
     gotoxy(26,i++);
    cout<<" price of the item: "<<price<<endl;
  }
  int ret_barcode()
  {
    return (barcode);
  }
  int ret_modelno()
  {
    return(modelno);
  }
  int ret_price()
  {
    return(price);
  }
  int cmpname(char cmp[40])
  {if(strcmp(name,cmp)==0)
      return 0;
    else
      return 1;
    }
 int cmpcategory(char mp[40])
   {if(strcmp(category,mp)==0)
      return 0;
     else
      return 1;
    }
   }s;
 void Write();
 void Read();
 void Modify();
 void Delete();
 void Search();
 void box()
{
 int n;
 for(n=18;n<59;n++)
 {
  gotoxy(n,23);
  cout<<"*";
 }
 for(n=18;n<59;n++)
 {
 gotoxy(n,7);
 cout<<"*";
 }
 for(n=7;n<24;n++)
 {
  gotoxy(59,n);
  cout<<"*";
 }
 for(n=7;n<24;n++)
 {
 gotoxy(17,n);
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
  gotoxy(26,11);
  cout<<"1.modify barcode"<<endl;
  gotoxy(26,12);
  cout<<"2.modify price"<<endl;
  gotoxy(26,13);
  cout<<"3.modify modelno"<<endl;
  int ch;
  gotoxy(26,15);
  cout<<"enter your choice";
  cin>>ch;
  char found='f';
  switch(ch)
  {
      case 1: { clrscr();
		int bc; float pos;
		gotoxy(26,8);
		cout<<"Enter the bar code to be modified :";
			cin>>bc;
		fin.open("stu.DAT",ios::in|ios::binary|ios::out);
		while(!fin.eof())
		{
		    pos=fin.tellg()	;
		    fin.read((char*)&s,sizeof(s));
		     if(s.ret_barcode()==bc)
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
	       int p;
	       float pos;
	       gotoxy(24,10);
		cout<<"Enter the price to be modified :";
			cin>>p;
		fin.open("stu.DAT",ios::in|ios::binary|ios::out);
		while(!fin.eof())
		{
		    pos=fin.tellg()	;
		    fin.read((char*)&s,sizeof(s));
		     if(s.ret_price()==p)
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
		int mno;
		float pos;
		gotoxy(26,10);
		cout<<"Enter the model no to be modified :";
			cin>>mno;
		fin.open("stu.DAT",ios::in|ios::binary|ios::out);
		while(!fin.eof())
		{
		    pos=fin.tellg()	;
		    fin.read((char*)&s,sizeof(s));
		     if(s.ret_modelno()==mno)
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
  cout<<"1. search the file by barcode "<<endl;
  cout<<"2. search the file by name "<<endl;
  cout<<"enter choice ";
  cin>>ch;
  switch(ch)
   {case 1:{clrscr();
	    finout.open("stu.dat",ios::binary|ios::in|ios::out);
	    cout<<"Enter the barcode to be searched:";
	    cin>>rn;
	    while(!finout.eof())
	  {
	    finout.read((char*)&s,sizeof(s));
	    if(s.ret_barcode()==rn)
	     {
	       s.dispdata();
	       found='y';
	       break;
	     }
	    }
	    if(found=='n')
	    cout<<"barcode not found in file!!"<<endl;
	    finout.close();
	    }
	     break;
  case 2:   {
	      finout.open("stu.dat",ios::binary|ios::in|ios::out);
	       cout<<"Enter the name to be searched:";
	       gets(nm);
	       while(!finout.eof())
	       {
		finout.read((char*)&s,sizeof(s));
		if(s.cmpname(nm)==0)
		 {
		  s.dispdata();
		  found='y';
		  break;
		 }
	       }
	      if(found=='n')
	      cout<<"name not found in file!!"<<endl;
	      finout.close();
	     }
	      break;

   default:cout<<"wrong choice"<<endl;
   }

 }


