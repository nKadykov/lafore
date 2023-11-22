#include <fstream>
using namespace std;

int main() {
    ofstream outfile("TEST.txt");

    outfile << "March comes. I am\n";
    outfile << "In hard situations\n";
    outfile << "I find good\n";
    outfile << "In difference\n";

    return 0;
}