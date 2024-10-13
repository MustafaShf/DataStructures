#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file;
     int row = 0;
    file.open("Q2_input.txt",ios::in);
    if (!file) {
        cout<< "Error opening file!" << endl;
        return 1;
    }
    string line;
    while(getline(file,line))
    {
        //cout<<line<<endl;
        row++;
    }
    int col=2; //always as there will be only two codes
    int **arr=new int*[row];
    for(int i=0;i<row;i++)
    {
        arr[i]=new int[col];
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<2;j++)
        {
            arr[i][j]=0;
        }
        
    }
     // Reset file pointer to the beginning for second pass
    //---------------------
    file.clear();             
    file.seekg(0, ios::beg); 
    //--------------------- 
    char word;
    int r=0;
    while(file.get(word))
    {
        if(word=='\n')
        {
            r++;
        }
        if(word=='Y')
        {
            
            arr[r][0]++;
        }
        else if(word=='N')
        {
            
            arr[r][1]++;
        }


    }
    cout<<"<-Compressed Data->\n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    


    
    return 0;
}
