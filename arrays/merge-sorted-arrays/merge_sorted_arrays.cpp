#include <iostream>
#include <vector>
#include <array>

/**
 * Given two sorted arrays, merges both of them into the first array. 
 * (we can assume that the first array is extended to allow enough space for the second array in it)
 */
class MergeSortedArrays {
public:
    static void mergeSortedArrays(int nums1[], int m, int nums2[], int n) {
        int i = 0, j = 0;

        while (i < m + n && j < n) {
            if (nums1[i] <= nums2[j]) {
                i++;
            }
            else {
                for (int k = m + n - 1; k > i; k--) {
                    nums1[k] = nums1[k-1];
                }
                nums1[i] = nums2[j];
                j++;
            }
        }

        while (j < n) {
            nums1[m + j] = nums2[j];
            j++;
        }
    }

    // (When a vector is passed to a function, a copy of the vector is created. So here we pass-by-reference so the changes to the vector are reflected outside of the function.)
    static void mergeSortedArrays(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) { 
        int i = 0, j = 0;

        while (i < m + n && j < n) {
            if (nums1[i] <= nums2[j]) {
                i++;
            }
            else {
                for (int k = m + n - 1; k > i; k--) {
                    nums1[k] = nums1[k-1];
                }
                nums1[i] = nums2[j];
                j++;
            }
        }

        while (j < n) {
            nums1[m + j] = nums2[j];
            j++;
        }
    }
};


// Using templates and iterator
template<class fwit>
void mergeSortedArrays(fwit it1, fwit end1, fwit it2, fwit end2) {
    while (it1 != end1 && it2 != end2) {
        if (*it1 <= *it2) {
            it1++;
        }
        else {
            for (fwit push = std::prev(end1); push != it1; ) {
                fwit temp = push--;
                *temp = *push;
            }
            *it1 = *it2;
            it2++;
        }
    }

    while (end2 != it2) {
        it1--;
        end2--;
        *it1 = *end2;
    }
}

// Print array
template<class fwit>
void print(fwit begin, fwit end) {
    fwit it = begin;

    while (it != end) {
        std::cout << *it << " ";
        it++;
    }

    std::cout << std::endl;
}

template<class T>
void mergeSortedArrays(T& container1, T& container2) {
    mergeSortedArrays(std::begin(container1), std::end(container1), std::begin(container2), std::end(container2));
}

int main() {
    // Primitive arrays
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};

    std::cout << "Using primite array: " << std::endl;
    MergeSortedArrays::mergeSortedArrays(nums1, 3, nums2, 3);

    print(std::begin(nums1), std::end(nums1));
    std::cout << std::endl;

    // Vectors
    std::vector<int> nums3 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums4 = {2, 5, 6};
    
    std::cout << "Using vector: " << std::endl;
    MergeSortedArrays::mergeSortedArrays(nums3, 3, nums4, 3);
    
    print(std::begin(nums3), std::end(nums3));
    std::cout << std::endl;
}