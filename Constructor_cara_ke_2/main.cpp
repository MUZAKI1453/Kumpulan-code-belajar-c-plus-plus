#include <iostream>
#include <string>
using namespace std;

// ini contoh class tanpa constructor
class TopScore {
public:
    string klub;
    int gol;
};

// ini contoh class dengan constructor
class Potm {
public:
    string nama;
    string klub;
    float rating;

    // ini adalah constructor tanpa parameter
    // potm() {
    //     cout << "player of the match" << endl;
    // }

    // ini adalah constructor dengan parameter
    Potm(string inputNama, string inputKlub, float inputRating) {
        Potm::nama = inputNama;
        Potm::klub = inputKlub;
        Potm::rating = inputRating;

        cout << "Player of the match on march : " << Potm::nama << endl;
        cout << "club saat ini : " << Potm::klub << endl;
        cout << "rating pemain : " << Potm::rating << endl;
        cout << "==================================================================" << endl;
    }

};

int main() {

    Potm march = Potm("Cole Palmer", "Chelsea", 9.5);

    Potm april = Potm("Odegard", "Arsenal", 9.1);

    Potm mei = Potm("Alexander Isak", "Newcastle", 9.6);


    //TopScore moSalah;
    //moSalah.klub = "liverpool";
    //moSalah.gol = 35;

    //cout << moSalah.klub << endl;
    //cout << moSalah.gol << endl;
    return 0;
}
