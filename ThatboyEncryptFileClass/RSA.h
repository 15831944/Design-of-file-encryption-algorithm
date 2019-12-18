#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>


class RSA {
public:
	using LONG = int32_t;
	using LONGLONG = int64_t;
	using LONG_PTR = LONG*;
	using LONG_CPTR = const LONG*;

	struct Key {
		//��Կ(public_key, share_key)
		LONGLONG share_key;
		LONGLONG public_key;
		//˽Կ(private_key, share_key)
		LONGLONG private_key;
	};

	RSA();
	Key GetKey() {
		return _key;
	}

	//�����ݽ��м��ܽ���
	void encrypt(LONG_CPTR dataIn, size_t dataInSize, LONG_PTR dataOut, LONG public_key, LONG share_key);
	void decrypt(LONG_CPTR dataIn, size_t dataInSize, LONG_PTR dataOut, LONG private_key, LONG share_key);

private:
	//��������
	LONG producePrime();
	//�ж�һ�����Ƿ�������
	bool isPrime(LONG prime);
	//�������е�keyֵ
	void produceKeys();
	//��share_kay
	LONG produceShareKey(LONG prime1, LONG prime2);
	//����ŷ��������˻�
	LONG produceOrla(LONG prime1, LONG prime2);
	//��public_key
	LONG producePublicKey(LONG orla);
	//�ж�������֮������Լ�Ƿ�Ϊ1
	LONG gcd(LONG public_key, LONG orla);
	//��private_key
	LONG producePrivateKey(LONG public_key, LONG orla);
	//���ܵ�����Ϣ
public:
	LONG encrypt(LONG msg, LONG key, LONG share_key);
private:
	Key _key;
};