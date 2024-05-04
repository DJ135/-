#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// 生成一个0到maxNum之间的随机整数
int generateRandomNumber(int maxNum) {
    return rand() % (maxNum + 1);
}

// 生成一个随机的运算符（+、-、*、/）
char generateRandomOperator(bool allowAddition, bool allowSubtraction, bool allowMultiplication, bool allowDivision) {
    char operators[] = { '+', '-', '*', '/' };
    int numOperators = 0;
    if (allowAddition) operators[numOperators++] = '+';
    if (allowSubtraction) operators[numOperators++] = '-';
    if (allowMultiplication) operators[numOperators++] = '*';
    if (allowDivision) operators[numOperators++] = '/';
    int randomIndex = rand() % numOperators;
    return operators[randomIndex];
}

// 生成一个随机的四则运算表达式
string generateRandomExpression(int maxNum, bool withParentheses, bool withDecimal, bool allowAddition, bool allowSubtraction, bool allowMultiplication, bool allowDivision) {
    stringstream ss;
    int operand1 = generateRandomNumber(maxNum);
    int operand2 = generateRandomNumber(maxNum);

    // 随机决定是否使用小数
    bool useDecimal = withDecimal && (rand() % 2 == 0);

    if (useDecimal) {
        double decimalOperand1 = static_cast<double>(operand1) + static_cast<double>(generateRandomNumber(maxNum)) / 10;
        double decimalOperand2 = static_cast<double>(operand2) + static_cast<double>(generateRandomNumber(maxNum)) / 10;
        ss << fixed << setprecision(1) << decimalOperand1;
        ss << " " << generateRandomOperator(allowAddition, allowSubtraction, allowMultiplication, allowDivision) << " ";
        ss << fixed << setprecision(1) << decimalOperand2;
    }
    else {
        ss << operand1;
        ss << " " << generateRandomOperator(allowAddition, allowSubtraction, allowMultiplication, allowDivision) << " ";
        ss << operand2;
    }

    if (withParentheses) {
        string expr = ss.str();
        return "(" + expr + ")";
    }
    else {
        return ss.str();
    }
}

// 输出表达式到指定的输出流
void outputExpressions(int maxNum, bool withParentheses, bool withDecimal, bool allowAddition, bool allowSubtraction, bool allowMultiplication, bool allowDivision, ostream& out, int numExpressions) {
    for (int i = 0; i < numExpressions; ++i) {
        out << generateRandomExpression(maxNum, withParentheses, withDecimal, allowAddition, allowSubtraction, allowMultiplication, allowDivision) << endl;
    }
}

int main() {
    // 使用当前时间作为随机数种子
    srand(time(0));

    int maxNum;
    cout << "请输入随机数的最大值: ";
    cin >> maxNum;

    char allowAdditionChoice;
    cout << "是否允许使用加法运算？(y/n): ";
    cin >> allowAdditionChoice;
    bool allowAddition = (allowAdditionChoice == 'y' || allowAdditionChoice == 'Y');

    char allowSubtractionChoice;
    cout << "是否允许使用减法运算？(y/n): ";
    cin >> allowSubtractionChoice;
    bool allowSubtraction = (allowSubtractionChoice == 'y' || allowSubtractionChoice == 'Y');

    char allowMultiplicationChoice;
    cout << "是否允许使用乘法运算？(y/n): ";
    cin >> allowMultiplicationChoice;
    bool allowMultiplication = (allowMultiplicationChoice == 'y' || allowMultiplicationChoice == 'Y');

    char allowDivisionChoice;
    cout << "是否允许使用除法运算？(y/n): ";
    cin >> allowDivisionChoice;
    bool allowDivision = (allowDivisionChoice == 'y' || allowDivisionChoice == 'Y');

    char withParenthesesChoice;
    cout << "是否允许表达式包含括号？(y/n): ";
    cin >> withParenthesesChoice;
    bool withParentheses = (withParenthesesChoice == 'y' || withParenthesesChoice == 'Y');

    char withDecimalChoice;
    cout << "是否允许表达式包含小数？(y/n): ";
    cin >> withDecimalChoice;
    bool withDecimal = (withDecimalChoice == 'y' || withDecimalChoice == 'Y');

    int numExpressions;
    cout << "请输入要生成的四则运算表达式的数量: ";
    cin >> numExpressions;

    char outputChoice;
    cout << "请选择输出方式 (c: 控制台, f: 文件): ";
    cin >> outputChoice;

    if (outputChoice == 'c' || outputChoice == 'C') {
        // 输出到控制台
        outputExpressions(maxNum, withParentheses, withDecimal, allowAddition, allowSubtraction, allowMultiplication, allowDivision, cout, numExpressions);
    }
    else if (outputChoice == 'f' || outputChoice == 'F') {
        // 输出到文件
        string filename;
        cout << "请输入要输出的文件名: ";
        cin >> filename;
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outputExpressions(maxNum, withParentheses, withDecimal, allowAddition, allowSubtraction, allowMultiplication, allowDivision, outFile, numExpressions);
            outFile.close();
            cout << "表达式已成功输出到文件 " << filename << " 中。" << endl;
            cout << "请按 Enter 键继续..." << endl;
            cin.ignore(); // 忽略上次输入的换行符
            cin.get();    // 等待用户按下 Enter 键
        }
        else {
            cerr << "无法打开文件 " << filename << " 进行写入。" << endl;
        }
    }
    else {
        cout << "未知的输出方式。";
    }

    return 0;
}

