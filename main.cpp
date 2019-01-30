#include <iostream>
#include <vector>

using namespace std;

vector<char> invertVector(vector<char> vec) {
    vector<char> invertedVec(vec.size());

    for(int i=0; i<vec.size(); i++) {
        invertedVec[vec.size() - i - 1] = vec[i];
    }

    return invertedVec;
}

vector<char> decToSome(int dec, int some) {
    vector<char> arr;

    while(dec != 0) {
        char curr = dec % some;
        dec /= some;

        arr.push_back(curr);
    }

    return invertVector(arr);
}

string getHEXFromVector(vector<char> hexNr) {
    string hexStr;

    for(int i=0; i<hexNr.size(); i++) {
        char curr = hexNr[i];
        if(curr < 10) {
            // In ASCII '0' has index 48
            hexStr += curr + 48;
        }else {
            // In ASCII 'A' has index 65
            hexStr += curr + 65 - 10;
        }
    }

    return hexStr;
}

int main()
{
    // 1010
    int type = 16;
    vector<char> arr = decToSome(123, type);

    for(int i=0; i<arr.size(); i++) {
        cout << (int)arr[i] << ".";
    }

    if(type == 16) {
        cout << endl << getHEXFromVector(arr) << endl;
    }

    return 0;
}
