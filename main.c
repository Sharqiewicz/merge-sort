#include <stdio.h>

int MAX = 4;

void print_array(int array[], int length){
    printf("[");
    for( int i = 0; i < length; i++){
        printf(" %i", array[i]);
        if(i < length - 1){
            printf(",");
        }
    }
    printf(" ] \n");
}


void merge(int array[], int left, int middle, int right) {

    // array jest caly czas pelnej wymiarow tablica ze wszystkimi wartosciami
    // sortujemy za kazdym razem najmniejsza czesc jaka zostala wywolana w merge_sort

    // NIE SORTUJEMY CALEJ TABLICY, BO BYŚMY LEFT NADPISALI RIGHT I ODWROTNIE!!! DLATEGO SORTUJEMY CZESC CALEJ TABLICY

    // Dzieki tej dlugości wiemy ile z glownej tablicy ma zostac przekopiowane elementow do poszczegolnej z tablic
    int array_left_length = middle - left + 1; // Dla lewej tablicy left zawsze jest 0, left jest wprowadzone do tych tablic po prawej
    int array_right_length = right - middle;

    int array_left[array_left_length];
    int array_right[array_right_length];


    // przekopiowujemy konkretna ilosc elementow do tablic
    for(int i = 0; i < array_left_length; i++){
        array_left[i] = array[i + left]; // Dodajemy dla elementow z tablic prawych
    }
    for(int i = 0; i < array_right_length; i++){
        array_right[i] = array[i + middle + 1]; // DLATEGO LEFT jest większa zazwyczaj
    }

    // tworzymy iteratory ktore pozwola nam kontrolowac jak daleko z kazdej L|R tablic jestesmy, a takze w ktorym momencie tablicy glownej mamy dodac dana wartosc
    int i = 0;
    int j = 0;
    int k = left;

    while(i < array_left_length && j < array_right_length){
        if(array_left[i] <= array_right[j]){
            array[k] = array_left[i];
            i++;
        }
        else{
            array[k] = array_right[j];
            j++;
        }
        k++;
    }

    // Tutaj dodajemy reszte elementow z tablicy ktora nie zostala przeiterowana do konca
    while( i < array_left_length ){
        array[k] = array_left[i];
        i++;
        k++;
    }

    while( j < array_right_length ){
        array[k] = array_right[j];
        j++;
        k++;
    }


}


void merge_sort(int array[], int left, int right){

    if(left < right){
        int middle = (left + right) / 2;
        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);
        merge(array, left, middle, right);

    }
}


int main(){

    int numbers[4] = {5,2,1,4};

    print_array(numbers, MAX);
    merge_sort(numbers, 0, MAX-1);
    print_array(numbers, MAX);
    return 1;
}


