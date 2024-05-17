#include <stdio.h>

int contains_substring(const char * stringone, const char * substring){
    for (int i = 0; stringone[i] != '\0'; i++) {
        int j = 0;
        while (substring[j] != '\0' && stringone[i + j] == substring[j]) {
            j++;
        }
        if (substring[j] == '\0') {
            return i;
        }
    }
    return -1;
}
int main(){
    int position = contains_substring("kaisa", "i");
   int position2 = contains_substring("kaisa", "lala");

   printf("%d %d ", position, position2);
   
    return 0;
}