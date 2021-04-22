#coding=utf8

A = [1, 3, 7, 11, 21, 25,45,78,90]
B = [2, 4, 48, 81, 91]


def find_mid(A, B):
    print(A)
    print(B)
    print('-----------')
    if A[(len(A)-1)//2] == B[(len(B)-1)//2]:
        return A[(len(A)-1)//2]
    if len(A) == 1:
        if len(B) % 2 ==1:
            if(B[(len(B)-1)//2] > A[0]):
                return max(A[0], B[(len(B)-1)//2 -1])
            else:
                return B[(len(B)-1)//2 -1]
        else:
            if A[0] > B[(len(B)-1)//2]:
                #print(min(A[0], B[len(B)//2]))
                #print(B[len(B)//2])
                return min(A[0], B[len(B)//2])
            else:
                #print(B[len(B)//2])
                return B[len(B)//2]
    if len(B) == 1:
        if len(A) % 2 ==1:
            if(A[len(A)//2] > B[0]):
                return max(B[0], A[(len(A)-1)//2 -1])
            else:
                return A[(len(A)-1)//2]
        else:
            if B[0] > A[(len(A)-1)//2]:
                print(min(B[0], A[(len(A)-1)//2 +1]))
                return min(B[0], A[(len(A)-1)//2 +1])
            else:
                return A[len(A)//2]
    if A[(len(A)-1)//2] > B[(len(B)-1)//2]:
        less = min(len(A)-(len(A)-1)//2-1, len(B)//2)
        B = B[less:]
        A = A[:len(A)-less]
        return find_mid(A, B)
    else:
        less = min(len(B)-(len(B)-1)//2-1, len(A)//2)
        A = A[less:]
        B = B[:len(B)-less]
        return find_mid(A, B)

mid = find_mid(A,B)
print("中位数: %s" %mid)
        
