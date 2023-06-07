#include <stdio.h>
#include <stdint.h>

struct pack_array {
    uint32_t array; // поле для хранения упакованного массива из 0 и 1
    uint32_t count0 : 8; // счетчик нулей в array
    uint32_t count1 : 8; // счетчик единиц в array
} pack_struct;

int input_array[32];

void array2struct(int array[], struct pack_array * pack_in) {

    const int arr_size = 32;

    pack_in->count1 = 0;
    for(size_t i=0; i<arr_size; i++) {

        if(array[i]){
            pack_in->count1++;
        }
    }

    pack_in->count0 = arr_size - pack_in->count1;

    pack_in->array = 0;
    for (size_t i = 0; i < arr_size; i++) {

        pack_in->array = (pack_in->array << 1) | array[i];
    }
}

int main() {
    for(size_t i=0; i<32; i++) {

        scanf("%u", &input_array[i]);
    }

    array2struct(input_array, &pack_struct);

    printf("%x\n", pack_struct.array);
    printf("%u\n", pack_struct.count0);
    printf("%u\n", pack_struct.count1);
    return 0;
}
