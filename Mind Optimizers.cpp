/*
our main subject is about online pharmacy where people can order the medicine online and we added in formation about each class for example 
class pharmacy consist of staff, medicines and the costumers that will buy the medicine we added staff as a pointer to the pharmacy and 
of course the staff have name, ID and their own salary we also added an action that the staff might do which is adding stock which is an
association relationship, of course we will not forget mentioning that the costumers who buy the medicine need to have name, phone number 
and address so the staff know where to deliver the medicine and how, we have two more classes which are medicine and date, medicine has 
name, date and price and the date is composed of releasing and expired date.

C++ Group project:

Group Name : Mind Optimizers

prepared by:
1). Sara Zuhair
2). Muhammed Raad
3). Yousif Faiq


Admin password : 1133


Staff password : mind optimizers

*/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "windows.h"
#include <ctime>

using namespace std;

//////////////////////////////////////////////////////////////


class Date // declaration of date class
{
	private : // praivate members of date class
	
		string release_date; 
		string exp_date;
	
	
	public : // punlic members of date class.
	
		Date(string rd ="1/1/2019" , string ed = "1/1/2023") // declaration of date constractor.
			{
				release_date=rd;
				exp_date=ed;
			}
		
		string getrelease_date() // accessor funtions
			{
			   return release_date;
			}
		
		string getexpdate() // accessor funtions
			{
				return exp_date;
			}
		
		void setreleasedate(string sr) // Mutator funtions
			{
				release_date=sr;
			}
		
		void setexpd(string exp) // Mutator funtions
			{
				exp_date=exp;
			}  
};

//////////////////////////////////////////////////////////////

class Medicine // declaration of Medicine class
{
	private: // praivate members of Medicine class
		string name;
		double price;

	public :  // public members of Medicine class
		Date date; //declaration of date object
		Medicine(string n="empty" , double p=0.0 , string r="1/1/2019" , string e="1/1/2019") : date(r,e) // declaration of Medicine constractor.
			{
				name = n;
				price = p;
			}
			
		void setnanme(string n)  // Mutator funtions
			{
				name=n;
			}
		
		void print()  // Mutator funtions
			{
				cout<<setw(20)<<name<<setw(20)<<price<<" $"<<setw(20)<<date.getrelease_date()<<setw(20)<<date.getexpdate()<<"     |"<<endl;
			}
		
		string getname() // accessor funtion
			{
				return name;
			}
		
		double getprice() // accessor funtion
			{
				return price;
			}
		
		void setprice(double p)  // Mutator funtions
			{
				price=p;
			}

};
//////////////////////////////////////////////////////////////

class update // declaration of update class
{
	public :	// public members of update class
		
		void dateupdate(vector <Medicine> &p ,int pcounters) // function to update the pills date, expire date or release date
			{
				int index , np;
				string change;
				string neww;
				
				cout<<"Which index do you want to change ?\n";
				cin>>index;
				index-=1;
				
				cin.ignore();
			
				cout<<"In the \n1- expire date \n2- release date \n";
				getline(cin,change);
			
				if(change=="expire date" || change=="Expire date" || change=="1")
					{
						cout<<"What do you want to change the expired date to ?\n";
						cin>>neww;
				
						
						p[index].date.setexpd(neww);	 // to set expire date/
						cout<<"\n---------------------------------------------------------------------------\n"; // here we can display the new pill's expire date ditails
						cout<<"ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(20)<<"EXPIRED DATE"<<endl<<endl;//////////////////////
						
						for (int i=0;i<pcounters;i++)
							{ 	// for loop to get into arrays and print values
								cout<<"|"<<(i+1)<<"-";
								p[i].print();
							}
							
						cout<<"\n----------------------------------------------------------------------------\n";		
					}
				
				if(change=="release date" || change=="Release date" || change=="2")
					{
						cout<<"What do you want to change the realese date to ?\n";
						cin>>neww;
				
						
						p[index].date.setreleasedate(neww);  // to set release date of the pill
						
			 			cout<<"\n---------------------------------------------------------------------------\n"; // // here we can display the new pill's new date, price and name ditails
						cout<<"ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(20)<<"EXPIRED DATE"<<endl<<endl;//////////////////////
												
						for (int i=0;i<pcounters;i++)
							{                         // for loop to get into arrays and print values
								cout<<"|"<<(i+1)<<"-";
								p[i].print();
							}
														
						cout<<"\n----------------------------------------------------------------------------\n";
					}
			}
};
//////////////////////////////////////////////////////////////

class Costumer   // declaration of Costumer class with inheratance of public payment 
{
	private :  // praivate members of Costumer class
   		string Name;
    	string adress;
    	string phoneno;
    	int ifvip;
   
    public : // public members of Costumer class
		Costumer(string n="Empty" , string ad="iraq/slemani/mawlawy" , string pn="Empty",int iv=0) // declaration of Costumer constractor.
			{
				Name=n;
				adress=ad;
				phoneno=pn;
				ifvip=iv;
			}

		int getifvip()
			{
				return ifvip;
			}

		string getname() // accessor funtion
			{
				return Name;
			}
			
		void setname(string n)  // Mutator funtions
			{
				Name=n;
			}

		void setadress(string a)  // Mutator funtions
			{
				adress=a;
			}

		void setphone(string p)  // Mutator funtions
			{
				phoneno=p;
			}

		string getaddress() // accessor funtion
			{
				return adress;
			}

		string getphoneno() // accessor funtion
			{
				return phoneno;
			}

		void print()  // Mutator funtions
			{ // print function to entering name, adress and phoneno
 				cout<<"\n\n<<<<  WELCOME  <3  >>>>\n\n";
 
 				cout<<"please put in your name :\n";
 				cin>>Name;
 
 				cout<<"Please put your adress :)\n";
 				cin>>adress;
 
 				cout<<"And finally put phone number ;)\n";
 				cin>>phoneno;
 			}

		friend ostream& operator <<(ostream &out , Costumer &c) //frinend function declaration
			{ // friend function to displaying name, adress and phoneno
				out<<"Name :"<<c.getname()<<endl;
				out<<"Adress :"<<c.getaddress()<<endl;
				out<<"Phone Number :"<<c.getphoneno()<<endl;
			}
};
//////////////////////////////////////////////////////////////

class Staff  // declaration of Staff class
{
	private :  // praivate members of Staff class
		string password="mind optimizers";
		string Name;
		string ID;
		double salary;

	public :  // public members of Staff class
		Staff(string n , string id, int s) // declaration of Staff constractor.
			{
				Name=n;
				ID=id;
				salary=s;
			}

		string getpassword()
			{
				return password;
			}


		void print()  // Mutator funtions
			{ // print function to display new staff member(name, ID and salary)
				cout<<setw(20)<<Name<<setw(22)<<ID<<setw(10)<<salary<<"        |"<<endl;
			}

		void deletestock(Medicine &m) // Mutator funtions to delete stock
			{
				m.setprice(0);
				m.setnanme("Empty");
				m.date.setexpd("1/1/2019");
				m.date.setreleasedate("1/1/2020");
			}

		string getname() // accessor funtion
			{
				return Name;
			}
 
		string getid() // accessor funtion
			{
				return ID;
			}

		double getsalary() // accessor funtion
			{
				return salary;
			}

		void setsalary(double s) // Mutator funtions
			{
				salary = s;
			}

		void updatesalary() // Mutator funtions for updating and changing salary
			{
				double newsalary;
	
				cout<<"what do you want to change it to ?\n";
				cin>>newsalary;
				setsalary(newsalary); // set salary to newsalary
			}
			
		void setname(string n) // Mutator funtions
			{
				Name = n;
			}

		void setID(string i) // Mutator funtions
			{
				ID = i;
			}
};
//////////////////////////////////////////////////////////////

class Storage // declaration of Storage class
{ 
public :  // public members of Storage class
	double balance;

	Storage(double b=8500) // declaration of Storage constractor.
		{
			balance=b;
		}

	double adding(double numb) // function for adding balance 
		{
			balance+=numb;
			return balance;
		}

