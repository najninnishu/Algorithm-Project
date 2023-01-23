#include<bits/stdc++.h>
using namespace std;
#define DNA_size 700

string mother_DNA="";

int LCS(string &child_DNA)
{
    int lcs_table[DNA_size + 1][DNA_size + 1];


    for (int i = 0; i <= DNA_size; i++) {
        for (int j = 0; j <= DNA_size; j++) {
            if (i == 0 || j == 0)
                lcs_table[i][j] = 0;
            else if (mother_DNA[i - 1] == child_DNA[j - 1])
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
            else
                lcs_table[i][j] = max(lcs_table[i - 1][j], lcs_table[i][j - 1]);
        }
    }

    int index = lcs_table[DNA_size][DNA_size];
    return index;
}

int main()
{

    string string_sequence[4]={"AT","TA","CG","GC"};
    string child_DNA[6];
    string s;
    srand( time(NULL) );

    ofstream file;
    file.open("dna.txt", ios::app);

    for(int i=0;i<DNA_size/2;i++){
        int randNum = rand() % 4;
        mother_DNA=mother_DNA+string_sequence[randNum];
    }
    cout<<"Annie's(mother's) DNA :";
    cout<<endl<<mother_DNA<<endl;
    for(int j=0;j<6;j++){
        for(int i=0;i<DNA_size/2;i++){
            int randNum = rand() % 4;
            file<<string_sequence[randNum];
        }
        file<<"\n";
    }
    file.close();
    cout<<endl;

    ifstream read;
    read.open("dna.txt");
    if(!read.is_open()){
        cout<<"could not open file"<<endl;
    }
    int number=0;
    while(!read.eof()){
        string line;
        getline(read,child_DNA[number]);
        if(number<=5)
        {
            cout<<"Child "<<number+1<<"'s DNA :"<<endl;
        }

        cout<<child_DNA[number]<<endl;
        number++;
    }


    std::ofstream ofs;
    ofs.open("dna.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    vector<int> lcs_size;
    int c;
    double maxi=0;
    for(int i=0;i<6;i++){


        lcs_size.push_back(LCS(child_DNA[i]));
        double accuracy = ((double)lcs_size[i]/mother_DNA.size())*100;
        if(accuracy>=maxi)
        {     maxi=accuracy;
             c=i;

        }
        cout<<"Accuracy of child "<<i+1<<" with Annie is "<<accuracy<<"%"<<endl;
    }
    cout<<endl;

    cout<<"The highest accuracy is "<<maxi<<"%"<<endl<<"\nSo child "<<c+1<<" is the daughter of Annie \n";

}

