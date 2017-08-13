#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

size_t hash_func(const string& s) {
    static const size_t multiplier = 263;
    static const size_t prime = 100003;
    unsigned long long hash = 0;
    for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * multiplier + s[i]) % prime;
    return hash;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

vector<int> precompute(const string t, const string s){

    int l=t.size()-s.size();
    vector<int> hash(l+1);
    hash[l] = hash_func(t.substr(l, s.size()));
    int y=1;
    for(int j=1;j<=s.size();j++){
        y = (y*263) % 100003;
    }
    //cout<<l;
    for (int i = l-1; i>=0; i--) {
         hash[i] = (263*hash[i+1] + t[i] - t[i+s.size()]*y)%100003;
         hash[i] = (hash[i]+100003) % 100003;
    }
    return hash;

}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    std::vector<int> ans;
    vector<int> hash=precompute(t,s);
    int phash=hash_func(s);
    for (size_t i = 0; i + s.size() <= t.size(); ++i){
        if(phash==hash[i]){
            if (t.substr(i, s.size()) == s)
                ans.push_back(i);
        }
    }
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
