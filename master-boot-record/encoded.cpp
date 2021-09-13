#include<bits/stdc++.h>

using namespace std;

vector<string> data;

int convert_to_decimal(string a) {
    int res = (int) stoul(a, NULL, 16);
    return res;
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
}

vector<int> getCylinderAndSector(string binStr) {
    vector<int> res;
    string cyl_tmp = binStr.substr(2, 8) + binStr.substr(0, 2);
    int cylinder = tmp.stoi(cyl_tmp, 0, 2);
    string sec_tmp = binStr.substr(10, 6);
    int sector = tmp.stoi(sec_tmp, 0, 2);
    res.push_back(cylinder);
    res.push_back(sector);
    return res;
}

void readFile() {
    string buffer;
    ifstream readFile("bang-phan-chuong.txt");
    while(getline(readFile, buffer)) {
        data.push_back(buffer);
    }
    for(int i = 0 ; i < data.size() ; i++){
        cout<<data[i]<<endl;
    }
}

void encode(string data) {
    if(data.substr(0, 2) == "80") {
        cout<<"Boot: YES"<<endl;
    } else {
        cout<<"Boot: NO"<<endl;
    }
    cout<<"VI TRI DAU: "<<endl;
    cout<<"   Header: "<<convert_to_decimal(data.substr(3, 2))<<endl;  
    cout<<"   Cylinder: "<<convert_to_decimal 
}

int main() {
    readFile();
    for(int i = 0 ; i < data.size() - 1 ; i++) {
        encode(data[i]);
        cout<<endl;
    }
}