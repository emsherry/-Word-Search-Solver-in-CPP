/**
 * @author Shehryar Ahmad (2021598)
 * 
 * @brief This code is basic implementation of a 2D array of characters as
 *        input and searches for all the possible word in the 2D array.
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Add(string wordSearch, int x1,int y1,int x2,int y2) 
{
    ofstream fout;

    fout.open("WordLocationFile.txt", ios::app);
    fout << wordSearch << " at ( " << x1 << " , " << y1 << " ) : ( " << x2 << " , " << y2 << " )" << endl;
    fout.close();
    cout << "data saved in file" << endl;

}

void searchWord(char array[7][13], string wordSearch)
{
 
    int iterationNo = 1;

    int x[8] = { -1,-1,-1,0,0,1,1,1 };
    int y[8] = { -1,0,1,-1,1,-1,0,1 };
    //these two arrays will help us check all 8 directions after the first word

    int x1=0, y1=0, x2=0, y2=0;  // x1,y1 will store starting index , x2,y2 will store ending index

    int storeCurrentX = -1, storeCurrentY = -1; 

    for (int r = 0 ; r < 7 ; r++){
        for (int c = 0; c < 12;c++) {
            if (wordSearch[0]==array[r][c]) {
                x1 = r;
                y1 = c;
                
                storeCurrentX = r;
                storeCurrentY = c;
                
                for (int m = 0; m < 8; m++)     //this loop will check all the directions
                {  
                    for (int i = 1; i < wordSearch.length() ; i++) {
                        if (wordSearch[iterationNo] == array[storeCurrentX+x[m]][storeCurrentY+y[m]])
                        {
                            iterationNo++;
                            storeCurrentX = storeCurrentX + x[m];
                            storeCurrentY = storeCurrentY + y[m];

                            if (wordSearch.length()==iterationNo)        // if complete word found, display it and reset values
                            { 
                                x2 = storeCurrentX;
                                y2 = storeCurrentY;
                                cout << "word " << wordSearch << " found at ( " << x1 << " , " << y1 << " ) : ( " << x2 << " , " << y2 << " )" << endl;
                                Add(wordSearch, x1, y1, x2, y2);
                                iterationNo = 1;
                                storeCurrentX = x1;
                                storeCurrentY = y1;
                            }
                        }
                        else {
                            iterationNo = 1;
                            storeCurrentX = x1;
                            storeCurrentY = y1;
                            break; // word not found in this direction
                        }      
                    }
                }
            }
        }
    }
}


//Driver Code
int main()
{
    char arrayOfCharacters[7][13] = { "okaydogisnow",   //13 coloumns because at the end there is a \0
                                      "ohellothered",
                                      "okmngtuvwf",
                                      "wxwgexlxhjij",
                                      "osookouxdraw",
                                      "rdldrxedtxja",
                                      "drownlonkgod"};
        
    string wordSearch = "";

    ofstream fout;
    fout.open("WordLocationFile.txt");   //this creates a new file 
    fout << "word at (start index):(end index)" << endl;//first line in new file used as a heading
    fout.close(); 


    ifstream fin;
    fin.open("wordListFile.txt");
    while (fin)     //read till end of the file
    {
        getline(fin, wordSearch);                   //read data from the file that consist of words to serch
        searchWord(arrayOfCharacters, wordSearch);  //this will search from the hardcoded character array
    }
}
