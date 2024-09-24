#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	
	FILE *fptr;
	
//	char file_input[100];
//	
////	printf("Enter path of source file: ");
////	scanf("%s", file_input);
	
	fptr = fopen("newfile_2.txt", "r");
	
	if(!fptr){
		
		printf("file not found...\n");
		exit(1);
		fclose(fptr);
		
	}
	
	char *str;
	char *buffer;
	int init_size = 10;
	int buffer_size = 10;
	int i = 0;
	
	str = (char *)malloc(init_size * sizeof(char));
	buffer = (char *)malloc(buffer_size * sizeof(char));
	
	while(fscanf(fptr, "%c", buffer) != EOF){
		
		int j = 0;
		int n = strlen(buffer);
		
		if(n >= buffer_size - 1){
			
			buffer_size *= 2;
			buffer = realloc(buffer, buffer_size);
		}
		
		if(n + i >= init_size){
			
			init_size = (n + i) * 2;
			str = realloc(str, init_size); 
		}
		
		str[i] = buffer[j];
		i++;
		str[i] = ' ';
	}
	
	str[i] = '\0';
	
	free(buffer);
	
	fclose(fptr);
	
	printf("%s\n", str);
	
	printf("\n");
	
	char input[50];
	char replace[50];
	
	printf("Enter word to replace: ");
	scanf("%s", input);
	
	printf("Replace '%s' with: ", input);
	scanf("%s", replace);
	
	int len_str = strlen(str);
	int j = 0;
	int index = 0;
	int len_input = strlen(input);
	int len_replace = strlen(replace);
	int new_space = len_replace - len_input;
	int k = 0;
	
	
	while(index < len_str){
		
		char temp[1000] = {};

		while(str[k] != ' ' && str[k] != '\0' && str[k] != '.' && str[k] != '\n'){
			
			temp[j] = str[k];

			k++;
			j++;
			index++;
		}
		
		j = 0;
		
		if(strcmp(temp, input) == 0){
			
			char temp1[1000] = {};
			
			while(str[k] != '\0'){
				
				temp1[j] = str[k];
				str[k] = ' ';
				k++;
				j++;
			}
			
			j = 0;
			len_str = len_str + new_space;
			k = k - strlen(temp1) + new_space;
			
			
			while(k < len_str){
				
				str[k] = temp1[j];
				k++;
				j++;
			}
			
			j = 0;
			k = k - (strlen(temp1) + new_space + len_input);
			int rep = k + len_replace;
			
			while(k < rep){
				
				str[k] = replace[j];
				k++;
				j++;
				
			}
		}
		
		index++;
		k++;
		j = 0;
		
	}
	
	printf("Successfully replaced all occurences of '%s' with '%s'.\n", input, replace);
	printf("\n");
	printf("%s", str);
	
	fptr = fopen("newfile_2.txt", "w");
	
	fprintf(fptr, "%s", str);

	fclose(fptr);
	free(str);
	
	
	return 0;
}
