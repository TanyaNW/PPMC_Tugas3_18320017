#include<stdio.h>
#include<stdlib.h>

// membuat fungsi yang membandingkan dua buah array
// panjang array yang akan dibandingkan, dapat ditetapkan secara fleksibel
// kedua array tidak perlu sama besar
char bandingkanArray(int a[], int b[], int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        if (a[i] != b[i]) // membandingkan masing-masing elemen dari kedua array, dengan posisi yang sama
        {
            return 0;
        }
        else
        {
            return 1; // array sama persis untuk jumlah elemen pertama yang ditetapkan
        }
    }
}

int
main()
{
    // inisiasi variabel
    FILE *filenya;
    char c;

    char arrayCek[5]; // menerima 5 karakter pertama file
    int i = 0,
        j = 0,
        k = 0;

    // inisisi array yang akan dibandingkan dengan array yang didapat dari file
    // array berupa file signature dari file PDF dan JPG
    char *arrayPDF[] = {"25", "50", "44", "46", "2D"};
    char *arrayJPG[] = {"FF", "D8", "FF", "E1"};

    // membuka file dan membacanya
    filenya = fopen("file.xxx", "r");

    // memastikan file tidak kosong
    if (filenya = NULL)
    {
        printf("file kosong");
    }

    else
    {
        // memasukkan 5 karakter pertama dari file ke arrayCek
        for (i = 0, j = 0; i <= 5 && c != EOF; i++)
        {
            arrayCek[j] = c;
            j++;

            c = fgetc(filenya);
        }


        if (bandingkanArray(arrayPDF, arrayCek, 5) == 1) // membandingkan arrayCek dengan arrayPDF
        {
            printf("File berupa PDF"); // jika sama, maka file berupa file PDF
        }

        else if (bandingkanArray(arrayJPG, arrayCek, 4) == 1) // membandingkan 4 elemen pertama arrayCek dengan arrayJPG
        {
            printf("File berupa JPG"); //jika sama, maka file berupa file JPG
        }

        else // file buka PDF maupun JPG, maka file tidak dikenali
        {
            printf("File tidak dikenali");
        }
    }

    return(0);
}

