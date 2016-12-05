#include <iostream>

using namespace std;

void showInput();
void getToken();
void checkStat();
void finalToken();

bool expStat;
char input[200];
int token[100];
int counter,expJ;

int main()
{
    cout<<"*****************************************************************"<<endl;
    cout<<"*                         DAFTAR STRING                         *"<<endl;
    cout<<"*****************************************************************"<<endl;
    cout<<"     1    |  2  |  3  |  4 |  5  | 6  |  7   |  8  |  9  |  10"<<endl;
    cout<<"  p,q,r,s | not | and | or | xor | if | then | iff |  (  |  ) "<<endl;

    cout<<endl<<"Input your string: ";
    cin.getline(input, 200);
    counter = cin.gcount()-1;

    input[counter] = ' ';

    /*for (int a=counter; a<=counter+5; a++){
        input[a] = ' ';
    }*/

    //input[counter+1] = ' ';

    cout<<endl<<endl;
    cout<<"*****************************************************************"<<endl;
    cout<<"*                             INPUT                             *"<<endl;
    cout<<"*****************************************************************"<<endl<<"  ";
    showInput();
    cout<<endl<<endl<<endl;
    cout<<"*****************************************************************"<<endl;
    cout<<"*                             TOKEN                             *"<<endl;
    cout<<"*****************************************************************"<<endl<<"  ";
    getToken();
    checkStat();
    cout<<endl;
    cout<<endl;
    cout<<"*****************************************************************"<<endl;
    cout<<"*                            VALIDASI                           *"<<endl;
    cout<<"*****************************************************************"<<endl<<"  ";
    finalToken();

    return 0;
}

void showInput(){
    for (int i=0;i<counter;i++){
        cout<<input[i];
        if (input[i+1] == ' '){
            cout<<" | ";
            i++;
        }
    }
    //cout<<input[i+2]<<"T";
}

void getToken(){
    int j = 0;
    int i = 0;
    bool status = false;
    while (( i < counter) && (not status)){
        if (((input[i] == 'p') || (input[i] == 'q') || (input[i] == 'r') || (input[i] == 's')) && (input[i+1] == ' ')){
            token[j] = 1;
            j++;
            i = i+2;
        }
        else if ((input[i] == 'n') && (input [i+1] == 'o') && (input[i+2] == 't') && (input[i+3] == ' ')){
            token[j] = 2;
            j++;
            i = i+4;
        }
        else if ((input[i] == 'a') && (input[i+1] == 'n') && (input[i+2] == 'd') && (input[i+3] == ' ')){
            token[j] = 3;
            j++;
            i = i+4;
        }
        else if ((input[i] == 'o') && (input[i+1] == 'r') && (input[i+2] == ' ')){
            token[j] = 4;
            j++;
            i = i+3;
        }
        else if ((input[i] == 'x') && (input[i+1] == 'o') && (input[i+2] == 'r') && (input[i+3] == ' ')){
            token[j] = 5;
            j++;
            i = i+4;
        }
        else if ((input[i] == 'i') && (input[i+1] == 'f') && (input[i+2] == 'f') && (input[i+3] == ' ')){
            token[j] = 8;
            j++;
            i = i+4;
        }
        else if ((input[i] == 'i') && (input[i+1] == 'f') && (input[i+2] == ' ')){
            token[j] = 6;
            j++;
            i = i+3;
        }
        else if ((input[i] == 't') && (input[i+1] == 'h') && (input[i+2] == 'e') && (input[i+3] == 'n') && (input[i+4] == ' ')){
            token[j] = 7;
            j++;
            i = i+5;
        }
        else if ((input[i] == '(') && (input[i+1] == ' ')){
            token[j] = 9;
            i = i+2;
            j++;
        }
        else if ((input[i] == ')') && (input[i+1] == ' ')){
            token[j] = 10;
            i = i+2;
            j++;
        }
        else{
            //cout<<"INPUT SALAH!"<<endl;
            status = true;
        }
        //cout<<token[j]<<" ";
    }
    expJ = j;
    expStat = status;
    /*if (status == false){
        cout<<"INPUT BENAR!"<<endl;
    }
    else{
        cout<<"INPUT SALAH!"<<endl;
    }*/
}

void checkStat(){
for (int i=0;i<expJ;i++){
        cout<<token[i]<<" ";
    }
    if (expStat){
        cout<<"INPUT SALAH!"<<endl;
    }
    else{
        cout<<endl<<"  INPUT BENAR!"<<endl;
    }
}

