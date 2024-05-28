#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
    std::ofstream myfile;
    myfile.open ("example.txt");

    for (int i = 1; i < argc; i++)
        myfile << argv[i] << " ";
    
    myfile.close();
    return 0;
}
