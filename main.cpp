#include <iostream>
#include <ctime>
using namespace std;
void fillArray(int arr1[],int arr2[],int *kol_vo);
void showArray(int array[],string massage,int *kol_vo);
void thirdArray(int array_1[],int array_2[],int array_3[],int *kol_vo,int *index);
void showArray3(int array[],string massage,int *index);
int minThird(int arr[],int index,string massage);
int main() {
    srand(time(NULL));
    int kol_vo = 0 ,index = 0;
    cout << "Enter size of the array's" << endl;
    cin >> kol_vo;
    int *arr1,*arr2,*arr3;
    arr1 = new int [kol_vo];
    arr2 = new int [kol_vo];
    arr3 = new int [kol_vo];
    fillArray(arr1,arr2,&kol_vo);
    thirdArray(arr1,arr2,arr3,&kol_vo,&index);
    showArray(arr1,"first array",&kol_vo);
    showArray(arr2,"second array",&kol_vo);
    showArray3(arr3,"third array",&index);
    cout << minThird(arr3,index,"min = ")<<endl;
    return 0;
}
void fillArray(int arr1[],int arr2[],int *kol_vo){                              //funkcia dly zadania pervix dvux massivov
    for (int i = 0;i < *kol_vo;i++){
        arr1[i] = rand()%19 + 1;
        arr2[i] = rand()%19 + 1;
    }
}

void thirdArray(int array_1[],int array_2[],int array_3[],int *kol_vo,int *index){ //funkcia dly obsheta 3 massiva(1 massiv bez obshih elementov so 2) + scheta peremennoi index chtobi isbezhat nulei
    for(int i = 0;i < *kol_vo;i++) {
        int rez = 0;
        for (int j = 0;j < *kol_vo;j++) {
            if (array_1[i] == array_2[j]) {
                rez = 1;
            }
        }
        if (rez == 0){
            array_3[*index] = array_1[i];
            *index += 1;
        }
    }
}
int minThird(int arr[],int index,string massge){                                   //funkcia dly obsheta minimalnogo znachenia v poluchivshemsy massive
    cout << massge;
    int min = arr[0];
    for (int i = 0;i < index;i++){
        if (arr[i] <= min){
            min = arr[i];
        }
    }
    return min;
}
void showArray(int array[],string massage,int *kol_vo){                         //funkcia dly pokaza pervih 2 massivov
    cout << massage << endl;
    for (int i = 0;i < *kol_vo;i++){
        cout << array[i] <<" ";
    }
    cout << endl;
}
void showArray3(int array[],string massage,int *index){                          //funkcia dly pokaza pervih 3 massivov
    cout << massage << endl;
    for (int i = 0;i < *index;i++){
        cout << array[i] <<" ";
    }
    cout << endl;
}