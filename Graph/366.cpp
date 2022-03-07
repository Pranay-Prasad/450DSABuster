// A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

// Every adjacent pair of words differs by a single letter.
// Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
// sk == endWord
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

#include<bits/stdc++.h>
using namespace std;
int solve(string a,string b,vector<string>&words){
    if(find(words.begin(),words.end(),b)==words.end()) return 0;
    set<string>s;
    for(auto w:words){
        s.insert(w);
    }
    queue<string>q;
    q.push(a);
    int ans = 0;
    while(!q.empty()){
        ans++;
        int n = q.size();
        while(n--){
            string curr = q.front();
            q.pop();
            for(int i = 0; i < curr.length();i++){
                string temp = curr;
                for(char c = 'a';c <= 'z';c++){
                    temp[i] = c;
                    if(temp == curr){
                        continue;
                    }
                    if(temp == b){
                        return ans + 1;
                    }
                    if(s.find(temp) != s.end()){
                        q.push(temp);
                        s.erase(temp);
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    string begin,end;
    cin>>begin>>end;
    int n;
    cin>>n;
    vector<string>words(n);
    for(int i = 0; i <n;i++){
        cin>>words[i];
    }
    cout<<solve(begin,end,words)<<endl;
    return 0;
}