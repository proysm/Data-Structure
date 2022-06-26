//--------------------------------------------------------------------
//
//  Laboratory C, In-lab Exercise 2                        sort.cpp
//
//  Implementation of a set of sorting routines
//
//--------------------------------------------------------------------

template < class DT >
void selectionSort(DT keyList[], int numKeys)

// Selection sort routine. Sorts the first numKeys keys in keyList
// into ascending order.

{
    int min; // 최소값
    int temp;

    for (int i = 0; i < numKeys - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < numKeys; j++)
        {
            if (keyList[j] < keyList[min]) min = j;
        }
        temp = keyList[i];
        keyList[i] = keyList[min];
        keyList[min] = temp;
    }
}

//--------------------------------------------------------------------

template < class DT >
void quickPartition(DT keyList[], int numKeys, int left, int right);

template < class DT >
void quickSort(DT keyList[], int numKeys)

// Quicksort routine. Sorts the first numKeys keys in keyList into
// ascending order.

{
    quickPartition(keyList, numKeys, 0, numKeys - 1);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < class DT >
void quickPartition(DT keyList[], int numKeys,
    int left, int right)

    // Recursive partner of the quickSort routine. Partitions the array
    // entries between left and right into two subarrays. One subarray
    // contains the keys that are less than or equal to splitValue, and
    // the other contains the keys that are greater than splitValue.
    // Recursively sorts each of these subarrays.

{
    if (left >= right) return;

    DT temp;
    int norm = left;
    int iL = left + 1,
        iR = right;


    while (iL < iR)
    {
        while (iL < right && keyList[iL] <= keyList[norm]) iL++;
        while (iR > left && keyList[iR] >= keyList[norm]) iR--;
        if (iL > iR)
        {
            temp = keyList[norm];
            keyList[norm] = keyList[iR];
            keyList[iR] = temp;
        }
        else
        {
            temp = keyList[iL];
            keyList[iL] = keyList[iR];
            keyList[iR] = temp;
        }
    }
    quickPartition(keyList, numKeys, left, iR - 1);
    quickPartition(keyList, numKeys, iR + 1, right);

}

//--------------------------------------------------------------------

template < class DT >
void bubbleSort(DT keyList[], int numKeys)

{
    DT temp; // 값을 바꿔주기 위한 임시 공간

    for (int i = 0; i < numKeys; i++)
    {
        for (int j = 0; j < numKeys - i - 1; j++)
        {
            if (keyList[j] > keyList[j + 1])
            {
                temp = keyList[j + 1];
                keyList[j + 1] = keyList[j];
                keyList[j] = temp;
            }
        }
    }
}
