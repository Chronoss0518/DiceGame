#ifndef Game
#define Game

enum StatusType
{
    Stan = 0x01,
    ice = 0x02,
    paralysis = 0x04,
    guard = 0x08
};

struct CharaData
{
    //���C�t�|�C���g//
    char lp;
    //�X�L�b�v�t���O//
    char statusflg;
    //�p���h���̃_�C�X�J�E���g//
    unsigned char pandoraDiceCount;
    //�L�����N�^�[�l�[��//
    char* name;
};

typedef void (*DiceType)(struct CharaData* _car);

static DiceType Critical[6];
static DiceType Magic[6];
static DiceType Guarf[6];
static DiceType Heal[6];
static DiceType Pandora[6];

static char doubleFlg = 0;  //�_���[�W�{�t���O//
static char fireFlg = 0; //�t�@�C�A�[�{�[���t���O//

void diceInit(void);

#endif