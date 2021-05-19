#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>
#include <algorithm>


void CheckIsValidDecimal(std::string, bool&);
void ConvertDecimalToHexadecimal(std::string, std::string&);

int main(void) {

    std::string Input, Output = "";
    bool ret;

    std::cout << "Enter Decimal Number: " << std::endl;
    std::cin >> Input;

    CheckIsValidDecimal(Input, ret);

    if(!ret){
        std::cout << "Given number is NOT valid Decimal. Please Enter valid Decimal Number..." << std::endl;
        std::cout << "Exiting..." << std::endl;
        return(0);
    }

    ConvertDecimalToHexadecimal(Input, Output);

    std::cout << Output << std::endl;
     
    return(0);
}

void CheckIsValidDecimal(std::string s, bool& ret){
    for(auto i : s)
        if(!(i >= '0' && i <= '9')){
            ret = false;
            return;
        }
     ret = true;
     return;

}

void ConvertDecimalToHexadecimal(std::string s, std::string& retVal){
    unsigned long long int actualNumber = 0;
    unsigned short int cnt = 0;
    std::string::reverse_iterator it;
    for(it = s.rbegin(); it != s.rend(); ++it){
        actualNumber += ((*it - '0') * (int)(pow(10, cnt)));   
        cnt++;
    }

    while(actualNumber){
        if(actualNumber % 16 < 10)
            retVal.push_back(static_cast<char>(48 + (actualNumber % 16)));
        else
            retVal.push_back(static_cast<char>(55 + (actualNumber % 16)));
        actualNumber /= 16;
    }
    
    reverse(retVal.begin(), retVal.end());
}


