#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class PrefixArray
{
private:
    int N;
    vector<int> prefix_sum_array;
    vector<int> prefix_xor_array;

    void _construct_prefix_arrays(vector<int> &arr)
    {
        this->N = arr.size();
        if (arr.size() == 0)
        {
            return;
        }

        this->prefix_sum_array = arr;
        this->prefix_xor_array = arr;

        for (int i = 1; i < arr.size(); i++)
        {
            this->prefix_sum_array[i] += this->prefix_sum_array[i - 1];
            this->prefix_xor_array[i] ^= this->prefix_xor_array[i - 1];
        }
    }

public:
    PrefixArray(vector<int> &arr)
    {
        this->_construct_prefix_arrays(arr);
    }

    int range_sum_query(int l, int r)
    {
        if (l < 0 || r >= this->N)
        {
            return INT_MIN;
        }
        if (l == 0)
        {
            return this->prefix_sum_array[r];
        }
        return this->prefix_sum_array[r] - this->prefix_sum_array[l - 1];
    }

    int range_xor_query(int l, int r)
    {
        if (l < 0 || r >= this->N)
        {
            return INT_MIN;
        }
        if (l == 0)
        {
            return this->prefix_xor_array[r];
        }
        return this->prefix_xor_array[r] ^ this->prefix_xor_array[l - 1];
    }
};

int main()
{
    int n, q;
    cout << "Enter the number of elements in the array and number of range queries \n";
    cin >> n >> q;

    vector<int> inputArray(n);
    cout << "Enter the array elements \n";
    for (int i = 0; i < n; i++)
    {
        cin >> inputArray[i];
    }

    PrefixArray arr(inputArray);

    cout << "Enter " << q << " queries in the form l r \n";
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << arr.range_sum_query(l, r) + arr.range_xor_query(l, r) << endl;
    }

    return 0;
}
