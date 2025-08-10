#include <iostream>
#include <fstream>
#include <vector>
#include <libfdt.h>
#include <cstring>
#include <unordered_set>

bool readDTBFile(const char* filename, std::vector<char>& dtbData) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open DTB file: " << filename << std::endl;
        return false;
    }

    // get file size, read the data into vector
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    dtbData.resize(size);
    file.read(dtbData.data(), size);

    return true;
}

// print top-level nodes
void printTopLevelNodes(const void* fdt) {
    int offset = 0;
    int node_offset;
    int depth = 0;

    // store the names of visited nodes
    std::unordered_set<std::string> visitedNodes;

    // print the top-level ones (depth == 1)
    while ((node_offset = fdt_next_node(fdt, offset, &depth)) != -1) {
        const char* node_name = fdt_get_name(fdt, node_offset, nullptr);

        // process and print the top-level nodes (depth == 1)
        if (depth == 1) {
            // check if the node has already been processed
            if (visitedNodes.find(node_name) != visitedNodes.end()) {
                // if yes, break the loop
                break;
            }

            // print node name and add to visited set
            std::cout << "Found node: " << node_name << " at depth " << depth << std::endl;
            visitedNodes.insert(node_name);
        }

        // update offset to next node
        offset = node_offset;
    }
}

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path_to_dtb_file>" << std::endl;
        return -1;
    }

    const char* dtbFilename = argv[1];

    // read the DTB file into memory
    std::vector<char> dtbData;
    if (!readDTBFile(dtbFilename, dtbData)) {
        return -1;
    }

    const void* fdt = dtbData.data();
    if (fdt_check_header(fdt) != 0) {
        std::cerr << "Error: Invalid DTB file." << std::endl;
        return -1;
    }

    std::cout << "DTB file read successfully!" << std::endl;

    // Print the top-level nodes
    printTopLevelNodes(fdt);

    return 0;
}
