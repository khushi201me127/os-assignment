#include <stdio.h>
#include <stdlib.h>

int main()
{
   char ch, source_file[20], target_file[20];
   FILE *source, *target;

   printf("Enter name of the source file : ");
   scanf("%s", source_file);

   source = fopen(source_file, "r");

   if (source == NULL)
   {
      printf("Cannot open file %s \n", source_file);
      exit(0);
   }

   printf("Enter name of the destination file : ");
   scanf("%s",target_file);

   target = fopen(target_file, "w");

   if (target == NULL)
   {
      fclose(source);
      printf("Cannot open file %s \n", target_file);
      exit(0);
   }

   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);

   printf("File copied successfully.\n");

   fclose(source);
   fclose(target);

   return 0;
}
