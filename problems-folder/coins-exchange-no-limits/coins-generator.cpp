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


void generateTestCase(int caseNum) {
    int amount;
    vector<int> coins;
    vector<int> expectedRes; 
    bool isChangePossible = true;

    switch (caseNum) {
        case 1:
            amount = 10;
            coins = {5, 1, 2};
            expectedRes = { 2, 0, 0 };
            break;
        case 2:
            amount = 123;
            coins = {1, 2, 5, 10, 20, 50, 100, 200};
            expectedRes = { 1, 1, 0, 0, 1, 0, 1, 0 };
            break;
        case 3:
            amount = 123;
            coins = { 2, 5, 10, 20, 50, 100, 200 };
            expectedRes = { 4, 1, 1, 0, 0, 1, 0 };
            break;
        case 4:
            amount = 23;
            coins = {1};
            expectedRes = { 23 };
            break;
        case 5:
            amount = 23;
            coins = {2};
            isChangePossible = false;
            break;
        case 6:
            amount = 23;
            coins = {50};
            isChangePossible = false;
            break;
        default:
            return; // End generation if caseNum is out of range
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
    flushOut(); // Ensure all stdout data is written

    // Prepare stderr output
    if (!isChangePossible) {
        printErr("null\n"); // If change is not possible, indicate with "null"
    } else {
        for (int change : expectedRes) {
            printErr(to_string(change).c_str());
            printErr(" ");
        }
        printErr("\n");
    }
    flushErr(); // Ensure all stderr data is written last
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <case number>" << endl;
        return 1;
    }

    int caseNum = atoi(argv[1]);
    generateTestCase(caseNum);
    return 0;
}
