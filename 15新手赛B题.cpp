// Problem#: 17264
// Submission#: 4399800
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int score[100001];

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int n, x1, A, B,C;
        int m1, m2, m3;
        cin >> n;
        memset(score, 0, sizeof(score));
        cin >> x1 >> A >> B >> C;
        score[0] = x1;
        m1 = 0, m2 = 0, m3 = x1;
        for (int j = 1; j <n; j++) {
            score[j] = (score[j-1] * A + B) % C;
            if (score[j] >= m3) {
                m1 = m2;
                m2 = m3;
                m3 = score[j];
            } else if (score[j] >= m2) {
                m1 = m2;
                m2 = score[j];
            } else if(score[j] >= m1) {
                m1 = score[j];
            } else {
                continue;
            }
        }
        cout << "Case #" << i << ": " << m1 + m2 + m3 << endl;

        
    }

    
    return 0;
}                                 
