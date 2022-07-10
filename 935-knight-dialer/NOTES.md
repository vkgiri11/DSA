Classic Approach
class Solution {
public:
bool isValid(int x, int y, vector<vector<int>> &keypad) {
if(x < 0 || x > 3 || y < 0 || y > 2)
return 0;
if(!keypad[x][y]) return 0;
else return 1;
}
int f(int x, int y, int n, vector<vector<int>> &keypad) {
if(n == 1) return 1;
int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {2,2,1,-1,-2,-2,1,-1};
int count = 0;
for(int i = 0; i < 8; i++) {
int newX = x + dx[i];
int newY = y + dy[i];
if(isValid(newX, newY, keypad))
count += f(newX, newY, n-1, keypad);
}
return count;
}
int knightDialer(int n) {
int ans = 0;
int mod = 1e9+7;
if(n == 1) return 10;
vector<vector<int>> keypad(4, vector<int>(3, 1));
keypad[3][0] = 0;
keypad[3][2] = 0;
for(int i = 0; i < 4; i++)
for(int j = 0; j < 3; j++) {
if(keypad[i][j])
ans += f(i, j, n, keypad) % mod;
}
return ans;
}
};