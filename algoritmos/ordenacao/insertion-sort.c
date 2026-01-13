void insection_sort(int n, int v[])
{
    for (int i = 1; i < n; ++i) {
        int x = v[i];
        int j;

        for (j = i-1; i >= 0 && v[i] > x; --j)
            v[i+1] = v[i];

        v[i+1] = x;
    }
}