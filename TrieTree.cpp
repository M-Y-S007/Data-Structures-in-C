//字典树（前缀树），用来存储和查询字符串
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int next1[MAXN][26], cnt;
bool isEnd[MAXN];
int wordCount[MAXN];
void init(){
    memset(next1, 0, sizeof(next1));
    memset(isEnd, 0, sizeof(isEnd));
    memset(wordCount, 0, sizeof(wordCount));
    cnt = 1;
}
void insert(const string &s){//插入操作
    int cur = 1;
    for(auto c : s){
        if(!next1[cur][c - 'a'])
            next1[cur][c - 'a'] = ++cnt;
        cur = next1[cur][c - 'a'];
        wordCount[cur]++;
    }
    isEnd[cur] = true;
}
bool search(const string &s){//找单词
    int cur = 1;
    for(auto c : s){
        if(!next1[cur][c - 'a'])
            return false;
        cur = next1[cur][c - 'a'];
    }
    return isEnd[cur];
}
bool removeHelper(int cur, const string &s , int depth){
    if(depth == s.length()){
        if(!isEnd[cur]) return false;
        isEnd[cur] = false;

        for(int i = 0; i < 26; i++){
            if(next1[cur][i]) return false;
        }
        return true;
    }

    int ch = s[depth] - 'a';
    if(!next1[cur][ch]) return false;

    bool shouldDelete = removeHelper(next1[cur][ch], s, depth + 1);

    wordCount[next1[cur][ch]]--;

    if(shouldDelete){
        next1[cur][ch] = 0;

        for(int i = 0; i < 26; i++){
            if(next1[cur][i]) return false;
        }
        return !isEnd[cur];
    }
    return false;
}
bool remove(const string &s){
    return removeHelper(1, s, 0);
}
bool find_prefix(const string &s){//找前缀
    int cur = 1;
    for(auto c : s){
        if(!next1[cur][c - 'a'])
            return false;
        cur = next1[cur][c - 'a'];
    }
    return true;
}
int countWordWithPrefix(const string &prefix){
    int cur = 1;
    for(auto c : prefix){
        if(!next1[cur][c - 'a'])
            return 0;
        cur = next1[cur][c - 'a'];
    }
    return wordCount[cur];
}
bool isEmpty(){
    for(int i = 0; i < 26; i++)
        if(next1[1][i]) return false;
    return true;
}
int main(){

    return 0;
    
}