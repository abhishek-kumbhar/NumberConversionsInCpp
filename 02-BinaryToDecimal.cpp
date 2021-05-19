#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>


void CheckIsValidBinary(std::string, bool&);
void ConvertBinaryToDecimal(std::string, std::string&);

int main(void) {

    std::string Input, Output;
    bool ret;

    std::cout << "Enter Binary Number: " << std::endl;
    std::cin >> Input;

    CheckIsValidBinary(Input, ret);

    if(!ret){
        std::cout << "Given number is NOT valid Binary. Please Enter valid Binary Number..." << std::endl;
        std::cout << "Exiting..." << std::endl;
        return(0);
    }

    ConvertBinaryToDecimal(Input, Output);

    std::cout << Output << std::endl;
     
    return(0);
}

void CheckIsValidBinary(std::string s, bool& ret){
    for(auto i : s)
        if(!(i == '0' || i == '1')){
            ret = false;
            return;
        }
     ret = true;
     return;
}

void ConvertBinaryToDecimal(std::string s, std::string& retVal){
    unsigned long long int retValTemp = 0;
    unsigned short int cnt = 0;
    std::string::reverse_iterator it;
    for(it = s.rbegin(); it != s.rend(); ++it){
        if((*it) == '1')
            retValTemp += (int)(pow(2, cnt));
        cnt++;
    } 
    retVal = std::to_string(retValTemp);
    
    return;
}

