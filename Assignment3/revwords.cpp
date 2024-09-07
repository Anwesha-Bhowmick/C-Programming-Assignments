#include <ctype.h>
#include <string.h>
#include "revwords.h"
#include <iostream>

using namespace std;

void reverse_substring(char str[], int start, int end)
{
  // reversing the substring beginning at "start" and ending at "end"
  char temp;
  // std::cout << "\ninside reverse_substring\n";
  while (start < end)
  {
    temp = str[start];
    str[start] = str[end]; // swap
    str[end] = temp;
    start++; // moving to the next character
    end--;   // moving to the previous character
  }
  // std::cout << "\noutside reverse_substring\n";
}

int find_next_start(char str[], int len, int i)
{
  /* TODO */
  int k;
  // std::cout << "\ninside find_next_start\n";
  if (i == 0 && len > 0) // string is non-empty
  {
    k = 0; // first character of first word
    return k;
  }
  for (i; i < len; i++)
  {
    if ((str[i] == ' ') && (i + 1 < len)) // second condition for case where the sentence might end with a space
    {
      k = i + 1; // character after the space is the required character
      return k;
    }
  }
  // std::cout << "\noutside find_next_start\n";
  return -1; // reached the end
}

int find_next_end(char str[], int len, int i)
{
  // std::cout << "\ninside find_next_end\n";
  /* TODO */
  int k;
  for (i; i < len; i++)
  {
    if (str[i] == ' ' || str[i] == '"' || str[i] == '.' || str[i] == '!' || str[i] == '?') // the string might end with any of these
    {
      k = i - 1; // character before the space or ending charcters, is the required character
      return k;
    }
  }
  // std::cout << "\noutside find_next_end\n";
  return -1; // no such i < len found
}

void reverse_words(char s[])
{
  /* TODO */
  int i, stringLength = strlen(s);
  int start = 0, end = 0;                               // initially both point to the first character of the string
  while (find_next_start(s, stringLength, start) != -1) // loop until the last word
  {
    start = find_next_start(s, stringLength, end); // next word begins after "end"
    end = find_next_end(s, stringLength, start);   // using the value of start, begin scanning till the end of that word
    reverse_substring(s, start, end);              // function call
  }
}
