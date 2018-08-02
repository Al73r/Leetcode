#include "iostream"
#include "map"
#include "vector"
using namespace std;

int main() {
    //map<int, map<int,int> > map_;  
    //map<int, map<int,int>>::const_iterator itr1 = map_.begin();  
    //const auto itr2 = map_.begin();  
    auto ptr = []()  
    {  
        std::cout << "hello world" << std::endl;  
    };  
    ptr();
    vector<int> buf(10);
    for(auto iv: buf) {
        cout << iv << endl;
    }
    return 0;
}