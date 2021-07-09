//Student ID: 20434384
// Limerick.cpp
// 2a-Lab-01
#include <iostream>
#include <sstream> //need this for istringstream below

#include <cmath> //needed for sqrt
#include <cstdlib> //for exit()

using namespace std; 
double eval_limerick(int dozen, int gross, int score) {
    return (dozen + gross + score + (3*sqrt(4)))/7 + 5 + 11 + 39; 
}
int main(int argc, char **argv) {
    int dozen, gross, score;
    if (argc < 4) {
        cerr << "Usage: limerick dozen-val gross-val score-val\n";
        exit(1);
    }
    istringstream(argv[1]) >>dozen;
    istringstream(argv[2]) >>gross;
    istringstream(argv[3]) >>score;
    // Invoke the eval_limerick function correctly and print the result
    // with a single newline at the end of the line. 
    double result = eval_limerick(dozen, gross, score);
    cout << result << endl;    
    return 0; 
}
