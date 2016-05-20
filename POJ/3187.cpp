#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int c(int n, int k)
{
    int result = 1;
    for (int i = 0; i < k; ++i)
    {
        result = result * (n - i) / (i + 1);
    }
 
    return result;
}
int main(int argc, char *argv[])
{
    int N, Sum;
    cin >> N >> Sum;
    int line[16];
    int i = 0;
    for (; i < N; ++i)
    {
        line[i] = i + 1;
    }
    do 
    {
        int result = 0;
        for (i = 0; i < N; ++i)
        {
            result += c(N - 1, i) * line[i];
        }
        if (result == Sum)
        {
            break;
        }
    } while (next_permutation(line, line + N));
    copy(line, line + N, ostream_iterator<int>(cout, " "));
    return 0;
}
