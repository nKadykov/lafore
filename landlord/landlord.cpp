#include "landlord.h"

void getaLine(std::string& inStr) {
    char temp[21];
    std::cin.get(temp, 20, '\n');
    std::cin.ignore(20, '\n');
    inStr = temp;
}

char getaChar() {
    char ch = std::cin.get();
    std::cin.ignore(80, '\n');
    return ch;
}

Tenant::Tenant(std::string n, int aNo) : name(n), aptNumber(aNo) {}

Tenant::~Tenant() {}

int Tenant::getAptNumber() {
    return aptNumber;
}

bool operator<(const Tenant& t1, const Tenant& t2) {
    return t1.name < t2.name;
}

bool operator==(const Tenant& t1, const Tenant& t2) {
    return t1.name == t2.name;
}

std::ostream& operator<<(std::ostream& s, const Tenant& t) {
    s << t.aptNumber << '\t' << t.name << std::endl;
    return s;
}

void TenantInputScreen::getTenant() {
    std::cout << "Enter tenant's name: ";
    getaLine(tName);
    std::cout << "Enter number: ";
    std::cin >> aptNo;
    std::cin.ignore(80, '\n');
    Tenant* ptrTenant = new Tenant(tName, aptNo);
    ptrTenantList->insertTenant(ptrTenant);
}

bool CompareTenants::operator() (Tenant* ptrT1, Tenant* ptrT2) const {
    return *ptrT1 < *ptrT2;
}

TenantList::~TenantList() {
    while(!setPtrsTens.empty()) {
        iter = setPtrsTens.begin();
        delete *iter;
        setPtrsTens.erase(iter);
    }
}

void TenantList::insertTenant(Tenant* ptrT) {
    setPtrsTens.insert(ptrT);
}

int TenantList::getAptNo(std::string tName) {
    int aptNo;
    Tenant dummy(tName, 0);
    iter = setPtrsTens.begin();
    while(iter != setPtrsTens.end()) {
        aptNo = (*iter)->getAptNumber();
        if(dummy == **iter++) {
            return aptNo;
        }
    }
    return -1;
}

void TenantList::display() {
    if(setPtrsTens.empty()) {
        std::cout << "No tenants" << std::endl;
    }
    else {
        iter = setPtrsTens.begin();
        while(iter != setPtrsTens.end()) {
            std::cout << **iter++;
        }
    }
}

RentRow::RentRow(int an) : aptNo(an) {
    std::fill(&rent[0], &rent[12], 0);
}

void RentRow::setRent(int m, float am) {
    rent[m] = am;
}

float RentRow::getSumOfRow() {
    return std::accumulate(&rent[0], &rent[12], 0);
}

bool operator<(const RentRow& t1, const RentRow& t2) {
    return t1.aptNo < t2.aptNo;
}

bool operator==(const RentRow& t1, const RentRow& t2) {
    return t1.aptNo == t2.aptNo;
}

std::ostream& operator<<(std::ostream& s, const RentRow& an) {
    s << an.aptNo << '\t';
    for(int i = 0; i < 12; i++) {
        if(an.rent[i] == 0) {
            s << " 0  ";
        }
        else {
            s << an.rent[i] << " ";
        }
    }
    return s;
}

bool CompareRows::operator() (RentRow* ptrR1, RentRow* ptrR2) const {
    return *ptrR1 < *ptrR2;
}

RentRecord::~RentRecord() {
    while(!setPtrsRR.empty()) {
        iter = setPtrsRR.begin();
        delete *iter;
        setPtrsRR.erase(iter);
    }
}

void RentRecord::insertRent(int aptNo, int month, float amount) {
    RentRow searchRow(aptNo);
    iter = setPtrsRR.begin();
    while(iter != setPtrsRR.end()) {
        if(searchRow == **iter) {
            (*iter)->setRent(month, amount);
            return;
        }
        else {
            iter++;
        }
    }
    RentRow* ptrRow = new RentRow(aptNo);
    ptrRow->setRent(month, amount);
    setPtrsRR.insert(ptrRow);
}

void RentRecord::display() {
    std::cout << "AptNo\tJan Fev Mar Apr May Jun Jul Aug Sep Oct Nov Dec" << std::endl;
    if(setPtrsRR.empty()) {
        std::cout << "No rent" << std::endl;
    }
    else {
        iter = setPtrsRR.begin();
        while(iter != setPtrsRR.end()) {
            std::cout << **iter++;
        }
    }
}

float RentRecord::getSumOfRents() {
    float sumRents = 0.0;
    iter = setPtrsRR.begin();
    while(iter != setPtrsRR.end()) {
        sumRents += (*iter)->getSumOfRow();
        iter++;
    }
    return sumRents;
}

void RentInputScreen::getRent() {
    std::cout << "Enter tenant name: ";
    getaLine(renterName);
    aptNo = ptrTenantList->getAptNo(renterName);
    if(aptNo > 0) {
        std::cout << "Enter sum: ";
        std::cin >> rentPaid;
        std::cin.ignore(80, '\n');
        std::cout << "Enter month: ";
        std::cin >> month;
        std::cin.ignore(80, '\n');
        month--;
        ptrRentRecord->insertRent(aptNo, month, rentPaid);
    }
    else {
        std::cout << "No tenant" << std::endl;
    }
}

bool operator<(const Expense& e1, const Expense& e2) {
    if(e1.month == e2.month) {
        return e1.day < e2.day;
    }
    else {
        return e1.month < e2.month;
    }
}


bool operator==(const Expense& e1, const Expense& e2) {
    return e1.month == e2.month && e1.day == e2.day;
}

