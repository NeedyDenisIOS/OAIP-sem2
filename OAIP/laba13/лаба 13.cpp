#include<iostream>
#include<ctime>

using std::endl; using std::cin; using std::cout;

class Heap
{
    int size = 10;
    int* heap = new int[size];

    void checkup(int index)
    {
        int p;
        p = index / 2;
        if (heap[p] > heap[index])
        {
            std::swap(heap[index], heap[p]);
            checkup(p);
        }
    }

    void checkdown(int p)
    {
        int c;
        c = 2 * p;
        if (c > size) return;
        if (c + 1 <= size && heap[c + 1] < heap[c]) c++;

        if (heap[c] < heap[p])
        {
            std::swap(heap[c], heap[p]);
            checkdown(c);
        }
    }

public:

    Heap(int size)
    {
        this->size = size;
        heap = new int[size];
    }

    void push(int x, int index)
    {
        heap[index] = x;
        checkup(index);
    }

    void output()
    {
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << '\t';
        }
    }

    int min()
    {
        return heap[0];
    }

    void erase(int index)
    {
        std::swap(heap[size - 1], heap[index]);
        heap = std::decay_t<int*>(realloc(heap, (size--) * sizeof(heap[0])));
        checkdown(index);
    }

    void outHeap(void)
    {
        int i = 0;
        int k = 1;
        while (i < size)
        {
            while ((i < k) && (i < size))
            {
                cout << heap[i] << " ";
                i++;
            }
            cout << endl;
            k = k * 2 + 1;
        }
    }

    friend void include(Heap& heap, Heap h1, Heap h2);
    friend int association(Heap& a1, Heap& a2);
};

void include(Heap& heap, Heap h1, Heap h2)
{
    cout << endl;
    int* buf = new int[h1.size + h2.size];
    for (int i = 0; i < h1.size; i++)
    {
        buf[i] = h1.heap[i];
    }
    for (int i = 0; i < h2.size; i++)
    {
        buf[i + h1.size] = h2.heap[i];
    }
    cout << endl;
    for (int i = 0; i < h1.size + h2.size; i++)
    {
        heap.push(buf[i], i);
    }
}

int association(Heap& a1, Heap& a2)
{
    return a1.size + a2.size;
}

int main()
{
    srand((unsigned int)time(NULL));
    setlocale(LC_ALL, "ru");
    int n = 0; cout << "Введите количество элементов кучи: "; cin >> n;
    Heap* heap = new Heap(n);
    int n1 = 0; cout << "Введите количество элементов второй кучи: "; cin >> n1;
    Heap* heap1 = new Heap(n1);

    for (int i = 0; i < n; i++)
    {
        int a = rand() % 10 + 1;
        cout << a << '\t';
        heap->push(a, i);
    }
    cout << endl;
    heap->output();
    cout << endl << heap->min();
    cout << endl;
    heap->outHeap();
    int index = 0; cout << "Введите индекс, который хотите удалить: " << endl; cin >> index;
    heap->erase(index);
    cout << endl;
    heap->output();
    cout << endl;
    heap->outHeap();
    cout << endl << "Объдинение двух куч: " << endl;
    for (int i = 0; i < n; i++)
    {
        int a = rand() % 10 + 1;
        cout << a << '\t';
        heap1->push(a, i);
    }
    cout << endl;
    heap1->output();
    cout << endl;
    Heap* union_heap = new Heap(static_cast<int>(association(*heap, *heap1)));
    include(*union_heap, *heap, *heap1);
    union_heap->output();
    cout << endl;
    union_heap->outHeap();
}