#include <iostream>
#include <fstream>

//using namespace std;

void empty_file(std::string filename) {
        std::fstream unfolded_paper(filename, std::ios::out | std::ios::trunc);
        unfolded_paper.close();
}


void write_file(std::fstream& unfolded_paper) {
    
    unfolded_paper.clear();
    
    std::cout << "(To refold the paper, enter -close-)" << std::endl;
    
    std::string line;
    
    std::cout << "Enter a line you want to write on the paper: " << std::endl;
    
    std::getline(std::cin >> std::ws, line);
    
    while (line != "close") {
        
        char command;
    
        std::cout << "Was this line a title or a bullet point? Enter T or B: ";
    
        std::cin >> command;
        
        if (std::tolower(command) == 't') {
            unfolded_paper << std::endl << "          -" << line << "-"<< std::endl;
        } else {
            unfolded_paper << "*" << line << std::endl;
        }
        
        std::cout << "Enter a line you want to write on the paper: " << std::endl;
        std::getline(std::cin >> std::ws, line);
    }
}

void display_file(std::fstream& unfolded_paper) {
    unfolded_paper.clear();
    unfolded_paper.seekg(0);
    
    std::string line;
    
    while (std::getline(unfolded_paper, line)) {
        std::cout << line << std::endl;
    }
}

int main() {
    std::string filename {"access.txt"};
    std::fstream unfolded_paper;
    unfolded_paper.open(filename, std::ios::in | std::ios::out | std::ios::app);
    
    if (!unfolded_paper) {
        std::cerr << "No paper to unfold, or can't unfold paper given" << std::endl;
        return 1;
    }
    
    std::cout << "Paper successfully unfolded" << std::endl;
    
    char input;
    std::cout << "Do you want to read or write onto the paper?, Enter W or R: ";
    std::cin >> input;
    
    while (std::tolower(input) != 'n'){
        if (std::tolower(input) == 'r') {
            display_file(unfolded_paper);
        } else {
            write_file(unfolded_paper);
        }
        
        std::cout << "Do you want to read or write onto the paper?, Enter W or R (or N): ";
        std::cin >> input;
    }
    
    
    unfolded_paper.close();
    
    char clear;
    std::cout << "Would you like to erase the paper? Enter Y or N: ";
    std::cin >> clear;
    
    if (std::tolower(clear) == 'y'){
        empty_file(filename);
    } 
    
    std::cout << "Paper has been succesfully refolded, see ya next time :)";
    
    return 0;
}