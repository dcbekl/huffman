// 测试文件的读取ascll码大于128的字符

# include <iostream>
# include <fstream>

using namespace std;

int main(){

    ofstream ofs;
    ofs.open("./tt.txt");

    if(!ofs.is_open())
        return 0;

    ofs << "abbccceeedd";
    ofs << char(255);
    ofs << "ddfffffggggg";

    cout << "成功！" << endl;
    ofs.close();

    ifstream ifs;
    ifs.open("./tt.txt");

    if(!ifs.is_open())
        return 0;

    cout << "成功！" << endl;
    char buf;

    buf = ifs.get();
    while(!ifs.eof()){

        cout << buf << endl;
        buf = ifs.get();
    }

    ifs.close();
    return 0;
}