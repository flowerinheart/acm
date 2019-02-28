//用两个数组或者一个hashtable都能解决
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for (int i = 0; i < maxNumbers; ++i) {
            hash.insert(i);
        }
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (hash.empty()) {
            return -1;
        }
        int ret = *(hash.begin());
        hash.erase(hash.begin());
        return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return hash.count(number) > 0;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        hash.insert(number);
    }
private:
    unordered_set<int> hash;
};
