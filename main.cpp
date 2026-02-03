#include <bits/stdc++.h>
using namespace std;

void addExpense() {
    ofstream file("expenses.txt", ios::app);
    if (!file) return;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int d = ltm->tm_mday;
    int m = 1 + ltm->tm_mon;
    int y = 1900 + ltm->tm_year;

    string desc;
    int amount;

    cin.ignore();
    cout << "Enter description: ";
    getline(cin, desc);
    cout << "Enter amount: ";
    cin >> amount;

    file << d << "/" << m << "/" << y
         << " | " << desc
         << " | Rs " << amount << endl;

    file.close();
    cout << "Expense added.\n";
}

void seeExpenses() {
    ifstream file("expenses.txt");
    string line;
    cout << "\n--- All Expenses ---\n";
    while (getline(file, line))
        cout << line << endl;
    cout << "--------------------\n";
}

int extractAmount(string line) {
    int pos = line.find("Rs ");
    return stoi(line.substr(pos + 3));
}

void totalTillNow() {
    ifstream file("expenses.txt");
    string line;
    int total = 0;

    while (getline(file, line))
        total += extractAmount(line);

    cout << "Total Expenses Till Now: Rs " << total << endl;
}

void totalByDate() {
    ifstream file("expenses.txt");
    string line, date;
    int total = 0;

    cout << "Enter date (DD/MM/YYYY): ";
    cin >> date;

    while (getline(file, line)) {
        if (line.find(date) == 0)
            total += extractAmount(line);
    }

    cout << "Total on " << date << ": Rs " << total << endl;
}

void totalByMonth() {
    ifstream file("expenses.txt");
    string line;
    int m, y, total = 0;

    cout << "Enter month and year (MM YYYY): ";
    cin >> m >> y;

    while (getline(file, line)) {
        int d2, m2, y2;
        sscanf(line.c_str(), "%d/%d/%d", &d2, &m2, &y2);
        if (m2 == m && y2 == y)
            total += extractAmount(line);
    }

    cout << "Total for " << m << "/" << y << ": Rs " << total << endl;
}

void totalByYear() {
    ifstream file("expenses.txt");
    string line;
    int y, total = 0;

    cout << "Enter year: ";
    cin >> y;

    while (getline(file, line)) {
        int d2, m2, y2;
        sscanf(line.c_str(), "%d/%d/%d", &d2, &m2, &y2);
        if (y2 == y)
            total += extractAmount(line);
    }

    cout << "Total for year " << y << ": Rs " << total << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. See All Expenses\n";
        cout << "3. Search Expenses by Date\n";
        cout << "4. Total Expenses Till Now\n";
        cout << "5. Total Expenses for a Date\n";
        cout << "6. Total Expenses for a Month\n";
        cout << "7. Total Expenses for a Year\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: seeExpenses(); break;
            case 3: totalByDate(); break;
            case 4: totalTillNow(); break;
            case 5: totalByDate(); break;
            case 6: totalByMonth(); break;
            case 7: totalByYear(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}
