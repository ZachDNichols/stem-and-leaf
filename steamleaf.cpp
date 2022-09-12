#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

std::vector<int> get_nums(){
    std::vector<int> nums;
    std::string input;
    int num;
    bool gathering = true;

    while(gathering){
        std::cout << "Enter a number. If it is a decimal, do not use a point. When done type \"done\"." << std::endl;
        std::cin >> input;
        
        if (input == "done")
            gathering = false;
        else{
            try{
            num = stoi(input);
            nums.push_back(num);
            }
            catch (...) {
                std::cout << "Number not entered." << std::endl;
            }
        }
    }
    return nums;
}

void print_steamleaf(std::vector<int> nums){

    std::string temp;
    std::string num;
    int max = 9;

    std::cout << "Stem\t|\tLeaf" << std::endl << "--------|---------------------" << std::endl;
    std::cout << "0\t|\t";
    
    for(int i = 0; i < nums.size(); i++){
        temp = std::to_string(nums.at(i));
        if(nums.at(i) > max){
                std::cout << std::endl;
                max = nums.at(i);
                num = std::to_string(max);
                num.erase(num.length()-1);
                max = stoi(num);
                std::cout << max << "\t|\t";
                max = ((max * 10) + 9);
        }
        while(temp.length() > 1)
            temp.erase(temp.begin());
        std::cout << std::right << temp << ' ' << std::flush;
    }
}

int main(){
    //std::string input = gather_input();
    //std::vector<int> numlist = convert_nums(input);
    std::vector<int> numlist = get_nums();

    std::sort(numlist.begin(), numlist.end(), std::less<int>());

    print_steamleaf(numlist);

    return 0;
}