	void withdraw(double numb) //  function for withdrawing balance 
		{
			balance-=numb;

			if(balance<0)
				{
					cout<<"\nYou are in great depth !!!!"<<endl<<endl;
				}
			cout<<"Now the blanace is : "<<balance<<endl;
		}

	double getbalance() // accessor funtion
		{
			return balance;
		}

	friend ostream& operator <<(ostream &out , Storage &s) //frinend function declaration to print the balance
		{
			out<<"\n\nThe Balance is : "<<s.balance<<"$"<<endl;
		}

	virtual void  discount(double disc)
		{}
};
//////////////////////////////////////////////////////////////

class Pharmacy // declaration of Pharmacy class
{
	private : // private members of Pharmacy class
		Medicine pills; //declaratiion of pills object
		Costumer buyer; //declaratiion of buyer object
	
	public :  // public members of Pharmacy class
		update upd; //declaratiion of upd object
		Storage balance; //declaratiion of balance object
};
//////////////////////////////////////////////////////////////

class admin  // declaration of admin class
{
	private :   // private members of admin class
		string name;
		string id;
		Storage storage_balance; // declaration of storage balance object

	public :  // public members of admin class
		admin(string n , string i) // declaration of admin constractor
			{
				name=n;
				id=i;
			}

		string getid() // accessor funtion
			{
				return id;
			}
};

class Vdisc  : public Storage
{
	private :
		Pharmacy pharmacy;
		
	public :
			 
		void discount(double disc)
			{
				disc =( disc - ( disc*15/100 ));
				
				cout<<"with the discount is : "<<disc<<"$"<<endl;
				pharmacy.balance.adding(disc);
			}
};
//////////////////////////////////////////////////////////////

class VVipdisc : public Storage
{
	private :
		
		Pharmacy pharmacy;
		
	public :
			 
		void discount(double disc)
			{
				disc =( disc - ( disc*25/100 ));
				
				cout<<"with the discount is : "<<disc<<"$"<<endl;
				pharmacy.balance.balance+=disc;
			}
};
////////////////////////////////////////////////////////////////

