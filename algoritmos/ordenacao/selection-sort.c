void selection_sort(int n, int v[])
{
    for (int i = 0; i < n-1; ++i) {
        int min = i;

        for (int j = i+1; j < n; ++j)
            if (v[j] < v[min]) min = j;

        int x = v[i];
        v[i] = v[min];
        v[min] = x;
    }
}