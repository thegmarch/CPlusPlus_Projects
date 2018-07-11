#include<iostream>
#include<string>
#include<array>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;


class PuzzleSolver
{
    public:
    string dictionary[7] = {"OX","CAT","TOY","AT","DOG","CATAPULT","T"};
    int wordCount = 0;
    bool IsWord(string testWord)
    {
        for(auto &i: dictionary)
        {
            if (i == testWord)
            {
               return true;
            }

        }
        return false;
    }

    //Initialize visited 2d array
    // This is used to keep track of cells that the algorithm has already visited
    void initVisited(bool **visited,int rows,int cols)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                visited[i][j] = false;
            }
        }
    }

    //DFS main function
    //This function essentially runs a DFS on each cell to determine if a word can be found
    int findWords(char **puzzle, int rowCount, int colCount)
    {
       // int totalWordsFound = 0;
        bool *visited[colCount];
        string str = "";
        unordered_map<string, bool> found;
        vector<int> rowCol;
        for(int i = 0; i < rowCount; i++)
        {
            visited[i] = new bool[colCount];
        }
        initVisited(visited, rowCount, colCount);

        for(int matRowPos = 0; matRowPos < rowCount; matRowPos++)
        {
            for(int matColPos = 0; matColPos < colCount; matColPos++)
            {

                helper(puzzle, visited, rowCount, colCount, matRowPos, matColPos, str,found, rowCol);
                rowCol.clear();
            }
        }
        return wordCount;
    }

    
    string reverseCords(string origCord)
    {
        stack<char> stackEven;
        stack<char> stackOdd;
        string cordRev = "";
        char temp;
        for(int i = 0; i < origCord.length();i++)
        {
            if(i % 2 == 0)
            {
                stackEven.push(origCord[i]);
            }
            else
            {
                stackOdd.push(origCord[i]);
            }
        }
        for(int j = 0; j < origCord.length(); j++)
        {
            if(j % 2 == 0)
            {
                cordRev += stackEven.top();
                stackEven.pop();
            }
            else
            {
                cordRev += stackOdd.top();
                stackOdd.pop();;
            }
        }

        return cordRev;
    }
    
    //DFS helper function
    void helper(char **puzzle, bool **visited, int rowCount, int colCount, int rowPos, int colPos, string &str, unordered_map<string,bool> &found, vector<int> rowCol)
    {
     visited[rowPos][colPos] = true;
     str += puzzle[rowPos][colPos];
     rowCol.push_back(rowPos);
     rowCol.push_back(colPos);
     string revCheck = str;
     reverse(revCheck.begin(),revCheck.end());
     string reverseCordString = "";
     string cordString = "";

     for(auto &i: rowCol)
     {
         cordString += '0' + i;
     }
     reverseCordString = reverseCords(cordString);
     if((IsWord(str) && !found[reverseCordString] ) )
     {
        if(!found[cordString])
        {
          if(checkHoriz(rowCol) || checkDiag(rowCol) || checkVert(rowCol))
          {

              cout << "Cord String: " << cordString << " Found: " << found[cordString];
              cout << " Reverse Cord String: " << reverseCordString << "Found: " << found[reverseCordString];
              cout << " Checks: " << checkHoriz(rowCol) << checkDiag(rowCol) << checkVert(rowCol);
              wordCount++;
              found[cordString] = true;

              cout << "reg " << str << endl;

          }
        }
     }
     else if((IsWord(revCheck) && !found[cordString]))
     {
        if(!found[reverseCordString])
        {
          //Check if valid in straight line
          if(checkHoriz(rowCol) || checkDiag(rowCol) || checkVert(rowCol))
          {
            cout << "Cord String: " << cordString << " Found: " << found[cordString];
            cout << " Reverse Cord String: " << reverseCordString << "Found: " << found[reverseCordString];
            cout << " Checks: " << checkHoriz(rowCol) << checkDiag(rowCol) << checkVert(rowCol);

            wordCount++;
            found[reverseCordString] = true;
            cout << "rev " << revCheck << endl;

          }
        }
     }

     for(int row = rowPos-1; row<=rowPos+1 && row<rowCount; row++)
     {
         for(int col = colPos-1; col<=colPos+1 && col<colCount; col++)
            if((row>=0 && col>=0 && !visited[row][col]))
             {
                if(!checkHoriz(rowCol) && !checkDiag(rowCol) && !checkVert(rowCol))
                {
                    break;
                }
                helper(puzzle, visited, rowCount, colCount, row, col, str, found, rowCol);
             }
     }
        str.erase(str.length()-1);
        visited[rowPos][colPos] = false;

    }

    //Check if string is horizontal
    bool checkHoriz(vector<int> rowCol)
    {
        bool rowMatch = true;
        for(int i = 0; i < rowCol.size()-2; i++)
        {

            if((rowCol[i] != rowCol[i+2]) && i%2==0)
            {
                rowMatch = false;
            }

        }
        return rowMatch;
    }

    //Check if string is vertical
    bool checkVert(vector<int> rowCol)
    {
        bool vertMatch = true;
        for(int i = 0; i < rowCol.size()-2; i++)
        {
            if(((rowCol[i]+1 != rowCol[i+2]) && i%2==0))
            {
                vertMatch = false;
            }
            if(((rowCol[i] != rowCol[i+2]) && i%2==1))
            {
               vertMatch = false;
            }
        }

        return vertMatch;
    }

    //Check if string is diagonal
    bool checkDiag(vector<int> rowCol)
    {
        if(checkDiagLR(rowCol) || checkDiagRL(rowCol))
            return true;
        else
            return false;
    }

    //checkDiag helper function
    //Checks if string is diagonal, oriented from left to right 
    bool checkDiagLR(vector<int> rowCol)
    {
       if(checkDiagLR_Down(rowCol) || checkDiagLR_UP(rowCol))
            return true;
       else
            return false;
    }

    //checkDiagLR helper function
    //Checks if string is diagonal with starting character in top left position
    bool checkDiagLR_Down(vector<int> rowCol)
    {
        bool diagMatchDown = true;
        for(int i = 0; i < rowCol.size()-2; i++)
        {
            if(((rowCol[i]+1) != rowCol[i+2]) && i%2==0)
            {
                diagMatchDown = false;
            }
            else if(((rowCol[i]+1) != rowCol[i+2]) && i%2==1)
            {
                diagMatchDown = false;
            }
        }
       return diagMatchDown;
    }

    //checkDiagLR helper function
    //Checks if string is diagonal with starting character in bottom right position
    bool checkDiagLR_UP(vector<int> rowCol)
    {
        bool diagMatchUp = true;
        for(int i = 0; i < rowCol.size()-2; i++)
        {
            if(((rowCol[i]-1) != rowCol[i+2]) && i%2==0)
            {
                diagMatchUp = false;
            }
            else if(((rowCol[i]-1) != rowCol[i+2]) && i%2==1)
            {
                diagMatchUp = false;
            }
        }
        return diagMatchUp;
    }

    //checkDiag helper function
    //Checks if string is diagonal, oriented from right to left 
    bool checkDiagRL(vector<int> rowCol)
    {
        if(checkDiagRL_Down(rowCol) || checkDiagRL_Up(rowCol))
            return true;
        else
            return false;
    }

    //checkDiagRL helper function
    //Checks if string is diagonal with starting character in top right position
    bool checkDiagRL_Down(vector<int> rowCol)
    {
        bool diagMatchDown = true;
        for(int i = 0; i < rowCol.size()-2; i++)
        {
            //reg
            if(((rowCol[i]+1) != rowCol[i+2]) && i%2==0)
            {
                diagMatchDown = false;
            }
            //reg
            else if(((rowCol[i]-1) != rowCol[i+2]) && i%2==1)
            {
                diagMatchDown = false;
            }
        }
        return diagMatchDown;
    }

    //checkDiagRL helper function
    //Checks if string is diagonal with starting character in bottom left position
    bool checkDiagRL_Up(vector<int> rowCol)
    {
        bool diagMatchUp = true;
        for(int i = 0; i < rowCol.size()-2; i++)
        {
            if(((rowCol[i]-1) != rowCol[i+2]) && i%2==0)
            {
                diagMatchUp = false;
            }
            else if(((rowCol[i]+1) != rowCol[i+2]) && i%2==1)
            {
                diagMatchUp = false;
            }
        }
        return diagMatchUp;
    }

};

