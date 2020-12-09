#include"header.h"
class ragi:crop,csvreader
{
    public:
        ragi():csvreader("ragi.csv"){
            cropname = "ragi";
            cout<<endl;
            showcroptype();
        }
        void print(){
            cout<<"\nprinting the ragi dataset here\n";
            vector<vector<string> > dataList = getData();
            printdataset(dataList);
        }

        void cal()
        {
            vector<vector<string> > dataList = getData();
            double yeild = 0;
            double totalyeild = 0;
            double minbound = this->temp+this->rain-3;
            double maxbound = this->rain+this->temp+3;

            multimap<double,pair<double,string>>::iterator it = m.begin();
            while(it!=m.end()){
                if(it->first>=minbound && it->first<=maxbound){
                    yeild+=it->second.first;
                }
                totalyeild+=it->second.first;
                it++;
            }
            cout<<"The success percentage for ragi is "<<((yeild/totalyeild)*100)<<" %"<<endl;
        }

        void show(){
            cout<<"The crop type here is \n"<<cropname<<endl;
        }
};

class rice:crop,csvreader
{
    public:
        rice():csvreader("rice.csv"){
            cropname = "rice";
            cout<<endl;
            showcroptype();
        }
        void print(){
            cout<<"\nprinting the rice dataset here\n";
            vector<vector<string> > dataList = getData();
            printdataset(dataList);
        }
        void cal()
        {
            vector<vector<string> > dataList = getData();
            double yeild = 0;
            double totalyeild = 0;
            double minbound = this->temp+this->rain-3;
            double maxbound = this->rain+this->temp+3;
            multimap<double,pair<double,string>>::iterator it = m.begin();
            while(it!=m.end()){
                if(it->first>=minbound && it->first<=maxbound){
                    yeild+=it->second.first;
                }
                totalyeild+=it->second.first;
                it++;
            }
            cout<<"The success percentage for rice is "<<((yeild/totalyeild)*100)<<" %"<<endl;
        }

        void show(){
            cout<<"The crop type here is \n"<<cropname<<endl;
        }
};


class sugarcane:crop,csvreader
{
    public:
        sugarcane():csvreader("sugarcane.csv"){
            cropname = "sugaercane";
            cout<<endl;
            showcroptype();
        }
        void print(){
            cout<<"\nprinting the sugarcane dataset here\n";
            vector<vector<string> > dataList = getData();
            printmap();
        }
        void cal()
        {
            vector<vector<string> > dataList = getData();
            double yeild = 0;
            double totalyeild = 0;
            double minbound = this->temp+this->rain-3;
            double maxbound = this->rain+this->temp+3;

            multimap<double,pair<double,string>>::iterator it = m.begin();
            while(it!=m.end()){
                if(it->first>=minbound && it->first<=maxbound){
                    yeild+=it->second.first;
                }
                totalyeild+=it->second.first;
                it++;
            }
            cout<<"The success percentage for sugarcane is "<<((yeild/totalyeild)*100)<<" %"<<endl;
        }
        void show(){
            cout<<"The crop type here is \n"<<cropname<<endl;
        }
};

void csvreader::printmap()
{
    cout<<"\nprinting the contents of the map here\n";
    multimap<double,pair<double,string>>::iterator it = m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
        it++;
    }
}

void csvreader::calculate()
{
    double temp,rain;
    cout<<"--------Enter the expected parameters-----------\n";
    cout<<"Enter temperature : ";
    cin>>temp; //int gettemp();
    cout<<endl;
    cout<<"Enter rainfall : ";
    cin>>rain; //int getrain();
    long long riceyeild = 0;
    long long ragiyeild  = 0;
    long long sugarcaneyeild = 0;
    double added = temp+rain;
    double minbound = added-3.0;
    double maxbound = added+3.0;
    int count = 0;

    multimap<double,pair<double,string>>::iterator it = m.begin();
    while(it!=m.end()){
        double curvalue = it->first;
        if(curvalue>=minbound && curvalue<=maxbound){
            count++;
            if(it->second.second == "Rice"){
                riceyeild+=it->second.first;
            }
            else if(it->second.second == "Ragi"){
                ragiyeild+=it->second.first;
            }
            else{
                sugarcaneyeild+=it->second.first;
            }
        }
        it++;
    }

    riceyeild = riceyeild/count;
    ragiyeild = ragiyeild/count;
    sugarcaneyeild = sugarcaneyeild/count;

    cout<<"\n The avg yeilds of the crops from the previous data is shown below,\n";
    cout<<endl;
    cout<<" Rice avg yeild : "<<riceyeild<<endl;
    cout<<" Ragi avg yeild : "<<ragiyeild<<endl;
    cout<<" Sugarcane avg yeild "<<sugarcaneyeild<<endl;

    cout<<endl;
    //getoutput(){}

    if(riceyeild>ragiyeild && riceyeild>sugarcaneyeild){ 
        cout<<"Thus, recommended crop for cultivation is ---> rice"<<endl;
    }

    else if(ragiyeild>riceyeild && ragiyeild>sugarcaneyeild){
        cout<<"Thus, recommended crop for cultivation is ---> ragi"<<endl;
    }

    else{
        cout<<"Thus, recommended crop for cultivation is ---> sugarcane"<<endl;
    }
}


void csvreader::addintomap(double temp,double rainfall,double yeild,string crop)
{
    //adding the data into map ds
    double addtemprain = temp+rainfall;
    m.insert(pair<double,pair<double,string>> {addtemprain,{yeild,crop}});
}

//function to print the dataset that is used for the analysis
void csvreader::printdataset(vector<vector<string> > dataList )
{
    for(vector<string> vec : dataList)
    {
        for(string data : vec)
        {
            cout<<data << " , ";
        }
        cout<<endl;
    }
}

// function to get the data from the csv file
// and store it in the map DS
vector<vector<string> > csvreader::getData()
{
    ifstream file(fileName);
    vector<vector<string> > dataList;
    string line = "";
    // Iterate through each line and split the content using delimeter
    while (getline(file, line))
    {
        vector<string> vec;
        vec = split(line,",");

        // vec[2] = rainfall
        // vec[3] = temperature
        // vec[5] = crop type
        // vec[6] = yeild

        addintomap((double)stod(vec[3]),(double)stod(vec[2]),(double)stod(vec[6]),vec[5]);
        dataList.push_back(vec);
    }
    // Close the File
    file.close();
    return dataList;
}


vector<string> csvreader::split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int main()
{

    while(1){

        cout<<"\t\t!! Welcome to crop seva kendra !!"<<endl;
        cout<<"\n please let us know your recommendations \n";
        cout<<"1) Know the best crop \n";
        cout<<"2) Know success rate for Rice \n";
        cout<<"3) Know success rate for Ragi \n";
        cout<<"4) Know success rate for Sugarcane \n";
        cout<<"5) Exit \n";

        int option;
        cout<<"Enter option : ";
        cin>>option;

        if(option == 1){
            csvreader reader("newfinal.csv");
            vector<vector<string> > dataList = reader.getData();
            reader.calculate();

        }

        if(option == 2){
            rice r;
            r.cal();
        }

        if(option == 3){
            ragi r;
            r.cal();
        }

        if(option == 4){
            sugarcane s;
            s.cal();
        }

        if(option == 5){
            cout<<"...";
            delay(1);
            cout<<".";
            delay(1);
            cout<<".";
            delay(1);
            cout<<".";
            delay(1);
            cout<<"....";
            cout<<"\nTHANK YOU"<<endl;
            break;
        }
        cout<<endl;
        cout<<endl;
    }
}

