#include <iostream>
#include <cstring>
using namespace std;

// deklarasi dari simpul
struct DLNode
{
    int bil;
    struct DLNode *back;
    struct DLNode *next;
};
struct DLNode *head, *tail;

void bentuk_awal()
{
    struct DLNode *awal;
    int j = 0;
    char jawab[2];
    while (1)
    {

        awal = (struct DLNode *)malloc(sizeof(struct DLNode));

        cout << "Masukkan bilangan : ";
        scanf("%d", &awal->bil);

        if (j == 0)
        {
            awal->back = NULL;
            awal->next = NULL;
            tail = awal;
            head = awal;
        }
        else
        {
            head->next = awal;
            awal->next = NULL;
            awal->back = head;
            head = awal;
        }

        cout << "Ada data lagi(y/t):";
        cin >> jawab;
        cout << endl;

        if ((strcmp(jawab, "Y") == 0) || (strcmp(jawab, "y") == 0))
        {
            j++;
            continue;
        }
        else if ((strcmp(jawab, "T") == 0) || (strcmp(jawab, "t") == 0))
            break;
    }
}

void tampil_list_lifo()
{
    struct DLNode *lifo;
    cout << "Data Bilangan yang Telah Diinputkan secara LIFO :\n";
    lifo = tail;
    while (lifo != NULL)
    {
        printf("%d\t", lifo->bil);
        lifo = lifo->next;
    }
    cout << "\n";
}

void tampil_list_fifo()
{
    struct DLNode *fifo;
    cout << "Data Bilangan yang Telah Diinputkan secara FIFO :\n";
    fifo = head;
    while (fifo != NULL)
    {
        printf("%d\t", fifo->bil);
        fifo = fifo->back;
    }
    cout << "\n";
}

void hapus_simpul()
{
    int num;
    struct DLNode *sbl, *hapus, *stl;
    cout << "Masukkan data yang akan dihapus : ";
    scanf("%d", &num);
    hapus = tail;

    // Menghapus Simpul Awal
    if (hapus->bil == num)
    {
        tail = tail->next;
        tail->back = NULL;
        free(hapus);
    }
    else
    {
        do
        {
            sbl = hapus;
            hapus = hapus->next;
        } while (hapus->bil != num);

        // Menghapus Simpul Terakhir
        if (hapus->next == NULL)
        {
            sbl->next = NULL;
            tail = sbl;
            free(hapus);
        }

        // Menghapus Simpul di Tengah
        else
        {
            stl = hapus->next;
            sbl->next = stl;
            stl->back = sbl;
            free(hapus);
        }
    }
}

int main()
{
    bentuk_awal();
    tampil_list_lifo();
    tampil_list_fifo();
    hapus_simpul();
}
