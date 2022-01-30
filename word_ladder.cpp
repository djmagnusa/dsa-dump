#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> myset;
        
        bool isPresent = false;
        
        for(auto word : wordList)
        {
            if(targetWord.compare(word)==0)
            {
                isPresent = true;
            }
            
            myset.insert(word);
        }
        
        if(!isPresent)
        {
            return 0;
        }
        
        queue<string> q;
        int depth = 0;
        q.push(startWord);
        
        while(!q.empty())
        {
            depth += 1;
            int lsize = q.size();
            
            while(lsize--)
            {
                auto curr = q.front();
                q.pop();
                
                for(int i=0;i<curr.length();i++)
                {
                    string temp = curr;
                    
                    for(char c='a';c<='z';c++)
                    {
                        temp[i] = c;
                        
                        if(temp.compare(curr)==0)
                        {
                            continue; //skip same word;
                        }
                        
                        if(temp.compare(targetWord)==0)
                        {
                            return depth+1; //target word found
                        }
                        
                        if(myset.find(temp)!=myset.end()) //word is in the set
                        {
                            q.push(temp);
                            myset.erase(temp);
                        }                        
                    }
                }
            }
        }
        
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
} 