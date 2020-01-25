// Serial Number : 75
//
// Author : Connor Widder
// Due Date : 11 - 4 - 19
// Programming Assignment Number 5
//
// Fall 2019 - CS 3358 - 1
//
// Instructor: Husain Gholoom.
//
// Program will perform a series of manipulations of various elements of
// an array consisting of randomly generated numbers. These interactions and
// manipulations include displaying array in reverse order, displaying powers
// of an element, displaying a table of squared valued of a certain element,
// displaying an element vertically, returning a boolean value of sequential
// digits, reversing an element, and returning a boolean value of a number's
// prime status

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayReverse(int arr[], int pos);
int displayPower(int num, int power);
void displaySquares(int num, int i);
void vertical(int arr[], int pos);
bool increasing(int num, int i, int comp);
int reverseElement(int arr[], int pos);
bool prime(int arr[], int pos);

int main(){

    srand(time(0)); //random number generator
    int sizeOfArray; //size of the array
    bool increase = false; //boolean value to determine increase in digits

    cout << "*** Welcome to My Recursion APP ***" << endl << endl;
    cout << "Enter The array size. ( Must be >= 5 ) -> ";
    cin >> sizeOfArray; //user inputs size of array
    cout << endl << endl;

    if (sizeOfArray > 15){
        cout << "Invalid arrays size. Size must <= 15" << endl << endl;
        cout << "Tristan Wells & Connor Widder - Programmer " << endl
         << "November 2019" << endl << endl << endl;
        return 0;
    }
    else if (sizeOfArray < 5){
        cout << "Invalid arrays size. Size must >= 5" << endl << endl;
        cout << "Tristan Wells & Connor Widder - Programmer " << endl
         << "November 2019" << endl << endl << endl;
        return 0;
    }

    int myArray[sizeOfArray];
    cout << "The generated array is : ";
    for (int i = 0; i < sizeOfArray; i++){ //iterates and displays array
        myArray[i] = rand() % 191 + 10;
        cout << myArray[i] << " ";
    }
    cout << endl << endl << "Reversed Array is : ";
    displayReverse(myArray, sizeOfArray); //reverse function

    cout << endl;
    cout << endl << myArray[sizeOfArray-1] << " raised to the 2nd power is: ";
    displayPower(myArray[sizeOfArray-1], 2); //displays power

    cout << endl << "Table of square values 1 - " << myArray[0] << endl;
    cout << endl << "N" << "\t" << "N Squared" << endl;
    displaySquares(myArray[0], 1); //table of squares

    cout << endl;
    vertical(myArray, 1); //displays number to vertical position

    cout << endl;
    increase = increasing(myArray[2], 0, 0);
    if ( increase == true )
        cout << myArray[2] << " is in increasing order";
    else if ( increase == false )
        cout << myArray[2] << " is not in increasing order";

    cout << endl << endl;
    reverseElement(myArray, 3); //reverses element

    cout << endl << endl;
    prime(myArray, 4); //return prime status

    cout << endl << endl << endl;
    cout << "Tristan Wells & Connor Widder - Programmer " << endl
         << "November 2019" << endl << endl << endl;

    return 0;
}

//function will receive array and return the array
//in reverse order under recursive iteration
void displayReverse(int arr[], int pos){

    if (pos != 0){
        cout << arr[pos-1] << " ";
        pos--;
        displayReverse(arr, pos);
    }else{
        return;
    }
}

//function will receive the last number of the
//array sequence and return the squared value
int displayPower(int num, int power){
    if (power != 1){
        num = num * num;
        power--;
        displayPower(num, power);
    }else{
        cout << num << endl;
        return 0;
    }
    return num, power;
}

//function will receive the first element of the
//array and display a table of squared values from 1
//up until the the iteration reaches the value of that
//first element
void displaySquares(int num, int i){
    int index = i;
    int square = index * index;
    if (index != num+1){
        cout << index << "\t" << square << endl;
        index++;
        displaySquares(num, index);
    }else{
        return;
    }
}

//function will receive the second element of
//the array and display the digits in a vertical
//manner
void vertical(int arr[], int pos){

    while( pos != 1){
        pos++;
        vertical(arr, pos);
    }
    int number = arr[pos];
    int digitArray[3];
    int i = 0;
    while ( number > 0 ){
        int digit = number % 10;
        number /= 10;
        digitArray[i] = digit;
        i++;
    }

    i--;

    cout << endl << arr[pos] << " vertically" << endl << endl;
    while (i >= 0){
        cout << digitArray[i] << endl;
        i--;
    }
}

//function returns a boolean value to determine whether
//or not the value have a sequence of digits in
//accending order
bool increasing(int num, int i, int comp){
    bool incr = false;

    int digitArray[3];

    if (i == 0){
        digitArray[0] = 0;
        digitArray[1] = 0;
        digitArray[2] = 0;
        while(num > 0){
            digitArray[i] = ((num%10));
            num /= 10;
            i++;
        }
        i = 2;
    }
    //while(digitArray[i] != NULL){
        if (digitArray[i] >= comp){
            comp = digitArray[i];
            i--;
            return incr = true;
            increasing(0, i, comp);
        }else{
            return incr = false;
        }
    //}
    return incr;
}

//function will return the fourth element of the
//array and display it with digits printed in
//reverse order
int reverseElement(int arr[], int pos){
    while( pos != 3){
        pos++;
        vertical(arr, pos);
    }
    int number = arr[pos];
    int digitArray[3];
    int i = 0;
    cout << number << " reversed is ";
    while ( number > 0 ){
        int digit = number % 10;
        number /= 10;
        digitArray[i] = digit;
        cout << digit;
        i++;
    }
    return number;
}

//function receives fifth element of the array
//and determines whether or not the number meets
//criteria to be classified as a prime number
bool prime(int arr[], int pos){

    bool isPrime = true;
    while( pos != 4){
        pos++;
        prime(arr, pos);
    }
    for (int i = 2; i <= ((arr[pos]) / 2); i++){
        if(arr[pos] % i == 0){
            isPrime = false;
        }
    }
    if (isPrime == true)
        cout << arr[pos] << " is Prime :";
    else if (isPrime == false)
        cout << arr[pos] << " is not Prime :";

    return isPrime;
}
