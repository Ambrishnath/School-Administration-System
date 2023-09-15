#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
class Employee
{ public:
 long salary,reg;
string name,address,father,mother,mobile;
 public:
 void getdata();
 void display();
 void show();
};
void Employee :: getdata()
{
cout<<"Enter your ID ";
cin>>reg;
cout<<"Enter your name ";
cin>>name;
cout<<"Enter your father name ";
cin>>father;
cout<<"Enter your mother name ";
cin>>mother;
cout<<"Enter your mobile no+91 ";
cin>>mobile;
cout<<"Enter your address ";
cin>>address;
cout<<"Enter your salary ";
cin>>salary;
}
void Employee :: display()
{
cout<<setw(15)<<setfill('*')<<endl;
cout<<"Hello Mr. "<<name<<setw(15)<<setfill('*')<<endl;
// cout<<setw(15)<<setfill('*')<<endl<<endl;
cout<<"Your ID:: "<<reg<<endl;
cout<<"Your Name:: "<<name<<endl;
cout<<"Father's Name:: "<<father<<endl;
cout<<"Mother's Name:: "<<mother<<endl;
cout<<"Your mobile no.+91 "<<mobile<<endl;
cout<<"Your Address:: "<<address<<endl;
cout<<"Your Salary:: "<<salary<<endl;
}
void Employee::show()
{
 cout<<"#"<<"\t";
cout<<reg<<"\t";
cout<<name<<"\t";
cout<<father<<"\t";
cout<<mother<<"\t";
cout<<"+91 "<<mobile<<"\t";
cout<<address<<"\t";
cout<<salary<<"\t";
cout<<endl;
}
void EmRecord();
void EmAdd_record();
void EmPrint_record();
void EmList_record();
void EmDelet_record();
void EmUpdate_Record();
Employee emp;
fstream f1,f2;
void EmRecord()
{
int choice;
do
{
cout<<"\n\n1. Employee Add Record"<<endl;
cout<<"2. list of record"<<endl;
cout<<"3. Update Record"<<endl;
cout<<"4.Display Record"<<endl;
cout<<"5.Delet record "<<endl;
cout<<"6. Exit"<<endl;
cout<<"Enter your choice";
 cin>>choice;
 switch(choice)
 {
case 1:
 EmAdd_record();
break;
case 2:
EmList_record();
break;
case 3:
EmUpdate_Record();
break;
case 4:
EmPrint_record();
break;
case 5:
EmDelet_record();
break;
case 6:
exit(0);
default :
cout<<"wrong choice";
 }
 }while(choice!=6);
}
void EmAdd_record(void)
{
char yn;
f1.open("Employ.txt",ios::out|ios::ate);
emp.getdata();
cout<<"Do you want to store a record Y/N";
cin>>yn;
if(yn=='y'|| yn=='Y')
{
f1.write((char*) &emp , sizeof(emp));
cout<<"store data successful"<<endl<<endl;
}
else
cout<<"not stored data"<<endl<<endl;
f1.close();
}
//update your record
void EmUpdate_Record()
{
int c=0;
float ins;
cout<<"enter your id";
cin>>ins;
f1.open("Employ.txt",ios::in|ios::ate|ios::out);
f1.seekg(0);
while(f1.read((char *) & emp , sizeof (emp)))
{
if(ins==emp.reg)
{
c=1;
break;
}
}
f1.clear();
if(c==0)
{
cout<<"Data are not find";
f1.close();
return;
}
char yn;
int pos=f1.tellp();
f1.seekp(pos - sizeof(emp));
emp.display();
cout<<"Do you want to modify the data Y|N-->";
cin>>yn;
if(yn=='y'||yn=='Y')
{
int sal;
string new_up;
int change;
cout<<"1. Name change"<<endl;
cout<<"2. Father name change"<<endl;
cout<<"3. Mother name change "<<endl;
cout<<"4. Address change "<<endl;
cout<<"5. mobile chnage "<<endl;
cout<<"6. salary update "<<endl;
cout<<"Enter your choice";
cin>> change;
switch(change)
{
case 1:
cout<<"Enter your new Name: ";
cin>>new_up;
emp.name = new_up;
 break;
 case 2:
cout<<"Enter your Father name for update: ";
cin>>new_up;
emp.father=new_up;
 break;
 case 3:
cout<<"Enter your mother name for update: ";
cin>>new_up;
emp.mother=new_up;
 break;
 case 4:
cout<<"New updated address ";
cin>>new_up;
emp.address=new_up;
 break;
 case 5:
cout<<"Enter your new Mobile number: ";
cin>>new_up;
emp.mobile=new_up;
 break;
 case 6:
cout<<"Enter your new Salary: ";
cin>>sal;
emp.salary=sal;
 break;
 default:
 cout<<"Worng choice"<<endl;
}
f1.write((char*) &emp,sizeof(emp));
 cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
}
else
cout<<"data not modify";
f1.close();
}
//list record
void EmList_record()
{
f1.open("Employ.txt",ios::in);
while(f1.read((char*)&emp ,sizeof(emp)))
{
 emp.show();
 }
 f1.close();
}
//Display record
void EmPrint_record()
{
f1.open("Employ.txt",ios::in);
while( f1.read((char*)&emp,sizeof(emp)))
{
emp.display();
}
f1.close();
}
//Delete record;
void EmDelet_record()
{
int c=0;
float fno;
cout<<"\n\n\t\t # Enter customer id :-->";
cin>>fno;
f1.open("Employ.txt",ios::in|ios::out|ios::ate);
f2.open("temp.dat",ios::in|ios::out|ios::ate);
f1.seekg(0);
while(f1.read((char*)&emp,sizeof(emp)))
{
 if(fno!=emp.reg)
 f2.write((char*) &emp,sizeof(emp));
 else
 c=1;
}
f1.clear();
f1.close();
f2.close();
if(c==0)
{
cout<<"\n\n\t\t **// Not found \\**";
f1.close();
f2.close();
return;
 }
 remove("Employ.txt");
 rename("temp.dat","E:\\Employ.txt");
 cout<<"\n\n\t\t***// DATA IS DELETED \\***";
}
//Student record
class Student
{
public:
 int reg;
 string name,Email,mobile,state,gender;
 string city,father,mother,post;
 string board,school;
 string address;
 int percentage,marks;
 public:
 void Personal()
 { cout<<"Enter your Registration number : ";
 cin>>reg;
 cout<<"Enter the student name : ";
cin>>name;
cout<<"Enter the father name : ";
cin>>father;
cout<<"Enter the mother name : ";
cin>>mother;
cout<<"Choice your Gender : ";
cin>>gender;
cout<<"Enter your Email id : ";
cin>>Email;
cout<<"Enter Mobile number +91 :";
cin>>mobile;
}
void Address();
void Qualification();
void Display();
void Show();
};
void Student::Address()
{
cout<<"Enter your state : ";
cin>>state;
cout<<"Enter your city: ";
cin>>city;
cout<<"Enter your postal code: ";
cin>>post;
cout<<"Enter your Address: ";
cin>>address;
}
void Student::Qualification()
{
cout<<"Enter your High School detail: "<<endl;
cout<<"Enter board name:";
cin>>board;
cout<<"Enter collage/univetrsity Name :";
cin>>school;
cout<<"Enter your marks: ";
cin>>marks;
}
void Student::Display()
{
cout<<"\tYour Registration number is="<<reg<<endl<<endl;
cout<<setw(60)<<setfill('*');
cout<<"\nHello Mr. "<<name<<endl;
cout<<"Father's name is = Mr. "<<father<<endl;
cout<<"Mother,s name is = Mrs. "<<mother<<endl;
cout<<"Your Gender is ="<<gender<<endl;
cout<<"Your Email is ="<<Email<<endl;
cout<<"Your mobile number is +91"<<mobile<<endl;
cout<<setw(60)<<setfill('*');
cout<<"\nYour State: "<<state<<endl;
cout<<" Your City is: "<<city<<endl;
cout<<" Your postal coad is: "<<post<<endl;
cout<<"Your Address is ="<<address<<endl;
cout<<setw(60)<<setfill('*');
cout<<"\n******Your Qualification detail******"<<endl;
cout<<"Your board "<<board<<endl;
cout<<"Yout school/university: "<<school<<endl;
cout<<"Your marks "<<marks<<endl;
}
void Student::Show()
{
cout<<reg<<" " <<name <<" "<<father<<" "<<mother<<" "<<gender<<" "<<Email<<" ";
cout<<" +91"<<mobile<<" "<<state<<" "<<city<<" "<<post<<" "<<address<<" "<<board<<" ";
cout<<school<<" "<<marks <<endl;
}
//Some Function use
void Record();
void Add_Record();
void Show_Record();
void List_Record();
void Search_Record();
void Update_Record();
void Delete();
Student obj;
fstream file;
fstream file2;
void Record ()
{
int enter;
do
{
 cout<<"1. Add Detail\n 2.Show Record\n 3. List Record\n 4. Search Record\n 5.Update Record\n6.delet\n7. exit"<<endl;
 cin>>enter;
 switch(enter)
 {
 case 1:
 Add_Record();
 break;
 case 2:
 Show_Record();
 break;
 case 3:
 List_Record();
 break;
 case 4:
 Search_Record();
 break;
 case 5:
 Update_Record();
 break;
 case 6:
 Delete();
 break;
 case 7:
 exit(0);
 default:
 cout<<"Wrong Choice ";
}
 }while(enter!=4);
}
//Add Record of the student
void Add_Record()
{
char yn;
obj.Personal();
obj.Qualification();
obj.Address();
file.open("Student.txt",ios::out|ios::app|ios::in);
cout<<"Do you want to Store your Data Y|N ";
cin>>yn;
if(yn=='y'||yn=='Y')
{
file.write((char*) & obj, sizeof(obj));
cout<<"\n********Your Data is Stored********"<<endl;
}
else
cout<<"Your Data is not Stored"<<endl;
file.close();
}
//show of the record
void Show_Record()
{
system("CLS");
file.open("Student.txt",ios::in);
while(file.read((char *)&obj,sizeof(obj)))
{
obj.Display();
}
 file.close();
}
//List of Record
void List_Record()
{
system("CLS");
file.open("Student.txt",ios::in);
while(file.read((char *)&obj,sizeof(obj)))
{
obj.Show();
file.close();
}
}
void Delete()
{
string fn;
int c=0;
cout<<"Enter your name: ";
cin>>fn;
file.open("Student.txt",ios::out|ios::in|ios::ate);
file2.open("Temp.txt",ios::out|ios::ate|ios::in);
file.seekg(0);
while(file.read((char*)&obj,sizeof(obj)))
{
 if(fn!=obj.name)
 file2.write((char*) &obj,sizeof(obj));
 else
 c=1;
}
file.clear();
file.close();
file2.close();
if(c==0)
{
cout<<"\n\n\t\t **// Not found \\**";
file.close();
file2.close();
return;
 }
 remove("Student.txt");
 rename("temp.txt","E:\\Employ.txt");
 cout<<"\n\n\t\t***// DATA IS DELETED \\***";
}
//Search the data
void Search_Record()
{
int init;
int c=1;
cout<<"Enter regstration number for search ";
cin>>init;
system("CLS");
file.open("Student.txt",ios::in);
while(file.read((char*)&obj,sizeof(obj)))
{
if(init!=obj.reg)
{
c=1;
break;
}
}
if(c==0)
 {
 cout<<"Data is not found"<<endl;
 file.close();
}
obj.Show();
 cout<<"\n";
 cout<<"********************END************************\n";
file.close();
}
//student update record
void Update_Record()
{ string new_up;
int c=0;
float ins;
cout<<"enter your id";
cin>>ins;
file.open("Student.txt",ios::in|ios::out|ios::ate);
 file.seekg(0);
while(file.read((char *) & obj , sizeof (obj)))
{
if(ins==obj.reg)
{
c=1;
break;
}
}
file.clear();
if(c==0)
{
cout<<"Data are not find";
file.close();
return;
}
char yn;
int pos=file.tellp();
file.seekp(pos - sizeof(obj));
obj.Display();
cout<<"Do you want to modify the data Y|N-->";
cin>>yn;
if(yn=='y'||yn=='Y')
{
int sal;
string new_up;
int change;
cout<<"1. Name change"<<endl;
cout<<"2. Father name change"<<endl;
cout<<"3. Mother name change "<<endl;
cout<<"4. Address change "<<endl;
cout<<"5. mobile chnage "<<endl;
cout<<"6. salary update "<<endl;
cout<<"Enter your choice";
cin>> change;
switch(change)
{
case 1:
cout<<"Enter your new Name: ";
cin>>new_up;
obj.name=new_up;
 file.write((char*) &obj,sizeof(obj));
 cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
 break;
 case 2:
cout<<"Enter your Father name for update: ";
cin>>new_up;
obj.father=new_up;
 file.write((char*) &obj,sizeof(obj));
 cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
 break;
 case 3:
cout<<"Enter your mother name for update: ";
cin>>new_up;
obj.mother=new_up;
 file.write((char*) &obj,sizeof(obj));
 cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
 break;
 case 4:
cout<<"New updated address ";
cin>>new_up;
obj.address=new_up;
 file.write((char*) &obj,sizeof(obj));
 cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
 break;
 case 5:
 cout<<"Enter your new Mobile number: ";
cin>>new_up;
obj.mobile=new_up;
 file.write((char*) &obj,sizeof(obj));
 cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
 break;
 case 6:
 break;
 default:
 cout<<"Worng choice"<<endl;
}
// file.write((char*) &obj,sizeof(obj));
 // cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
}
else
cout<<"data not modify";
file.close();
}
//Teacher Record
class Teacher
{
public:
int reg;
string name,father,mother,qualif;
string mobile,address;
int salary;
public:
void getdata();
void print();
void list();
};
void Teacher::getdata()
{
cout<<"enter your Registration no\t";
cin>>reg;
cout<<"Enter your name\t";
cin>>name;
cout<<"Enter your father name\t";
cin>>father;
cout<<"Enter your mother name\t";
cin>>mother;
cout<<"Enter your mobile +91";
cin>>mobile;
cout<<"Enter your qualification\t";
cin>>qualif;
cout<<"Enter Your Address:";
cin>>address;
cout<<"Enter the Teacher Salary: ";
cin>>salary;
}
void Teacher::print()
{ cout<<"*************************************"<<endl;
cout<<"Hello Mr."<<name<<endl;
cout<<"*************************************"<<endl;
cout<<"Your Name is "<<name<<endl;
cout<<"Your Father's name is "<<father<<endl;
cout<<"Your Mother's name is "<<mother<<endl;
cout<<"Your mobile number is +91"<<mobile<<endl;
 cout<<"Your Last year Qualification "<<qualif<<endl;
 cout<<"The salary of the teacher is "<<endl;
cout<< "Your address is= "<<address<<endl;
}
void Teacher::list()
{
 cout<<"List of the record"<<endl;
 cout<<"\n\n\t# "<<reg<<" "<<name<<" "<<father<<" ";
 cout<<mother<<" "<<mobile<<" ";
 cout<<qualif <<" "<<address<<endl;
}
void Teacher_record();
void Tadd_record();
void Tdelet_record();
void Tupdate_record();
void Tshow_record();
void Tlist_record();
void Tsearch();
Teacher master;
fstream tea;
fstream del;
void Teacher_record()
{
int choice;
system("CLS");
do
{
cout<<"\n 1.Add Teacher Record";
cout<<"\n 2.Update Teacher Record";
cout<<"\n 3.Total show of Teacher Record";
cout<<"\n 4.Delet Teacher Record";
cout<<"\n 5.list Record";
cout<<"\n 6.Search record";
cout<<"\n 7.exit";
cout<<"\n Enter your choice";
cin>>choice;
switch(choice)
{
 case 1:
Tadd_record();
break;
 case 2:
Tupdate_record();
break;
 case 3:
Tshow_record();
break;
 case 4:
Tdelet_record();
break;
case 5:
Tlist_record();
break;
case 6:
Tsearch();
break;
case 7:
break;
default:
cout<<"Wrong choice";
}
} while(choice!=5);
}
 void Tadd_record()
 {
char yn;
system("CLS");
tea.open("Teacher_record.txt",ios::in|ios::out|ios::app);
master.getdata();
cout<<"\nDo you want store record ";
cin>>yn;
 if(yn=='y'||yn=='Y')
{
 tea.write((char*)&master,sizeof(master));
 cout<<"\nData stored\n";
 }
else
cout<<"\nData Not Stored\n";
 tea.close();
}
void Tshow_record()
{
system("CLS");
tea.open("Teacher_record.txt",ios::in);
while(tea.read((char *)&master,sizeof(master)));
{
master.print();
tea.close();
 }
}
void Tlist_record()
{
system("cls");
tea.open("Teacher_record.txt",ios::in);
while(tea.read((char *)&master,sizeof(master)));
{
master.list();
tea.close();
 }
}
void Tsearch()
{
 int c=0;
float fno;
cout<<"\n\t\t Enter teacher registration number =";
cin>>fno;
tea.open("Teacher_record.txt",ios::in|ios::out|ios::app);
tea.seekg(0);
while(tea.read((char*)&master,sizeof(master)))
{
 if(fno==master.reg)
 {
 c=1;
 break;
 }
}
tea.clear();
if(c==0)
{
cout<<"\n\n\t\t **// Not found \\**";
tea.close();
return;
}
master.print();
}
//update the clas
void Tupdate_record()
{
int c=0;
int ins;
cout<<"enter your registration number ";
cin>>ins;
tea.open("Teacher_record.txt",ios::in|ios::out|ios::ate);
 tea.seekg(0);
while(tea.read((char *) & master , sizeof (master)))
{
if(ins==master.reg)
{
c=1;
break;
}
}
tea.clear();
if(c==0)
{
cout<<"Data are not find";
tea.close();
return;
}
char yn;
int pos=tea.tellp();
tea.seekp(pos - sizeof(master));
master.print();
cout<<"Do you want to modify the data Y|N-->";
cin>>yn;
if(yn=='y'||yn=='Y')
{
int sal;
string new_up;
int change;
cout<<"1. Name change"<<endl;
cout<<"2. Father name change"<<endl;
cout<<"3. Mother name change "<<endl;
cout<<"4. Address change "<<endl;
cout<<"5. mobile chnage "<<endl;
cout<<"6. salary update "<<endl;
cout<<"Enter your choice";
cin>> change;
switch(change)
{
case 1:
cout<<"Enter your new Name: ";
cin>>new_up;
master.name=new_up;
 break;
 case 2:
cout<<"Enter your Father name for update: ";
cin>>new_up;
master.father=new_up;
 break;
 case 3:
cout<<"Enter your mother name for update: ";
cin>>new_up;
master.mother=new_up;
 break;
 case 4:
cout<<"New updated address ";
cin>>new_up;
master.address=new_up;
 break;
 case 5:
cout<<"Enter your new Mobile number: ";
cin>>new_up;
master.mobile=new_up;
 break;
 case 6:
cout<<"Enter your new Salary: ";
cin>>sal;
master.salary=sal;
 break;
 default:
 cout<<"Worng choice"<<endl;
}
tea.write((char*) &master,sizeof(master));
 cout<<"\n\n\t\t***// DATA IS MODIFIED \\***";
}
else
cout<<"data not modify";
tea.close();
}
//Delet record
void Tdelet_record()
{
int fn;
int c=0;
cout<<"Enter your Registration number: ";
cin>>fn;
tea.open("Teacher_record.txt",ios::out|ios::in|ios::ate);
del.open("Temp.txt",ios::out|ios::ate|ios::in);
tea.seekg(0);
while(tea.read((char*)&master,sizeof(master)))
{
 if(fn!=master.reg)
 del.write((char*) &master,sizeof(master));
 else
 c=1;
}
tea.clear();
tea.close();
del.close();
if(c==0)
{
cout<<"\n\n\t\t **// Not found \\**";
tea.close();
del.close();
return;
 }
 remove("E:\\Teacher_record.txt");
 rename("temp.txt","E:\\Teacher_record.txt");
 cout<<"\n\n\t\t***// DATA IS DELETED \\***";
}
int main()
{
int choice;
do
{
 cout<<"-*-*-*-*-*-*-*-*-*-*********WELCOME TO THE AAGS PUBLIC SCHOOL*********-*-*-*-*-*-*-*-*-*-"<<endl;
cout<<"-*-* 1. show Student Record *-*-"<<endl;
cout<<"-*-* 2. show Employee Record *-*-"<<endl;
cout<<"-*-* 3. show Teacher Record *-*-"<<endl;
 cout<<"-*-* 4. Exit *-*-"<<endl;
cout<<"-*-* *-*-"<<endl;
 cout<<"-*-*-*-*-*-*-*-*-*-*********-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**********-*-*-*-*-*-*-*-*-*"<<endl;
 cout<<" please Enter your choice:";
 cin>>choice;
switch(choice)
{
case 1:
Record();
break;
case 2:
EmRecord();
break;
case 3:
Teacher_record();
break;
case 4:
break;
defaut:
cout<<"Wrong choice ";
}
}while(choice!=3);
return 0;
}
