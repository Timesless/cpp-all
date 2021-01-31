/**
 * @author yangzl
 * @date 2021/1/30
 * @desc
 *
 *      1. 文本文件
 *      2. 二进制文件
 *          fstream::in | fstream::binary
 *
 *  文件操作：
 *      fstream「读写」
 *      ifstream
 *      ofstream
 *
 *  1. include头文件
 *  2. 创建流对象
 *  3. 打开文件
 *      ios::in
 *      ios::out
 *      ios::app
 *      ios::ate
 *      ios::trunc「如果文件存在，先删除再创建」
 *      ios::binary
 *  4. 读写数据
 *  5. 关闭文件
 */
#include <iostream>
#include <fstream>

using namespace std;


void test_create_file() {

    ofstream of;
    of.open("test.txt", ios::out);

    of << "hello world" << endl;
    of << "hello java" << endl;
    of << "hello js" << endl;
    of << "hello node" << endl;
    of << "hello python" << endl;
    of << "hello groovy" << endl;
    of << "hello c" << endl;
    of << "hello cpp" << endl;
    of << "hello rust" << endl;

    of.close();
}

void test_read_file() {

    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open()) {
        cout << "打开文件失败" << endl;
        return;
    }
    char buf[1024] = {0};
    /*
     * 1. ifs >> buf
     * 2. ifs.getline(char*, size_t)
     * 3. getline(ifs, buf)
     *
     * // 单字节读，效率低
     * 4. (char c = ifs.get()) != EOF
     */
    while (ifs.getline(buf, sizeof(buf))) {
        cout << buf << endl;
    }

    ifs.close();
}

void test_copy_file() {
    ifstream src("test.txt", fstream::in);
    ofstream dest("test_copy.txt", ios::out);
    dest << src.rdbuf();

    dest.close();
    src.close();
}

/**
 *
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *const argv[]) {

    test_create_file();

    test_read_file();

    test_copy_file();

    return 0;
}

