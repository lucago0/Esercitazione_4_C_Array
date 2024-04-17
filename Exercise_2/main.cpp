#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "src/Utils.hpp"

using namespace std;

int main()
{
    string inFile = "data.csv";
    string outFile = "result.txt";
    ifstream ifs(inFile);
    ofstream ofs(outFile);

    if (ifs.fail()){
        cerr << "Input file does not exist." << endl;
        return 1;
    }

    if (ofs.fail()){
        cerr << "Error opening output file." << endl;
        return 1;
    }

    char separator;
    string line;

    getline(ifs,line);
    double S = 1;
    line.erase(0,2);
    S = stod(line);

    getline(ifs,line);
    unsigned int n;
    line.erase(0,2);
    n = stoi(line);

    getline(ifs,line);

    double* wPtr = new double[n];
    double* rPtr = new double[n];

    unsigned int i = 0;
    while(getline(ifs,line)){
        istringstream convert(line);
        convert >> *(wPtr+i) >> separator >> *(rPtr+i);
        i++;
    }
    ifs.close();

    double rate = 0;
    rate = UtilsLibrary::dot_product(n,wPtr,rPtr);

    double V = (1+rate)*S;

    ofs << fixed;

    ofs << "S = " << setprecision(0) << S << ", n = " << n << endl;
    ofs << "w = [ ";
    for (unsigned int i = 0; i<n; i++){
        ofs << setprecision(2) << *(wPtr+i) << " ";
    }
    ofs << "]" <<endl;
    ofs << "r = [ ";
    for (unsigned int i = 0; i<n; i++){
        ofs << setprecision(2) << *(rPtr+i) << " ";
    }
    ofs << "]" <<endl;
    ofs << "Rate of return of the portfolio: " << setprecision(4) << rate << endl;
    ofs << "V: " << setprecision(2) << V << endl;

    ofs.close();

    delete [] wPtr;
    delete [] rPtr;

    return 0;
}

