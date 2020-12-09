#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
class csvreader
{
    public:
        string fileName;
        string delimeter;
        //map<(add of temperature,rainfall),<yeild,crop>>
        multimap<double,pair<double,string>> m;

    public:
        csvreader(string filename, string delm = ",") :fileName(filename), delimeter(delm){ }
        vector<vector<string> > getData();
        vector<string> split(const string& str, const string& delim);
        void printdataset(vector<vector<string> > dataList );
        void addintomap(double temp,double rainfall,double yeild,string crop);
        void printmap();
        void calculate();

};

class crop
{
    public:
        string cropname;
        double temp;
        double rain;

    public:
        void showcroptype(){
            cout<<"The crop type is "<<cropname<<endl;
            cout<<"--------Enter the expected parameters-----------\n";
            cout<<"Enter temperature : ";
            cin>>temp;
            cout<<endl;
            cout<<"Enter rainfall : ";
            cin>>rain;
            
            
            /*
            int getoption(){
            return option;
            }
            int gettemp(){
            return temp;
            }
            int getrain(){
            return rain;
            }
            string getoutput(){
            return output;
            }
            */
            
        }

        virtual void show(){
            cout<<"Printing the crop type \n";
        }
};

