#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>


void CheckIsValidOctal(std::string, bool&);
void ConvertOctalToDecimal(std::string, std::string&);

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

    ConvertOctalToDecimal(Input, Output);

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

void ConvertOctalToDecimal(std::string s, std::string& retVal){
    unsigned long long int retValTemp = 0;
    unsigned short int cnt = 0;
    std::string::reverse_iterator it;
    for(it = s.rbegin(); it != s.rend(); ++it){
        retValTemp += ((*it - '0') * (int)(pow(8, cnt)));
        cnt++;
    }
    retVal = std::to_string(retValTemp);
    return;
}

