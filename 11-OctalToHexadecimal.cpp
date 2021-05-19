#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>
#include <algorithm>


void CheckIsValidOctal(std::string, bool&);
void ConvertOctalToHexadecimal(std::string, std::string&);

// Helper Function Declaration
void ConvertDecimalToBinary(char, std::string&);
void ConvertBinaryToHexadecimal(std::string, char&);
void ConvertBinaryToDecimal(std::string, char&);





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

    ConvertOctalToHexadecimal(Input, Output);

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



void ConvertBinaryToHexadecimal(std::string s, char& retVal){
    ConvertBinaryToDecimal(s, retVal);
    return;
}



void ConvertDecimalToBinary(char s, std::string& retVal){
    unsigned long long int actualNumber = 0;
    unsigned short int cnt = 0;
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


void ConvertOctalToHexadecimal(std::string s, std::string& retVal){
    std::string tempStr, tempStr2=  "";
    std::string::iterator it;

    for(auto i : s){
        tempStr = "";
        ConvertDecimalToBinary(i, tempStr);
        retVal.append(tempStr);
    }
    

    while((retVal.size() % 4) != 0)
        retVal.insert(0, 1, '0');
    
    
    it = retVal.begin();

    for(int i = 0; i < retVal.size(); i += 4){
        tempStr = "";
        char c;   
        for(int j = 0; j < 4; ++j){
            tempStr.push_back(*it);
            it++;
        }
        ConvertBinaryToHexadecimal(tempStr, c);
        tempStr2.push_back(c);   
    }
    retVal = "";
    retVal = tempStr2;

    return;
}

