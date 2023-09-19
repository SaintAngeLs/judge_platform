
#include <bits/stdc++.h>
#include <random>



#ifdef putchar
#undef putchar
#endif
#define putchar(x) (*_pout++=(x), (_pout==_eout?(fwrite(_pout=_out, 1, 4096, stdout)):0))
#define flush() fwrite(_out, 1, _pout-_out, stdout)
char _oute[4097], *_eoute=_oute+4096, *_poute=_oute;

#define flushe() fwrite(_oute, 1, _poute-_oute, stderr)

#define print(x) do{ \
    int _temp_x = (x); \
    if(!_temp_x) putchar('0'); \
    else{ \
        while(_temp_x) { \
            *_p++ = '0' + _temp_x % 10; \
            _temp_x /= 10; \
        } \
        do putchar(*--_p); \
        while(_p != _buf); \
    } \
} while(0)

#define printe(x) do{ \
    int _temp_xe = (x); \
    if(!_temp_xe) putchare('0'); \
    else{ \
        while(_temp_xe) { \
            *_pe++ = '0' + _temp_xe % 10; \
            _temp_xe /= 10; \
        } \
        do putchare(*--_pe); \
        while(_pe != _bufe); \
    } \
} while(0)

#define putchare(x) (*_poute++=(x), (_poute==_eoute?(fwrite(_poute=_oute, 1, 4096, stderr)):0))
char _bufe[20], *_pe=_bufe;



char _out[4097], *_eout=_out+4096, *_pout=_out;

char _buf[20], *_p=_buf;


std::mt19937 random_engine(0xdeadbeef);

using namespace std;

vector<vector<int>> get_permutation(vector<int> lst) {
    if (lst.empty()) return {};
    if (lst.size() == 1) return {lst};
    vector<vector<int>> perms;
    for (int i = 0; i < lst.size(); i++) {
        int current = lst[i];
        vector<int> rem_list = lst;
        rem_list.erase(rem_list.begin() + i);
        vector<vector<int>> rem_perm = get_permutation(rem_list);
        for (auto p : rem_perm) {
            perms.push_back({current});
            perms.back().insert(perms.back().end(), p.begin(), p.end());
        }
    }
    return perms;
}

int randint(int a, int b) {
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(random_engine);
}


void generate_test(int N) {
   set<int> unique_data;
    while(unique_data.size() < N) {
        unique_data.insert(randint(1, 100));
    }
    vector<int> data(unique_data.begin(), unique_data.end());


    //print(data.size());
    //putchar('\n');
    for(int num : data) {
        print(num);
        putchar(' ');
    }
    putchar('\n');
    flush();
    
    // Print expected output to stderr
    vector<vector<int>> perms = get_permutation(data);
    for(auto perm : perms) {
        for(int num : perm) {
            printe(num);
            putchare(' ');
        }
        putchare('\n');
    }
    flushe();
}

int main(int argc, char **argv) {
    int T = atoi(argv[1]);
    // for(int t=0; t<T; t++) {
    //     int N = randint(1, 7); // Restricting size to 7 to ensure reasonable output size.
    //     generate_test(N);
    // }
    

    switch(T) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            generate_test(T);  // Generate test for the specified size
            break;
        default:
            cerr << "Invalid size. Choose between 1 to 17." << endl;
            return 1;
    }
    
    //flush();
    return 0;
}
