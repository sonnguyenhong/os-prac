#include<bits/stdc++.h>
using namespace std;

int convert(string a) {
    int number = (int) stoul(a, NULL, 16);
    return number;
}

string convert_to_binary(string a) {
    int i = 0;
    string res = "";
    while(a[i]) {
        switch(a[i]) {
            case '0': 
                res += "0000";
                break;
            case '1': 
                res += "0001";
                break;
            case '2': 
                res += "0010";
                break;
            case '3':
                res += "0011";
                break;
            case '4':
                res += "0100";
                break;
            case '5':
                res += "0101";
                break;
            case '6':
                res += "0110";
                break;
            case '7':
                res += "0111";
                break;
            case '8':
                res += "1000";
                break;
            case '9':
                res += "1001";
                break;
            case 'A':
            case 'a':
                res += "1010";
                break;
            case 'B':
            case 'b':
                res += "1011";
                break;
            case 'C':
            case 'c':
                res += "1100";
                break;
            case 'D':
            case 'd':
                res += "1101";
                break;
            case 'E':
            case 'e':
                res += "1110";
                break;
            case 'F':
            case 'f':
                res += "1111";
                break;
            default:
                break;
        }
        i++;
    }
    return res;
}


vector<int> getCylinderAndSector(string binStr) {
    vector<int> res;
    string cyl_tmp = binStr.substr(8, 2) + binStr.substr(0, 8);
    int cylinder = (int) stoi(cyl_tmp, 0, 2);
    string sec_tmp = binStr.substr(10, 6);
    int sector = (int) stoi(sec_tmp, 0, 2);
    res.push_back(cylinder);
    res.push_back(sector);
    return res;
}

int main() {
    string a = "FFFFFFF";
    vector<int> res = getCylinderAndSector("0000000111111001");
    cout<<res[0]<<endl;
    
}