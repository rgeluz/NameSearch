

/* 
 * File:   main.cpp
 * Author: Roman Geluz
 *
 * Created on July 12, 2017, 4:02 PM
 * 
 * Course: CISC 192 C/C++ Programming
 * Assignment: Name Search
 * If you have downloaded this book's source code from the companion Web site, you
 * will find the following files in this chapter's folder:
 * 
 *  • GirlNames.txt-This file contains a list of the 200 most popular names given to girls
 *    born in the United States from 2000 to 2009.
 *  • BoyNames.txt-This file contains a list of the 200 most popular names given to
 *    boys born in the United States from 2000 to 2009.
 * 
 * Write a program that reads the contents of the two files into two separate arrays or
 * vectors. The user should be able to enter a boy's name, a girl's name, or both, and the
 * application should display messages indicating whether the names were among the
 * most popular.
 * 
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;



/*void storeInVector(ifstream inputFile, string fileName){
    
    inputFile.open(fileName);
    string name = "";
    vector<string> namesList;
    int numOfNamesStored =0;
    while(inputFile >> name){
        namesList.push_back(name);
        numOfNamesStored++;
    }
    cout << "number of names stored is " << numOfNamesStored << endl ;
}*/

/*
 * 
 */
/*int main(int argc, char** argv) {
    cout << "Name Search" << endl;
    
    ifstream inputFile;
    string name;
    
    //Read the first name:
    inputFile.open("BoyNames.txt");
    cout << "Reading first name from the file.\n";
    inputFile >> name; //Read name 1 from the file
    cout << name << endl;
    cout << endl;
    inputFile.close();
    
    //Read all the names:
    int nameCount=0;
    inputFile.open("BoyNames.txt");
    cout << "Reading all of the names from the file.\n";
    while(inputFile >> name) {
        cout << name << endl;
        nameCount++;
    }
    cout << endl;
    cout << "There are " << nameCount <<  " total names in the file." << endl;
    cout << endl;
    inputFile.close();
    
    //storeInVector(inputFile, "BoyNames.txt");
    cout << endl;
    cout << "storing all names in a vector" << endl;
    string fileName = "BoyNames.txt";
    inputFile.open(fileName);
    //string name = "";
    vector<string> namesList;
    int numOfNamesStored =0;
    while(inputFile >> name){
        cout << name << endl;
        namesList.push_back(name);
        numOfNamesStored++;
    }
    inputFile.close();
    cout << "number of names stored is " << numOfNamesStored << endl;
    cout << endl;
    
    //Sort arrays alphabetically 
    cout << endl;
    cout << "sorting vector alphabetically and then display list:" << endl;
    sort(namesList.begin(), namesList.end());
    for(string name: namesList)
        cout << name << endl;
    
    
    //Search vector for a particular value
    cout << endl;
    cout << "Enter a name to search the name list: ";
    string nameToSearch;
    cin >> nameToSearch;
    if(find(namesList.begin(),namesList.end(),nameToSearch)!=namesList.end())
        cout << "The name " << nameToSearch << " is available!" << endl;
    else
        cout << "The name " << nameToSearch << " is not available!" << endl;
    cout << endl;
    
    return 0;
}*/

