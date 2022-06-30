#include <iostream>
#include <vector>
// IN this we have to search and element in 2-d matrix
using namespace std;
class search2dmatrix
{
private:
    vector<vector<int>> matrix;
    int target; // Element to be searched in the matrix

public:
    search2dmatrix()
    {
        int row, column;
        cin >> row >> column;
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            for (int j = 0; j < column; j++)
            {
                int tempvar;
                cin >> tempvar;
                temp.push_back(tempvar);
            }
            matrix.push_back(temp);
        }
        cout << "Enter the element to be searched " << endl;
        cin >> target;
    }
    bool ispresentBasicOptimized()
    {
        // Basic optimized soltuion
        // In this we will traverse the row and in column as these are sorted we will use binary search
        for (int i = 0; i < matrix.size(); i++)
        {
            int colstart = 0;
            int colend = matrix[0].size() - 1;
            while (colstart <= colend)
            {
                auto colmid = (colstart + colend) / 2;
                if (matrix[i][colmid] == target)
                {
                    return true;
                }
                else if (matrix[i][colmid] < target)
                {
                    // To  search in the right half
                    colstart = colmid + 1;
                }
                else
                {
                    // To search in the left half
                    colend = colmid - 1;
                }
            }
        }
        return false;
        // The time complexity of this solution is O(N.logn)
    }
    bool ispresent()
    {

        // The time complexity of this solution is O(N)
        //  Using two pointer approach
        int temprow = 0;
        int tempcolumn = matrix[0].size() - 1;
        int rowsize = matrix.size();

        while (temprow < rowsize && tempcolumn >= 0)
        {
            int temp = matrix[temprow][tempcolumn];
            if (temp == target)
            {
                return true;
            }
            else if (temp < target)
            {
                temprow++; // Traverse in row
            }
            else
            {
                // Traverse in column

                tempcolumn--;
            }
        }
        return false;
    }
};
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
int main()
{
    search2dmatrix s1;
    cout << s1.ispresent() << endl;
    cout << s1.ispresentBasicOptimized() << endl;

    return 0;
}