#include <fstream>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <future>

using namespace std;
const int THREAD_COUNT = 4;
#define MAX_LINE_LENGTH 256
#define BREADSTICKS "breadsticks"
#define BREADSTICKS_LNGTH  11

int buildChunks(char *pBegin, char *pEnd) {
  char pCurrentLine[MAX_LINE_LENGTH];
  char *pCurrent = pBegin;
  char *pBreadVal;
  char *pEol;
  char *pStartOfNum;
  int iNumSize;
  int iTotal = 0;

  while (pCurrent < pEnd) {
    pEol = strstr(pCurrent, "\n");
    if (!memcmp(pCurrent, BREADSTICKS, BREADSTICKS_LNGTH)) {
      pStartOfNum = pCurrent + BREADSTICKS_LNGTH + 1;
      iNumSize = pEol - pCurrent;
      char *pValueDest = (char*)calloc(iNumSize + 1, sizeof(char));
      memcpy(pValueDest, pStartOfNum, iNumSize);
      iTotal += atoi(pValueDest);
      free(pValueDest);
    }
    pCurrent = pEol + 1;
  }
  return iTotal;
}


int main () {
  ifstream is("../word_number.txt");
  int iLength = 0;
  int iChunkSize = 0; iLength / THREAD_COUNT;
  char *pFileBuffer = nullptr;
  char *boundraries[THREAD_COUNT];

  is.seekg(0, is.end);
  iLength = is.tellg();
  iChunkSize = iLength / THREAD_COUNT;
  pFileBuffer = (char*) malloc(sizeof(char) * iLength);
  is.seekg(0);
  is.read(pFileBuffer, iLength);

  char *boundrary = pFileBuffer + iChunkSize;
  for(int i = 0; i < THREAD_COUNT - 1; i++) {
    while (*boundrary != '\n') {
      boundrary++;
    }

    boundraries[i] = boundrary;
    boundrary = boundrary + iChunkSize + 1;
  }

  char *pStartPos = pFileBuffer;
  future<int> thrdMunchers [THREAD_COUNT];
  for(int i = 0; i < THREAD_COUNT - 1; i++) {
    thrdMunchers[i] = async(buildChunks, pStartPos, boundraries[i]);
    pStartPos = boundraries[i] + 1;
  }
  // could probably make clean by adding iLength -1 to boundraries array
  thrdMunchers[THREAD_COUNT - 1]  = async(buildChunks, pStartPos, pFileBuffer + iLength);
  is.close();

  int iTotal = 0;
  for(int i = 0; i < THREAD_COUNT; i++) {
     iTotal += thrdMunchers[i].get();
  }

  free(pFileBuffer);
  cout << iTotal << '\n';


}
