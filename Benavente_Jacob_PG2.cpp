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
//  The hailstone sequence program calculates a hailstone sequence for
//  a number that the user inputs. It then outputs the sequence, the length
//  of the sequence, the largest and smallest numbers in the sequence, and
//  all of the even and odd numbers in the sequence.
#include <iostream>
#include <vector>

using namespace std;

// calculates the hailstone sequence
void hailstoneFinder (vector<int>&, int);

// displays the hailstone sequence
void display (vector<int>&);

// outputs the length of the hailstone sequence
void hLength(vector<int>&);

// outputs the largest number in the hailstone sequence
int lNumber(vector<int>&);

// outputs the smallest number in the hailstone sequence
int sNumber(vector<int>&);

// outputs the even numbers in the hailstone sequence
void evenNum(vector<int>&);

//outputs the odd numbers in the hailstone sequence
void oddNum(vector<int>&);


int main()
{

    int number;     // Integer value used to store the number that the
                    // user inputs for the hailstone sequence
    char choice;    // character value used in determining whether or
                    // not the user wants to get another sequence

    bool flag1 = true;  // boolean value that is true if the user's input
                        // is a positive integer

    cout << "Welcome to the hailstone sequence program.\n";
    cout << "The function of the program is to read a number n from the\n";
    cout << "user and then tells the user four things\n";
    cout << "\t1.\tThe entire hailstone sequence start at n, all on one line";
    cout << ",\n";
    cout << "\t\twith the numbers separated by spaces;\n";
    cout << "\t2.\tThe length of the hailstone sequence that starts with n;";
    cout << "\n";
    cout << "\t3.\tThe largest number in the hailstone sequence that ";
    cout << "starts with n;\n";
    cout << "\t4.\tThe smallest number in the hailstone sequence that starts";
    cout << " with n;\n";
    cout << "\t5.\tCount and display the numbers in that hailstone sequence ";
    cout << "are even.\n";
    cout << "\t6.\tCount and display the numbers in that hailstone sequence ";
    cout << "are odd.\n\n";

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
            cout << "The largest number in the sequence is  " << lNumber(v1);
            cout << ".\n";
            cout << "The smallest number in the sequence is  " << sNumber(v1);
            cout << ".\n";
            oddNum(v1);
            evenNum(v1);
        }





        cout << "\n\nWould you like to find hailstone sequence for another ";
        cout << "number - ";
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
            cout << "\nError *** Invalid choice - Must enter y | Y | n | N";
            cout << endl;
            cout << "\nWould you like to find another magic square ";
            cout << "- Enter y | Y for yes \nor n | N for no:  ";
            cin >> choice;
            cout << endl;
        }



    }while(choice != 'n' && choice != 'N');

    cout << "\n\nThe hailstone Algorithm is implemented By Conor Schindel "
         << "and Jacob Benavente.\n";

    return 0;
}

/*
 * void hailstoneFinder()
 * accepts the integer vector and value input by the user
 * calculates the hailstone seqeunce and stores it in the vector
 */
void hailstoneFinder (vector<int> &v1, int number)
{

    cout << "The sequence of the hailstone starting at " << number;
    cout << " is\n\n";
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

/*
 * void display()
 * accepts the vector containing the hailstone sequence
 * displays the completed hailstone sequence
 */
void display (vector<int> &v1)
{

    for(int x = 0; x < v1.size(); ++x)
    {
        cout << v1[x] << " ";
    }

    cout << endl << endl;

}

/*
 * void hLength()
 * accepts the vector containing the hailstone sequence
 * outputs the length of the sequence
 */
void hLength(vector<int> &v1)
{
    cout << "The length of the sequence is " << v1.size() << ".\n";

}

/*
 * int lNumber()
 * accepts the vector containing the hailstone sequence
 * calculates and outputs the largest number in the sequence
 */
int lNumber(vector<int> &v1)
{

    int largestN = 0;   // int value to hold the largest number
                        // in the vector
    for(int x = 0; x < v1.size(); ++x)
    {
        if(v1[x] > largestN)
        {
            largestN = v1[x];
        }
    }

    return largestN;
}

/*
 * int sNumber()
 * accepts the vector containing the hailstone sequence
 * calculates and outputs the smallest number in the sequence
 */
int sNumber(vector<int>& v1)
{
    int smallestN = 9999999;    // int value to hold the smallest number
                                // in the vector
    for(int x = 0; x < v1.size(); ++x)
    {
        if(v1[x] < smallestN)
        {
            smallestN = v1[x];
        }
    }

    return smallestN;
}

/*
 * void evenNum
 * accepts the vector containing the hailstone sequence
 * determines and outputs all the even values in the sequence
 */
void evenNum(vector<int>& v1)
{

    int holder = 0; // int value that holds the total of even numbers
                    // in the vector
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

/*
 * void oddNum
 * accepts the vector containing the hailstone sequence
 * determines and outputs all the odd values in the sequence
 */
void oddNum(vector<int>& v1)
{
    int holder = 0; // int value that holds the total of odd numbers
                    // in the vector
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
