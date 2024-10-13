#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    //Open File
    ifstream file;
    file.open("Q2_input.txt", ios::in);  

    if (!file) {
        cout << "file not opened" << endl;
        return 0;
    }

    // find total no of row and col I should create
    int row = 0, col = 0;
    string line;

    while (getline(file, line)) {
        if (col == 0) {
            //count col in first line
            for (int i = 0; i < line.length(); i++) {

                if (line[i] == 'Y' || line[i] == 'N') 
                {
                    col++;  
                }
            }
        }
        row++;  
    }

    // Create a 2D arr
    string **arr = new string*[row];
    for (int i = 0; i < row; i++) {
        arr[i] = new string[col];
    }

    // Reset file pointer
    file.clear();
    file.seekg(0, ios::beg);

    //-------------------------------------
    //filling 2D arr with yes and no
    int r = 0;
    while (getline(file, line)) {
        int c = 0;
        for (int i = 0; i < line.length(); i++) 
        {

            if (line[i] == 'Y') 
            {
                arr[r][c] = "Yes";
                c++;
            }
            else if (line[i] == 'N') 
            {
                arr[r][c] = "No";
                c++;
            }
        }
        r++;
    }

    file.close();

    //2D arr for counting matrix

    int **countArr = new int*[row];

    for (int i = 0; i < row; i++) 
    {
        countArr[i] = new int[2]; //awasys
        //initializing
        countArr[i][0] = 0;  
        countArr[i][1] = 0;  
    }

    //counting Start
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            if (arr[i][j] == "Yes") 
            {
                countArr[i][0]++;  
            }
            else if (arr[i][j] == "No") 
            {
                countArr[i][1]++;  
            }
        }
    }

    // Output the compressed data
    cout << "<- Compressed Data ->\n";

    for (int i = 0; i < row; i++) 
    {
        for(int j=0;j<2;j++)
        {
            cout << countArr[i][j]<<" ";    
        }
        cout<<endl;
        
    }

    

    for (int i = 0; i < row; i++) 
    {
        delete[] arr[i];
        delete[] countArr[i];
    }
    delete[] arr;
    delete[] countArr;

    return 0;
}
