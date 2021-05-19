#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>
#include <algorithm>


void CheckIsValidOctal(std::string, bool&);
void ConvertOctalToBinary(std::string, std::string&);

// Helper Function Declaration
void ConvertDecimalToBinary(char, std::string&);


int main(void) {

    std::string Input, Output;
    bool ret;

    std::cout << "Enter Octal Number: " << std::endl;
    std::cin >> Input;

    CheckIsValidOctal(Input, ret);

    if(!ret){
        std::cout << "Given number is NOT valid Octal. Please Enter valid Octal Number..." << std::endl;
        std::cout << "Exiting..." << std::endl;
        return(0);
    }

    ConvertOctalToBinary(Input, Output);

    std::cout << Output << std::endl;
     
    return(0);
}

void CheckIsValidOctal(std::string s, bool& ret){
    for(auto i : s)
        if(!(i >= '0' && i <= '7')){
            ret = false;
            return;
        }
     ret = true;
     return;
}

void ConvertDecimalToBinary(char s, std::string& retVal){
    unsigned long long int actualNumber = 0;
    retVal = "";
    actualNumber = s - '0';   
    while(actualNumber){
        actualNumber % 2 == 1 ? retVal.push_back('1') : retVal.push_back('0');
        actualNumber /= 2;
    }
    
    if(retVal.size() < 3)
        while(retVal.size() != 3)
            retVal.push_back('0');

    reverse(retVal.begin(), retVal.end());
    return;
}


void ConvertOctalToBinary(std::string s, std::string& retVal){
    std::string tempStr = "";
    for(auto i : s){
        ConvertDecimalToBinary(i, tempStr);
        retVal.append(tempStr);
    }
    return;
}

