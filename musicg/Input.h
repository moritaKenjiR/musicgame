#pragma once
#include <memory>
#include <map>
#include <unordered_map>

struct  PeripheralInfo {
	PeripheralInfo() {};
	PeripheralInfo(int perin, int cd) :periNo(perin), code(cd) {};
	int periNo;		// ���Ӌ@��ԍ�
	int code;		//���Ӌ@��̐�����
	struct HashFunc 
	{
		size_t operator()(const PeripheralInfo& p)const
		{
			return p.periNo | (p.code << 4);
		}
	};
};

bool operator<(const PeripheralInfo & lval, const  PeripheralInfo & rval);
bool operator==(const PeripheralInfo & lval, const  PeripheralInfo & rval);
bool operator!=(const PeripheralInfo & lval, const  PeripheralInfo & rval);

class Input
{
public:
	Input();
	~Input();

	//�ڑ����ꂽ�߯�ސ���Ԃ�
	int GetConnectedPadCount(void)const;

	//��ڲ԰���̐ݒ�
	void SetPlayerCount(int plcount);

	//����ނ̐ݒ�
	//@param plNo ��ڲ԰�ԍ�
	//@param cmd ����ޖ�
	//@param periNo ���Ӌ@��ԍ�
	//@param code ���ͺ���
	void AddCommand(int plNo, std::string cmd, int periNo, int code);

	//���X�V
	//@remarks ���ڰьĂяo��
	void Update(void);
	
	//������Ă��邩�̊m�F
	bool Ispressed(int plNo, std::string cmd)const;

	//�����ꂽ���̊m�F
	bool IsTriggered(int plNo, std::string cmd)const;

	bool IsReleasd(int plNo, std::string cmd)const;

private:
	char _keystate[256];				//���݂̃L�[�{�[�h��
	std::vector<int> _padstate;	//���݂��߯�ޏ�
	

	std::vector<std::multimap<std::string, PeripheralInfo>> _inputTable;//��ڲ԰�ԍ��Ɠ��͑Ή�ð��ق̾��
	std::unordered_map < PeripheralInfo, std::pair<int, std::string>,PeripheralInfo::HashFunc> _inputMap;//���͏��Ɨ��p���̾�� 
	std::vector<std::unordered_map<std::string, bool>> _currentState; //���݂���������ؽ�
	std::vector<std::unordered_map<std::string, bool>> _lastState; //���O�����݉�������ؽ�
};

