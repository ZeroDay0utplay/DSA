int binarySearch(int arr[], int target, int begin, int end){
    int mid;
    while (begin <= end){
        mid = (begin + end) / 2;
        if (target == arr[mid]){
            printf("[+] Found.");
            return 1;
        }
        else if (target < arr[mid]) end = mid - 1;
        else begin = mid + 1;
    }
    printf("[!] Not Found.");
    return 0;
}