#include <utility.h>

void Cursor::consume() {
  if (position.index < contentLength()) {
    position.index++;
    position.column++;
    currentChar = content[position.index];
  }
}