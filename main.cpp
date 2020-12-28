#include <rpx.hpp>

#include <fstream>
#include <cstring>

int main(int argc, char** argv) {
	if(argc < 4)
	{
		printf("wiiurpxtool - version:1.3\n");
		printf("Compress or decompress RPL/RPX files for Wii U\n\n");
		printf("Usage:\n");
		printf("decompress:\n");
		printf("wiiurpxtool -d <rpx_name> [out_name]\n");
		printf("compress:\n");
		printf("wiiurpxtool -c <rpx_name> [out_name]\n");
		return 0;
	}

	std::ifstream infile(argv[2], std::ios::binary);
	auto elf_o = readrpx(infile);
	if (!elf_o) {
		printf("Couldn't parse input file!\n");
		return -1;
	}
	auto elf = *elf_o;

	std::ofstream outfile(argv[3], std::ios::binary);
	if (strcmp("-d", argv[1]) == 0) {
		printf("decompressing...\n");
		decompress(elf);
		writerpx(elf, outfile);
	} else if (strcmp("-c", argv[1]) == 0) {
		printf("compressing...\n");
		compress(elf);
		writerpx(elf, outfile);
	} else {
		printf("invalid operation\n");
		return -1;
	}

	return 0;
}