void finalToken(){
    bool status = true;
    int open = 0;
    int close = 0;
    int i = -1;
    while ((i < expJ-1) && (status)){
        i++;
        cout<<token[i]<<" ";
        if (token[0] == 0){
            status = false;
            break;
        }
        else if (token[1] == 0){
            if (token[0] != 1){
                status = false;
                break;
            }
        }
        else if ((token[0] == 3) || (token[0] == 4) || (token[0] == 5) || (token[0] == 8) || (token[0] == 10) || (token[0] == 7)){
            status = false;
            break;
        }
        else if (token[i] == 1){
            if ((token[i+1] == 1) || (token[i+1] == 6) || (token[i+1] == 9) /*|| (token[i+1] == 0)*/){
                status = false;
                break;
            }
        }
        else if (token[i] == 2){
            if ((token[i+1] == 2) || (token[i+1] == 3) || (token[i+1] == 4) || (token[i+1] == 5) || (token[i+1] == 6) || (token[i+1] == 7) || (token[i+1] == 8) || (token[i+1] == 10)){
                status = false;
                break;
            }
        }
        else if (token[i] == 3){
            if ((token[i+1] == 3) || (token[i+1] == 4) || (token[i+1] == 5) || (token[i+1] == 6) || (token[i+1] == 7) || (token[i+1] == 8) || (token[i+1] == 10) || (token[i+1] == 0)){
                status = false;
                break;
            }
        }
        else if (token[i] == 4){
            if ((token[i+1] == 3) || (token[i+1] == 4) || (token[i+1] == 5) || (token[i+1] == 6) || (token[i+1] == 7) || (token[i+1] == 8) || (token[i+1] == 10) || (token[i+1] == 0)){
                status = false;
                break;
            }
        }
        else if (token[i] == 5){
            if ((token[i+1] == 3) || (token[i+1] == 4) || (token[i+1] == 5) || (token[i+1] == 6) || (token[i+1] == 7) || (token[i+1] == 8) || (token[i+1] == 10)){
                status = false;
                break;
            }
        }
        else if (token[i] == 6){
            if ((token[i+1] == 3) || (token[i+1] == 4) || (token[i+1] == 5) || (token[i+1] == 6) || (token[i+1] == 7) || (token[i+1] == 8) || (token[i+1] == 10)){
                status = false;
                break;
            }
            else if (token[i-1] == 1){
                status = false;
                break;
            }
        }
        else if (token[i] == 7){
            if ((token[i-2] == 3) || (token[i-2] == 4) || (token[i-2] == 5)/* || (token[i-2] == 4)*/){
                if (token[i-1] != 10){
                    status = false;
                    break;
                }
            }
            else if ((token[i+1] == 3) || (token[i+1] == 4) || (token[i+1] == 5) || (token[i+1] == 6) || (token[i+1] == 7) || (token[i+1] == 8) || (token[i+1] == 10) || (token[i+1] == 0)){
                status = false;
                break;
            }
            else if (token[i-1] == 6){
                status = false;
                break;
            }
            /*else if (token[i-2] == 1){
                status = false;
                break;
            }*/
            else if ((token[i-1] != 10) && token[i-1] != 1){
                status = false;
                break;
            }
        }
        else if (token[i] == 8){
            if ((token[i+1] == 2) || (token[i+1] == 3) || (token[i+1] == 4) || (token[i+1] == 5) || (token[i+1] == 6) || (token[i+1] == 7) || (token[i+1] == 8) || (token[i+1] == 10)){
                status = false;
                break;
            }
        }
        else if ((close == 0) && (open == 0) && (token[i] == 9)){
            for (int j = i; j<expJ; j++){
                if (token[j] == 9){
                    open++;
                }
                else if (token[j] == 10){
                    close++;
                }
            }
        }
        else if (close != open){
            //if ((close != 0) || (open != 0)){
                status = false;
                break;
            //}
        }
        else if ((close == open) && (close != 0) && (open != 0)){
            if (token[i] == 9){
                if ((token[i+1] == 3) || (token[i+1] == 4) || (token[i+1] == 5) || (token[i+1] == 7)){
                    status = false;
                    break;
                }
            }
            else if (token[i] == 10){
                if ((token[i+1] == 1) || (token[i+1] == 6) || (token[i+1] == 9)){
                    status = false;
                    break;
                }
            }
        }
        //cout<<token[i-1]<<" ";
        //i++;
    }
    if (expStat == true){
        status = false;
    }
    if (status == false){
            cout<<"VALIDASI SALAH"<<endl;
        }
        else{
            cout<<"VALIDASI BENAR"<<endl;
            //cout<<token[i];
        }
}
