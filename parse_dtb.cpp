#include <iostream>
#include <fstream>
#include <vector>

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

int main() {
    
    const char* dtbFilename = "dtb_files/bcm2708-rpi-b-rev1.dtb";

    // read the DTB file into memory
    std::vector<char> dtbData;
    if (!readDTBFile(dtbFilename, dtbData)) {
        return -1;
    }

    std::cout << "DTB file read successfully!" << std::endl;

    return 0;
}