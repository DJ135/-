#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// ����һ��0��maxNum֮����������
int generateRandomNumber(int maxNum) {
    return rand() % (maxNum + 1);
}

// ����һ��������������+��-��*��/��
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

// ����һ�����������������ʽ
string generateRandomExpression(int maxNum, bool withParentheses, bool withDecimal, bool allowAddition, bool allowSubtraction, bool allowMultiplication, bool allowDivision) {
    stringstream ss;
    int operand1 = generateRandomNumber(maxNum);
    int operand2 = generateRandomNumber(maxNum);

    // ��������Ƿ�ʹ��С��
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

// ������ʽ��ָ���������
void outputExpressions(int maxNum, bool withParentheses, bool withDecimal, bool allowAddition, bool allowSubtraction, bool allowMultiplication, bool allowDivision, ostream& out, int numExpressions) {
    for (int i = 0; i < numExpressions; ++i) {
        out << generateRandomExpression(maxNum, withParentheses, withDecimal, allowAddition, allowSubtraction, allowMultiplication, allowDivision) << endl;
    }
}

int main() {
    // ʹ�õ�ǰʱ����Ϊ���������
    srand(time(0));

    int maxNum;
    cout << "����������������ֵ: ";
    cin >> maxNum;

    char allowAdditionChoice;
    cout << "�Ƿ�����ʹ�üӷ����㣿(y/n): ";
    cin >> allowAdditionChoice;
    bool allowAddition = (allowAdditionChoice == 'y' || allowAdditionChoice == 'Y');

    char allowSubtractionChoice;
    cout << "�Ƿ�����ʹ�ü������㣿(y/n): ";
    cin >> allowSubtractionChoice;
    bool allowSubtraction = (allowSubtractionChoice == 'y' || allowSubtractionChoice == 'Y');

    char allowMultiplicationChoice;
    cout << "�Ƿ�����ʹ�ó˷����㣿(y/n): ";
    cin >> allowMultiplicationChoice;
    bool allowMultiplication = (allowMultiplicationChoice == 'y' || allowMultiplicationChoice == 'Y');

    char allowDivisionChoice;
    cout << "�Ƿ�����ʹ�ó������㣿(y/n): ";
    cin >> allowDivisionChoice;
    bool allowDivision = (allowDivisionChoice == 'y' || allowDivisionChoice == 'Y');

    char withParenthesesChoice;
    cout << "�Ƿ�������ʽ�������ţ�(y/n): ";
    cin >> withParenthesesChoice;
    bool withParentheses = (withParenthesesChoice == 'y' || withParenthesesChoice == 'Y');

    char withDecimalChoice;
    cout << "�Ƿ�������ʽ����С����(y/n): ";
    cin >> withDecimalChoice;
    bool withDecimal = (withDecimalChoice == 'y' || withDecimalChoice == 'Y');

    int numExpressions;
    cout << "������Ҫ���ɵ�����������ʽ������: ";
    cin >> numExpressions;

    char outputChoice;
    cout << "��ѡ�������ʽ (c: ����̨, f: �ļ�): ";
    cin >> outputChoice;

    if (outputChoice == 'c' || outputChoice == 'C') {
        // ���������̨
        outputExpressions(maxNum, withParentheses, withDecimal, allowAddition, allowSubtraction, allowMultiplication, allowDivision, cout, numExpressions);
    }
    else if (outputChoice == 'f' || outputChoice == 'F') {
        // ������ļ�
        string filename;
        cout << "������Ҫ������ļ���: ";
        cin >> filename;
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outputExpressions(maxNum, withParentheses, withDecimal, allowAddition, allowSubtraction, allowMultiplication, allowDivision, outFile, numExpressions);
            outFile.close();
            cout << "���ʽ�ѳɹ�������ļ� " << filename << " �С�" << endl;
            cout << "�밴 Enter ������..." << endl;
            cin.ignore(); // �����ϴ�����Ļ��з�
            cin.get();    // �ȴ��û����� Enter ��
        }
        else {
            cerr << "�޷����ļ� " << filename << " ����д�롣" << endl;
        }
    }
    else {
        cout << "δ֪�������ʽ��";
    }

    return 0;
}

