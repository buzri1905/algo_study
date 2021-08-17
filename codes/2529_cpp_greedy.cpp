#include <iostream>
using namespace std;

char list[10];

void max(int k, char * list) {
    int top = 9;
    int num_right = 0;

    for (int j = 0; j < k; j++) {
        if (list[j] == '<') {
            num_right++;
        }

        else {
            for (int k = top - num_right; k <= top; k++) {
                cout << k;
            }
            top = top - num_right - 1;
            num_right = 0;
        }
    }
    for (int t = top - num_right; t <= top; t++) {
        cout << t;
    }
}

void min(int k, char* list) {
    int bottom = 0;
    int num_left = 0;

    for (int j = 0; j < k; j++) {
        if (list[j] == '>') {
            num_left++;
        }

        else {
            for (int k = bottom + num_left; k >= bottom; k--) {
                cout << k;
            }
            bottom = bottom+num_left+1;
            num_left = 0;
        }
    }
    for (int t = bottom+num_left; t >= bottom; t--) {
        cout << t;
    }

}



int main() {

    int k;
    cin >> k;

   
    for (int i = 0; i < k; i++) {
        cin >> list[i];
    }

    max(k,list);
    cout << endl;
    min(k,list);
    


}