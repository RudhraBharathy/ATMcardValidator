#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string atmnumber,cardIssuerName;
    int multipliednumbers=1,addedvalues=0,evennumberadded=0;
    cout<<"Enter your 16 digits ATM Number : ";
    getline(cin,atmnumber);//used getline insted of cin because cin cannot take input as string with space.
    atmnumber.erase(remove(atmnumber.begin(),atmnumber.end(), ' '),atmnumber.end());//used to remove space in string
    if(atmnumber.length()!=16){
        cout<<"Couldn't recognize ,Please enter your 16 digits ATM number."<<endl;
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
        char firstATMnumber = atmnumber[0];
        int firstATMnumberconverted = firstATMnumber - '0';
        char lastATMnumber = atmnumber[atmnumber.length()-1];
        int lastATMnumberconverted = lastATMnumber - '0';

        if(firstATMnumberconverted == 4){
            cardIssuerName = "Visa";
        }
        else if (firstATMnumberconverted == 5)
        {
            cardIssuerName = "MasterCard";
        }
        else if (firstATMnumberconverted == 6)
        {
            cardIssuerName = "Rupay";
        }
        
        if (finaladdedvalues==lastATMnumberconverted)
        {
            cout<<"Your " << cardIssuerName << " ATM card Number is Original.."<<endl;
            cout<<"Thank You have a Nice Day!!"<<endl;
        }
        else{
            cout<<"Sorry, Your " << cardIssuerName << " ATM card Number is not Original,\nPlease contact your nearby bank Branch..\n" << endl;
        }

    }
    return 0;
} 
