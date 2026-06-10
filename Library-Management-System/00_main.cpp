#include <iostream>
using namespace std;
const int Max = 100;
class library_management 
{ 
public:
   
    int book_number =100;
    
    string book_name [Max]=
{
    "physics","chemistry","biology","mathematics","english",
    "science","computer","psychology","anatomy","civics"
};
     string author_name [Max]=
{
    "Ashir","Billy","Carol","David","Mimi",
    "Musa","Georgor","Henry","Inglis","Conrad"
};
     int quantity[Max]={3,6,9,4,5,2,1,10,7,8};
     bool issued[Max]=
{
         false,false,false,false,false,
         false,false,false,false,false
};
     string issued_to[Max];
     int total_books = 10;

void addbook()
{ 
    cin.ignore();

    cout<<"\nEnter book name:";
    getline(cin,book_name[total_books]);

    cout<<"Enter author name:";
    getline (cin, author_name[total_books]);

    cout<<"Enter quantity:";
    cin>> quantity[total_books];

    issued [total_books]=false;
    issued_to[total_books] = "";

    total_books++;
    cout<<"Book added successfully!\n";
}
   //ISSUE book

void issuebook()
{
    string name;
    string student_name;
    bool found=false;

    cin.ignore();

    cout<<"Enter Student Name:";
    getline(cin, student_name);

    cout<<"Enter book name to issue:";
    getline(cin, name);
   
  for(int i=0;i<total_books; i++)
{

    if(book_name[i]==name)
    {
      found=true;
      if(!issued[i])
      {
        issued[i]=true;
        issued_to[i] = student_name;

        cout<<"book issued successfully!\n";
        cout<<"Issued To:"<<issued_to[i]<<endl;
      }
    else
    {
        cout<<"Book already issued!\n";
    }
        break;
    }
}
    if(!found)
    {
        cout<<"Book not found!\n";
    }
  }

  void returnbook()
{
    string name;
    bool found=false;

    cin.ignore();

    cout<<"Enter book name to return:";
    getline(cin, name);
    
    for(int i=0; i<total_books; i++)
    {
        if(book_name[i] == name)
    {
        found=true;

        if(issued[i])
    {
        issued[i] = false;
        issued_to[i] = "";
        cout<< "Book returned successfully!"<<endl;
        

    } 
    else
    {
        cout<<"Book was not issued, it is already available"<<endl;
    }
     break;
    }
}
    if(!found)
    {
        cout<<"Book not found!";
    }
}
    
void viewallstock()
{
    cout<<"==================================================="<<endl;
    cout<<"TOTAL BOOKS:"<< total_books<<endl;
    cout<<"==================================================="<<endl;

    for(int i=0; i<total_books; i++)
    {
        cout<<"Book Name:"<<book_name[i]<<endl;
        cout<<"Author Name:"<<author_name[i]<<endl;
        cout<<"Quantity:"<<quantity[i]<<endl;
        
    if (issued[i])
     {
        cout<<"Status: Issued"<<endl;
        cout<<"Issued To:"<<issued_to[i]<<endl;
     }
    else
    {
        cout<<"Status: Available"<<endl;
    }
     
      cout<<"-----------------------------------------------------"<<endl;

      cout<<endl;

    }
}
void searchstock()
{
    string search_book;
    bool found = false;

    cin.ignore();

    cout<<"Enter book name:"<<endl;
    getline(cin, search_book);

    for(int i=0; i<total_books; i++)
{
    if(book_name[i]==search_book)
 {
        found = true;
        
        cout<<"Book Found:"<<endl;
        cout<<"Book Name:"<<book_name[i]<<endl;
        cout<<"Author Name:"<<author_name[i]<<endl;
        cout<<"Quantity:"<<quantity[i]<<endl;
        
        if(issued[i])
    {

        cout<<"Status : Issued" <<endl;
        cout<<"Issued To :" <<issued_to[i]<<endl;
    }
       else
    {
        cout<<"Status : Available"<< endl;
    }

    break;
 }
}
   if(!found)
   {
    cout<<"Book not found!";
   }
  }
};

int main()
{
    library_management L1;

    int choice;
    char again;
    
    do
 {
    cout<<"===================================================="<<endl;
    cout<<"============ Library Management System ============="<<endl;
    cout<<"===================================================="<<endl;
    cout<<endl;
   
    

    cout<<"1.View complete stock"<<endl;
    cout<<"2.Search specific book"<<endl;
    cout<<"3.Add book"<<endl;
    cout<<"4.Issue book"<<endl;
    cout<<"5.Return book"<<endl;
    cout<<endl;

    cout<<"Enter choice:"<<endl;
    cin>>choice;

    switch(choice)
    {

    case 1:
     L1.viewallstock();
     break;

    case 2:
     L1.searchstock();
     break;

    case 3:
     L1.addbook();
     break;

    case 4:
     L1.issuebook();
     break;

    case 5:
     L1.returnbook();
     break;


    default:
     cout<< "Invalid Choice!"<<endl;

    }
     cout<<"Do u want another operation? (Y/N): ";
     cin>>again;
 }
    while(again == 'Y' || again == 'y');
    cout<<"THANK U FOR USING LIBRARY MANAGEMENT SYSTEM!"<<endl;

     return 0;


}


    
 








