bool substring_search(string s, string key) {
    int count = 0;
    for(int i = 0; i<(int)s.size(); i++) {
        if(s[i] == key[count]) count++;
        if(count == (int)key.size()) return true;
    }
    return false;
}
