#include <iostream>
using namespace std;

struct pohon
{
    pohon* kanan;
    pohon* kiri;
    char data;
};

pohon* simpul;
pohon* root;
pohon* saatini;
pohon* alamat[256];

// inisialisai root
void inisialisasi(){
    root = NULL;
}

//manambahakan data//
 void simpulbaru(char datamasukan) {
    simpul = new pohon;
    simpul->data = datamasukan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
 }
//manambahkan akar
void simpulakar () {
    if (root == NULL){
        char dataanda;
        cout << "silahkan masukan data :";
        cin >> dataanda;
        simpulbaru(dataanda);
        root = simpul;
        cout << "root terbentuk" <<endl;
    } else {
        cout << "root sudah ada" <<endl;
    }
}

void tambahsimpulkiri () {
    if (root !=NULL){
    int i = 1; 
    int j = 1;
    int penanda =0; 
    char datauser;
    alamat[i] = root;
    while (penanda == 0 && j < 256) {
        cout <<"masukan data kiri : " ;
        cin >> datauser;
        if (datauser !='0') {
            simpulbaru(datauser);
            saatini = alamat[i];
            saatini->kiri=simpul;
            j++;
            alamat[j] = simpul;
        } else {
            penanda = 1;
            j++;
            alamat[j] = NULL;
        }
      }
    }
}
            void tambahsimpulkanan () {
            int i = 1; 
            int j = 1;
            int penanda =0; 
            char datauser;
            if (penanda == 0){
            cout<< "masukan data kanan : " ;
            cin >> datauser;
            if(datauser !='0'){
                simpulbaru(datauser);
                saatini = alamat[i];
                saatini->kanan = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
          }
          i++;       
        }   

void bacaPohon() {
    if (root != NULL) {
        int i, n, pencacah;
        i = 1;
         n = 1; 
         pencacah = 0;
        cout << endl;

        while (alamat[i] != NULL) {
            saatini = alamat[i];
            cout << saatini->data << " ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}
    
int main() {
inisialisasi();
    int pilih;
    char dataanda;
    do {
        cout << endl;
        cout << "MENU" <<endl;
        cout << "1. membuat simpul akar" <<endl;
        cout << "2. menambahkan simpul kiri" <<endl;
        cout << "3. menambahkan simpul kanan" <<endl;
        cout << "4. tampilkan pohon" <<endl;
        cout << "5. keluar" <<endl;
        cout << "pilih : ";
        cin >> pilih ;
        cout <<endl;

        switch (pilih) {
            case 1:
            simpulakar ();
            break;

            case 2 :
            tambahsimpulkiri ();
            break;

            case 3 :
            tambahsimpulkanan ();
            break;

            case 4 :
            bacaPohon();
            break;

            case 5 :
                cout << "Keluar dari program" << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
            
        }
    } while (true);
   
}
