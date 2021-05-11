#include <bits/stdc++.h>
using namespace std;
void set_mines(int k, int l, int m)
{
int num_count[l][m];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            num_count[i][j] = 0;
        }
    }
    string mines[l][m];
    for (int i = 0; i < k;)
    {
        int x = rand() % l;
        int y = rand() % m;
        if (mines[x][y] == "$")
            continue;
        else
        {
            i++;
            mines[x][y] = "$";
            num_count[x][y]=-1;
            if (num_count[x - 1][y] == 0)
            {
                num_count[x - 1][y] = 1;
            }
            if (num_count[x + 1][y] ==0)
            {
                num_count[x + 1][y] = 1;
            }
            if (num_count[x][y - 1] == 0)
            {
                num_count[x][y - 1] = 1;
            }
            if (num_count[x][y + 1] == 0)
            {
                num_count[x][y + 1] = 1;
            }
            if (num_count[x - 1][y + 1] == 0)
            {
                num_count[x - 1][y + 1] = 1;
            }
            if (num_count[x + 1][y - 1] == 0)
            {
                num_count[x + 1][y - 1] = 1;
            }
            if (num_count[x - 1][y - 1] == 0)
            {
                num_count[x - 1][y - 1] = 1;
            }
            if (num_count[x + 1][y + 1] == 0)
            {
                num_count[x + 1][y + 1] = 1;
            }
            
        }
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mines[i][j] == "$")
                cout << " " << mines[i][j] << " ";
            else
                cout << " "
                     << "*"
                     << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << " " << num_count[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int r, c, n;
    cout << "enter the number of rows: ";
    cin >> r;
    cout << "enter the number of columns: ";
    cin >> c;
    cout << "enter the number of mines: ";
    cin >> n;
    set_mines(n, r, c);
}