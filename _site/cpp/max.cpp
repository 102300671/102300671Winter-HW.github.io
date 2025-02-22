#include <iostream>
using namespace std;

// 找到数组的最大值或根据需要对数组进行排序
void process(double array[], int n, int num) {
    if (num == 1 || num == 2) {
        // 找到最大值
        double max_value = array[0];
        for (int i = 1; i < n; i++) {
            if (array[i] > max_value) {
                max_value = array[i];
            }
        }
        cout << "最大值: " << max_value << endl;  // 输出最大值
    } else if (num == 3 || num == 4) {
        // 对数组进行排序(降序)
        for (int i = 0; i < n - 1; i++) {
            int maxindex = i;
            for (int j = i + 1; j < n; j++) {
                if (array[j] > array[maxindex]) {
                    maxindex = j;
                }
            }
            // 交换
            if (maxindex != i) {
                double temp = array[maxindex];
                array[maxindex] = array[i];
                array[i] = temp;
            }
        }

        // 输出数组
        if (num == 3) {
            cout << "降序排列: ";
            for (int i = 0; i < n; i++) {
                cout << array[i] << ' ';
            }
            cout << endl;
        } else if (num == 4) {
            cout << "升序排列: ";
            for (int i = n - 1; i >= 0; i--) {
                cout << array[i] << ' ';
            }
            cout << endl;
        }
    }
}

int main() {
    double array[100];  // 限制数组大小
    int n, num;

    while (true) {
        // 显示菜单
        cout << "菜单选项:" << endl;
        cout << "1: 两个数的最大值" << endl;
        cout << "2: n 个数的最大值" << endl;
        cout << "3: n 个数降序排列" << endl;
        cout << "4: n 个数升序排列" << endl;
        cout << "0: 退出程序" << endl;
        cout << "请选择: ";
        cin >> num;  // 输入操作编号

        if (num == 0) {
            cout << "程序已退出。" << endl;
            break;  // 输入 0 退出
        } else if (num == 1) {
            // 输入两个数,查找最大值
            cout << "请输入两个数: ";
            for (int i = 0; i < 2; i++) {
                cin >> array[i];
            }
            process(array, 2, num);
        } else if (num == 2 || num == 3 || num == 4) {
            cout << "输入个数 (最多 100 个): ";
            cin >> n;  // 输入数组大小

            if (n > 100) {
                cout << "超出最大限制，请重新输入个数！" << endl;
                continue;
            }

            cout << "请输入 " << n << " 个数: ";
            for (int i = 0; i < n; i++) {
                cin >> array[i];  // 输入数组元素
            }
            process(array, n, num);
        } else {
            cout << "无效选项，请重新选择！" << endl;
        }
    }

    return 0;
}