#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string atmnumber;
    int multipliednumbers=1,addedvalues=0,evennumberadded=0;
    cout<<"Enter your 16 digits ATM Number : ";
    getline(cin,atmnumber);//used getline insted of cin because cin cannot take input as string with space.
    atmnumber.erase(remove(atmnumber.begin(),atmnumber.end(), ' '),atmnumber.end());//used to remove sapce in string
    if(atmnumber.length()!=16){
        cout<<"Couldn't recognize your ATM number ,Please enter 16 digits."<<endl;
    }
    else{
        for(int i=0;i<atmnumber.length()-1;i+=2){
            char ctoi = atmnumber[i];
            int ctoiconverted = ctoi - '0';
            multipliednumbers*=ctoiconverted*2;
            ostringstream itos;
            itos<<multipliednumbers;
            string itosconverted = itos.str();
            if(itosconverted.length()>=2){
                addedvalues += multipliednumbers%10 + multipliednumbers/10;
            }
            else{
                addedvalues+=multipliednumbers;

            }
            multipliednumbers=1;    
        }
        for (int j = 1; j <=atmnumber.length()-2; j+=2){
            char ctoiforeven = atmnumber[j];
            int ctoiconvertedeven = ctoiforeven - '0';
            evennumberadded+=ctoiconvertedeven;
            }
        int finaladdedvalues = 10-((addedvalues+evennumberadded)%10);
        char lastATMnumber = atmnumber[atmnumber.length()-1];
        int lastATMnumberconverted = lastATMnumber - '0';
        if (finaladdedvalues==lastATMnumberconverted)
        {
            cout<<"Don't worry Your ATM card Number Ligit.."<<endl;
            cout<<"Thank You have a Nice Day!!"<<endl;
        }
        else{
            cout<<"Sorry, Your ATM card Number is not Legit,\nPlease contact your nearby bank Branch..\n" << endl;
        }

    }
    return 0;
} 
