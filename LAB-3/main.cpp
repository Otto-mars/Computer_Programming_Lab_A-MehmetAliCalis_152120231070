#include <iostream>

using namespace std;

struct Song {

string title , artist;
int ratings [3];

Song *next;
Song *prev;
};

Song *head    = nullptr;
Song *current = nullptr;

void add(string title, string artist, int r0, int r1, int r2) {
    Song *yeni_sarki = new Song();
    yeni_sarki->title  = title;
    yeni_sarki->artist = artist;
    yeni_sarki->ratings[0] = r0;
    yeni_sarki->ratings[1] = r1;
    yeni_sarki->ratings[2] = r2;
    yeni_sarki->next = nullptr;
    yeni_sarki->prev = nullptr;

    if (head == nullptr) {
        head    = yeni_sarki;
        current = yeni_sarki;
    } else {
        Song *son_dugum = head;
        while (son_dugum->next != nullptr)
            son_dugum = son_dugum->next;
        son_dugum->next   = yeni_sarki;
        yeni_sarki->prev  = son_dugum;
    }
}



void next() {
    if (current != nullptr && current->next != nullptr)
        current = current->next;
    else
        cout << "Zaten son sarkidasin." << endl;
}

void prev() {
    if (current != nullptr && current->prev != nullptr)
        current = current->prev;
    else
        cout << "Zaten ilk sarkidasin." << endl;
}

void removeCurrent() {
    if (current == nullptr) return;

    Song *silinecek = current;

    if (silinecek->prev != nullptr)
        silinecek->prev->next = silinecek->next;
    else
        head = silinecek->next;

    if (silinecek->next != nullptr)
        silinecek->next->prev = silinecek->prev;

    if (silinecek->next != nullptr)
        current = silinecek->next;
    else
        current = silinecek->prev;

    delete silinecek;
}


void display() {
    Song *ptr = head;
    while (ptr != nullptr) {
        if (ptr == current) cout << "-> ";
        else                cout << "   ";

        cout << ptr->title << " / " << ptr->artist << "  Ratings: [";
        for (int i = 0; i < 3; i++) {
            cout << ptr->ratings[i];
            if (i < 2) cout << ", ";
        }
        cout << "]" << endl;

        ptr = ptr->next;
    }
}



int main (){

    add("Itri Segah", "Buhurizade Itri", 9, 8, 10);
    add("Nihavend Longa", "Tatyos Efendi", 7, 9, 8);
    add("Huseyni Sazsemaisi", "Dede Efendi", 10, 9, 9);

    cout << "--- Initial Playlist ---" << endl;
    display();

    cout << "\n--- Move to Next ---" << endl;
    next();
    display();

    cout << "\n--- Remove Current ---" << endl;
    removeCurrent();
    display();

    cout << "\n--- Move to Prev ---" << endl;
    prev();
    display();


return 0;
}
