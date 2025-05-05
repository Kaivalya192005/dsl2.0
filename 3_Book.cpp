#include <iostream>
#include <cstring>
using namespace std;

struct node {
    char name[20];
    node *next;
    node *down;
    int flag;
};

class Gll {
    char chapterName[20], sectionName[20];
    int n, i;
    node *head = NULL, *temp = NULL, *t1 = NULL, *t2 = NULL;

public:
    node* create();
    void insertb();
    void insertc();
    void inserts();
    void insertss();
    void displayb();
};

node* Gll::create() {
    node *p = new node;
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    cout << "\nEnter the name: ";
    cin.ignore();
    cin.getline(p->name, 20);
    return p;
}

void Gll::insertb() {
    if (head == NULL) {
        t1 = create();
        head = t1;
    } else {
        cout << "\nBook already exists";
    }
}

void Gll::insertc() {
    if (head == NULL) {
        cout << "\nThere is no book";
    } else {
        cout << "\nHow many chapters do you want to insert: ";
        cin >> n;
        for (i = 0; i < n; i++) {
            t1 = create();
            if (head->flag == 0) {
                head->down = t1;
                head->flag = 1;
            } else {
                temp = head->down;
                while (temp->next != NULL)
                    temp = temp->next;
                temp->next = t1;
            }
        }
    }
}

void Gll::inserts() {
    if (head == NULL) {
        cout << "\nThere is no book";
        return;
    }

    cout << "\nEnter the name of the chapter where you want to add sections: ";
    cin.ignore();
    cin.getline(chapterName, 20);

    temp = head->down;
    while (temp != NULL) {
        if (!strcmp(chapterName, temp->name)) {
            cout << "\nHow many sections do you want to enter: ";
            cin >> n;
            for (i = 0; i < n; i++) {
                t1 = create();
                if (temp->flag == 0) {
                    temp->down = t1;
                    temp->flag = 1;
                } else {
                    t2 = temp->down;
                    while (t2->next != NULL)
                        t2 = t2->next;
                    t2->next = t1;
                }
            }
            return;
        }
        temp = temp->next;
    }
    cout << "\nChapter not found!";
}

void Gll::insertss() {
    if (head == NULL) {
        cout << "\nThere is no book";
        return;
    }

    cout << "\nEnter the name of the chapter: ";
    cin.ignore();
    cin.getline(chapterName, 20);

    node *chapter = head->down;
    while (chapter != NULL && strcmp(chapter->name, chapterName) != 0)
        chapter = chapter->next;

    if (chapter == NULL) {
        cout << "\nChapter not found!";
        return;
    }

    if (chapter->flag == 0) {
        cout << "\nThere are no sections";
        return;
    }

    cout << "\nEnter the name of the section where you want to insert subsections: ";
    cin.getline(sectionName, 20);

    node *section = chapter->down;
    while (section != NULL && strcmp(section->name, sectionName) != 0)
        section = section->next;

    if (section == NULL) {
        cout << "\nSection not found!";
        return;
    }

    cout << "\nHow many subsections do you want to enter: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        t1 = create();
        if (section->flag == 0) {
            section->down = t1;
            section->flag = 1;
        } else {
            t2 = section->down;
            while (t2->next != NULL)
                t2 = t2->next;
            t2->next = t1;
        }
    }
}

void Gll::displayb() {
    if (head == NULL) {
        cout << "\nBook does not exist";
        return;
    }

    temp = head;
    cout << "\nNAME OF BOOK: " << temp->name;
    if (temp->flag == 1) {
        temp = temp->down;
        while (temp != NULL) {
            cout << "\n\tCHAPTER: " << temp->name;
            t1 = temp;
            if (t1->flag == 1) {
                t1 = t1->down;
                while (t1 != NULL) {
                    cout << "\n\t\tSECTION: " << t1->name;
                    t2 = t1;
                    if (t2->flag == 1) {
                        t2 = t2->down;
                        while (t2 != NULL) {
                            cout << "\n\t\t\tSUBSECTION: " << t2->name;
                            t2 = t2->next;
                        }
                    }
                    t1 = t1->next;
                }
            }
            temp = temp->next;
        }
    }
}

int main() {
    Gll g;
    int x;

    while (1) {
        cout << "\n\nMenu:";
        cout << "\n1. Insert book"; 
        cout << "\n2. Insert chapter";
        cout << "\n3. Insert section";
        cout << "\n4. Insert subsection";
        cout << "\n5. Display book";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> x;

        switch (x) {
            case 1: g.insertb(); break;
            case 2: g.insertc(); break;
            case 3: g.inserts(); break;
            case 4: g.insertss(); break;
            case 5: g.displayb(); break;
            case 6: exit(0);
            default: cout << "\nInvalid choice. Try again.";
        }
    }

    return 0;
}
