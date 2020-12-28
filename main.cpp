#include <rpx.hpp>

#include <fstream>
#include <cstring>

int main(int argc, char** argv) {
	if(argc < 3)
	{
		printf("wiiurpxtool-ng - version " VERSION "\n");
		printf("Compress or decompress RPL/RPX files for Wii U\n\n");
		printf("Usage:\n");
		printf("decompress:\n");
		printf("wiiurpxtool -d <rpx_name> [out_name]\n");
		printf("compress:\n");
		printf("wiiurpxtool -c <rpx_name> [out_name]\n");
		return 0;
	}

	std::ifstream infile(argv[2], std::ios::binary);
	auto rpx_o = rpx::readrpx(infile);
	if (!rpx_o) {
		printf("Couldn't parse input file!\n");
		return -1;
	}
	rpx::rpx rpx = *rpx_o;

	std::ofstream outfile((argc == 3) ? argv[2] : argv[3], std::ios::binary);
	if (strcmp("-d", argv[1]) == 0) {
		printf("decompressing...\n");
		rpx::decompress(rpx);
		rpx::writerpx(rpx, outfile);
	} else if (strcmp("-c", argv[1]) == 0) {
		printf("compressing...\n");
		rpx::compress(rpx);
		rpx::writerpx(rpx, outfile);
	} else {
		printf("invalid operation\n");
		return -1;
	}

	return 0;
}
