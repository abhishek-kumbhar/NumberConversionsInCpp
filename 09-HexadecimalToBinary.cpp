#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>
#include <algorithm>


void CheckIsValidHexadecimal(std::string, bool&);
void ConvertHexadecimalToBinary(std::string, std::string&);

// Helper Function Declaration
void ConvertDecimalToBinary(char, std::string&);


int main(void) {

    std::string Input, Output;
    bool ret;

    std::cout << "Enter Hexadecimal Number: " << std::endl;
    std::cin >> Input;

    CheckIsValidHexadecimal(Input, ret);

    if(!ret){
        std::cout << "Given number is NOT valid Hexadecimal. Please Enter valid Hexadecimal Number..." << std::endl;
        std::cout << "Exiting..." << std::endl;
        return(0);
    }

    ConvertHexadecimalToBinary(Input, Output);

    std::cout << Output << std::endl;
     
    return(0);
}

void CheckIsValidHexadecimal(std::string s, bool& ret){
    for(auto i : s)
        if(!(i >= '0' && i <= '9' || i >= 'A' && i <= 'F')){
            ret = false;
            return;
        }
     ret = true;
     return;
}


void ConvertDecimalToBinary(char s, std::string& retVal){
    unsigned long long int actualNumber = 0;
    retVal = "";

    if(s >= '0' && s <= '9')
        actualNumber = s - '0';
    else
        actualNumber = s - ('A' - 10);

    while(actualNumber){
        actualNumber % 2 == 1 ? retVal.push_back('1') : retVal.push_back('0');
        actualNumber /= 2;
    }

    if(retVal.size() < 4)
        while(retVal.size() != 4)
            retVal.push_back('0');

    
    reverse(retVal.begin(), retVal.end());
    return;
}

void ConvertHexadecimalToBinary(std::string s, std::string& retVal){
    std::string tempStr = "";
    for(auto i : s){
        ConvertDecimalToBinary(i, tempStr);
        retVal.append(tempStr);
    }
    return;
}