int main() // Main function of the program.
{ 
	system("color e5");
	string newname,newphone,newadress;
	double number;
	string admin_id;
	int stocks=5;
	int ccounter=3; // costumer counter
	string answer = "";
	int scounter=3;  // scounter
	string name1;
	double sum=0;
	int pcounter=5; // pill counter
	double x;
	int year=2019;
    int counter=10 ;
    int days;
    int minute;
    int hours ;
	int seconds; 
    string months[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	string n1;
	string re;
	string ex;												
	int ifv=0;
										
	Storage *p;

	Storage pharmacy_balance; // declaration of pharmacy balance

	pharmacy_balance.balance=8500; // setting pharmacy balance to 8500 by defult
	
	admin leader("Mhamad","1133"); // password id is 1133
	
	update upd;
	
	//object declaration in vector 
	vector <Medicine> pill;


	//vector function it is used to insert/add an element 
	pill.push_back(Medicine("Panadol",2,"6/9/2019","1/1/2022") );
	pill.push_back(Medicine("Dolipram",7,"21/9/2019","21/5/2019") );
	pill.push_back(Medicine("Buscopan",4,"18/7/2019","21/3/2020") );
	pill.push_back(Medicine("Alermine",12,"28/6/2018","7/6/2020") );
	pill.push_back(Medicine("Amoxicillin",3,"6/1/2019","10/5/2021") );

	Date date; // declaration of class date

	Pharmacy pharmacy; // declaration of class pharmacy

	//object declaration in vector 	
	vector<Costumer> costumers;
	
	costumers.push_back(Costumer("mudhafar","hawler kn qaraty","07503992511",1));
	costumers.push_back(Costumer("hama","mallawa","xxxxxxxxxx",2));
	costumers.push_back(Costumer("zhilwan","star cafe","xxxxxxxxx",0));

	//object declaration in vector
	vector<Staff> pharmacy_staff;  
	pharmacy_staff.push_back(Staff("Sara", "180119", 700));
	pharmacy_staff.push_back(Staff("Hama","18015",750));
	pharmacy_staff.push_back( Staff("Yousif","8899",700));

	ofstream o;
	o.open("data.txt" , ios::out);

	ofstream s;
	s.open("Staff.txt" , ios::out);

	ofstream c;
	c.open("Customer.txt" , ios::out);

	ofstream a;
	a.open("Admin.txt" , ios::out);


// we added these as a data traser so it saves in the files what has happened when the program was opened



	o<<"\n----------------------------------------------------------------\n";
	o<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"ID"<<setw(20)<<"Salary        |"<<endl;
									
	for(int i=0;i<scounter;i++) //to access the array of (scounter) members and print them
		{ 
			o<<"|"<<(i+1)<<"-";
			o<<setw(20)<<pharmacy_staff[i].getname()<<setw(22)<<pharmacy_staff[i].getid()<<setw(10)<<pharmacy_staff[i].getsalary()<<"        |"<<endl;
		}
		
	o<<"\n----------------------------------------------------------------\n";
	o<<endl<<endl<<endl;
	o<<"\n---------------------------------------------------------------------------\n";
	o<<"ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(20)<<"EXPIRED DATE"<<endl<<endl;//////////////////////
		
	for(int i=0;i<pcounter;i++)//to access the array of (pill counter) and print them
		{
			o<<"|"<<(i+1)<<"-";
			o<<setw(20)<<pill[i].getname()<<setw(20)<<pill[i].getprice()<<" $"<<setw(20)<<pill[i].date.getrelease_date()<<setw(20)<<pill[i].date.getexpdate()<<"     |"<<endl;
		}
		
	o<<"\n----------------------------------------------------------------------------\n";

	cout<<"\t\t<<<<WELCOME>>>>>> \n\n\n";
									
	// to display name, ID, and salary of staff members
	cout<<"\n----------------------------------------------------------------\n";
	cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"ID"<<setw(20)<<"Salary        |"<<endl;
								
	for(int i=0;i<scounter;i++) //to access the array of (scounter) members and print them
		{ 
			cout<<"|"<<(i+1)<<"-";
			pharmacy_staff[i].print();
		}
		
	cout<<"\n----------------------------------------------------------------\n";
	cout<<endl;
	
	// to display pill's name, price, release date and expire date.
	cout<<"\n---------------------------------------------------------------------------\n";
	cout<<"ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(20)<<"EXPIRED DATE"<<endl<<endl;//////////////////////
												
	for(int i=0;i<pcounter;i++)//to access the array of (pill counter) and print them
		{
			cout<<"|"<<(i+1)<<"-";
			pill[i].print();
		}
		
	cout<<"\n----------------------------------------------------------------------------\n";
																												
	// to display the opening time and date															
	cout<<"Opened at :";
	time_t aa;
	
		aa=time(NULL);
		tm *t=localtime(&aa);
			
	if(t->tm_hour<10)
		{
			cout<<0<<t->tm_hour<<":";
		}
		
	if(t->tm_hour>=10)
		{
			cout<<t->tm_hour<<":";
		}
			
	if(t->tm_min<10)
		{
			cout<<0<<t->tm_min<<":";
		}
		
	if(t->tm_min>=10)
		{
			cout<<t->tm_min<<":";
		}
		
	if(t->tm_sec<10)
		{
			cout<<0<<t->tm_sec<<endl;
		}
		
	if(t->tm_sec>=10)
		{
			cout<<t->tm_sec<<endl;
		}
		
	cout<<t->tm_mday<<"/"<<months[t->tm_mon]<<"/"<<t->tm_year+1900;
		
	o<<"It was opened at : ";
		
	if(t->tm_hour<10)
		{
			o<<0<<t->tm_hour<<":";
		}
		
	if(t->tm_hour>=10)
		{
			o<<t->tm_hour<<":";
		}
			
	if(t->tm_min<10)
		{
			o<<0<<t->tm_min<<":";
		}
		
	if(t->tm_min>=10)
		{
			o<<t->tm_min<<":";
		}
		
	if(t->tm_sec<10)
		{
			o<<0<<t->tm_sec<<endl;
		}
		
	if(t->tm_sec>=10)
		{
			o<<t->tm_sec<<endl;
		}
		
	o<<"On "<<t->tm_mday<<"/"<<months[t->tm_mon]<<"/"<<t->tm_year+1900<<endl<<endl;
	cout<<"\n\nPlease wait";
	
		Sleep(700);
		cout<<".";
		Sleep(700);
		cout<<".";
		Sleep(900);
		cout<<"."<<endl<<endl;
		Sleep(100);
															
	cout<<"\n\nPress Enter to continue \n";
	cin.get();		 										
															
	o<<"\nAnonymous Pressed Enter \n\n";
															
again1:
again:
beginning:
	
	sum=0;
	
first:
	
	cout<<"\n\nPlease before anything begins\n"; //fiest we want to know who are you( Administrator, Customer or Staff.
	cout<<"\nWe would like to know if you are an \n\n1- Administrator  \n2- Customer \n3- Staff\n\n------------------------------\n\n";
	cin>>answer;

	o<<"\nAnonymous Wrote :" <<answer<<endl<<endl;

	if (answer=="admin" || answer=="1" || answer=="Admin" || answer=="a" || answer=="A")
		{
			retry: 
	 		a<<"\nAdmin opened\n\n";
			cout<<"\nPlease put the ID so i can confirm it's you : "<<endl<<">";
			cin>>admin_id;
			
			if(admin_id == leader.getid())
				{
					something:
					a<<"\nAdmin put the right password\n\n";
					// the Administrator's menu

					cout<<"\n---------------------------------------------\n";
					cout<<"\nWelcome sir what do you want to do ?\n\n";
					cout<<"1- See the balance\n";
					cout<<"2- Change a salary of a staff member\n";
					cout<<"3- Add a staff member\n";
					cout<<"4- Firing a staff member\n";
					cout<<"\n---------------------------------------------\n";
					cout<<endl;
					cin.ignore();
					getline(cin,answer);
			
					a<<"\n---------------------------------------------\n";
					a<<"\nWelcome sir what do you want to do ?\n\n";
					a<<"1- See the balance\n";
					a<<"2- Change a salary of a staff member\n";
					a<<"3- Add a staff member\n";
					a<<"4- Firing a staff member\n";
					a<<"\n---------------------------------------------\n";
					a<<"\nThe admin chose "<<answer<<endl<<endl;
			
					if(answer=="1" || answer=="Balance" || answer=="balance" || answer=="b" || answer=="B") // to change, add and wirthdraw balance by Administrator.
						{
							cout<<pharmacy.balance;
							cout<<"\n---------------------------------------------\n";
							cout<<"\nDo you want to : \n\n|1-add  \n\n|2-wirthdraw \n\n";
							cout<<"\n---------------------------------------------\n";
							cin >> answer;
				
							a<<"\n---------------------------------------------\n";
							a<<"\nDo you want to : \n\n|1-add  \n\n|2-wirthdraw \n\n";
							a<<"\n---------------------------------------------\n";
							a<<"The admin chose "<<answer<<endl<<endl;
				
					if(answer=="1" || answer=="add" || answer=="Add") // adding balance by Administrator
						{
							cout<<"How much do you want to add sir\n";
							cin>>number;
					
							pharmacy_balance.adding(number); // setting balance to pharmacy_balance obj
							cout<<"Now the Balance is : "<<pharmacy_balance.getbalance(); // print and get balace
					
							a<<"The admin added : "<<number<<endl;
							a<<"And the balance now is : "<<pharmacy_balance.getbalance()<<endl<<endl;
							cout<<"\nDo you want to \n1- go back \n2- Do something else  \n3- End:"<<endl;  //asking if Administrator want to go back or not, for do more changing on staff members
							cin>>answer;
							a<<"The admin chose "<<answer<<endl<<endl;
									
							if(answer=="1" || answer=="back" || answer=="Back")
								{
									a<<" Now it goes back to the begining \n\n";
									goto again;
								}
					
							if(answer=="2" || answer=="Else" || answer=="else")
								{
									a<<"Admin wanted to do something else \n\n";
									goto something;
								}
					
							if(answer=="3" || answer=="end" || answer=="Endl")
								{
									a<<"\nThe admin chose to end the program \n\n";
									goto end;
								}
							}
				
					if(answer=="withdraw" || answer=="Withdraw" || answer=="2") // withdrawing balance
						{
							a<<"The Admin chose to withdraw \n\n";
							cout<<"\nHow much do you want to withdraw sir\n";
							cin>>number;
			
							pharmacy_balance.withdraw(number); // setting withdraw to pharmacy_balance obj
			
							pharmacy.balance.balance-=number;
			
							a<<"The admin chose to withdraw "<<number<<" and now the balance is "<<pharmacy_balance.balance;
			
							cout<<"\nDo you want to go back :"<<endl; //asking if Administrator want to go back or not
							cin>>answer;
					
							a<<"The admin chose "<<answer<<endl<<endl;
					
							if(answer=="yes")
								{
									a<<"The admin chose to do something else "<<endl<<endl;
									goto again;
								}
					
							if(answer=="no")
								{
									a<<"The admin chose to end the program"<<endl<<endl;
									goto end;
								}
							}
						}
						
					if (answer=="2" || answer=="Change" || answer=="change") //to changing staffs by Administrator(name, ID or salary)
						{
							a<<"The admin chose to change one of the staffs salary\n";
							cout<<"\n----------------------------------------------------------------\n";
							cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"ID"<<setw(20)<<"Salary        |"<<endl;
								
							for(int i=0;i<scounter;i++) //for loop to access pharmacy_staff array
								{
									cout<<"|"<<(i+1)<<"-";
									pharmacy_staff[i].print();
								}
								
							cout<<"\n----------------------------------------------------------------\n";		
							cout<<"\nTheir password is : "<<pharmacy_staff[0].getpassword()<<endl;				
							int index; // to update staff's salary by administrator
							cout<<"Which staff you want to update the salary too ? \n";
							cin>>index;
							index-=1;
							pharmacy_staff[index].updatesalary(); //calling updatesalary to  pharmacy_staff array to change salary of staffs 
			
							a<<"The admin chose to change "<<pharmacy_staff[index].getname()<<" and changed it to "<<pharmacy_staff[index].getsalary()<<endl<<endl;
			
							cout<<"\nDo you want to \n1- go back \n2- Do something else  \n3- End:"<<endl;  //asking if Administrator want to go back or not, for do more changing on staff members
							cin>>answer;
					
							if(answer=="1" || answer=="back" || answer=="Back")
								{
									a<<"The admin chose to go back to first \n\n"<<endl<<endl;
									goto again;
								}
					
							if(answer=="2" || answer=="Else" || answer=="else")
								{
									a<<"The admin chose to do something else \n\n"<<endl<<endl;
									goto something;
								}
				
							if(answer=="3" || answer=="end" || answer=="Endl")
								{
									a<<"The admin chose to end the program \n\n"<<endl<<endl;
									goto end;
								}
			
						}
			
					if(answer=="3" || answer=="add a staff member" || answer=="Add a staff member") // adding new staff member by Administrator
						{
							a<<"The admin chose to add a staff member \n\n";
							scounter=scounter+1; // add one staff more to scounter
							string newname; //deffing name
							string newid; // deffing ID
							int newsalary; // deffing salary
				
							pharmacy_staff[scounter]; // adding scounter to pharmacy staff array
				
							cout<<"Please insert the name : \n"; // adding name
							cin>>newname;
				
							cout<<"Please insert the id :\n"<<endl; //adding id
							cin>>newid;
				
							cout<<"please insert the salary in integer default(500) : \n"; // adding salary
							cin>>newsalary;
				
							a<<"The admin added "<<newname<<" with the id of "<<newid<<" with a salary of :"<<newsalary;

							pharmacy_staff.push_back( Staff(newname,newid,newsalary)); //saving all new datas in pharmacy staff array (newname, newid and newsalary)
					
							cout<<"\nDo you want to \n1- go back \n2- Do something else  \n3- End:"<<endl;  //asking if Administrator want to go back or not, for do more changing on staff members
							cin>>answer;
					
					if(answer=="1" || answer=="back" || answer=="Back")
						{
							a<<"The admin chose to go back to first "<<endl<<endl;
							goto again;
						}
					
					if(answer=="2" || answer=="Else" || answer=="else")
						{
							a<<"The admin chose to do something else \n\n"<<endl<<endl;
							goto something;
						}
					
					if(answer=="3" || answer=="end" || answer=="End")
						{
							a<<"The admin chose to end the program \n\n"<<endl<<endl;
							goto end;
						}
				}	
			
			if(answer=="4" || answer=="Firing a staff member" || answer=="firing a staff member") // to firing staff member by Administrator
				{
					a<<"The admin chose to fire a staff\n\n";
					int x;
				
					cout<<endl<<endl;
					cout<<"\n----------------------------------------------------------------\n";
					cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"ID"<<setw(20)<<"Salary        |"<<endl;
								
					for(int i=0;i<scounter;i++) // here all members will be displayed so that the Administrator will choose the fired member
						{
							cout<<"|"<<(i+1)<<"-";
							pharmacy_staff[i].print();			
						}
					cout<<"\n----------------------------------------------------------------\n";
															
					cout<<"which member do want to fire ?"<<endl; // to choose the member that Administrator want to fire
					
					cin>>x;
					x-=1;
					a<<"The admin fired "<<pharmacy_staff[x].getname()<<endl;
					
					pharmacy_staff[x]= Staff("Empty","0000",500);
				
					cout<<"\nDo you want to \n1- go back \n2- Do something else  \n3- End:"<<endl;  //asking if Administrator want to go back or not, for do more changing on staff members
					cin>>answer;
					
					a<<"\nDo you want to \n1- go back \n2- Do something else  \n3- End"<<endl;
					a<<"\nThe admin chose "<<answer;
					
					if(answer=="1" || answer=="back" || answer=="Back")
						{
							a<<"The admin chose to go back to first "<<endl<<endl;
							goto again;
						}
					
					if(answer=="2" || answer=="Else" || answer=="else")
						{
							a<<"The admin chose to do something else "<<endl<<endl;
							goto something;
						}
					
					if(answer=="3" || answer=="end" || answer=="Endl")
						{
							a<<"The admin chose to end the program "<<endl<<endl;
							goto end;
						}
				}
		}
		
			if(admin_id!=leader.getid()) // when the user enter the wrong leader ID, it will ask again to enter the right ID code
				{
					a<<"The admin password was in correct \n\n";
					cout<<"\n\nThe id you entered is wrong \n would you like to \n1- Retry  \n2- Change \n3- Exit\n\n\n";
					
					a<<"\n\nThe id you entered is wrong \n would you like to \n1- Retry  \n2- Change \n3- Exit\n\n\n";
					
					cin>>answer;
					cout<<"The anonymous chose : "<<answer<<endl;
					
					if(answer=="1" || answer=="retry" || answer=="Retry") // to try for re-entering ID
						{
							a<<"The anonymous chose to retry \n";
							goto retry; // ging to retry
						}
					
					if(answer=="2" || answer=="Change"|| answer=="change") // to start at the beginning of program asking who are you (Administrator, Customer or Staff)
						{
							a<<"The anonymous chose to go to the begining \n";
					
							goto beginning; //going to beginning
						}
					
					if(answer=="3" || answer=="exit"|| answer=="Exit") // to exit the program
						{
							a<<"The anonymous chose to end the program \n";
					
							goto end; // going to end
					
						}		
				}
	}

			if(answer=="Customer" || answer=="customer" || answer=="2" || answer=="C" || answer=="c") //costomer's choice
				{
					a<<"\nthe costumer was opened \n\n";
			
					cout<<"\nHave you been on our website before ?\n"; // asking if he/she for first time visiting our site 
					cin>>answer;
		
			
					if(answer=="yes" || answer=="Yes" || answer=="1" || answer=="y" || answer=="Y")
						{
							c<<"The costumer has been here before \n\n";
		
							cout<<"Please insert the your name to check if your name is in the system ... \n>"; // if they were already been on our site the system will check there name if it is entered or not
							cin>>name1;
		
							for(int i=0;i<ccounter;i++) // if they been on our site it will display by array of costumers
								{
									if(costumers[i].getname()==name1)
										{
											cout<<"Hello "<<costumers[i].getname();
				
											c<<"The costumers name is "<<costumers[i].getname();
				
											cout<<"\n\nYour informations are :"<<endl<<endl;
											cout<<costumers[i];
				
											cout<<"\n\nCorrect ?"<<endl<<endl; // asking if the infomations which entered are correct or not?
											cin>>answer;
				
											if(answer=="yes" || answer=="1")
												{
													c<<"\n\nHis informations are : "<<costumers[i]; 
													ifv=i;
													break;
												}
				
											if(answer=="changed" || answer=="no")
												{
													goto log ;
												}
										}
				
									if(costumers[0].getname()!=name1 && costumers[1].getname()!=name1 && costumers[2].getname()!=name1 &&  costumers[3].getname()!=name1 && costumers[4].getname()!=name1 )
										{ // searching in costumers for make sure if the costumer been on our site or not
											cout<<"your name is not there anymore  ";
											ccounter+=1;                              
											costumers[ccounter].print(); 
											goto log;             
										}
								}
			
		cout << "\a";
		cout << "\n\n\n\n\n<3 WELCOME <3\n\n\n";
		cout << "\t\tMENU\n\n\n";
		
		menu : // displaying menu for costumers, so that he/she can chooce the wanted pill
		cout<<"\n----------------------------------------------------------------------------------------------\n";
		cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(30)<<"EXPIRED DATE        |"<<endl;
		
		for(int i=0;i<pcounter;i++)
			{
				cout<<"|"<<(i+1)<<"-";
				pill[i].print(); // printing pills
			}
		cout<<"\n----------------------------------------------------------------------------------------------\n";
		cout<<"What kind of medicine do you want to buy ?\n\n"; // asking what kind of pill costumer want to buy
		cin>>answer;
		
		
		
		
		
		if(answer=="1" || answer=="panadol")// if costumer want to buy panadol
		{
			c<<"He wanted to buy panadol"<<endl<<endl;
			
		    sum+=pill[0].getprice(); // getting price and displaying it for costumer
		  
		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
			cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
			
			
			cin>>answer;
			
					if(answer=="yes" || answer=="1")
					{
						c<<"He wanted to buy another\n\n";
						goto menu ; // if costumer enter yes or 1, it will call menu
						
					}
			
							if(answer=="no"|| answer =="n")
					{
						
					
		  
		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
						
						cout<<"\n\nDo you have a vip or vvip membership \n";
				  cin>>answer;
				  
				  if (answer=="yes")
				  {
				  	
					  
				  
				  	
				  	
				  	cout<<"\n\n---------------------------------------\n";
				  	cout<<"|1- VIP\n |2- VVIP\n|\n";
				  	cout<<"---------------------------------------\n\n";
				  	
				  	cout<<"which ?"<<endl;
				  	cin>>answer;
				  	
				  	if(answer=="1" || answer=="vip" || answer=="Vip")
				  	{
				  		
				  			if(costumers[ifv].getifvip()!=1 )
					{	c<<"He had a vip membership\n\n";
						cout<<"\nSorry but in our infromation you dont have vip \n";
						goto end ;
						pharmacy_balance.balance=+sum;
						
					}
				  		
					  if(costumers[ifv].getifvip()==1)
				  	{
				  		
				  		cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
				  		p= new Vdisc;
				  	p->discount(sum);
				  	Sleep(1000);
				  		
				  		pharmacy_balance.balance=+sum;
				  		cout<<endl;
					  }
					  }
					  
					  
					
					  
					  if(answer=="2" || answer=="vvip" || answer=="Vvip")
					  {
					  	
					  		if( costumers[ifv].getifvip()!=2)
					{
						cout<<"\nSorry but in our infromation you dont have vvip \n";
						goto end ;
						
					}
					  	
					  	
					  	if(costumers[ifv].getifvip() ==2 )
					  	{
					  		
					  	c<<"He had a vvip membership\n\n";
					  	cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
					  	p= new VVipdisc;
					  	
					  	p->discount(sum);
					  	Sleep(1000);
					  pharmacy_balance.balance=+sum;
					  	
					  }
					  }
					
					
						
					
				  }
						
						
						
						
						
						
					cout<<"Thank you for purchasing at Supreme pharmacy\n\n"; // thanks
					
					
					cout<<"\a";
					pharmacy_balance.balance=+sum;
					goto end;
				}
		}
		
		
		
		if(answer=="2" || answer=="Dolipram") // if costumer want to buy Dolipram
		{
			c<<"He wanted to buy dolipram"<<endl<<endl;
		
		sum+=pill[1].getprice(); // getting price and displaying it for costumer
		  
		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
			cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
			cin>>answer;
			
			
					if(answer=="yes" || answer=="1")
					{c<<"He wanted to buy another \n\n";
						goto menu; // if costumer enter yes or 1, it will call menu
					}
			
							if(answer=="no") 
				{
						c<<"He didnt want more \n\n";
				  
						
				  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
				  
				  
				  cout<<"\n\nDo you have a vip or vvip membership \n";
				  cin>>answer;
				  
				  if (answer=="yes")
				  {
				  	
				  	
				  	
				  	cout<<"\n\n---------------------------------------\n";
				  	cout<<"|1- VIP\n |2- VVIP\n|\n";
				  	cout<<"---------------------------------------\n\n";
				  	
				  	cout<<"which ?"<<endl;
				  	cin>>answer;
				  	
				  	if(answer=="1" || answer=="vip" || answer=="Vip")
				  	{
				  		
				  		if(costumers[ifv].getifvip()!=1 )
					{
						cout<<"\nSorry but in our infromation you dont have vip \n";
						pharmacy_balance.balance=+sum;
						goto end ;
						
					}
				  		
				  		
				  		if(costumers[ifv].getifvip()==1)
				  	{
				  		cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
				  		p= new Vdisc;
				  	p->discount(sum);
				  	Sleep(1000);
				  	pharmacy_balance.balance=+sum;
					  c<<"He had a vip membership \n\n";
				  		
				  	}
				  		
				  		cout<<endl;
					  }
				  		
				  		
				  		
					  }
					  
					  if(answer=="2" || answer=="vvip" || answer=="Vvip")
					  {
							  	if( costumers[ifv].getifvip()!=2)
							{
								cout<<"\nSorry but in our infromation you dont have vvip \n";
								goto end ;
								
							}
					  	
					  	
					  	if(costumers[ifv].getifvip()==2)
				  	{
					  	
					  	c<<"He had a vvip membership \n\n";
					  	cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
					  	p= new VVipdisc;
					  	
					  	p->discount(sum);
					  	Sleep(1000);
				
					  
					  }
					  }
				  }
				  
				  
					cout<<"Thank you for purchasing at Supreme pharmacy\n\n";
					// if costumer finish the purchasing it will end the program
					
					cout<<"\a";
					goto end;
				}
		}
		
		
		
	
		
		if(answer=="3" || answer=="Buscopan") // if costumer want to buy Buscopan
		{
			c<<"He wanted to buy "<<pill[2].getname()<<endl<<endl;
			sum+=pill[2].getprice(); // getting price and displaying it for costumer
		  
		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
		
			cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
			cin>>answer;
			
			
				if(answer=="yes" || answer=="1")
				{c<<"He wanted to buy another\n\n";
					goto menu ;  // if costumer enter yes or 1, it will call menu
				}
			
			
							if(answer=="no" || answer =="n")
				{
					
				  
				  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
						
						
						cout<<"\n\nDo you have a vip or vvip membership \n";
				  cin>>answer;
				  
				  if (answer=="yes")
				  {
				  	
				  	
				  	cout<<"\n\n---------------------------------------\n";
				  	cout<<"|1- VIP\n |2- VVIP\n|\n";
				  	cout<<"---------------------------------------\n\n";
				  	
				  	cout<<"which ?"<<endl;
				  	cin>>answer;
				  	
				  	if(answer=="1" || answer=="vip" || answer=="Vip")
				  	{
				  			if(costumers[ifv].getifvip()!=1 )
					{
						cout<<"\nSorry but in our infromation you dont have vip \n";
						goto end ;
						
					}
				  	
				  		if(costumers[ifv].getifvip()==1)
				  	{
				  		
				  		
				  			c<<"He had a vip membership \n\n";
				  		cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
				  		p= new Vdisc;
				  	p->discount(sum);
				  	Sleep(1000);
				  	
				  }
				  	
					  }
					  
					  if(answer=="2" || answer=="vvip" || answer=="Vvip")
					  {
					  		if(costumers[ifv].getifvip()!=2 )
					{
						cout<<"\nSorry but in our infromation you dont have vvip \n";
						goto end ;
						
					}
				  	if(costumers[ifv].getifvip()==2)
				  	{
					  	
					  	
					  		c<<"He had a vvip membership \n\n";
					  	cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
					  	p= new VVipdisc;
					  	
					  	p->discount(sum);
					  	Sleep(1000);
					  pharmacy_balance.balance=+sum;
					  
				}
					  	
					  }
				  }
						
						
					cout<<"Thank you for purchasing at Supreme pharmacy\n\n";
					// if costumer finish the purchasing it will end the program
					
					cout<<"\a";
					goto end;
				}
	
	
		}
		
		
		
		
		
		if(answer=="4" || answer=="alermine") // if costumer want to buy alermine
		{c<<"He wanted to buy alermine"<<endl<<endl;
		sum+=pill[3].getprice(); // getting price and displaying it for costumer
		  
		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
		
			cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
			cin>>answer;
			
					if(answer=="yes" || answer=="1")
					{c<<"he wanted to buy another pill \n\n";
						goto menu ; // if costumer enter yes or 1, it will call menu
					}
			
								if(answer=="no" || answer=="n")
				{
						
				  
				  cout<<"\n it costs :"<<sum<<"$"<<endl;
				  
				  cout<<"\n\nDo you have a vip or vvip membership \n";
				  cin>>answer;
				  
				  if (answer=="yes")
				  {
				  	
				  	
				  	cout<<"\n\n---------------------------------------\n";
				  	cout<<"|1- VIP\n |2- VVIP\n|\n";
				  	cout<<"---------------------------------------\n\n";
				  	
				  	cout<<"which ?"<<endl;
				  	cin>>answer;
				  	
				  	
				  	if(answer=="1" || answer=="vip" || answer=="Vip")
				  	{
				  		
				  		
				  		if(costumers[ifv].getifvip()!=1 )
					{
						cout<<"\nSorry but in our infromation you dont have vip \n";
						goto end ;
						
					}
				  		
				  		if(costumers[ifv].getifvip()==1)
				  	{
					  	
				  		c<<"He had a vip membership\n\n";
				  		cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
				  		p= new Vdisc;
				  	p->discount(sum);
				  	Sleep(1000);
				  		pharmacy_balance.balance=+sum;
				  		
				  }
				  		
					  }
					  
					  if(answer=="2" || answer=="vvip" || answer=="Vvip")
					  {
					  	
					  		if(costumers[ifv].getifvip()!=2 )
					{
						cout<<"\nSorry but in our infromation you dont have vvip \n";
						goto end ;
						
					}
					  	
					  	if(costumers[ifv].getifvip()==2)
				  	{
					  	
					  	
					  	c<<"He had a vvip membership\n\n";
					  	cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
					  	p= new VVipdisc;
					  	
					  	p->discount(sum);
					  	Sleep(1000);
					  	pharmacy_balance.balance=+sum;
					  
				}
					  	
					  }
					  
					  
				  }
				  
				  
					cout<<"\n\nThank you for purchasing at Supreme pharmacy\n\n";
						// if costumer finish the purchasing it will end the program
					
					cout<<"\a";
					goto end;
				}
		
		}
		
	
		
		
		
		if(answer=="5" || answer=="amoxilline") // if costumer want to buy amoxilline
		{c<<"He wanted amoxilline\n\n";
			sum+=pill[4].getprice(); // getting price and displaying it for costumer
		  
		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
		
			cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
			cin>>answer;
			
					if(answer=="yes" || answer=="1")
					{c<<"he wanted to buy another\n\n";
						goto menu ; // if costumer enter yes or 1, it will call menu
					}
				
							if(answer=="no" || answer=="n" || answer=="2")
				{
						
				  
				  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
				  
				  cout<<"\n\nDo you have a vip or vvip membership \n";
				  cin>>answer;
				  
				  if (answer=="yes")
				  {
				  	
				  	
				  	cout<<"\n\n---------------------------------------\n";
				  	cout<<"|1- VIP\n |2- VVIP\n|\n";
				  	cout<<"---------------------------------------\n\n";
				  	
				  	cout<<"which ?"<<endl;
				  	cin>>answer;
				  	
				  	if(answer=="1" || answer=="vip" || answer=="Vip")
				  	{
				  		
						  	if(costumers[ifv].getifvip()!=1 )
					{
						cout<<"\nSorry but in our infromation you dont have vip \n";
						pharmacy_balance.balance=+sum;
						goto end ;
						
					}
				  		if(costumers[ifv].getifvip()==1)
				  	{
				  		
				  		c<<"He had a vip membership \n\n";
				  		cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
				  		p= new Vdisc;
				  	p->discount(sum);
				  	Sleep(1000);
				  	pharmacy_balance.balance=+sum;
				  }
				  	
					  }
					  
					  if(answer=="2" || answer=="vvip" || answer=="Vvip")
					  {
					  		if(costumers[ifv].getifvip()!=2 )
					{
						cout<<"\nSorry but in our infromation you dont have vvip \n";
						pharmacy_balance.balance=+sum;
						goto end ;
						
					}
					  	
					  	if(costumers[ifv].getifvip()==2)
				  	{
					  	c<<"He had a vip membership \n\n";
					  	cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
					  	p= new VVipdisc;
					  	
					  	p->discount(sum);
					  	Sleep(1000);
					  	pharmacy_balance.balance=+sum;
					  
					  }
					  }
				  }
					
					cout<<"Thank you for purchasing at Supreme pharmacy\n\n";
					
					
						// if costumer finish the purchasing it will end the program
						pharmacy_balance.balance=+sum;
					
					cout<<"\a";
					goto end;
				
				}
		
		}
		
		
		
		

				
				if(answer=="6" || answer=="7" || answer=="8" || answer=="9" || answer=="10")
				{
		
		
					int twice;
					
					
					
		cout<<"\n----------------------------------------------------------------------------------------------\n";
		
		cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(30)<<"EXPIRED DATE        |"<<endl;
		
		
		for(int i=0;i<pcounter;i++)
		{
			
			cout<<"|"<<(i+1)<<"-";
			pill[i].print(); // printing pills
			
		}
		
		
		
		cout<<"\n----------------------------------------------------------------------------------------------\n";

					
					cout<<"This is a pill has been added recently please enter again to confirm : \n";
					cin>>twice;
					
					sum+=pill[twice].getprice(); // getting price and displaying it for costumer
		  
		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
		
			cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
			cin>>answer;
			
					if(answer=="yes" || answer=="1")
					{
						goto menu ; // if costumer enter yes or 1, it will call menu
					}
				
							if(answer=="no" || answer=="n")
				{
						
				  
				  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
				  
				  cout<<"\n\nDo you have a vip or vvip membership \n";
				  cin>>answer;
				  
				  if (answer=="yes")
				  {
				  	
				  	
				  	cout<<"\n\n---------------------------------------\n";
				  	cout<<"|1- VIP\n |2- VVIP\n|\n";
				  	cout<<"---------------------------------------\n\n";
				  	
				  	cout<<"which ?"<<endl;
				  	cin>>answer;
				  	
				  	if(answer=="1" || answer=="vip" || answer=="Vip")
				  	{
					  if(costumers[ifv].getifvip()!=1 )
					{
						cout<<"\nSorry but in our infromation you dont have vip \n";
						goto end ;
						
					}
					  		if(costumers[ifv].getifvip()==1)
				  	{
					  
					  c<<"He had a vip membership \n\n";
				  		cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
				  		p= new Vdisc;
				  	p->discount(sum);
				  	Sleep(1000);
				  	pharmacy_balance.balance=+sum;
				  }
				  	
					  }
					  
					
					  if(answer=="2" || answer=="vvip" || answer=="Vvip")
					  {
					  	if(costumers[ifv].getifvip()!=2 )
					{
						cout<<"\nSorry but in our infromation you dont have vvip \n";
						goto end ;
						
					}
					  		if(costumers[ifv].getifvip()==2)
				  	{
					  	c<<"He had a vvip membership \n\n";
					  	cout<<"\nHello sir wait till we do the discount ...\n";
				  		Sleep(2000);
					  	p= new VVipdisc;
					  	
					  	p->discount(sum);
					  	Sleep(1000);
					  	pharmacy_balance.balance=+sum;
					  }
					
				}
		
		
	}
	
}
}
		
					if(answer=="no" || answer=="n" || answer=="2") // if costumer visiting our site for first time
					{
					log:
						ccounter+=1;
					
					
					 cout<<"\n\n<<<<  WELCOME  <3  >>>>\n\n";
			 
			 cout<<"please put in your name :\n"; // they have to enter their name
			 cin.ignore();
			 getline(cin,newname);
			 
			 cout<<"Please put your adress :)\n"; // and also the adress
			 cin.ignore();
			 getline(cin,newadress);
			 
			 cout<<"And finally put phone number ;)\n"; // finaly adding phone number
			 cin>>newphone;
			 
			 cout<<"\nDo you want to buy a vip or vvip member ship for your next visit to our website ?\n";
			 cin>>answer;
			 
			 if(answer=="yes" || answer=="1")
			 {
			 	cout<<"1- Vip costs : 12$"<<endl<<endl;
			 	cout<<"2- VVip costs : 18$"<<endl<<endl;
			 	cin>>answer;
			 	
			 	if(answer=="1" || answer=="vip")
			 	{
			 		ifv=1;
				 }
				 
				 if(answer=="2" || answer=="vvip")
			 	{
			 		ifv=2;
				 }
				 
				
			 	
			 	
			 }
			 
			 
			 if(answer=="no" || answer=="2")
			 {
			 	ifv=0;
			 	
			 }
			 
			 
			 c<<"An extra customer came with name "<<newname<<" adress with "<<newadress<<" Phone number of "<<newphone<<endl<<endl;
			 
			 costumers.push_back(Costumer(newname,newadress,newphone)); // saving all new datas in costumers.push_back
			 
					
					
					
					
					back1:
					cout<<endl<<endl;
					
					cout<<"\n----------------------------------------------------------------------------------------------\n";
						cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(30)<<"EXPIRED DATE        |"<<endl;
		
							for(int i=0;i<pcounter;i++)
							{
			
								cout<<"|"<<(i+1)<<"-";
								pill[i].print();
			
							}
						cout<<"\n----------------------------------------------------------------------------------------------\n";
								cout<<"\n\nWhat do you want to purchase ?\n>";
								cin>>answer;
									if(answer=="1" || answer=="panadol")// if costumer want to buy panadol
									{
										c<<"He wanted to buy panadiol\n\n";
		   								 sum+=pill[0].getprice(); // getting price and displaying it for costumer
		  
										  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
										cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
										cin>>answer;
			
										if(answer=="yes" || answer=="1")
										{
										goto back1; // if costumer enter yes or 1, it will call menu
							
										}
			
										if(answer=="no"|| answer =="n")
										{
						
										cout<<"\nSo far it costs :"<<sum<<"$"<<endl; // if costumer finish the purchasing it will end the program
						
										cout<<"Thank you for purchasing at Supreme pharmacy\n\n"; // thanks
					
						pharmacy_balance.balance=+sum;
										cout<<"\a";
										goto end;
										}
									}		
		
		
		
								if(answer=="2" || answer=="Dolipram") // if costumer want to buy Dolipram
								{c<<"He wanted to buy dolipram\n\n";
		
									sum+=pill[1].getprice(); // getting price and displaying it for costumer
		  
							      		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
										cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
										cin>>answer;
			
			
										if(answer=="yes" || answer=="1")
										{c<<"He wanted to buy another \n\n";
										goto back1; // if costumer enter yes or 1, it will call menu
										}
			
										if(answer=="no") 
										{
						
				  
												pharmacy_balance.balance=+sum;
				 						 cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
										cout<<"Thank you for purchasing at Supreme pharmacy\n\n";
										// if costumer finish the purchasing it will end the program
					
										cout<<"\a";
											goto end;
										}
								}
		
		
		
	
		
							if(answer=="3" || answer=="Buscopan") // if costumer want to buy Buscopan
								{
									c<<"He wanted to buy Buscopan\n\n";
									sum+=pill[2].getprice(); // getting price and displaying it for costumer
		  
									  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
				
										cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
										cin>>answer;
			
			
									if(answer=="yes" || answer=="1")
									{c<<"He wanted to buy another \n\n";
										goto back1 ;  // if costumer enter yes or 1, it will call menu
									}
			
			
									if(answer=="no" || answer =="n")
									{
					
				  									pharmacy_balance.balance=+sum;
				  						cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
						
										cout<<"Thank you for purchasing at Supreme pharmacy\n\n";
										// if costumer finish the purchasing it will end the program
					
										cout<<"\a";
										goto end;
							     	}	
	
	
							}
		
		
		
		
		
							if(answer=="4" || answer=="alermine") // if costumer want to buy alermine
							{
								c<<"He wanted to buy Alermine \n\n";
								sum+=pill[3].getprice(); // getting price and displaying it for costumer
		  
		 						 cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
		
									cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
									cin>>answer;
			
								if(answer=="yes" || answer=="1")
								{c<<"He wanted to buy another \n\n";
									goto back1 ; // if costumer enter yes or 1, it will go to menu
								}
			
								if(answer=="no" || answer=="n")
								{
					
					
				  
				 				 cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
				  
								cout<<"Thank you for purchasing at Supreme pharmacy\n\n";
								// if costumer finish the purchasing it will end the program
										pharmacy_balance.balance=+sum;
								cout<<"\a";
								goto end;
								}
		
						}
		
	
		
		
		
						if(answer=="5" || answer=="amoxilline") // if costumer want to buy amoxilline
						{
							c<<"He wanted to buy amoxilline \n\n";
							sum+=pill[4].getprice(); // getting price and displaying it for costumer
		  
		 					 cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
		
							cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
							cin>>answer;
			
						if(answer=="yes" || answer=="1")
						{c<<"He wanted to buy another \n\n";
							goto back1 ; // if costumer enter yes or 1, it will call menu
						}
				
						if(answer=="no" || answer=="n")
						{
							pharmacy.balance.balance+=sum;
						
				  
				 			 cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
				  								pharmacy_balance.balance=+sum;
							cout<<"Thank you for purchasing at Supreme pharmacy\n\n";
							// if costumer finish the purchasing it will end the program
					
							cout<<"\a";
							goto end;
						}
		
					}
		
		
		
		
		
		
		
				if(answer=="6" || answer=="7" || answer=="8" || answer=="9" || answer=="10")
				{
		
		
					int twice;
					
					
					
		cout<<"\n----------------------------------------------------------------------------------------------\n";
		
		cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(30)<<"EXPIRED DATE        |"<<endl;
		
		
		for(int i=0;i<pcounter;i++)
		{
			
			cout<<"|"<<(i+1)<<"-";
			pill[i].print(); // printing pills
			
		}
		
		
		
		cout<<"\n----------------------------------------------------------------------------------------------\n";

					
					cout<<"This is a pill has been added recently please enter again to confirm : \n";
					cin>>twice;
		
					sum+=pill[twice].getprice(); // getting price and displaying it for costumer
		  
		  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
		
			cout<<"Do you want to buy another ?\n"; // asking if costumer want to buy another pill or not
			cin>>answer;
			
					if(answer=="yes" || answer=="1")
					{
					c<<"He wanted to buy another \n\n";
						goto back1 ; // if costumer enter yes or 1, it will call menu
					}
				
							if(answer=="no" || answer=="n")
				{
						
				  
				  cout<<"\nSo far it costs :"<<sum<<"$"<<endl;
				  pharmacy_balance.balance=+sum;
				  goto end;		
		
		}
		
		
		

}

			}
			
			
					}



						if(answer=="3" || answer=="Staff" || answer=="staff") //staff's choice
						{s<<"The staff file has been opened \n\n";
							passagain:
							string pass;
							
							cout<<"Please put the Password : "<<endl;
							cin.ignore();
							
							getline(cin,pass);
							
							if(pass == pharmacy_staff[0].getpassword())
							{
							
									s<<"The password was correct \n\n";
						
						
								select :
							
							answer==" ";
								cout<<"\n----------------------------------------------------------------\n";
								//it will display the name, ID and salary of staff members
									cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"ID"<<setw(20)<<"Salary        |"<<endl;
									
									for(int i=0;i<scounter;i++)
									{ // accessing the pharmacy staff array by for loop
										
										cout<<"|"<<(i+1)<<"-";
										pharmacy_staff[i].print(); // printing the staff mebmers' ditails
										
									}
									cout<<"\n----------------------------------------------------------------\n";
															
								int ansint;
								cout<<endl;
								cout<<"Plaese choose which member are you in int (1/2/3):\n"; // asking what is your staff number 1, 2 or 3
								cin>>ansint;
								
								ansint-=1;
								
								if(ansint==1 || ansint==2 || ansint == 3 || ansint==0 || ansint==5  || ansint==4)
								{
									saraagain: 
									cout<<endl;
									cout<<"Hello "<<pharmacy_staff[ansint].getname()<<endl<<endl; // after entering staff number the program will print all staff ditails
									
									if(ansint==0)
									{
										s<<"Sara Has opened the staff file \n\n";
									}
									if(ansint==1)
									{
										s<<"Hama Has opened the staff file \n\n";
									}
									if(ansint==2)
									{
										s<<"Yousif Has opened the staff file \n\n";
									}
									cout<<"Do you want to \n1- Add a stock \n2- delete  \n3- update the date\n"; // asking what do you want to do Add a stock, delete or update the date
									cin>>answer;
									
									
										
										if(answer=="1" || answer=="add" || answer=="Add" ) // if staff choose adding stock
										{
											s<<"(He/She) wanted to add a pill \n\n";
											
											
											pcounter+=1;

											
											 //adding stocks to pill array
											
											
												
												
												
												cout<<"The name of the pill :"; //entering pill name
												cin>>n1;
												cout<<"\nThe price of the pill :"; // after that  price of the pill
												cin>>x;
												cout<<"\nWhats the release date :"; // then release date
												cin>>re;
												cout<<"\nWhats the expire date :"; // finaly expire date
												cin>>ex;
												
												pill.push_back(Medicine(n1,x,re,ex)); // saving all new pill ditails in to 	pill.push_back
											
												
													
														s<<"A pill has been aded with the name : "<<n1<<" price of "<<x<<" Release date of "<<re<<" expire date of "<<ex<<endl<<endl;
														
														
												cout<<"\nDo you want to publish it ?\n"; // asking if staff member want to publish the new pills
												cin>>answer;
												
											
											}
												
												if(answer=="yes" || answer=="Yes" || answer=="1" || answer=="y")
											{
												s<<"(He/She) wanted to share it \n\n";
												
												
												 // when staff say yes, it will display all ditails of the new pills
												cout<<"\n---------------------------------------------------------------------------\n";
												cout<<"ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(20)<<"EXPIRED DATE"<<endl<<endl;//////////////////////
												
													
									
									
															for(int i=0;i<pcounter;i++)
															{
																
																cout<<"|"<<(i+1)<<"-";
																pill[i].print();
																
															}
															cout<<"\n----------------------------------------------------------------------------\n";
															
															
															
											            cout<<"\n-----------------------------------------------------------------------\n";
														cout<<"|do want to do \n|1- something else  \n|2- go back to first\n|3- change staff\n";
														//asking staff member if want to do something else, go back to first, change staff
														cout<<"-----------------------------------------------------------------------\n";
														cin>>answer;
														
														if(answer=="1" || answer=="something")// when staff member chooce this 
														{
															s<<"(He/She) wanted to do another function\n\n";
															goto saraagain; //it will goto display staffs' ditails and (Add a stock, delete, update the date) menu
														}
														
														if(answer=="2" || answer=="back")// when staff member chooce this 
														{s<<"(He/She) wanted to go back to the beginning  \n\n";
															goto first; // it will go to the first beginning menu of the program
														}
														 
														 if(answer=="3" ||answer=="change") // when staff member chooce this 
														 {
														 	s<<"(He/She) wanted to change staff member \n\n";
														 	goto select; // it will change the entered pill's ditails
														 }
													
													if (answer=="no" || answer=="No" || answer=="2" || answer=="n") // when staff member chooce this 
											{
												s<<"(He/She) didn't wanted to share it yet \n\n";
												
												 cout<<"\n-----------------------------------------------------------------------\n";
														cout<<"|do want to do \n|1- something else  \n|2- go back to first\n|3- change staff\n";
														//asking staff member if want to do something else, go back to first, change staff
														cout<<"-----------------------------------------------------------------------\n";
														cin>>answer;
														
														if(answer=="1" || answer=="something")// when staff member chooce this 
														{
															s<<"(He/She) wanted to do another function\n\n";
															
															goto saraagain; //it will goto display staffs' ditails and (Add a stock, delete, update the date) menu
														}
														
														if(answer=="2" || answer=="back")// when staff member chooce this 
														{s<<"(He/She) wanted to go back to the beginning  \n\n";
															goto first; // it will go to the first beginning menu of the program
														}
														 
														 if(answer=="3" ||answer=="change") // when staff member chooce this 
														 {
														 	s<<"(He/She) wanted to change staff member \n\n";
														 	goto select; // it will change the entered pill's ditails
														 }
													
											}
											
											
											}
											
											
											


										}
										
										
										
										if(answer=="2" || answer=="delete" || answer=="Delete")// staff member chooce this
										{
											int s1;
											s<<"(He/She) wanted to delete a pill stack \n\n";
												
												cout<<"\n---------------------------------------------------------------------------\n";
												// it will display pill's ditails (name, price, relrase date and expired date)
												cout<<"ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(20)<<"EXPIRED DATE"<<endl<<endl;//////////////////////
												
													
									
									
															for(int i=0;i<pcounter;i++)
															{
																
																cout<<"|"<<(i+1)<<"-";
																pill[i].print();
																
															}
															cout<<"\n----------------------------------------------------------------------------\n";
											
											cout<<"Which class of medicine you want to delete ? "; // it will ask staff member which pill want to delete
											cin>>s1;
												s<<"(He/She) wanted to  delete stock number \n\n"<<s1;
												s<<"ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(20)<<"EXPIRED DATE"<<endl<<endl;
											for(int i=0;i<pcounter;i++)
															{
																
																s<<"|"<<(i+1)<<"-";
																s<<setw(20)<<pill[i].getname()<<setw(20)<<pill[i].getprice()<<" $"<<setw(20)<<pill[i].date.getrelease_date()<<setw(20)<<pill[i].date.getexpdate()<<"     |"<<endl;
																
															}
															s<<"\n----------------------------------------------------------------------------\n";
											//then the program display the pills but one of them is deleted
											
											
											
											s1=s1-1;
											s<<"\n---------------------------------------------------------------------------\n";
											
											
											pharmacy_staff[ansint].deletestock(pill[s1]);	
											
											cout<<"\n-----------------------------------------------------------------------\n";
														cout<<"|do want to do \n|1- something else  \n|2- go back to first\n|3- change staff\n";
														//asking staff member if want to do something else, go back to first, change staff
														cout<<"-----------------------------------------------------------------------\n";
														cin>>answer;
														
														if(answer=="1" || answer=="something")// when staff member chooce this 
														{
														s<<"(He/She) wanted to do something else\n\n";
															goto saraagain;//it will goto display staffs' ditails and (Add a stock, delete, update the date) menu
														}
														
														if(answer=="2" || answer=="back")// when staff member chooce this 
														{
															s<<"(He/She) wanted to go back to the beginning \n\n";
															goto first;// it will go to the first beginning menu of the program
														}
														 
														 if(answer=="3" ||answer=="change") // when staff member chooce this 
														 {
														 	s<<"(He/She) wanted to go back to staff member selection \n\n";
														 	goto select; // it will change the entered pill's ditails
														 }
													
													
										}
										
										
										if(answer=="3" || answer=="Update" || answer=="update")// when the staff member chooce this
										{
											s<<"(He/She) wanted to update a release date or expirey date \n\n";
											cout<<"\n----------------------------------------------------------------------------------------------\n";
											// it will display the pill's ditais, then staff member must chooce which pill need update, for re-new the date of expired or released
												cout<<"|ROW"<<setw(20)<<"NAME"<<setw(20)<<"PRICE"<<setw(20)<<"RELEASE DATE"<<setw(30)<<"EXPIRED DATE        |"<<endl;
		
													for(int i=0;i<5;i++)
													{
			
														cout<<"|"<<(i+1)<<"-";
															pill[i].print();
			
													}
														cout<<"\n----------------------------------------------------------------------------------------------\n";
											
											
											
														upd.dateupdate(pill,pcounter); // saving the updated pill in upd.dateupdate(pill1,pcounter)
										
													
												     	cout<<"\n-----------------------------------------------------------------------\n";
														cout<<"|do want to do \n|1- something else  \n|2- go back to first\n|3- change staff\n";
															//asking staff member if want to do something else, go back to first, change staff
														cout<<"-----------------------------------------------------------------------\n";
														cin>>answer;
														
														if(answer=="1" || answer=="something") // when staff member chooce this 
														{s<<"(He/She) wanted to do something else\n\n";
															goto saraagain; //it will goto display staffs' ditails and (Add a stock, delete, update the date) menu
														}
														
														if(answer=="2" || answer=="back") // when staff member chooce this 
														{s<<"(He/She) wanted to go back to the begining\n\n";
															
															goto first; // it will go to the first beginning menu of the program
														}
														 
														 if(answer=="3" ||answer=="change")  // when staff member chooce this 
														 {s<<"(He/She) wanted to go back to member selection\n\n";
														 	goto select; // it will change the entered pill's ditails
														 }
													
													
											
								
										}
								
								
			



						


						}
						
						
						if(pass != pharmacy_staff[0].getpassword())
						{
							s<<"The password was not correct\n\n";
							cout<<"\nThe password you entered is invalid \n\n";
							
							cout<<"\n---------------------------------------------\n";
							cout<<"|Do you want to \n|1- Retry \n|2- End the program \n";
							cout<<"\n---------------------------------------------\n";
							
							cin>>answer;
							
							if(answer=="1" || answer=="retry" || answer=="Retry")
							{
								s<<"(He/She) wanted to retry again \n\n";
								goto passagain;
							}
							
							if(answer=="2" || answer=="end" || answer=="End")
							{s<<"(He/She) wanted to end the program\n\n";
								goto end;
							}
						}
						
						
						
					}
					


					
					
				
end:
	
	// ending the program with beep sound and good bye with sleep function in windows.h library.
	
	c<<"The money inserted from the customer was : "<<sum<<endl;
	
			cout<<"G";Beep(700,200);
			Sleep(500);
			cout<<"O";Beep(700,200); 
			Sleep(500);
			cout<<"O";Beep(700,200); 
			Sleep(500);
			cout<<"D";Beep(700,200);
			Sleep(500);
			cout<<" ";Beep(700,200);
			Sleep(500);
			cout<<"B";Beep(700,200);
			Sleep(500);
			cout<<"Y";Beep(700,200);
			Sleep(500);
			cout<<"E";Beep(700,200);
			Sleep(500);
			cout<<" ";Beep(700,200);
			Sleep(500);
			cout<<";";Beep(700,200);
			Sleep(500);
			cout<<"}";Beep(700,200);
			Sleep(500);
			cout<<"\a";
			
			a<<"the Admin file is closed now \n";
			c<<"the Customer file is closed now \n";
			s<<"the Stuff file is closed now \n";
			o<<"the Data file is closed now \n";
			
	return 0;
		



}




