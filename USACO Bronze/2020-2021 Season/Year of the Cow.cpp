#include <iostream>
#include <map>

using namespace std;

int get_year(string w)
{
    if (w == "Ox")
        return 1;
    if (w == "Tiger")
        return 2;
    if (w == "Rabbit")
        return 3;
    if (w == "Dragon")
        return 4;
    if (w == "Snake")
        return 5;
    if (w == "Horse")
        return 6;
    if (w == "Goat")
        return 7;
    if (w == "Monkey")
        return 8;
    if (w == "Rooster")
        return 9;
    if (w == "Dog")
        return 10;
    if (w == "Pig")
        return 11;
    return 12;
}

int get_month(int n)
{
    return (n - 1) % 12 + 1;
}

map<string, int> input;

int main()
{
    input["Bessie"] = 1;

    int N;
    cin >> N;
    string tmp[8];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> tmp[j];
        }

        int diff = abs(input[tmp[7]] - get_year(tmp[0]));
        if (tmp[3] == "previous")
        {
            int dx = get_month(input[tmp[7]]) - get_year(tmp[4]);
            if (dx < 0)
                dx += 12;
            input[tmp[0]] = input[tmp[7]] - dx;
            cout << dx << "\n";
        }
        else
        {
            int dx = get_year(tmp[4]) - get_month(input[tmp[7]]);
            if (dx > 0)
                dx -= 12;
            input[tmp[0]] = input[tmp[7]] + dx;
            cout << dx << "\n";
        }

        cout << tmp[0] << " " << input[tmp[0]] << "\n";
    }

    cout << abs(input["Bessie"] - input["Elsie"]) << "\n";

    return 0;
}
