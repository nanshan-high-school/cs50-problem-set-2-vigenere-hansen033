#include <iostream>
#include <stdio.h>
using namespace std;

int lock( int a, int b ){//只能是英文字母，都會變小寫
  if( b >= 'A' && b <= 'Z' ){
    b -= 'A';
  } else if( b >= 'a' && b <= 'z' ){
    b -= 'a';
  } else{
    cout << "key ERROR!";
    return 0;
  }
  if( a >= 'A' && a <= 'Z' ){
    a += ('a' - 'A' + b);
  } else if( a >= 'a' && a <= 'z' ){
    a += b;
  } else{
    return a;
  }
  if( a > 'z' ){
    a -= 26;//超出z
  }
  return a;
}

int main() {
  int longc, longp, i;
  cout << "請輸入明文有多長:";
  cin >> longc;
  char content[longc + 1];
  char out[longc + 1];
  cout << "請輸入明文";
  i = cin.get();//清除快取 
  fgets(content, sizeof(content), stdin);
  cout << "請輸入密碼有多長:";
  cin >> longp;
  char password[longp + 1];
  cout << "請輸入密碼";  
  i = cin.get();  
  fgets(password, sizeof(password), stdin);
  for( int t = 0 ; t <= longc + 1 ; t ++ ){
  	out[t] = lock(content[t], password[t % longp]);
  }
  cout << "密文:";
  for( int t = 0 ; t < longc ; t ++ ){
  	cout << out[t];
  }
  system("Pause");
  return 0;
}