std::ostream& operator<<(std::ostream& s, const Expense& exp) {
    s << exp.month << "/" << exp.day << "\t" << exp.payee << "\t";
    s << exp.amount << "\t" << exp.category << std::endl;
    return s;
}

bool CompareDates::operator() (Expense* ptrE1, Expense* ptrE2) const {
    return *ptrE1 < *ptrE2;
}

bool CompareCategories::operator() (Expense* ptrE1, Expense* ptrE2) const {
    return ptrE1->category < ptrE2->category;
}

ExpenseRecord::~ExpenseRecord() {
    while(!vectPtrsExpenses.empty()) {
        iter = vectPtrsExpenses.begin();
        delete *iter;
        vectPtrsExpenses.erase(iter);
    }
}

void ExpenseRecord::insertExp(Expense* ptrExp) {
    vectPtrsExpenses.push_back(ptrExp);
}

void ExpenseRecord::display() {
    std::cout << "Date\tRenter\t\tSum\tCategory" << std::endl;
    if(vectPtrsExpenses.size() == 0) {
        std::cout << "No expense" << std::endl;
    }
    else {
        sort(vectPtrsExpenses.begin(), vectPtrsExpenses.end(), CompareDates());
        iter = vectPtrsExpenses.begin();
        while(iter != vectPtrsExpenses.end()) {
            std::cout << **iter++;
        }
    }
}

float ExpenseRecord::displaySummary() {
    float totalExpenses = 0;
    if(vectPtrsExpenses.size() == 0) {
        std::cout << "\tAll categories" << std::endl;
        return 0;
    }
    sort(vectPtrsExpenses.begin(), vectPtrsExpenses.end(), CompareCategories());
    iter = vectPtrsExpenses.begin();
    std::string tempCat = (*iter)->category;
    float sumCat = 0.0;
    while(iter != vectPtrsExpenses.end()) {
        if(tempCat == (*iter)->category) {
            sumCat += (*iter)->amount;
        }
        else {
            std::cout << "\t" << tempCat << "\t" << sumCat << std::endl;
            totalExpenses += sumCat;
            tempCat = (*iter)->category;
            sumCat = (*iter)->amount;
        }
        iter++;
    }
    std::cout << "\t" << tempCat << "\t" << sumCat << std::endl;
    return totalExpenses;
}

ExpenseInputScreen::ExpenseInputScreen(ExpenseRecord* per): ptrExpenseRecord(per) {}

void ExpenseInputScreen::getExpense() {
    int month, day;
    std::string category, payee;
    float amount;
    std::cout << "Enter month: ";
    std::cin >> month;
    std::cin.ignore(80, '\n');
    std::cout << "Enter day: ";
    std::cin.ignore(80, '\n');
    std::cout << "Enter category: ";
    getaLine(category);
    std::cout << "Enter payee: ";
    getaLine(payee);
    std::cout << "Enter sum: ";
    std::cin >> amount;
    std::cin.ignore(80, '\n');
    Expense* ptrExpense = new Expense(month, day, category, payee, amount);
    ptrExpenseRecord->insertExp(ptrExpense);
}

AnnualReport::AnnualReport(RentRecord* pRR, ExpenseRecord* pER): ptrRR(pRR), ptrER(pER) {}

void AnnualReport::display() {
    std::cout << "Sum of rents: ";
    rents = ptrRR->getSumOfRents();
    std::cout << rents << std::endl;
    std::cout << "Summary: ";
    expenses = ptrER->displaySummary();
    std::cout << "Balance: " << rents - expenses << std::endl;
}

UserInterface::UserInterface() {
    ptrTenantList = new TenantList;
    ptrRentRecord = new RentRecord;
    ptrExpenseRecord = new ExpenseRecord;
}

UserInterface::~UserInterface() {
    delete ptrTenantList;
    delete ptrRentRecord;
    delete ptrExpenseRecord;
}

void UserInterface::interact() {
    while(true) {
        std::cout << "Push 'i' to input, 'd' to output, 'q' to exit: ";
        ch = getaChar();
        if(ch == 'i') {
            std::cout << " 't' to add tenant, 'r' to write rent, 'e' to write expenses: ";
            ch = getaChar();
            switch(ch) {
                case 't':
                    ptrTenantInputScreen = new TenantInputScreen(ptrTenantList);
                    ptrTenantInputScreen->getTenant();
                    delete ptrTenantInputScreen;
                    break;
                case 'r':
                    ptrRentInputScreen = new RentInputScreen(ptrTenantList, ptrRentRecord);
                    ptrRentInputScreen->getRent();
                    delete ptrRentInputScreen;
                    break;
                case 'e':
                    ptrExpenseInputScreen = new ExpenseInputScreen(ptrExpenseRecord);
                    ptrExpenseInputScreen->getExpense();
                    delete ptrExpenseInputScreen;
                    break;
                default:
                    std::cout << "Unknown function" << std::endl;
                    break;
            }
        }
        else if(ch == 'd') {
            std::cout << " 't' to output tenant, 'r' to output rent, 'e' to output expenses, 'a' to output summary: ";
            ch = getaChar();
            switch(ch) {
                case 't':
                    ptrTenantList->display();
                    break;
                case 'r':
                    ptrRentRecord->display();
                    break;
                case 'e':
                    ptrExpenseRecord->display();
                    break;
                case 'a':
                    ptrAnnualReport = new AnnualReport(ptrRentRecord, ptrExpenseRecord);
                    ptrAnnualReport->display();
                    delete ptrAnnualReport;
                    break;
                default:
                    std::cout << "Unknown function" << std::endl;
                    break;
            }
        }
        else if(ch == 'q') {
            return;
        }
        else {
            std::cout << "Unknown function" << std::endl;
        }
    }
}