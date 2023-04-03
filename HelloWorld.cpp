#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    cout << "----------------------" << endl;
    /** https://code.visualstudio.com/docs/cpp/config-clang-mac */
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    
    cout << "----------------------" << endl;
    /** https://westhillworker.com/visualstudiocode-cpp/ */
    cout << "Hello!VisualStudioCode" << endl;
    //return 0;
   
    }