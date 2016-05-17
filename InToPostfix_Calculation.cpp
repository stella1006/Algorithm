#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <set>
#define LL long long
#define ULL unsigned long long 
#define INF 1<<30 
#define Mod 1000000007
#define PII pair<int,int>
#define mk make_pair
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a<b?b:a)
using namespace std;
const double PI=acos(-1.0);
const double EPS=1e-12;
#define N 1000000
#define LL long long
#define lowbit(x) x&(-x)
LL tree[N + 10];

/*

inline int read() {
    static char ch;
    bool sgn = false;
    while (ch = getchar(), ch < '0' || ch > '9') if (ch == '-') sgn = true;
    int res = ch - 48;
    while (ch = getchar(), ch >= '0' && ch <= '9') res = res * 10 + ch - 48;
    return sgn ? -res : res;
}

*/

long long power(long long a, long long b)
{
    long long ans = 1;
    for(int i = 0; i < b; i++)
        ans *= a;
    return ans;
}

bool prior(char stacktop, char input) {
    bool ret = true;
    switch(stacktop) {
        case '+':
        case '-':
            switch(input) {
                case '*':
                case '^':
                    ret = false;
                    break;
            }
        case '*':
            switch(input) {
                case '^':
                    ret = false;
                    break;
            }
        break;
    }
    return ret;
}
string InToPostfix(string infix) {
    string postfix;
    stack<char> temp;
    for(int i = 0; i < infix.length(); i++) {
        if(infix[i] == ' ')
            continue;
        if(infix[i] == '(')
            temp.push(infix[i]);
        else if(infix[i] == ')') {
            while(!temp.empty() && temp.top() != '(') {
                postfix += temp.top();
                temp.pop();
            }
            temp.pop();
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '^') {
            while(!temp.empty() && temp.top() != '(' && prior(temp.top(), infix[i])) {
                postfix += temp.top();
                temp.pop();
            }
            temp.push(infix[i]);
        }
        else {
            if(isdigit(infix[i])) {
                while(i < infix.length() && isdigit(infix[i]))
                {
                    postfix += infix[i];
                    i++;
                }
                i--;
                postfix += "#";     //区别这个是常数
            }
            else
                postfix += infix[i];
        }
    }
    while(!temp.empty()) {
        postfix += temp.top();
        temp.pop();
    }
    //cout << postfix << endl;
    return postfix;
}
LL cal(string res, int a) {
    stack<LL> ans;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == 'a') ans.push(a);
        else if (isdigit(res[i])) {
            long long tmp = 0;
            while(i < res.size() && isdigit(res[i]))
            {
                tmp = tmp*10 + (res[i] - '0');
                i++;
            }
            i--;
            ans.push(tmp);
        }
        else {
            if (res[i] == '#') continue;
            LL a = ans.top();
            ans.pop();
            LL b = ans.top();
            ans.pop();
            if (res[i] == '+') ans.push(a + b);
            else if (res[i] == '-') ans.push(b - a);
            else if (res[i] == '*') ans.push(b * a);
            else if (res[i] == '^') ans.push(power(b, a));
            //cout << ans.top() << endl;
        }
    }
    LL ress = ans.top();
    return ress;
}


int main() {
    //a*a^2+a^3
    string origin;
    string s;
    getline(cin, origin, '\n');
    int k;
    cin >> k;
    s = InToPostfix(origin);
    getchar();
    for (int i = 0; i < k; i++) {
        
        string str = "";
        getline(cin, str, '\n');
        bool flag = true;
        if (str == "") continue;
        string nstr = InToPostfix(str);
        for (int j = 0; j < 10; j++) {
            LL sum1 = cal(s, j);
            LL sum2 = cal(nstr, j);
            //cout << sum1 << " " << sum2 << endl;
            if (sum1 != sum2) {
                flag = false;
                break;
            }
        }
        if (flag) cout << (char)('A' + i);

    }
 
    cout << endl;
   //system("pause");
    return 0;
    //a2#^2#a*1#*+1#2#^+10#+10#-a+a-
}                   