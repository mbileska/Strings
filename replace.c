/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: ???                                                        */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *s,
                              const char *pcFrom, const char *pcTo)
{

    /*char* result;*/
    int i, cnt = 0;
    int newWlen = strlen(pcTo);
    int oldWlen = strlen(pcFrom);
 
    
    for (i = 0; s[i] != '\0'; i++) {
        if (strstr(&s[i], pcFrom) == &s[i]) {
            cnt++;
 
           
            i += oldWlen - 1;
        }
    }
 
    /*result = (char*)malloc(i + cnt * (newWlen - oldWlen) + 1);*/
    char result[i+cnt* (newWlen - oldWlen) + 1];
 
    i = 0;
    while (*s) {
       
        if (strstr(s, pcFrom) == s) {
            strcpy(&result[i], pcTo);
            i += newWlen;
            s += oldWlen;
        }
        else{
            result[i++] = *s++;}
    }
 
    result[i] = '\0';
    printf("%s\n", result);
    return cnt;
/*
   size_t count=0;
   size_t lLine = Str_getLength(*pcLine);
   size_t lTo= Str_getLength(*pcTo);
   size_t lFrom = Str_getLength(*pcFrom);
   size_t i = 0;
   size_t j = 0;
   char* result;

   char* temp;
   temp = pcLine;
   char* concatTemp;

   for(i = 0; pcLine[i] != '\0'; i++){
      if(Str_search(&pcLine[i], pcFrom) == &pcLine[i]){
         count++;
         i = i + lFrom;
      }
   }

 result = (char*)malloc(i + count * (lTo - lFrom) + 1);

 i=0;

 while(*pcLine){
   if(Str_search(pcLine, pcFrom) == pcLine){
      Str_copy(&result[i], pcTo);
      i= i+ lTo;
      pcLine = pcLine + lFrom;
   }else{
      result[i++] = *pcLine++;
   }
 }
 result[i] = '\0';
 printf("%s\n", result);
 return count;

   /*

   for(i = 0; pcLine[i] != '\0'; i++){
      if(Str_search(&pcLine[i], *pcFrom)==&pcLine[i]){
         count++;
         i += lFrom-1;
      }
   }
   char *newString = (char *)malloc(i+count*(lLine-lFrom));

   while(*temp){
      if(Str_search(*temp, *pcFrom)==*temp){
         Str_copy(&newString[i], pcTo);
         i += lLine;
         *temp += lFrom;
      }else{
         newString[i++] = *pcLine++;
      }
   }

   printf("%s\n", newString);
   return count;



*/


 /*  if(*pcFrom == '\0'){
      printf("%s\n",pcLine);
      return 0;
   }
   
   temp = pcLine;

   while(temp != NULL){
      *temp = Str_search(*pcLine, *pcFrom);
      count++;
   }

   temp = pcLine;
   concatTemp = pcLine;

   while(*pcLine != '\0'){
      *concatTemp = Str_search(*pcLine, *pcFrom);   /* Creating a char array where
      it begins from the pcFrom till the end*/
 /*     for(i = 0; i < lFrom; i++){
         *concatTemp++; /*Removing the letters of the pcFrom*/
 /*     }
      i = Str_getLength(*concatTemp); /*Finding the new length of the string
      with the letters removed*/
 /*     for(j = 0; j < lLine - i;j++){ /*Removing the initial part of the char array so that
      it gets incremented at the proper index later*/
 /*        *temp++;
      }
      for(j = 0; j < i; j++){
         *temp = *concatTemp;
         *temp++;
         *concatTemp++;
      }
      *pcLine++;

   }
   for(j = 0; j < lLine + (lTo - lFrom); j++){
      *temp--;
   }

   printf("%s\n",temp);
   return count; */

 /*
   char* place;
  
  
   
   temp = pcLine;
   while(temp != NULL){
      *temp = Str_search(*pcLine, *pcFrom);
      count++;
      i += lFrom - 1
   }
   if(count == 0){
      printf("%d\n",*pcLine);
      return 0;
   }
   if(Str_compare(*pcFrom,*pcTo)==0){
      printf("%s\n",*pcLine);
      return count;
   }
   char* temp0[i+ count * (lTo- lFrom)];

   while(*pcLine){
      if(Str_search(pcLine, pcFrom) == pcLine){
         Str_copy(&temp0[i], pcTo);
         i += lTo;
         pcLine += lFrom;
      }else{
         temp0[i++] = *pcLine++;
      }
   }
   temp0[i] = '\0';
   
   printf("%s\n",*temp0);
   return count;
   /* Insert your code here. */
   /*
   char* tempString;
    char* tempSearch;
    char* pcLineTemp;
    pcLineTemp = pcLine;
    tempSearch = pcFrom;
   
   size_t count = 0;
   size_t l = 0;
   size_t i = 0;
   while(*pcLineTemp != '\0'){

        if(*pcLineTemp != *pcFrom){
            pcLineTemp++;
            continue;
        }
        tempString = pcFrom;
        while(1){
            if(*tempSearch == '\0'){
                 count++;
                 l = strlen(*pcFrom);
                 for(i = 0; i < l; i++){
                     *pcLineTemp = *pcFrom;
                     *pcLineTemp++;
                     *pcFrom++;
                  }
            }
            if(*tempString++ != *tempSearch++){
              break;
            }
                
            
        }



   }
   printf("%p\n",*pcLine);
   return count;*/
}
/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char* pcFrom;
   char* pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

  

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL){
      /* Insert your code here. */
      uReplaceCount = replaceAndWrite(acLine, pcFrom, pcTo);

      fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
      return 0;
   }
   
}
