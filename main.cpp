//  Authors: Conor Schindel, Jacob Benavente
//  Due Date: 2/3/16
//  Programming Assignment Number 1
//  Spring 2016 - CS 3358 - Section 253
//
//  Instructor: Husain Gholoom
//
//  Serial Number : 02 && 24
//
//  Description
//
//
#include <iostream>
#include <vector>

using namespace std;


void hailstoneFinder (vector<int>&, int);
void display (vector<int>&);
void hLength(vector<int>&);
int lNumber(vector<int>&);
int sNumber(vector<int>&);
void evenNum(vector<int>&);
void oddNum(vector<int>&);





int main()
{

    int number;
    char choice;

    bool flag1 = true;

    cout << "Welcome to the hailstone sequence program.\n";
    cout << "The function of the program is to read a number n from the\n";
    cout << "user and then tells the user four things\n";
    cout << "\t1.\tThe entire hailstone sequence start at n, all on one line,\n";
    cout << "\t\twith the numbers separated by spaces;\n";
    cout << "\t2.\tThe length of the hailstone sequence that starts with n;\n";
    cout << "\t3.\tThe largest number in the hailstone sequence that start starts with n;\n";
    cout << "\t4.\tThe smallest number in the hailstone sequence that starts with n;\n";
    cout << "\t5.\tCount and display the numbers in that hailstone sequence are even.\n";
    cout << "\t6.\tCount and display the numbers in that hailstone sequence are odd.\n\n";

    do{

        cout << "Enter a Positive integer Number  ";
        cin >> number;
        vector<int> v1(0);
        cout << endl;

        try{

            if(number < 0)
            {
                throw number;
            }

        }catch(int number){

            cout << "Error *** Number must be > 0" << endl;
            flag1 = false;

        }

        if(flag1 == true)
        {
            hailstoneFinder(v1, number);
            display(v1);
            hLength(v1);
            cout << "The largest number in the sequence is  " << lNumber(v1) << ".\n";
            cout << "The smallest number in the sequence is  " << sNumber(v1) << ".\n";
            oddNum(v1);
            evenNum(v1);
        }





        cout << "\n\nWould you like to find hailstone sequence for another number - ";
        cout << " Enter y for Y for yes or n | N for no ";
        cin >> choice;

        try{

            if(choice != 'n' && choice != 'N' && choice !='y' && choice != 'Y')
            {
                throw choice;
            }

        }catch(char choice){}

        while(choice != 'n' && choice != 'N' && choice !='y' && choice != 'Y')
        {
            cout << "\nError *** Invalid choice - Must enter y | Y | n | N" << endl;
            cout << "\nWould you like to find another magic square - Enter y | Y for yes \nor";
            cout << " n | N for no:  ";
            cin >> choice;
            cout << endl;
        }



    }while(choice != 'n' && choice != 'N');

    cout << "\n\nThe hailstone Algorithm is implemented By Conor Schindel and Jacob Benavente.\n";

    return 0;
}


void hailstoneFinder (vector<int> &v1, int number)
{

    cout << "The sequence of the hailstone starting at " << number << " is\n\n";
    v1.push_back(number);

    while(number != 1)
    {
        if(number % 2)
        {
            number = 3 * number + 1;
            v1.push_back(number);
        }
        else
        {
            number = number / 2;
            v1.push_back(number);
        }
    }
}


void display (vector<int> &v1)
{

    for(int x = 0; x < v1.size(); ++x)
    {
        cout << v1[x] << " ";
    }

    cout << endl << endl;

}


void hLength(vector<int> &v1)
{
    cout << "The length of the sequence is " << v1.size() << ".\n";

}


int lNumber(vector<int> &v1)
{

    int largestN = 0;
    for(int x = 0; x < v1.size(); ++x)
    {
        if(v1[x] > largestN)
        {
            largestN = v1[x];
        }
    }

    return largestN;
}


int sNumber(vector<int>& v1)
{
    int smallestN = 9999999;
    for(int x = 0; x < v1.size(); ++x)
    {
        if(v1[x] < smallestN)
        {
            smallestN = v1[x];
        }
    }

    return smallestN;
}


void evenNum(vector<int>& v1)
{

    int holder = 0;
    for(int x = 0; x < v1.size(); ++x)
    {
        if(v1[x] % 2)
        {
            holder++;
        }
    }
    cout << holder << "\tof the numbers are odd. The odd sequence : ";
    for(int y = 0; y < v1.size(); ++y)
    {
        if(v1[y] % 2)
        {
            cout << v1[y] << " ";
        }
    }
    cout << endl;
}


void oddNum(vector<int>& v1)
{
    int holder = 0;
    for(int x = 0; x < v1.size(); ++x)
    {
        if(v1[x] % 2 == 0)
        {
            holder++;
        }
    }
    cout << holder << "\tof the numbers are even. The even sequence : ";
    for(int y = 0; y < v1.size(); ++y)
    {
        if(v1[y] % 2 == 0)
        {
            cout << v1[y] << " ";
        }
    }
    cout << endl;
}
