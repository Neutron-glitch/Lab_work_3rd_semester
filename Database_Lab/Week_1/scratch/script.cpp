#include <iostream>
#include <fstream>
#include <sstream>
#include<cstdio>

using namespace std;

int main()
{
 /* ofstream my_file;
  my_file.open("Customer.txt");
  if (!my_file)
  {
    cout << "File not created!";
  }
  else
  {
    cout << "File created successfully!";
    // my_file.close();
  }*/

  ifstream my_file;
  ofstream my_file_1;
  string customer_line,word;
  
  my_file.open("Customer.txt");
  my_file_1.open("w.txt");

  while( getline(my_file,customer_line) )
  {
    if(isdigit(customer_line[0]))
       cout<<customer_line<<endl;
  }
   my_file.close();








  my_file.open("Customer.txt");


  string Customer_id , name , age , gender, no_of_purchases_s, customer_type;
  int counter=6 , no_of_purchases_i;
  bool doge=false;
   int k=0;


  while (my_file >> word)
    {
      counter++;
      

      if(doge==true)
      {
        word="Frequent";
        doge = false;
      }

   

    if((counter-5) % 6==0)
       {
        no_of_purchases_s = word ;
        //cout<<no_of_purchases_s<< "jadsodjsajkdsa"<<endl;
        k=1;
       }

      stringstream ss;
      ss << no_of_purchases_s;
      ss>> no_of_purchases_i;
      
    if(no_of_purchases_i>=20)
        {
          doge=true;
          no_of_purchases_i=0;
          
        }

      if(counter%6==0)
      {
         my_file_1<<word ;
      my_file_1<<"\n";
      }
      else
       my_file_1<<word<<" ";

      cout<< word << '\n';
    }
      
    
      
    
   my_file.close();
   my_file_1.close();

  cout<<no_of_purchases_i;

    int status = remove("Customer.txt");
    if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nErorr Occurred!";





        char oldname[] = "w.txt";
	char newname[] = "Customer.txt";
	
	/*	Deletes the file if exists */
	if (rename(oldname, newname) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";

  return 0;
}