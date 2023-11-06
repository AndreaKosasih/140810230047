#include <iostream> 
using namespace std;

void menu(){
    cout << " 1. Bubble sort\n 2. Selection sort\n 3. Insertion sort\n 4. Shell\n 5. Counting\n 6. Keluar program" << endl << endl; 
}

void bubble(){
    int h[6] = {5, 4, 9, 3, 1, 2};
    for(int i = 0; i < 5; i++){ // mempresentasikan berapa kali melakukan sorting 
        for(int j = 0; j < 5; j++){ // mempresentrasikan di setiap sorting melakukan berapa kali perbandingan
            if(h[j] > h[j+1]) {
                int temp = h[j];
                h[j] = h[j+1];
                h[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < 6; i++){
        cout << h[i] << " "; 
    }
}

void selection(){
    int h[6] = {9, 7, 6, 5, 4, 3};
    for(int i = 0; i <= 5; i++){
        int minIndex = i; 
        for(int j = i + 1; j <= 5; j++){
            if(h[j] < h[minIndex]){
                minIndex = j;
            }
        }
        int temp = h[i];
        h[i] = h[minIndex];
        h[minIndex] = temp; 
    }
    for(int i = 0; i < 6; i++){
        cout << h[i] << " ";
    }
}

void insertion(){
    int h[6] = {4, 3, 2, 8, 5, 3};
    int pos;
    for(int i = 0; i < 6; i++){
        pos = i;
        while(pos > 0 && h[pos] < h[pos-1]){
            int temp = h[pos];
            h[pos] = h[pos-1];
            h[pos-1] = temp; 
            pos--; 
        }
    }
    for(int i = 0; i < 6; i++){
        cout << h[i] << " ";
    }
}

void shell(){
    int h[6] = {5, 4, 9, 3, 1, 2};
    for (int gap = 3; gap > 0; gap /= 2) {
        for (int i = gap; i < 6; i++) {
            int temp = h[i];
            int j;
            for (j = i; j >= gap && temp < h[j - gap]; j -= gap) {
                h[j] = h[j - gap];
            }
            h[j] = temp;
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << h[i] << " ";
    }
}

void counting(){
    int h[6] = {1, 3, 2, 2, 1, 5};
    int ftable[10000] = {0}; 
    for(int i = 0; i < 6; i++){
        int x = h[i];
        ftable[x]++; 
    }
    int index = 0; 
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < ftable[i]; j++){ 
            h[index] = i;
            index++; 
        }
    }
    for(int i = 0; i < 6; i++){ 
        cout << h[i] << " ";
    }
}



int main(){
    menu();
    bool gas = true;
    while(gas){
        int option; cin >> option;
        switch (option) {
        case 1: bubble(); menu(); cout << endl; break;
        case 2: selection(); menu(); cout << endl; break;
        case 3: insertion(); menu(); cout << endl; break; 
        case 4: shell(); menu(); cout << endl; break; 
        case 5: counting(); menu(); cout << endl; break; 
        case 6: gas = false; cout << endl; break; 
        default: cout << "salah cuk"; break;
        }
    }
    cout << "Selesai" << endl; 
    return 0; 
}
