#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>
using namespace std;
// Global Constants for the limits
const int MAX_CONTACT_NAME = 25;
const int MAX_CONTACT_ADDRESS= 50;
const int MAX_CONTACT_EMAIL= 50;
const int MAX_CONTACTS = 200;
const int MAX_CONTACT_NUMBER = 15;
struct Contact{
	char name[MAX_CONTACT_NAME];
	char number[MAX_CONTACT_NUMBER];
	char address[MAX_CONTACT_ADDRESS];
	char email[MAX_CONTACT_EMAIL];
};

// The Function to add the contact
void addContact(Contact arr[],int size, Contact newContact)
{
	bool valid1 = false;
	bool valid2 = false; 
	bool valid3 = false;
	bool valid4 = false;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<MAX_CONTACT_NAME-1;j++)
		{
			if(arr[i].name[j] =='\0')
			{
				arr[i].name[j] = newContact.name[j];
				valid1 = true;
			}
		}
		for(int j=0; j<MAX_CONTACT_ADDRESS-1;j++)
		{
			if(arr[i].address[j]=='\0')
			{
				arr[i].address[j] = newContact.address[j];
				valid2= true;
			}
		}
		for(int j=0;j<MAX_CONTACT_EMAIL-1;j++)
		{
			if(arr[i].email[j]=='\0')
			{
				arr[i].email[j] = newContact.email[j];
				valid3 = true;
			}
			
		}
	    for(int j=0;j<MAX_CONTACT_NUMBER-1;j++)
		{
			if(arr[i].number[j] =='\0')
			{
				arr[i].number[j] = newContact.number[j];
				valid4 = true;
			}
		}
	    if(valid1 == true && valid2 == true && valid3 == true && valid4== true)
	    {
	    	break;
		}
	}
	if( valid1 == true && valid2 == true && valid3 == true)
	{
		cout<<" \nThe Contact has been added Successfully";
	}
	else
	{
		cout<<"\n The Contact has not been added Successfully";
	}
}

//The Function to delete the Contacts
void deleteContact(Contact arr[],int size,Contact dltContact)
{
	bool valid1 = false;
	bool valid2 = false; 
	bool valid3 = false;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<MAX_CONTACT_NAME-1;j++)
		{
			if(arr[i].name[j]== dltContact.name[j])
			{
				arr[i].name[j] = '\0';
				valid1 = true;
			}
		}
		if( valid1== true)
		{
		for(int j=0; j<MAX_CONTACT_ADDRESS-1;j++)
		{
				arr[i].address[j] = '\0';
				valid2= true;
		}
		for(int j=0;j<MAX_CONTACT_EMAIL-1;j++)
		{
				arr[i].email[j] = '\0';
				valid3 = true;
		}
		 for(int j=0;j<MAX_CONTACT_NUMBER-1;j++)
		 {
				arr[i].number[j] = '\0';
				valid3 = true;
		 } 
	    }
	    else
	    {
	    	continue;
		}
	}
	if( valid1 == true && valid2 == true && valid3 == true)
	{
		cout<<" \nThe Contact has been deleted Successfully";
	}
	else
	{
		cout<<"\n The Contact has not been deleted Successfully";
	}
}
// Function to edit the Contacts
void editContact(Contact arr[],int size, Contact editCont , Contact oldContact)
{
	bool valid1 = false;
	bool valid2 = false; 
	bool valid3 = false;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<MAX_CONTACT_NAME-1;j++)
		{
			if(arr[i].name[j] == oldContact.name[j])
			{
				arr[i].name[j] = editCont.name[j];
				valid1 = true;
			}
		}
		if(valid1 == true)
		{
		for(int j=0; j<MAX_CONTACT_ADDRESS-1;j++)
		{
				arr[i].address[j] = editCont.address[j];
				valid2= true;
		}
		for(int j=0;j<MAX_CONTACT_EMAIL-1;j++)
		{
				arr[i].email[j] = editCont.email[j];
				valid3 = true;
		}
		for(int j=0;j<MAX_CONTACT_NUMBER-1;j++)
		{
				arr[i].number[j] = editCont.number[j];
				valid3 = true;
		}
      }
	}
	if( valid1 == true && valid2 == true && valid3 == true)
	{
		cout<<" \nThe Contact has been edited Successfully \n";
	}
	else
	{
		cout<<"\n The Contact has not been edited Successfully \n";
	}
}
// Function to save the Contacts in Csv File
void saveContacts(Contact arr[], int size)
{
	bool valid = true;
	ofstream file;
	file.open("Contacts.csv",ios::app);
	if(file.fail())
	{
		cout<<"	File NOT Open"<<endl;
		valid=false;
	}
	else
	{
		for(int i=0;i<size;i++)
    	{
		    file<<arr[i].name<<","<<arr[i].number<<","<<arr[i].address<<","<<arr[i].email;
	    } 
	    file.close();
	}	 
}
// Function to load the contacts from the File
void loadContacts(Contact arr[],int size)
{
	bool valid= true;
    ifstream file;
	file.open("Contacts.csv");
	if(file.fail())
	{
		cout<<"	\n File NOT Open \n"<<endl;
		valid=false;
	}
	else
	{
		for(int i=0;i<size;i++)
    	{
			file.getline(arr[i].name,',');
			file.getline(arr[i].number,',');
			file.getline(arr[i].address,',');
			file>>(arr[i].email);
		    valid=true;
	    }
	    file.close();
	}
}
// Function to Print the Contacts on he Screen
void printContacts(Contact arr[],int size)
{
	cout<<"\n";
	cout<<"Name:"<<'\t'<<"Contact:"<<'\t'<<"Address:"<<'\t'<<"Email:"<<"\n";
	for(int i=0;i<size;i++)
	{
		
		cout<<arr[i].name<<"\n"<<arr[i].number<<"\n"<<arr[i].address<<"\n"<<arr[i].email;
	}
}
// The Menu Function
void Menu(){
	cout<<"*********************Contact Management System **************************************"<<endl;
	cout<<"1. Add Contact \n";
	cout<<"2. Delete Contact \n";
	cout<<"3. Edit Contact \n";
	cout<<"4. Display Contacts \n";
	cout<<"5. Search Conatcts \n";
	cout<<"6. Exit \n";
	cout<<"*************************************************************************************"<<endl;
}
// Function to take input from the User 
void TakeMenuInput(int &Option)
{
	cout<<"\nChoose an Option: \t";
	cin>>Option;
}

