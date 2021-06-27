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

  ifstream my_file_p;
  ofstream my_file_p_1;
  string product_line,word,tempo={};
  int count=0 , j, k , price;
  
  my_file_p.open("Product.txt");
  my_file_p_1.open("wo.txt");

  while( getline(my_file_p,product_line) )
  { 
      count =0;
    //if(isdigit(product_line[0]))
      // cout<<product_line<<endl;

    cout<<"ppspd :"<<product_line.size()<<endl;

    if( ! isdigit(product_line[0]))
    {
         cout<<product_line<<endl;
        my_file_p_1<<product_line<<endl;;
    }

    else{
    for( int i=0;i<product_line.size();i++)
    {
       /* if(product_line[i]=="/0")
        {
            while(j<i)
            {
                tempo=tempo + product_line[j];
                j++;
            }
        }*/
    //stringstream product_line_1(product_line);


        if(product_line[i]==' ')
        {
            count++;

            if(count==2)
                j=i+1;

         if(count==3)
        {
            k=i;
            
        }
        }
        
       
     //  cout<<"count :"<<count<<"     "<<i<<endl;

    }

    for(j;j<k;j++)
        tempo=tempo+product_line[j];

    cout<<"tempo :"<<tempo<<endl;
    
    stringstream ss;
    ss << tempo;
    ss>> price;
    tempo="";


       // cout<<"geronimo"<<endl;
    if(price<=1000)
    {
        cout<<product_line<<endl;
        my_file_p_1<<product_line<<endl;;
    }
    
    }   


  }
   my_file_p.close();
  my_file_p_1.close();
    int status = remove("Product.txt");
    if(status==0)
        cout<<"\nFile Deleted Successfully!";
    else
        cout<<"\nErorr Occurred!";
        


    
        char oldname[] = "wo.txt";
	char newname[] = "Product.txt";
	
	/*	Deletes the file if exists */
	if (rename(oldname, newname) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";



/*

  my_file_p.open("Product.txt");


  string Product_id , name , Price , Weight;
  int counter=4 , price_i;
  bool doge=false;



  while (my_file_p >> word)
    {
      counter++;
      

      if(doge==true)
      {
        word="Frequent";
        doge = false;
      }

   

    if((counter % 4== 3)
       {
        Price = word ;
        //cout<<no_of_purchases_s<< "jadsodjsajkdsa"<<endl;
        
       }

      stringstream ss;
      ss << Price;
      ss>> price_i;
      
    if(price_i > 20)
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
	/*if (rename(oldname, newname) != 0)
		perror("Error renaming file");
	else
		cout << "File renamed successfully";*/

  return 0;
}