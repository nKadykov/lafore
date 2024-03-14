#pragma warning(disable:4786)

#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <numeric>

void getLine(std::string& inStr);
char getChar();

class Tenant {
    std::string name;
    int aptNumber;
public:
    Tenant(std::string n, int aNo);
    ~Tenant();
    int getAptNumber();
    friend bool operator<(const Tenant&, const Tenant&);
    friend bool operator==(const Tenant&, const Tenant&);
    friend std::ostream& operator<<(std::ostream&, const Tenant&);
};

class CompareTenants {
public:
    bool operator() (Tenant*, Tenant*) const;
};

class TenantList {
    std::set<Tenant*, CompareTenants> setPtrsTens;
    std::set<Tenant*, CompareTenants>::iterator iter;
public:
    ~TenantList();
    void insertTenant(Tenant*);
    int getAptNo(std::string);
    void display();
};

class TenantInputScreen {
    TenantList* ptrTenantList;
    std::string tName;
    int aptNo;
public:
    TenantInputScreen(TenantList* ptrTL): ptrTenantList(ptrTL) {}
    void getTenant();
};

class RentRow {
    int aptNo;
    float rent[12];
public:
    RentRow(int);
    void setRent(int, float);
    float getSumOfRow();
    friend bool operator<(const RentRow&, const RentRow&);
    friend bool operator==(const RentRow&, const RentRow&);
    friend std::ostream& operator<<(std::ostream&, const RentRow&);
};

class CompareRows {
public:
    bool operator() (RentRow*, RentRow*) const;
};

class RentRecord {
    std::set<RentRow*, CompareRows> setPtrsRR;
    std::set<RentRow*, CompareRows>::iterator iter;
public:
    ~RentRecord();
    void insertRent(int, int, float);
    void display();
    float getSumOfRents();
};

class RentInputScreen {
    TenantList* ptrTenantList;
    RentRecord* ptrRentRecord;
    std::string renterName;
    float rentPaid;
    int month;
    int aptNo;
public:
    RentInputScreen(TenantList* ptrTL, RentRecord* ptrRR): ptrTenantList(ptrTL), ptrRentRecord(ptrRR) {}
    void getRent();
};

class Expense {
public:
    int month, day;
    std::string category, payee;
    float amount;
    Expense() {}
    Expense(int m, int d, std::string c, std::string p, float a) : month(m), day(d), category(c), payee(p), amount(a) {}
    friend bool operator<(const Expense&, const Expense&);
    friend bool operator==(const Expense&, const Expense&);
    friend std::ostream& operator<<(std::ostream&, const Expense&);
};

class CompareDates {
public:
    bool operator() (Expense*, Expense*) const;
};

class CompareCategories {
public:
    bool operator() (Expense*, Expense*) const;
};

class ExpenseRecord {
    std::vector<Expense*> vectPtrsExpenses;
    std::vector<Expense*>::iterator iter;
public:
    ~ExpenseRecord();
    void insertExp(Expense*);
    void display();
    float displaySummary();
};

class ExpenseInputScreen {
    ExpenseRecord* ptrExpenseRecord;
public:
    ExpenseInputScreen(ExpenseRecord*);
    void getExpense();
};

class AnnualReport {
    RentRecord* ptrRR;
    ExpenseRecord* ptrER;
    float expenses, rents;
public:
    AnnualReport(RentRecord*, ExpenseRecord*);
    void display();
};

class UserInterface {
    TenantList* ptrTenantList;
    TenantInputScreen* ptrTenantInputScreen;
    RentRecord* ptrRentRecord;
    RentInputScreen* ptrRentInputScreen;
    ExpenseRecord* ptrExpenseRecord;
    ExpenseInputScreen* ptrExpenseInputScreen;
    AnnualReport* ptrAnnualReport;
    char ch;
public:
    UserInterface();
    ~UserInterface();
    void interact();
};