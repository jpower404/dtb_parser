#ifndef PARSE_DTB_H
#define PARSE_DTB_H

#include <vector>

// Function to read the DTB file into memory
bool readDTBFile(const char* filename, std::vector<char>& dtbData);

#endif
