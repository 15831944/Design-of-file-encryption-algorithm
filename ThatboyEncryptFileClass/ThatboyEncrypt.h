#pragma once

#include "ThatboyCriticalChunk.h"
#include "Base64.h"
#include "USBMassStorageDeviceSerial.h"

namespace thatboy
{
	class EncryptFileStream
	{
	public:
		static constexpr size_t ChunkDataSize = 3 * 4 * 256;	// ����base64���룬ͬʱ4�ֽڶ���
		static constexpr DWORD XORCode = 0B101010101010101010101010;
		static bool Encrypt(std::string file, std::string encryptFile, std::string password = "", std::string deviceSerial = "");
		static bool Decrypt(std::string encryptFile, std::string file = "", std::string password = "", std::string deviceSerial = "");

		EncryptFileStream(const EncryptFileStream&) = delete;
		EncryptFileStream(EncryptFileStream&&) = delete;
	protected:
		EncryptFileStream() = default;


		SignatureDomain signature;
		THDR_Chunk thdrChunk;
		TEND_Chunk tendChunk;
		std::vector<TDAT_Chunk> dataChunk;
			
	};
}
