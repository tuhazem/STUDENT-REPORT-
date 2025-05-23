#include <iostream>
#include<fstream>
using namespace std;
struct student
{
char name[80];
char id[80];
int STD;
float pro,arc,writing,alg,sum,average;
};
void intro();
void mainmenu();
void acceptdata();
void view_Specific(int);
void viewall();
void result(int);
void deleterecord(int);
void modify(int);

int main()
{

    char c;
    intro();

    do{


   cout<<"\n\n";
   cout<<"\t====================STUDENT REPORT CARD MANEGEMENT //===================="<<endl;
   cout<<endl;
   cout<<"\t\t\t\t1. MAIN MENU\n\n";
   cout<<"\t\t\t\t2. EXIT\n\n";
   cout<<"ENTER YOUR CHOICE :";
   cin>>c;
   switch(c)
   {
   case '1':
    {
        mainmenu();
        break;
    }
   case '2':
    {          cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE"<<endl;
    }
   }
    }while(c!='2');
    return 0;
}
void acceptdata()
{
    student s;
    ofstream outfile;
    outfile.open("Report.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t=======CREATE A REPORT CARD========\n\n";
    cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ENTER YOUR ID NUMBER : DTU/";

    cin.get(s.id,80);
    cout<<"ENTER YOUR STD NUMBER :";
    cin>>s.STD;
    cout<<"ENTER YOUR PROGRAMMING MARK :";
    cin>>s.pro;
    cout<<"ENTER YOUR COMPUTER ARCITECTURE MARK :";
    cin>>s.arc;
    cout<<"ENTER YOUR WRITING SKILL MARK :";
    cin>>s.writing;
    cout<<"ENTER YOUR ALGEBRA MARK :";
    cin>>s.alg;
    s.sum=s.pro+s.arc+s.writing+s.alg;
    s.average=(s.sum/4);
    outfile.write(reinterpret_cast<char *> (&s), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void intro()

{

    cout << "\n\n\n";
    cout << "\t\t\t\t * * *  **** *      ****  ***   ***   ****   " << endl;
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        "<< endl;
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;

    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    cout<<"\t\t\t\tTHIS IS STUDENT REPORT CARD MANEGEMENT //"<<endl;

    cout<<"\t\t\t\t============================================="<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void mainmenu()

{

    char cc;
    cout<<"\t\t\t\t=================MAIN MENU================\n\n"<<endl;

    cout<<"\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n"<<endl;

    cout<<"\t\t\t\t2. VIEW ALL STUDENTs REPORT CARD\n\n"<<endl;

    cout<<"\t\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n"<<endl;

    cout<<"\t\t\t\t4. MODIFY REPORT CARD\n\n"<<endl;
    cout<<"\t\t\t\t5. RESULT\n\n"<<endl;
     cout<<"\t\t\t\t6. DELETE RECORD\n\n"<<endl;

    cout<<"\t\t\t\t=============================="<<endl;
    cout<<"\t\t\t\tENTER YOUR CHOICE...:) <1-6> :";
    cin>>cc;
    cout<<endl;
    switch(cc)
    {
    case '1':
        {
            acceptdata();
            break;
        }
    case '2':
        {
            viewall();
            break;
        }
    case '3':
          {
              int n;
              cout<<"ENTER YOUR STD NUMBER :";
              cin>>n;
              view_Specific(n);
              break;
          }
    case '4':
        {
            int n;
            cout<<"ENTER YOUR STD NUMBER :";
            cin>>n;
            modify(n);
            break;
        }

    case '5':
        {
            int n;
            cout<<"ENTER YOUR STD NUMBER :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    case '6':
        {
            int n;
            cout<<"ENTER YOUR STD NUMBER :";
            cin>>n;
            cout<<endl;
            deleterecord(n);
            break;
        }
    }
}

void viewall()

{

    student s;
    ifstream infile;
    bool check=false;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t\tALL STUDENTS REPORT CARDS"<<endl;
     cout<<"=================================================================================="<<endl;
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :DTU/"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT STD NUMBER :"<<s.STD<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.pro<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arc<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg<<endl<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl<<endl;
        cout<<"=================================================================================="<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}

void view_Specific(int n)

{

    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"\t\t\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.STD==n)
        {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :DTU/"<<s.id<<endl;
        cout<<"\t\t\t\tSTUDENT STD NUMBER :"<<s.STD<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.pro<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arc<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        equality=true;
        }
    }
        infile.close();
        if(equality==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void result(int n)

{

    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        if(s.STD==n)
        {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.pro<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCITECTURE MARK :"<<s.arc<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg<<endl<<endl;
        cout<<"\t\t\t\tSUM :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\tAVERAGE :"<<s.average<<endl<<endl;
        cout<<"\t\t\t\t=================================================="<<endl;
        eq=true;
        }
    }
        infile.close();
        if(eq==false)
            cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
}

void modify(int n)

{

    student s;
    fstream infile;
    infile.open("Report.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&s),sizeof(student));
     {
         if(s.STD==n)
         {
        cout<<"\t\t\t\tSTUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT ID NUMBER :DTU/"<<s.id<<endl<<endl;
        cout<<"\t\t\t\tSTUDENT STD NUMBER :"<<s.STD<<endl<<endl;
        cout<<"\t\t\t\tPROGRAMMING MARK :"<<s.pro<<endl<<endl;
        cout<<"\t\t\t\tCOMPUTER ARCHITECTURE MARK :"<<s.arc<<endl<<endl;
        cout<<"\t\t\t\tWRITING SKILL MARK :"<<s.writing<<endl<<endl;
        cout<<"\t\t\t\tALGEBRA MARK :"<<s.alg<<endl<<endl;
        cout<<"============================================="<<endl;
        cout<<"\t\tENTER THE NEW INFORMATION"<<endl;
        cout<<"============================================="<<endl;
        cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,80);
    cout<<"ENTER YOUR ID NUMBER : DTU/";
    cin.ignore();
    cin.get(s.id,80);
    cout<<"ENTER YOUR STD NUMBER :";
    cin>>s.STD;
    cout<<"ENTER YOUR PROGRAMMING MARK :";
    cin>>s.pro;
    cout<<"ENTER YOUR COMPUTER ARCITECTURE MARK :";
    cin>>s.arc;
    cout<<"ENTER YOUR WRITING SKILL MARK :";
    cin>>s.writing;
    cout<<"ENTER YOUR ALGEBRA MARK :";
    cin>>s.alg;
    s.sum=s.pro+s.arc+s.writing+s.alg;
    s.average=(s.sum/4);
    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&s), sizeof(student));
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY updated"<<endl;
    checker=true;
         }
     }
     }
     infile.close();
         if(checker==false)
            cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
            cout<<endl;
            cout<<"press any key to continue...";
            cin.ignore();
            cin.get();
  }

  void deleterecord(int n)

  {
     student s;
     ifstream infile;
     infile.open("Report.txt",ios::binary);
     if(!infile)
     {
         cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
         cin.ignore();
         cin.get();
     }
     ofstream outfile;
     outfile.open("Record2.txt",ios::binary);
     infile.seekg(0,ios::beg);
     cout<<"\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
     while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
     {
         if(s.STD!=n)
         {
             outfile.write(reinterpret_cast<char*>(&s),sizeof(student));
         }
     }
     infile.close();
     outfile.close();
     remove("Report.txt");
     rename("Record2.txt","Report.txt");
     cout<<endl;
     cout<<"\t\t\t\tRECORD SUCCESSFULLY DELETED"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
  }


