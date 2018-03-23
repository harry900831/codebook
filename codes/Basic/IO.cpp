#define getchar_unlocked getchar
#define putchar_unlocked putchar

template <typename T>
inline bool getint(T& x) {
  char __c = 0;
  bool flag = false;
  while (__c = getchar_unlocked(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar_unlocked(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template<class T>
void putint(T ___)
{
  char buf[1000];
  int _=0;
  if(___<0) putchar_unlocked('-'),___=___*-1;
  do
  {
    buf[_++]='0'+(___%10);
    ___=___/10;
  }while(___>0);
  for(_=_-1;_>=0;_--)
    putchar_unlocked(buf[_]);
}
