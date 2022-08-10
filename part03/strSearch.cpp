// Copyright 2022 A.SHT

int strSearch(const char* s, const char* p) {
   char *pbeg=p;
   while(*s) {
      if(*s==*p) {
         while(*s==*p) {
           s++;
           p++;
         }
         if(!*p || !*(s-1))
           return 1;
         p=pbeg;
      }
      s++;
   }
   return 0;
}