int main(){

    PuzzleSolver p;
    string test = "CAT";
    int ROW_COUNT;
    int COL_COUNT;

    cout <<  "Enter Row Count: ";
    cin >> ROW_COUNT;

    cout <<  "Enter Col Count: ";
    cin >> COL_COUNT;


   char *matrix[ROW_COUNT];
   for(int i = 0; i < ROW_COUNT; i++)
   {
       matrix[i] = new char[COL_COUNT];
   }

/*
    matrix[0][0] = 'C';
    matrix[0][1] = 'A';
    matrix[0][2] = 'T';
    matrix[1][0] = 'X';
    matrix[1][1] = 'Z';
    matrix[1][2] = 'T';
    matrix[2][0] = 'Y';
    matrix[2][1] = 'O';
    matrix[2][2] = 'T'; */
/*
    //Test Matrix: Ans - 8
    matrix[0][0] = 'T';
    matrix[0][1] = 'A';
    matrix[0][2] = 'T';
    matrix[1][0] = 'A';
    matrix[1][1] = 'Z';
    matrix[1][2] = 'O';
    matrix[2][0] = 'T';
    matrix[2][1] = 'O';
    matrix[2][2] = 'Y';
*/
/*
    matrix[0][0] = 'G';
    matrix[0][1] = 'O';
    matrix[0][2] = 'D';
    matrix[1][0] = 'X';
    matrix[1][1] = 'O';
    matrix[1][2] = 'T';
    matrix[2][0] = 'T';
    matrix[2][1] = 'T';
    matrix[2][2] = 'G'; */

    matrix[0][0] = 'C';
    matrix[0][1] = 'A';
    matrix[0][2] = 'T';
    matrix[0][3] = 'A';
    matrix[0][4] = 'P';
    matrix[0][5] = 'U';
    matrix[0][6] = 'L';
    matrix[0][7] = 'T';
    matrix[1][0] = 'X';
    matrix[1][1] = 'Z';
    matrix[1][2] = 'T';
    matrix[1][3] = 'T';
    matrix[1][4] = 'O';
    matrix[1][5] = 'Y';
    matrix[1][6] = 'O';
    matrix[1][7] = 'O';
    matrix[2][0] = 'Y';
    matrix[2][1] = 'O';
    matrix[2][2] = 'T';
    matrix[2][3] = 'O';
    matrix[2][4] = 'X';
    matrix[2][5] = 'T';
    matrix[2][6] = 'X';
    matrix[2][7] = 'X';



    cout << p.findWords(matrix, ROW_COUNT, COL_COUNT);


return 0;
}
