#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


int count_num_words(char *string) {
  int count = 0;
    const char* it = string;
    int word = 0;
    do switch(*it) {
        case '\0':
        case ' ': case '\t': case '\n': case '\r':
            if (word) { word = 0; count++; }
            break;
        default: word = 1;
    } while(*it++);
    return count;
}

int count_nums(char *string) {
    int c = 0; int numWords = 0; 
    int z = 0;
    int u = 0;
    c = strcspn(string+z, "0123456789");
    if(c == 0) {
      c = strspn(string, "0123456789");
      numWords++;
    }
    if(c == 0) {
      return 0;
    }
    while(c != 0) {
        z += c;
        u = strspn(string+z, "0123456789");
        if(u != 0) {
          numWords++;
        }
        z+=u;
        c = strcspn(string+z, "0123456789");
    }
    return numWords;
}

int main(int argc, char **argv) {

  int n = 0, w = 0, c = 0, l = 0; 
  int f = 20;
  char* out_name; int o = 0;
  int opt;
  int any_set = 0;
  while((opt = getopt(argc, argv, "nwclf:o:")) >= 0) { //cwnl
    switch(opt) {
      case 'n': n = 1; any_set++; break;
      case 'w': w = 1; any_set++; break;
      case 'c': c = 1; any_set++; break;
      case 'l': l = 1; any_set++; break;
      case 'f': f = atoi(optarg); break;
      case 'o': out_name = optarg; o = 1; break;
    }
  }
  if(any_set == 0) {
    c = 1; w = 1; l = 1;
  }
  FILE *out_file;	
  if(o == 1) {
  out_file = fopen(out_name, "w");	
      
	if(out_file == NULL) {
   
        }
  }
  else {
	out_file = fopen("stdout.txt", "w");

	if(out_file == NULL) {
  
        }
  }
  int num_words = 0; int total_words = 0;
  int num_lines = 0; int total_lines = 0;
  int num_chars = 0; int total_chars = 0;
  int num_nums = 0; int total_nums = 0;
  
  int cur_index = optind; 
  FILE *cur_file;
  char *buffer =  (char*)malloc(sizeof(char)*50);
  size_t buff_size = 50;
  char *name;

  while(cur_index < argc) {
    // name = argv[cur_index];
    // printf("File Name: %s\n", name);

    // cur_file = fopen(name, "r");
    // if(cur_file == NULL) {
    //   printf("Could not open %s\n", name);
    // }
    // else {
    //   printf("Successfully opened %s\n", name);
    // }
    // int x = getline(&buffer, &buff_size, cur_file);
    // while(x > 0) {
    
    //   printf("%s\n", buffer);
    //   x = getline(&buffer, &buff_size, cur_file);
    // }
    // fclose(cur_file);


    cur_file = fopen(argv[cur_index], "r");
//	printf("len of %s :%d\n", argv[cur_index], strlen(argv[cur_index]));
//	printf("%s\n", argv[cur_index]);
    if(cur_file == NULL) {
      fprintf(stderr, "%s: No such file or directory\n", argv[cur_index]);
      //printf("%s: No such file or directory\n", argv[cur_index]);
      
      cur_index++;
    }
    else {
    int x = getline(&buffer, &buff_size, cur_file);
    while(x > 0) {
      num_lines++;
      num_chars += x / sizeof(char);
      num_words += count_num_words(buffer);
      num_nums += count_nums(buffer);
      x = getline(&buffer, &buff_size, cur_file);
    }
    // do formatting
    fprintf(out_file, "%-s", argv[cur_index]);
     for(int i = 0; i < f - strlen(argv[cur_index]); i++) {
       fprintf(out_file, " ");
     }
     fprintf(out_file, ":");
     if(c == 1) {
       fprintf(out_file, "%6d", num_chars);
     }
     if(w == 1) {
       fprintf(out_file, "%6d", num_words);
     }
     if(n == 1) {
       fprintf(out_file, "%6d", num_nums);
     }
     if(l == 1) {
       fprintf(out_file, "%6d", num_lines);
     }
     fprintf(out_file, "\n");
     printf("%-s", argv[cur_index]);
     for(int i = 0; i < f - strlen(argv[cur_index]); i++) {
       printf(" ");
     }
     printf(":");
     if(c == 1) {
       printf("%6d", num_chars);
     }
     if(w == 1) {
       printf("%6d", num_words);
     }
     if(n == 1) {
       printf("%6d", num_nums);
     }
     if(l == 1) {
       printf("%6d", num_lines);
     }
     printf("\n");
  //  printf("nums: %d, words: %d, chars: %d, lines: %d\n", num_nums, num_words, num_chars, num_lines);
    total_chars += num_chars; num_chars = 0;
    total_lines += num_lines; num_lines = 0;
    total_nums += num_nums; num_nums = 0;
    total_words += num_words; num_words = 0;
    fclose(cur_file);
    cur_index++;
    }
    }
   fprintf(out_file, "total");
   for(int i = 0; i < f - strlen("total"); i++) {
       fprintf(out_file, " ");
     }
     fprintf(out_file, ":");
     if(c == 1) {
       fprintf(out_file, "%6d", total_chars);
     }
     if(w == 1) {
       fprintf(out_file, "%6d", total_words);
     }
     if(n == 1) {
       fprintf(out_file, "%6d", total_nums);
     }
    if(l == 1) {
      fprintf(out_file, "%6d\n", total_lines);
    }
  
     printf("total");
   for(int i = 0; i < f - strlen("total"); i++) {
       printf(" ");
     }
     printf(":");
     if(c == 1) {
       printf("%6d", total_chars);
     }
     if(w == 1) {
       printf("%6d", total_words);
     }
     if(n == 1) {
       printf("%6d", total_nums);
     }
    if(l == 1) {
      printf("%6d\n", total_lines);
    }
  
  fclose(out_file);
  // printf("t nums: %d,t words: %d,t chars: %d,t lines: %d\n", total_nums, total_words, total_chars, total_lines);
  free(buffer);
}


