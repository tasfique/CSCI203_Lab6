//Name- Tasfique Enam
//Student ID- 5886429

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <list>

using namespace std;

string fileName;
int num;
ifstream ifs;

class Hash
{
    int STORE;    // No. of buckets

    // Pointer to an array containing buckets
    list<int> *table = 0; ///it got initialized to zero.
public:
    Hash(int V);  // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x) {
        return (x % STORE);
    }

    void displayHash();
};

Hash::Hash(int b)
{
    this->STORE = b;
    table = new list<int>[STORE];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

// function to display hash table
void Hash::displayHash() {
  int count = 0;

  for (int i = 0; i < STORE; i++) {
    cout << i;
    for (auto x : table[i])
      cout << " --> " << x;

    cout << endl;
  }

}

void deleteRepeat(int a[], int &n) {
    int k;
    int j;
    for(int i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        if(a[i]==a[j]) {
            for(k=j; k<n; k++) {
                a[k] = a[k+1];
            } n--;
            j--;
        }
}

int main() {
    bool check = true;
    int arrayStorage [100];
    int n = *(&arrayStorage + 1) - arrayStorage; // the sizing of the array
    int i;
    int b[100];

    do {
        cout << "Enter the name of the File with .txt Extention " << endl; //for opening the fiel.
        cin >> fileName;

        if(fileName != "document.txt") {
            cout << "File name is Invalid! " << endl;
         } else {
            ifs.open("document.txt");

            if (ifs.is_open()) {
                cout<<"The File have been successfully opened." << endl;
                //ifs>>num1;
            } else {
                cout << "File failed to Open " << endl;
                check = false;
            }
         }

    } while (fileName != "document.txt" || check == false);

    ///Reading from the file and putting it in the array.
    for(i=0; i<n; i++) {
            ifs >> num;
            arrayStorage[i] = num;
            cout << "Array numbers " << arrayStorage[i] << " " << endl;

            if(arrayStorage[i] < 0 ) { //validation for number not being positive.
                cout << "In the Array the number " << arrayStorage[i] << " is not Positive." << endl;
                exit(0); ///check
            }
    }

    ifs.close();

    deleteRepeat(arrayStorage, n); ///delete repeating data.

    Hash h(100);

    for (int j=0; j<n; j++) {
        h.insertItem(arrayStorage[j]);
    }

    // display the Hash table
    h.displayHash();

    cout << " " << endl;


    for(int i=0; i<100; i++)
    {
        b[i]=0;
    }
    for(int i=0; i<100; i++)
    {
        int result=0;
        if(i<n)
        {
            result = arrayStorage[i] % 100;
        b[result]++;
        }

    }

    /*for(int i=0; i<n; i++)
    {
        cout<<b[i]<<endl;
    }*/

    int counter=0;

    for(int i=0; i<100; i++)
    {
        if(b[i]==0)
            counter++;
    }

    cout << "The number of empty entries in the hash table: " << counter << endl;

    int max=b[0];
    for(int i=0; i<100; i++)
    {
        if(max<b[i])
            max=b[i];
    }

    cout << "The length of the longest chain: " << max << endl;


    return 0;

}

