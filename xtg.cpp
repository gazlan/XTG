#include "stdafx.h"

#include <stdlib.h>

#define ASCII_SIZE         (256)

BYTE  pTable[ASCII_SIZE];

/* ******************************************************************** **
** @@ ShowHelp()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

static void ShowHelp()
{
   printf("-*-   XTG  *  (c) gazlan, 2013   -*-\n");
   printf("\nXLAT Table Generator\n");
   printf("\nUsage: xtg.com description.txt\n");
   printf("\nDescr: XX: C [One record per line]\n");
   printf("\ncomplains_n_suggestions direct to gazlan@yandex.ru\n");
}

/* ******************************************************************** **
** @@ main()
** @  Copyrt :
** @  Author :
** @  Modify :
** @  Update :
** @  Notes  :
** ******************************************************************** */

int main(int argc,char** argv)
{
   if (argc != 2)
   {
      ShowHelp();
      return 0;
   }

   if (argc == 2 && ((!strcmp(argv[1],"?")) || (!strcmp(argv[1],"/?")) || (!strcmp(argv[1],"-?")) || (!stricmp(argv[1],"/h")) || (!stricmp(argv[1],"-h"))))
   {
      ShowHelp();
      return 0;
   }

   for (int ii = 0; ii < ASCII_SIZE; ++ii)
   {
      pTable[ii] = (BYTE)ii;
   }
   
   FILE*    pIn = fopen(argv[1],"rt");

   int      iHex = 0;
   int      iChr = 0;

   char     pLine[MAX_PATH + 1];

   while (fgets(pLine,MAX_PATH,pIn))
   {
      sscanf(pLine,"%x: %c",&iHex,&iChr);

      pTable[iHex] = (BYTE)iChr;
   }
   
   fclose(pIn);
   pIn = NULL;

   FILE*    pOut = fopen("table.xlt","wb");

   for (int jj = 0; jj < ASCII_SIZE; ++jj)
   {
      fprintf(pOut,"%c",(BYTE)pTable[jj]);
   }

   fclose(pOut);
   pOut = NULL;

   return 0;
}
