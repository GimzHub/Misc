#include <bits/stdc++.h>

int main(){
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()){
        std::cout << "\n--- FAILED TO OPEN FILE! ---\n"; 
        return -1;
    }
    
    std::vector<std::string>vs{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string line;
    int output{};

    while (getline(input_file, line)){
        std::vector<std::pair<int, int>>vi;
        int idx{}, ls{(int)line.size()};

        for (int i{}; i < ls; ++i){ // digits
            if (line[i] <= '9' && line[i] >= '0'){
                vi.push_back({i, line[i] - '0'}); 
            }
        }
        
        for (const auto& n : vs){ // words
            size_t x{};
            while (x < line.size()){
                std::string::size_type p{line.find(n, x)};
                if (p == std::string::npos){break;} // if word not in string move on to the next one.

                vi.push_back({p, idx});
                x = p + n.size() + 1; // move x along by size of current word+1
            } ++idx;
        }
        
        sort(vi.begin(), vi.end());
        output += (vi.cbegin() -> second * 10) + vi.crbegin() -> second; // first digit*10 then add last digit apply to output
    }
    input_file.close();
    
    std::cout << "\n-----------------------------\n";
    std::cout << '\t' << "output: " << output; 
    std::cout << "\n-----------------------------\n";

    return 0;
}
