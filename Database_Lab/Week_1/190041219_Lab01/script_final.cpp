/*
    H.M. Shadid Rez Chowdhury
    ID- 190041219
    CSE-2
    Batch -19
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

// function for the customer txt file

void customer_func()
{
    ifstream my_file_inp;
    ofstream my_file_out;
    string customer_line, word;

    // opening  the customer txt file and making a new file

    my_file_inp.open("Customer.txt");
    my_file_out.open("revised_customer.txt");

    // variable declaration

    string Customer_id, no_of_purchases_s;
    int counter = 6, no_of_purchases_i;
    bool flag = false;

    // using loop to read every word of the file

    while (my_file_inp >> word)
    {

        counter++;

        if (flag == true)
        {
            word = "Frequent";
            flag = false;
        }

        // condition to check the 5th word of each line and converting it to integer

        if ((counter - 5) % 6 == 0)
        {

            no_of_purchases_s = word;

            //cout << "  oss : " << no_of_purchases_s << "  " << no_of_purchases_i << endl;

            stringstream ss;
            ss << no_of_purchases_s;
            ss >> no_of_purchases_i;
        }

        // checking whether the number of puchases is greater than 20

        if (no_of_purchases_i > 20)
        {
            flag = true;
            no_of_purchases_i = 0;
        }

        // appending the desired words in the new file

        if (counter % 6 == 0)
        {
            my_file_out << word;
            my_file_out << "\n";
        }
        else
            my_file_out << word << " ";
    }

    //closing the files

    my_file_inp.close();
    my_file_out.close();

    // deleting the previous customer.txt file

    int status = remove("Customer.txt");
    if (status == 0)
        cout << "Product.txt deleted Successfully!";
    else
        cout << "Erorr Occurred while deleting product.txt!";

    // renaming the new revised file into customer.txt

    char oldname[] = "revised_customer.txt";
    char newname[] = "Customer.txt";

    if (rename(oldname, newname) != 0)
        perror("\nError renaming customer file");
    else
        cout << "\nCustomer.txt renamed successfully!";
}

void product_func()
{

    ifstream my_file_p;
    ofstream my_file_p_1;
    string product_line, word, temp_s = {};
    int count = 0, j, k, price;

    // opening the product txt file and a new file

    my_file_p.open("Product.txt");
    my_file_p_1.open("revised_product.txt");

    // using loop to read line by line from file

    while (getline(my_file_p, product_line))
    {
        count = 0;

        // condition to check the first line and ignore editing it

        if (!isdigit(product_line[0]))
        {
            my_file_p_1 << product_line << endl;
        }
        else
        {

            // loop to find out the price of each product by retrieving each word

            for (int i = 0; i < product_line.size(); i++)
            {

                // making sure to count the no of spaces as the price lies between 2nd and 3rd space of each line

                if (product_line[i] == ' ')
                {
                    count++;

                    if (count == 2)
                        j = i + 1;

                    if (count == 3)
                    {
                        k = i;
                    }
                }
            }

            // storing the product price in temp_s string

            for (j; j < k; j++)
                temp_s = temp_s + product_line[j];

            // converting the temp_s string to integer format

            stringstream ss;
            ss << temp_s;
            ss >> price;
            temp_s = "";

            // checking the price to find out whether it is more than 1000$

            if (price <= 1000)
            {
                my_file_p_1 << product_line << endl;
            }
        }
    }

    // closing the both files

    my_file_p.close();
    my_file_p_1.close();

    // deleting the previous product.txt file

    int status = remove("Product.txt");
    if (status == 0)
        cout << "\nProduct.txt deleted Successfully!";
    else
        cout << "\nErorr Occurred while deleting product.txt!";

    // renaming the new revised file into customer.txt

    char oldname[] = "revised_product.txt";
    char newname[] = "Product.txt";

    if (rename(oldname, newname) != 0)
        perror("\nError renaming product file");
    else
        cout << "\nProduct.txt renamed successfully!";
}

// main function to run

int main()
{
    customer_func();

    product_func();

    return 0;
}