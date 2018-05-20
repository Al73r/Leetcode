class Solution {
public:
    bool isScramble(string s1, string s2) {
        cache.clear();
        return isScramble(s1.begin(), s1.end(), s2.begin());
    }
private:
    typedef string::const_iterator Iterator;
    map<tuple<Iterator, Iterator, Iterator>, bool> cache;
    bool isScramble(Iterator first1, Iterator last1, Iterator first2){
        auto length = distance(first1, last1);
        auto last2 = next(first2, length);
        if(length==1) return *first1 == *first2;

        for(int i=1; i<length; i++){
            if((getOrUpdate(first1, first1+i, first2) &&
                getOrUpdate(first1+i, last2-i))
                || (getOrUpdate(first1, first1+i, last2-i) &&
                    getOrUpdate(first1+i, last1, first2)))
                return true;
        }
        return false;
    }
    bool getOrUpdate(Iterator first1, Iterator last1, Iterator first2){
        auto key = make_tuple(first1, last1, first2);
        auto pos = cache.find(key);
        return (pos != cache.end() ?
                pos.second : (cache[key] = isScramble(first1, last1, first2)));
    }
};