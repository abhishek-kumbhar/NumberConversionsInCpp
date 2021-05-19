#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>


void CheckIsValidHexadecimal(std::string, bool&);
void ConvertHexadecimalToDecimal(std::string, std::string&);

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

    ConvertHexadecimalToDecimal(Input, Output);

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

void ConvertHexadecimalToDecimal(std::string s, std::string& retVal){
    unsigned long long int retValTemp = 0;
    unsigned short int cnt = 0;
    std::string::reverse_iterator it;
    for(it = s.rbegin(); it != s.rend(); ++it){
        if(*it >= '0' && *it <= '9')
            retValTemp += ((*it - '0') * (int)(pow(16, cnt)));
        else
            retValTemp += ((*it - ('A' - 10)) * (int)(pow(16, cnt)));

        cnt++;
    }

    retVal = std::to_string(retValTemp);
    return;
}

