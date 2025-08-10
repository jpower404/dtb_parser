# dtb_parser

A C++ project to parse Device Tree Blobs (DTBs) and extract properties from specified subnodes.

## Prerequisites

To run this project, you will need the following dependencies:

- **DTB File**: A Device Tree Blob file, which is required for the program to parse. The example DTB file is from the [Raspberry Pi GitHub repository](https://github.com/raspberrypi/firmware/blob/master/boot/bcm2708-rpi-b-plus.dtb).
- **libfdt**: A C library used for working with Device Tree files. It is required for parsing DTB files.

### Installing Dependencies

1. Install `dtc` on **Ubuntu/Debian**:
     ```bash
     sudo apt-get install device-tree-compiler
     ```

1. Install `libfdt` on **Ubuntu/Debian**:
     ```bash
     sudo apt-get install libfdt-dev
     ```

## How to Decompile a DTB File into DTS

If you want to inspect the contents of a DTB file (including the properties), you can use the `dtc` (Device Tree Compiler) command to decompile it into a readable **DTS** (Device Tree Source) format.

1. Decompile the DTB file into a DTS file:
    ```bash
    dtc -I dtb -O dts -o output.dts input.dtb
    ```
    - -I dtb: Specifies input file-type is DTB

    - -O dts: Specifies output file-type is DTS

    - -o output.dts: Specifies output file name

    - input.dtb: DTB file you want to decompile

    - Once decompiled, you can open the .dts file to view the properties and structure of the DTB.

## Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/jpower404/dtb_parser.git
   cd dtb-parser
   ```

2. Update DTB filepath

3. Compile and run
    ```
    g++ -o parse_dtb parse_dtb.cpp -lfdt
    ./parse_dtb
    ```