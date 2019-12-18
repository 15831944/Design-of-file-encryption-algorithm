#pragma once
#include "ThatboyEncryptBase.h"

namespace thatboy
{

	/********************************** �ļ�ͷ **********************************/
	class THDR_Chunk final
		: public Chunk
	{
	public:
		THDR_Chunk();

		std::ostream& write(std::ostream&)const;
		std::istream& read(std::istream&);
		bool checkCrcCode(BYTE crcEncodeType = defaultCrcType)const;
		void doFigure(BYTE crcEncodeType = defaultCrcType);


		BYTE crcEncodeType;		// CRCУ������
		BYTE reserve[3];		// ����
	};

	/********************************** �ļ�β **********************************/
	class TEND_Chunk final
		: public Chunk
	{
	public:
		TEND_Chunk();
		bool checkCrcCode(BYTE crcEncodeType = defaultCrcType)const;
		void doFigure(BYTE crcEncodeType = defaultCrcType);

	protected:
	};

	/********************************** ���ݿ� **********************************/
	class TDAT_Chunk 
		: public Chunk
	{
	public:
		TDAT_Chunk();

		std::ostream& write(std::ostream&)const;
		std::istream& read(std::istream&);
		bool checkCrcCode(BYTE crcEncodeType = defaultCrcType)const;
		void doFigure(BYTE crcEncodeType = defaultCrcType);

		std::vector<BYTE> compressData;// zibѹ������
	};


}
