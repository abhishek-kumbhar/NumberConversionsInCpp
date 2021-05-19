#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <math.h>
#include <algorithm>


void CheckIsValidBinary(std::string, bool&);
void ConvertBinaryToHexadecimal(std::string, std::string&);

// Helper Function Declaration
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

    ConvertBinaryToHexadecimal(Input, Output);

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

    if(retValTemp < 10)
        retVal.push_back(retValTemp + 48);    
    else
        retVal.push_back(retValTemp + 55);
    
    return;
}

void ConvertBinaryToHexadecimal(std::string s, std::string& retVal){
    std::string::reverse_iterator it;

    while((s.size() % 4) != 0)
        s.insert(0, 1, '0');
   
    it = s.rbegin();
    for(int i = 0; i < s.size(); i += 4){
        std::string tempStr = "", tempStr2 = "";
        for(int j = 0; j < 4; ++j){
            tempStr.push_back(*it);
            it++;
        }
        reverse(tempStr.begin(), tempStr.end());
        ConvertBinaryToDecimal(tempStr, tempStr2);
        retVal.append(tempStr2);
    }

    reverse(retVal.begin(), retVal.end());
   
    return;
}
