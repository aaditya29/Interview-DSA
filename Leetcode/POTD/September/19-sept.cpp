// Leetcode 3484. Design Spreadsheet
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

class Spreadsheet
{
public:
    int numRows;
    vector<int> cells;

    Spreadsheet(int rows)
    {
        numRows = rows;
        cells = vector<int>(26 * rows, 0);
    }

    void setCell(string cell, int value)
    {

        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        int index = col * numRows + row;
        cells[index] = value;
    }

    void resetCell(string cell)
    {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        int index = col * numRows + row;
        cells[index] = 0;
    }

    int getValue(string formula)
    {

        string expression = formula.substr(1);

        size_t plusPos = expression.find('+');

        string leftOperand = expression.substr(0, plusPos);
        string rightOperand = expression.substr(plusPos + 1);

        int leftValue;
        if (isalpha(leftOperand[0]))
        {
            // It's a cell reference - parse it
            int col = leftOperand[0] - 'A';
            int row = stoi(leftOperand.substr(1)) - 1;
            int index = col * numRows + row;
            leftValue = cells[index];
        }
        else
        {
            leftValue = stoi(leftOperand);
        }

        int rightValue;
        if (isalpha(rightOperand[0]))
        {
            int col = rightOperand[0] - 'A';
            int row = stoi(rightOperand.substr(1)) - 1;
            int index = col * numRows + row;
            rightValue = cells[index];
        }
        else
        {
            rightValue = stoi(rightOperand);
        }

        return leftValue + rightValue;
    }
};

int main()
{
    Spreadsheet spreadsheet(3); // Initialize a spreadsheet with 3 rows

    spreadsheet.setCell("A1", 5);
    spreadsheet.setCell("B2", 10);

    std::cout << "Value of A1: " << spreadsheet.getValue("A1") << std::endl;          // Output: 5
    std::cout << "Value of B2: " << spreadsheet.getValue("B2") << std::endl;          // Output: 10
    std::cout << "Value of A1 + B2: " << spreadsheet.getValue("=A1+B2") << std::endl; // Output: 15

    spreadsheet.resetCell("A1");
    std::cout << "Value of A1 after reset: " << spreadsheet.getValue("A1") << std::endl; // Output: 0

    return 0;
}