// Function to Search the Contacts from the array
void searchContact(Contact arr[],int size, Contact search)
{
	bool valid1 = false;
	cout<<"The contact you searched for is: \n";
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<MAX_CONTACT_NAME-1;j++)
		{
			if(search.name[j] == arr[i].name[j])
			{
				cout<<arr[i].name[j];
				valid1 = true; 
			}
		}
		if(valid1 == true)
		{
		for(int j=0; j<MAX_CONTACT_ADDRESS-1;j++)
		{
				cout<<arr[i].address[j];
		}
		for(int j=0;j<MAX_CONTACT_EMAIL-1;j++)
		{
				cout<<arr[i].email[j];
		}
		for(int j=0;j<MAX_CONTACT_NUMBER-1;j++)
		{
				cout<<arr[i].number[j];
		}
		if(valid1 == true)
		{
			break;
		}
	  }
	}
}

int main()
{
	int Option;
	int size = MAX_CONTACTS;
	Contact arr[MAX_CONTACTS] = {'\0'};
	Contact newContact;
	Contact dltContact;
	Contact editCont;
	Contact oldContact;
	Contact search;
	loadContacts(arr,size);
	Menu();    
	while(true)
	{
		TakeMenuInput(Option);
	  switch(Option)
	{ 
	     // Portion of code to add the contacts
		case 1:
			cout<<"Enter the Name for the Contact \t";
            for(int i=0;i<MAX_CONTACT_NAME;i++)
           {
    	   cin.get(newContact.name[i]);
    	   if(cin.peek()=='\n')
    	   break;
	       }
	cout<<"Enter the address of the Contact \t";
	for(int i=0;i<MAX_CONTACT_ADDRESS;i++)
    {
    	cin.get(newContact.address[i]);
    	if(cin.peek()=='\n')
    	break;
	}
	cout<<"Enter the email of the Contact \t";
	for(int i=0;i<MAX_CONTACT_EMAIL;i++)
    {
    	cin.get(newContact.email[i]);
    	if(cin.peek()=='\n')
    	break;
	}
	cout<<"Enter the Contact Number \t";
	for(int i=0;i<MAX_CONTACT_NUMBER;i++)
    {
    	cin.get(newContact.number[i]);
    	if(cin.peek()=='\n')
    	break;
	}
	addContact(arr,size,newContact);
	break;
	case 2:
		// Portion of code to delete the contacts
		cout<<"Enter the Name of the Contact you want to delete \t";
		for(int i=0;i<MAX_CONTACT_NAME;i++)
        {
    	  cin.get(dltContact.name[i]);
    	  if(cin.peek()=='\n')
    	  break;
	    }
	    deleteContact(arr,size,dltContact);
	    break;
	case 3:
	// Portion of code to edit the Contacts
	cout<<"Enter the Name of the Contact you want to edit: \t";
	 for(int i=0;i<MAX_CONTACT_NAME;i++)
    {
    	cin.get(oldContact.name[i]);
    	if(cin.peek()=='\n')
    	break;
	}
	cout<<"\nEnter the new detalis of the Contact \n" ;
	cout<<"Enter the Name for the Contact \t";
    for(int i=0;i<MAX_CONTACT_NAME;i++)
    {
    	cin.get(editCont.name[i]);
    	if(cin.peek()=='\n')
    	break;
	}
	cout<<"Enter the address of the Contact \t";
	for(int i=0;i<MAX_CONTACT_ADDRESS;i++)
    {
    	cin.get(editCont.address[i]);
    	if(cin.peek()=='\n')
    	break;
	}
	cout<<"Enter the email of the Contact \t";
	for(int i=0;i<MAX_CONTACT_EMAIL;i++)
    {
    	cin.get(editCont.email[i]);
    	if(cin.peek()=='\n')
    	break;
	}
	cout<<"Enter the Contact Number \t";
	for(int i=0;i<MAX_CONTACT_NUMBER;i++)
    {
    	cin.get(editCont.number[i]);
    	if(cin.peek()=='\n')
    	break;
	}
	editContact(arr,size,editCont,oldContact);
	break;
	case 4:
		// Print the contacts on the Screen
	   printContacts(arr,size);
	   break;
	case 5:
	cout<<"Enter the contact Name you want to Search: \t";
	  for(int i=0;i<MAX_CONTACT_NAME;i++)
    {
    	cin.get(search.name[i]);
    	if(cin.peek()=='\n')
    	break;
	}
    searchContact(arr,size,search); 
    break;
	 case 6:
	  saveContacts(arr,size);
	  Menu();
	  break;     
	}
  }
}
