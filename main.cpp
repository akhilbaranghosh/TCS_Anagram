#include <bits/stdc++.h>
using namespace std;
char rotate_first(string array,char direction,int rotate){
    int left=0;
    int right=array.size()-1;
    if(rotate%array.size()!=0){
        if(direction=='L'){
            right=(right+rotate)%array.size();
            left=(left+rotate)%array.size();
        }
        else if(direction=='R'){
            int l=left-rotate;
            int r=right-rotate;
            if(l<0&&r>=0){
                left=array.size()+l;
                right=r;
            }
            else if(l>=0&&r<0){
                right=array.size()+r;
                left=l;
            }
            else if(l>=0&&r>=0){
                left=l;
                right=r;
            }
        }
    }
    return array[left];
}
string form_string(string s,vector<pair<char,int>> operation){
    string str="";
    for(int i=0;i<operation.size();i++){
        str=str+rotate_first(s,operation[i].first,operation[i].second);
    }
    return str;
}
int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<pair<char,int>> operation(n);
    for(int i=0;i<n;i++){
        cin >> operation[i].first >> operation[i].second;
    }
    unordered_map<char,int> m;
    string str=form_string(s,operation);
    for(int i=0;i<str.size();i++){
        if(m.find(str[i])==m.end()){
            m[str[i]]=1;
        }
        else{
            m[str[i]]++;
        }
    }
    stack<char> st;
    int count=str.size();
    for(int i=0;i<n;i++){
        if(m.find(s[i])!=m.end()&&str[i]>0){
            m[s[i]]--;
            st.push(s[i]);
            count--;
        } else{
            while (!st.empty()){
                m[st.top()]++;
                st.pop();
                count++;
            }
        }
        if(count==0)break;
    }
    if(count==0)cout << "Anagram found" << endl;
    else cout << "Not found" << endl;
}