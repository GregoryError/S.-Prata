#include <iostream>
#include <algorithm>
#include <ctime>

template <class Item>
int partition(Item a[], int l, int r)
{
    int j = l - 1;
    int i = r;
    Item v = a[r];
    for (;;)
    {
        while (a[++j] < v) ;
        while (a[--i] > v) if (j == i) break;
        if (j >= i) break;
        Item t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    Item t = a[r];
    a[r] = a[i];
    a[i] = t;
    return i;
}



template <class Item>
void qSort(Item a[], int l, int r)
{
    if (l >= r) return;
    int i = partition(a, l, r);
    qSort(a, l, i - 1);
    qSort(a, i + 1, r);
}

int main()
{
    double arr[40];
    std::srand(std::time(0));
    std::generate(std::begin(arr), std::end(arr), [](){ return std::rand() % 100; });
    qSort(arr, 0, 40);

    for (const auto& v : arr)
        std::cout << v << std::endl;

    return 0;
}
