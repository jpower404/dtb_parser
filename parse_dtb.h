#ifndef PARSE_DTB_H
#define PARSE_DTB_H

#include <vector>

// read the DTB file into memory
bool readDTBFile(const char* filename, std::vector<char>& dtbData);

// print the top-level nodes
void printTopLevelNodes(const void* fdt);

#endif
