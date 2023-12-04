#include <bits/stdc++.h>

bool is_digit(const char& c){return (c <= '9' && c >= '0');}

int main(){
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()){
        std::cout << "failed to open file!";
        return -1;
    }

    std::string line;
    int output{};
    
    while (getline(input_file, line)){
        std::vector<bool>vb(101, false);
        std::string temp{""};
        bool check{};
        int count{};

        for (int i{8}, ls{(int)line.size()}; i < ls; ++i){
            if (line[i] == '|'){check = true; ++i;}
            else if (check){
                if (is_digit(line[i])){temp += line[i];} 
                else if (temp.size() && vb[stoi(temp)]){
                    if (count){count <<= 1;}
                    else {++count;}
                    temp.clear();
                }
                else {temp.clear();}
            }
            else {
                if (is_digit(line[i])){temp += line[i];} 
                else if (temp.size()){
                    vb[stoi(temp)] = true;
                    temp.clear();
                }
            }
        } 
        if (temp.size() && vb[stoi(temp)]){
            if (count){count <<= 1;}
            else {++count;}
        }

        output += count;
    }
    input_file.close();

    std::cout << "-----------------------\n";
    std::cout << "output: "<< output << '\n';
    std::cout << "-----------------------\n";
    
    return 0;
}
