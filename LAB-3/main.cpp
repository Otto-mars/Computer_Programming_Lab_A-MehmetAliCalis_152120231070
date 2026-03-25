#include <iostream>

using namespace std;

struct Song {

string title , artist;
int ratings [3];

Song *next;
Song *prev;
};



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



int main (){









return 0;
}
