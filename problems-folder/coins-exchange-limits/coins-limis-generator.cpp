#include <bits/stdc++.h>
using namespace std;

// Custom output handling for stdout
char bufferOut[4096];
char* out = bufferOut;
void flushOut() { fwrite(bufferOut, 1, out - bufferOut, stdout); out = bufferOut; }
void printOut(int x) { out += sprintf(out, "%d", x); }
void printOut(char c) { *out++ = c; }

// Custom output handling for stderr
char bufferErr[4096];
char* err = bufferErr;
void flushErr() { fwrite(bufferErr, 1, err - bufferErr, stderr); err = bufferErr; }
void printErr(const char* str) { while (*str) *err++ = *str++; }


void generateTestCaseWithLimits(int caseNum) {
    int amount;
    vector<int> coins;
    vector<int> limits;
    vector<int> expectedResChange; 
    bool isChangePossible = true;

    switch (caseNum) {
        case 1:
            amount = 10;
            coins = {5, 1, 2};
            limits = {1, 20, 10};
            expectedResChange = { 1, 1, 2 };
            break;
        case 2:
            amount = 123;
            coins = {1, 2, 5, 10, 20, 50, 100, 200};
            limits = {99999, 99999, 99999, 99999, 99999, 99999, 99999, 99999};
            expectedResChange =  { 1, 1, 0, 0, 1, 0, 1, 0 };
            break;
        case 3:
            amount = 123;
            coins = {2, 5, 10, 20, 50, 100, 200};
            limits = {99999, 99999, 99999, 99999, 99999, 99999, 99999};
            expectedResChange = { 4, 1, 1, 0, 0, 1, 0 };
            break;
        case 4:
            amount = 123;
            coins = {1, 2, 5, 10, 20, 50, 100, 200};
            limits = {0, 99999, 99999, 99999, 99999, 99999, 99999, 99999};
            expectedResChange = { 0, 4, 1, 1, 0, 0, 1, 0 };
            break;
        case 5:
            amount = 123;
            coins = {1, 2, 5, 10, 20, 50, 100, 200};
            limits = {99999, 99999, 3, 4, 3, 0, 0, 99999};
            expectedResChange = { 0, 4, 3, 4, 3, 0, 0, 0 };
            break;
        case 6:
            amount = 23;
            coins = {1, 2, 5};
            limits = {99999, 99999, 3};
            expectedResChange = { 0, 4, 3 };
            break;
        case 7:
            amount = 23;
            coins = { 5, 1, 2 };
            limits = { 3, 2, 3, 3 };
            expectedResChange = { 2, 3, 5 };
            break;
        case 8:
            amount = 23;
            coins = { 5, 5, 1, 2 };
            limits = { 3, 2, 3, 3 };
            expectedResChange = { 3, 1, 1, 1 };
            break;
        case 9:
            amount = 23;
            coins =  { 2, 137, 65, 35, 30, 9, 123, 81, 71 };
            limits = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
            expectedResChange = { 1, 0, 1, 1, 1, 1, 0, 0, 0 };
            break;
        case 10:
            amount = 23;
            coins = {2};
            limits = vector<int>(15, 1); 
            // expectedResChange = "null";
            isChangePossible = false; 
            break;
        case 11:
            amount = 23;
            coins = {50};
            limits = {1}; 
            // expectedResChange = "null"; 
            isChangePossible = false;
            break;
        case 12:
            amount = 23;
            coins = {1};
            // limits = vector<int>(20, 1);
            isChangePossible = false;
            break;

        default:
            return; 
    }

    // Output the test case data to stdout
    printOut(amount);
    printOut(' ');
    printOut(static_cast<int>(coins.size()));
    printOut('\n');
    for (int coin : coins) {
        printOut(coin);
        printOut(' ');
    }
    printOut('\n');
    for (int limit : limits) {
        printOut(limit);
        printOut(' ');
    }
    printOut('\n');
    flushOut(); // Ensure all stdout data is written

    // Prepare stderr output
    string stderrOutput;

    if (!isChangePossible) {
        // If change is not possible, prepare "null" for stderr output
        stderrOutput = "null\n";
    } else {
        // If change is possible, prepare the expected change list for stderr output
        stringstream ss;
        for (size_t i = 0; i < expectedResChange.size(); ++i) {
            ss << expectedResChange[i];
            if (i + 1 < expectedResChange.size()) ss << " ";
        }
        stderrOutput = ss.str() + "\n";
    }

    // Write to stderr after all stdout data has been written
    printErr(stderrOutput.c_str());
    flushErr(); // Ensure all stderr data is written last


}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <case number>" << endl;
        return 1;
    }

    int caseNum = atoi(argv[1]);
    generateTestCaseWithLimits(caseNum);
    return 0;
}
