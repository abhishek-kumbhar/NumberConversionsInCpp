#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>
#include <algorithm>


void CheckIsValidDecimal(std::string, bool&);
void ConvertDecimalToBinary(std::string, std::string&);

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

    ConvertDecimalToBinary(Input, Output);

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

void ConvertDecimalToBinary(std::string s, std::string& retVal){
    unsigned long long int actualNumber = 0;
    unsigned short int cnt = 0;
    std::string::reverse_iterator it;
    for(it = s.rbegin(); it != s.rend(); ++it){
        actualNumber += ((*it - '0') * (int)(pow(10, cnt)));   
        cnt++;
    }

    while(actualNumber){
        actualNumber % 2 == 1 ? retVal.push_back('1') : retVal.push_back('0');
        actualNumber /= 2;
    }
    
    reverse(retVal.begin(), retVal.end());
    return;
}


