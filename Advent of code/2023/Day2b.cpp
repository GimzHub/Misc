#include <bits/stdc++.h>

int main(){
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()){
        std::cout << "failed to open file!";
        return -1;
    }

    std::string line;
    int output{};
    
    while (getline(input_file, line)){
        int R{}, G{}, B{};
        for (int i{8}, ls{(int)line.size()}; i < ls;){
            int j{};
            std::string temp{""};
            
            while (i+j < ls-1 && line[i+j] != ';'){
                if (line[i+j] == ';' || (i+j == ls-1)){break;}
                else if (line[i+j] <= '9' && line[i+j] >= '0'){temp += line[i+j];}

                if      (line[i+j] == 'r'){R = std::max(R, stoi(temp)); temp.clear();}
                else if (line[i+j] == 'g'){G = std::max(G, stoi(temp)); temp.clear(); j += 2;}
                else if (line[i+j] == 'b'){B = std::max(B, stoi(temp)); temp.clear();}
                ++j;
            } 

            i += j+1;
        }
        
        output += R*G*B;
    }
    input_file.close();

    std::cout << "-----------------------\n";
    std::cout << "output: " << output << '\n';
    std::cout << "-----------------------\n";

    return 0;
}
