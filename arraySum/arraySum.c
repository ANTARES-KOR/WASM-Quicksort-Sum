// To compile to WASM, use: https://wasdk.github.io/WasmFiddle/

int arraySum (int arr[], int arrLen) 
{
    int sum = arr[0];
    for (int i = 1; i < arrLen; i++) {
        sum += arr[i];
    };
    return sum;
};