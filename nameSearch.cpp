/* 
 * File:   nameSearch.cpp
 * Author: Roman Geluz
 * Created on July 12, 2017, 4:02 PM
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
#include <string>

using namespace std;

//Function Prototypes
vector<string> readNames(string);
vector<string> sortArrayAlphabetically(vector<string>);
void searchNameList(vector<string>, vector<string>);

/**
 * main method
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {    
    cout << "\t" << "____________________________________________________" << endl;
    cout << "\t" << "|                                                  |" << endl;
    cout << "\t" << "|                                                  |" << endl;
    cout << "\t" << "|                                                  |" << endl;
    cout << "\t" << "|      WELCOME TO THE NAME SEARCH APPLICATION      |" << endl;
    cout << "\t" << "|                                                  |" << endl;
    cout << "\t" << "|                 BY: Roman Geluz                  |" << endl;
    cout << "\t" << "|           CISC 192 C/C++ Programming             |" << endl;
    cout << "\t" << "|                                                  |" << endl;
    cout << "\t" << "|                                                  |" << endl;
    cout << "\t" << "|__________________________________________________|" << endl;
    cout << "\t" << "" << endl << endl;
    
    cout << endl << endl;
    char* message = "The Name Search Application contains a searchable collection of about 400 names. \n"
                     "The collection of names contains 200 of the most popular names given to girls " 
                     "born in the United States from 2000 to 2009. \n"
                     "The collection of names also contains 200 most popular names given to boys "
                     "born in the United States from 2000 to 2009. \n"
                     "You can search the Name Search Application to see whether a name was among the most popular."; 
    cout << message << endl;
    
    //Read BoyNames.txt file and store contents in vector 
    vector<string> boyNamesList;
    boyNamesList = readNames("BoyNames.txt");
    
    //Read GirlNames.txt file and store contents in vector
    vector<string> girlNamesList;
    girlNamesList = readNames("GirlNames.txt");
    
    //Sort boy name list
    //cout << endl;
    //cout << "sorting boy name list vector alphabetically and then display list:" << endl; //DEBUG
    boyNamesList = sortArrayAlphabetically(boyNamesList);
    
    //Sort girl name list
    //cout << endl;
    //cout << "sorting girl name list vector alphabetically and then display list:" << endl; //DEBUG
    girlNamesList = sortArrayAlphabetically(girlNamesList);
    
    //Search both vectors for a particular value
    searchNameList(boyNamesList,girlNamesList);
    
    return 0;
}

/**
 * Read text file and store contents in vector
 * @param fileName
 * @return 
 */
vector<string> readNames(string fileName){
    //cout << "storing names in vector" << endl;    //DEBUG
    string name;
    int numOfNamesStored = 0;
    vector<string> namesList;
    ifstream inputFile;
    inputFile.open(fileName);
    if(inputFile){
        while(inputFile >> name){
            //cout << name << endl; //DEBUG
            namesList.push_back(name);
            numOfNamesStored++;
        }
    } else {
        cout << "error opening "<< fileName << " file" << endl;
    }
    //cout << "number of names stored: " << numOfNamesStored << endl;   //DEBUG
    cout << "" << endl;;
    inputFile.close();
    return namesList;
}

/**
 * Sort arrays alphabetically 
 * This function is probably not necessary, but I assuming the find() function 
 * invoked in the searchNameList() function, 
 * would prefer a sorted list, possibly for better search performance. 
 * @param nameList
 * @return 
 */
vector<string> sortArrayAlphabetically(vector<string> nameList){
    //cout << "sorting name list" << endl;  //DEBUG
    sort(nameList.begin(), nameList.end());
    //for(string name: nameList)        //DEBUG
       //cout << name << endl;
    //cout << "" << endl;
    return nameList;
}

/**
 * //Search vector for a particular value
 * @param boyNamesList
 * @param girlNamesList
 */
void searchNameList(vector<string> boyNamesList, vector<string> girlNamesList){ 
    cout << endl;
    string nameToSearch;
    do { 
        cout << "Enter a name to search the name list (first letter needs to be capitalized)," << endl; 
        cout << " or type \"exit\" to exit name search: ";
        cin >> nameToSearch;  
        
        //Search Boy name list
        if(find(boyNamesList.begin(),boyNamesList.end(),nameToSearch)!=boyNamesList.end()) {
            cout << "_________________________________________________" << endl;
            cout << "                                                 " << endl;
            cout << "   Search Results: The name " << nameToSearch << " is available!" << endl;
            cout << "_________________________________________________" << endl << endl;
        
        //Search Girl name list
        } else if(find(girlNamesList.begin(),girlNamesList.end(),nameToSearch)!=girlNamesList.end()) {
            cout << "_________________________________________________" << endl;
            cout << "                                                 " << endl;
            cout << "   Search Results: The name " << nameToSearch << " is available!" << endl;
            cout << "_________________________________________________" << endl << endl;
         
        //Exit application if "exit" is given    
        } else if(nameToSearch.compare("exit")==0) {  
            cout << "_________________________________________________" << endl;
            cout << "                                                 " << endl;
            cout << "   Exiting Name Search Application! " << endl;
            cout << "_________________________________________________" << endl << endl;
         
        //otherwise if name is not on the list, display "not available"
        } else {
            cout << "_________________________________________________" << endl;
            cout << "                                                 " << endl;
            cout << "   Search Results: The name " << nameToSearch << " is not available!" << endl;
            cout << "_________________________________________________" << endl << endl;
 
        }
        cout << endl; 
    } while(nameToSearch.compare("exit")!=0);
}