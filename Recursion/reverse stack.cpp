https://www.geeksforgeeks.org/problems/reverse-a-stack/1

class Solution {
  public:
    void reverseStack(stack<int> &st) {
        // code here
        vector<int> a;
        while(!st.empty()){
            a.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<a.size();i++){
            st.push(a[i]);
        }
    }
};