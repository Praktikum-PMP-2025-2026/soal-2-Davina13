#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char str[100];
    printf("");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; 

    int len = strlen(str);
    char *result = (char *)malloc(len + 1); 
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int j = 0; 
    int b = 0; 

    for (int i = 0; i < len; i++) {
        if (str[i] == '(') {
            b++;
            result[j++] = str[i]; 
        } else if (str[i] == ')') {
            if (b > 0) { 
                b--;
                result[j++] = str[i];
            }
        } else {
            result[j++] = str[i]; 
        }
    }
    result[j] = '\0'; 

    printf("%s\n", result);
    
    free(result); 
    return 0;
}
