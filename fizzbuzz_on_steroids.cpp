#include <iostream>
using namespace std;

struct Mapping {
    int digit;
    string word;
};
const __uint128_t MAX_DECIMAL_PLACES = 1e14;

Mapping mappings[] = {{3, "Fizz"}, {5, "Buzz"}, {7, "Boom"}};
const int num_mappings = sizeof(mappings) / sizeof(mappings[0]);

bool is_divisible(int num, int n) {
    int div = num / n;
    return div * n == num;
}

bool is_integer(double num) {
    int one = num / num;
    int temp = one * num;
    return temp == num;
}

int get_integer_part(double num) {
    return num; 
}

int count_prime_power(int num, int prime) {
    int count = 0;
    while (is_divisible(num, prime)) {
        num /= prime;
        count++;
    }
    return count;
}

void solve_decimal(double num) {
    // int temp = num;
    // num -= temp;
    __uint128_t scaled_num = (__uint128_t)(num * MAX_DECIMAL_PLACES);
    
    while (scaled_num > 0) {
        __uint128_t divisor = 1;
        __uint128_t temp = scaled_num;
        while (temp >= 10) {
            temp /= 10;
            divisor *= 10;
        }
        
        int digit = scaled_num / divisor;
        scaled_num = scaled_num - (digit * divisor);
        
        if (digit == 0) {
            break;
        }
        
        for (int i = 0; i < num_mappings; i++) {
            if (digit == mappings[i].digit) {
                cout << mappings[i].word;
            }
        }
        
    }
    cout << "\n";
}
void solve_decimal_counter(double num) {
    // int temp = num;
    // num -= temp;
    __uint128_t scaled_num = (__uint128_t)(num * MAX_DECIMAL_PLACES);
    
    int counter[num_mappings] = {};

    while (scaled_num > 0) {
        __uint128_t divisor = 1;
        __uint128_t temp = scaled_num;
        while (temp >= 10) {
            temp /= 10;
            divisor *= 10;
        }
        
        int digit = scaled_num / divisor;
        scaled_num = scaled_num - (digit * divisor);
        
        if (digit == 0) {
            break;
        }
        
        for (int i = 0; i < num_mappings; i++) {
            if (digit == mappings[i].digit) {
                counter[i]++;
            }
        }
        
    }

    for (int i = 0; i < num_mappings; i ++) {
        cout << mappings[i].word << ": " << counter[i] << '\n';
    }
    cout << "\n";
}

void solve_divis(int num) {
    bool hasOutput = false;
    
    for (int i = 0; i < num_mappings; i++) {
        if (is_divisible(num, mappings[i].digit)) { 
            cout << mappings[i].word;
            hasOutput = true;
        }
    }
    if (hasOutput) cout << '\n';

    if (!hasOutput) {
        cout << num << "\n";
    }
}
void solve_divis_counter(int num) {
    int counter[num_mappings];
    for (int i = 0; i < num_mappings; i++) {
        counter[i] = 0;
        int power = count_prime_power(num, mappings[i].digit);
        if (power > 0) {
            for (int j = 0; j < power; j++) counter[i]++;
        }
        cout << mappings[i].word << ": " << counter[i] << '\n';
    }
    cout << '\n';
}

int main() {
    double m;
    cin >> m;

    if (is_integer(m)) {
        bool counters;
        cout << "Write 1 for Counter.\nWrite 0 for no Counter.\n";
        cin >> counters;
        if (counters) {
            cout << "Write 0 for decimal representation instances count \nWrite 1 for count of prime factors.\n";
            bool primex;
            cin >> primex;
            cout << '\n';
            if (primex) {
                int int_num = get_integer_part(m);
                for (int j = 1; j <= int_num; j++) {
                    cout << j << ": ";
                    solve_divis_counter(j);
                }
                return 0;
            }
            for (double j = 1; j <= m; j++) {
                cout << j << ": ";
                solve_decimal_counter(j);
            }
            return 0;
        }


        cout << "Write 0 for decimal representation instances \nWrite 1 for divisibility check.\n";
        bool primex;
        cin >> primex;
        cout << '\n';
        if (primex) {
            int int_num = get_integer_part(m);
            for (int j = 1; j <= int_num; j++) {
                cout << j << ": ";
                solve_divis(j);
            }
            return 0;
        }
        for (double j = 1; j <= m; j++) {
            cout << j << ": ";
            solve_decimal(j);
        }
        return 0;
    }

    bool counters;
    cout << "Write 1 for Counter.\nWrite 0 for no Counter.\n";
    cin >> counters;
    if (counters){ 
        solve_decimal_counter(m);
        return 0;
    }
    solve_decimal(m);
}