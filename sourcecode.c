#include <stdio.h> //Untuk menjalankan protokol printf()
#include <stdlib.h> //Untuk menjalankan protokol exit()
#include <string.h> //Untuk memanipulasi string, menjalankan protokol strlen()

#define MAX_LENGTH 2024 //Mendefinisikan variabel konstan MAX_LENGTH dengan inisiasi nilai = 2024
#define MIN_LENGTH 1945 //Mendefinisikan variabel konstan MIN_LENGTH dengan inisiasi nilai = 1945

void lessThanRequired(int *lengthOfText) { //Mendefinisikan fungsi lessThanRequired, yang mengambil pointer ke integer lengthOfText
    printf("The length of your text is less than specified, please update your text\n"); //Mencetak pesan kesalahan jika panjang teks kurang dari MIN_LENGTH ketika dicek dalam fungsi checkLengthRequirement
    *lengthOfText += (MIN_LENGTH - *lengthOfText); //Menambah nilai lengthOfText dengan selisih nilai MIN_LENGTH dan lengthOfText sebelumnya
}

void equalThanRequired(int *lengthOfText) { //Mendefinisikan fungsi equalThanRequired, yang mengambil pointer ke integer lengthOfText
    printf("Thank you, Your text length is correct\n"); //Mencetak pesan bahwa panjang teks sudah sesuai
}

void moreThanRequired(int *lengthOfText) { //Mendefinisikan fungsi moreThanRequired, yang mengambil pointer ke integer lengthOfText
    printf("Your text is too long, please reduce the text\n"); //Mencetak pesan kesalahan jika panjang teks lebih dari MAX_LENGTH ketika dicek dalam fungsi checkLengthRequirement
    *lengthOfText += (MAX_LENGTH - MIN_LENGTH); //Menambah nilai lengthOfText  dengan selisih antara MAX_LENGTH dan MIN_LENGTH
}

int checkLengthRequirement(char *text) { //Mendefinisikan fungsi checkLengthRequirement, yang mengambil pointer ke string text
    int length = strlen(text); //Menghitung panjang teks ke dalam variabel length
    if (length < MIN_LENGTH) //Melakukan pengecekan apakah panjang teks kurang dari nilai variabel MIN_LENGTH
        return 0; //Jika true, maka akan mengembalikan nilai 0 dan fungsi lessThanRequired akan dijakankan
    else if (length == MIN_LENGTH) //Jika false, namun sama dengan nilai variabel MIN_LENGTH
        return 1; //Maka akan mengembalikan nilai 1 dan fungsi equalThanRequired dijalankan
    else //Jika false dari kedua pernyataan sebelumnya, atau nimai sama dengan lebih dari nilai di MIN_LENGTH
        return 2; //Maka akan mengembalikan nilai 2, fungsi moreThanRequired dijalankan
}

int main() { //Mendefinisikan fungsi main
    int lengthOfText, selectOption; //Mendeklarasikan dua variabel integer lengthOfText dan selectOption
    FILE *fptr = NULL; //Mendeklarasikan pointer fptr ke struktur FILE dengan inisiasi NULL
    char text[MAX_LENGTH]; //Pendeklarasian variabel text sebagai array dengan panjang maksimum MAX_LENGTH, untuk menyimpan teks yang dibaca dari file

    fptr = fopen("file.txt", "r"); //Membuka file bernama "file.txt" dalam mode read dan menetapkan file pointer ke fptr

    if (fptr == NULL) { //Melakukan pengecekan pembukaan file
        printf("Error"); //Jika tidak berhasil, akan dicetak pesan kesalahan
        exit(1); //Perintah keluar dari program dengan kode kesalahan 1, yang menandakan kesalahan pada pembukaan file
    }

    fgets(text, MAX_LENGTH, fptr); //Membaca string dari file yang terbuka ke dalam array text, dengan panjang maksimum MAX_LENGTH

    fclose(fptr); //Menutup file yang telah dibuka

    selectOption = checkLengthRequirement(text); //Memanggil fungsi checkLengthRequirement untuk menentukan selectOption berdasarkan panjang teks yang dibaca

    void (*functionPtr[])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired}; //Membuat array dari pointer ke fungsi yang mengambil pointer ke integer, dan menginisialisasinya dengan tiga fungsi yang telah didefinisikan sebelumnya
    functionPtr[selectOption](&lengthOfText); //Memanggil fungsi yang sesuai dari array functionPtr berdasarkan nilai selectOption dan meneruskan alamat variabel lengthOfText ke dalamnya

    printf("Length Before: %d", strlen(text)); //Mencetak panjang teks sebelumnya menggunakan fungsi strlen()
    
    printf("\nThe Length is updated to %d", lengthOfText); //Mencetak panjang teks yang telah diupdate

    return 0;
}
