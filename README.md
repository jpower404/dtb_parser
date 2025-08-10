# dtb_parser
A C++ project to parse Device Tree Blobs (DTBs) and extract properties from specified subnodes.

## Prerequisites

- To run this project, you need to have a **DTB file** (Device Tree Blob file).

### Example DTB file used for this project:

- The example DTB file is from the [Raspberry Pi GitHub repository](https://github.com/raspberrypi/firmware/blob/master/boot/bcm2708-rpi-b-plus.dtb).

## How to Decompile a DTB File into DTS

If you want to inspect the contents of a DTB file (including the properties), you can use the `dtc` (Device Tree Compiler) command to decompile it into a readable **DTS** (Device Tree Source) format. Here's how you can do it:

1. Install `dtc` if you don't have it:
   - On Ubuntu/Debian, use:
     ```bash
     sudo apt-get install device-tree-compiler
     ```

2. Decompile the DTB file into a DTS file:
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
    g++ -o parse_dtb parse_dtb.cpp
    ./parse_dtb
    ```