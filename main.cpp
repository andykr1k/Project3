#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 3){
        cout << "Deterministic Program...Needs all arguments(./x.out -json nameOfFile)" << endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
