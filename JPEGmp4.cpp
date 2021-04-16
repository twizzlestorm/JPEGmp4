/* JPEGmp4 by twizzlestorm */

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

void main()
{
    string infile, outfile;
    int a, v;
    bool invA = true, invV = true;
    char yn;
    cout << "drag and drop original video file: ";
    getline(cin, infile);
    
    while (invA == true) {
        invA = false;
        cout << "set audio bitrate: ";
        cin >> a;
        if (cin.fail()) {
            invA = true;
            cin.clear();
            cin.ignore();
            cout << "<!> invalid input";
        }
    }

    while (invV == true) {
        invV = false;
        cout << "set video bitrate: ";
        cin >> v;
        if (cin.fail()) {
            invV = true;
            cin.clear();
            cin.ignore();
            cout << "<!> invalid input";
        }
    }

    cout << "specify output file (original video path: " << infile << "): ";
    cin >> outfile;

    cout << endl << "passing over your input to ffmpeg..." << endl;
    system(("ping localhost -n 2 >nul"));
    system(("ffmpeg -i " + infile + " -b:a " + to_string(a) + "k -b:v " + to_string(v) + "k " + outfile).c_str());
    system(("ping localhost -n 2 >nul"));
    
    cout << endl << "if there was an error, you may have typed an invalid path. check your input and try again." << endl;
    cout << "if there wasn't an error... would you like to play your video now? (Y/N): ";
    cin >> yn;
    yn = toupper(yn);

    if (yn == 'Y') {
        system((outfile).c_str());
        cout << "video played ok bye";
        system("pause >nul");
    }
    else {
        cout << "ok bye";
    }
}
