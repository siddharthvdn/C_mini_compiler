int main()
{
    int a[] = {16, 19, 11, 15, 10, 12, 14},i,j;
	j=0;
    //repeating loop 7 (number of elements in the array) times
    while(j<7)
    {
        //initially swapped is false
        int swapped = 1;
        i = 0;
	
        while(i<6)
        {
            //comparing the adjacent elements
            if (a[i] > a[i+1])
            {
                //swapping
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                //Changing the value of swapped
                swapped = 0;
            }
            i = i+1;
        }
        //if swapped is false then the array is sorted
        //we can stop the loop
        if (swapped)
            break;
	j++;
    }
return 0;
}
