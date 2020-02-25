int hIndex(int* A, int n){
    if(n ==0)
        return 0;
    int max = A[0];
    for (int i=0;i<n;i++)
    {
        if(A[i] > max)
            max = A[i];
    }
    int h = 0;
    int minim = 1000000000;
    int  i;
    int minim_index = 0;
    //printf("%d %d\n",min,max);
    for (i = 0; i <= max; i++)
    {
        h =0;
        for (int j = 0; j < n; j++)
        {
          //  printf("%d>=%d\n",A[j],i);
            if(A[j] >= i)
                h += 1;
        }
        //printf("%d\n",h);
        if(h-i <= minim && h-i>=0)
        {    minim = h-i;
            minim_index = i;}
        if(h-i < 0 )
            break;
    }
    return minim_index;
    

}