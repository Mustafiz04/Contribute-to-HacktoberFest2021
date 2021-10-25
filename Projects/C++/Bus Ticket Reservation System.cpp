//Bus Ticket Reservation System
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<process.h>
char from[30], to[30];
void detail()
{ 
  cout<<"\n"<<"From : ";
  gets(from);
  cout<<"To : ";
  gets(to);
}

class bus
{
 char stop[30];
 unsigned int distance;
 float fare;
 public:
 void ad_data()
 {
  cout<<"\n"<<"Enter bus stop name : ";
  gets(stop);
  cout<<"Enter its distance from New Delhi (in km) : ";
  cin>>distance;
 }
 void amount(int a,int b,int c)
 {
  cout<<"Total distance = "<<fabs((a-b))<<"\n"<<"Charges per/km = "<<c;
  fare=fabs((a-b))*c;
  cout<<"\n"<<"Ticket cost = "<<fare;
 }
 unsigned int dist()
 {
  return distance;
 }
 char *stop_v()
 {
  return stop;
 }
 void modify()
 {
  cout<<"\n"<<"Enter new bus stop : ";
  gets(stop);
  cout<<"Enter its distance from New Delhi (in km) : ";
  cin>>distance;
 }
}bs;

void main()
{
 clrscr();
 unsigned int per_km=5, choice, d1=0,d2=0, i;
 char stop_searched[30];
 while(1)
 {
  clrscr();
  cout<<"\t"<<"\t";
  cout<<"WELCOME TO redBUS TICKET RESERVATION SYSTEM";
  cout<<"\n";
  for(i=0;i<80;i++)
  {
   cout<<"-";
  }
  cout<<"Enter your choice : \n \t 1:-> Add new bus stop \n \t 2:-> Book ticket"<<endl;
  cout<<" \t 3:-> Change per km rates \n \t 4:-> Modify database of bus \n \t 5:-> Exit \n";
  for(i=0;i<80;i++)
  {
  cout<<"-";
  }
  cin>>choice;
  if(choice==1)
  {
  ofstream of1("bus.dat",ios::binary|ios::app);
  bs.ad_data();
  of1.write((char*)&bs,sizeof(bs));
  of1.close();
  }
  else if(choice==2)
  {
   ifstream of1("bus.dat",ios::binary);
   detail();
   while(of1)
   {
    of1.read((char*)&bs,sizeof(bs));
    if(0==stricmp(from,bs.stop_v()))
    {
     d1=bs.dist();
    }
    if(0==stricmp(to,bs.stop_v()))
    {
     d2=bs.dist();
    }
    if(d1 && d2)
    {
     bs.amount(d1,d2,per_km);
     getch();
    }
    if(of1.eof())
    {
     cout<<"Stop not found. Check your spelling";
     getch();
    }
   }
   of1.close();
   break;
  }
 else if(choice==3)
  {
   cout<<"\n";
   cout<<"Enter new per km rates : ";
   cin>>per_km;
  }
  else if(choice==4)
  {
   cout<<"\n";
   cout<<"Enter the bus stop to be changed : ";
   gets(stop_searched);
   ifstream f1("bus.dat",ios::binary);
   while(f1 )
  {
   f1.read((char*)&bs,sizeof(bs));
   long pos=f1.tellg();
   if(0==strcmp(stop_searched,bs.stop_v()))
   {
    f1.seekg((-1*sizeof(bs),ios::cur));
    bs.modify();
    f1.close();
    ofstream f1("bus.dat",ios::app);
    f1.seekp(pos,ios::beg);
    f1.write((char*)&bs,sizeof(bs));
    cout<<"Record modified";
    f1.close(); break;
   }
   else if(f1.eof())
   {
    cout<<"Stop not found";
    getch();
   }
  }
 }
else  if(choice==5)
 {
  cout<<"\n"<<"THANK YOU FOR USING redBUS!";
  getch();
  exit(0);
 }
else
 {
  cout<<"Entered wrong choice."<<"\n";
  cout<<"PROGRAM IS ABORTING!!!!!!";
  getch();
  exit(0);
 }
}
getch();
}
