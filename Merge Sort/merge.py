def mergeSort(alist):
    if len(alist)>1:
        print("Splitting ",alist)
        mid = len(alist)//2
        print("\tmidlle: ", mid)
        lefthalf = alist[:mid]
        print("\tleftHalf: ", lefthalf)
        righthalf = alist[mid:]
        print("\trightHalf: ", righthalf)
        print("\n")

        mergeSort(lefthalf)
        mergeSort(righthalf)

        # print("\t\tLeft now: ", lefthalf)
        # print("\t\tRight now: ", righthalf)
        print("\t\tMerging ", lefthalf, righthalf)

        i=0
        j=0
        k=0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k] = lefthalf[i]
                i += 1
            else:
                alist[k] = righthalf[j]
                j += 1
            k += 1

        while i < len(lefthalf):
            alist[k] = lefthalf[i]
            i += 1
            k += 1

        while j < len(righthalf):
            alist[k] = righthalf[j]
            j += 1
            k += 1
    print("\t\tMerged: ",alist)

alist = [54,26,93,17,77,31,44,55,20]
mergeSort(alist)
print(alist)