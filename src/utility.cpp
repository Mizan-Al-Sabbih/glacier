#include <utility.h>

char Cursor::consume() {
  if (position.index < contentLength()) {
    position.index++;
    position.column++;
    currentChar = content[position.index];
    if (currentChar == '\n') {
      position.line++;
      position.column = 1u;
    }
    return currentChar;
  }
  return endOfFileChar;
}