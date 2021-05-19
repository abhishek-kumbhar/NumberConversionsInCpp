#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>
#include <algorithm>


void CheckIsValidHexadecimal(std::string, bool&);
void ConvertHexadecimalToOctal(std::string, std::string&);

// Helper Function Declarations
void ConvertDecimalToBinary(char, std::string&);
void ConvertBinaryToOctal(std::string, char&);
void ConvertBinaryToDecimal(std::string, char&);



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

    ConvertHexadecimalToOctal(Input, Output);

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



void ConvertBinaryToDecimal(std::string s, char& retVal){
    unsigned long long int retValTemp = 0;
    unsigned short int cnt = 0;
    std::string::reverse_iterator it;
    for(it = s.rbegin(); it != s.rend(); ++it){
        if((*it) == '1')
            retValTemp += (int)(pow(2, cnt));
        cnt++;
    } 
    if(retValTemp < 10)
        retVal = retValTemp + 48;
    else
        retVal = retValTemp + 55;
    
    return;
}

void ConvertBinaryToOctal(std::string s, char& c){
    ConvertBinaryToDecimal(s, c);
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


void ConvertHexadecimalToOctal(std::string s, std::string& retVal){
    std::string tempStr = "", tempStr2 = "";
    std::string::iterator it;

    for(auto i : s){
        ConvertDecimalToBinary(i, tempStr);
        retVal.append(tempStr);
    }

    it = retVal.begin();
    
    for(int i = 0; i < retVal.size(); i += 3){
        tempStr = "";
        char c;
        for(int i = 0; i < 3; ++i){
            tempStr.push_back(*it);
            it++;
        }
        ConvertBinaryToOctal(tempStr, c);
        tempStr2.push_back(c);
    }
    
    retVal = "";
    retVal = tempStr2;
    return;
}

