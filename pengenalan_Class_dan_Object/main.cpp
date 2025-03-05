#include <iostream>
#include <string>
using namespace std;

// ini class
class Timnas {
    public:
        string nama;
        string klub;
};

int main()
{

    Timnas centerBack_1;  // ini membuat objek
    centerBack_1.nama = "Jay Idzes";
    centerBack_1.klub = "venezia";

    Timnas leftBack_1;
    leftBack_1.nama = "Calvin Verdonk";
    leftBack_1.klub = "Nec Nijmegan";

    Timnas rightBack_1;
    rightBack_1.nama = "Kevin Diks";
    rightBack_1.klub = "Copanhagen";

    Timnas midfielder_1;
    midfielder_1.nama = "Thom Haye";
    midfielder_1.klub = "Alamare";

    Timnas striker_1;
    striker_1.nama = "Ole Romeny";
    striker_1.klub = "Oxford United";\

    cout << endl;

    cout << "National Team Profile" << endl;
    cout << "1. " << centerBack_1.nama << " (" << centerBack_1.klub << ")" << endl;
    cout << "2. " << leftBack_1.nama << " (" << leftBack_1.klub << ")" << endl;
    cout << "3. " << rightBack_1.nama << " (" << rightBack_1.klub << ")" << endl;
    cout << "4. " << midfielder_1.nama << " (" << midfielder_1.klub << ")" << endl;
    cout << "5. " << striker_1.nama << " (" << striker_1.klub << ")" << endl;
    return 0;
}
