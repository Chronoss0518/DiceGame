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
    //ライフポイント//
    char lp;
    //スキップフラグ//
    char statusflg;
    //パンドラのダイスカウント//
    unsigned char pandoraDiceCount;
    //キャラクターネーム//
    char* name;
};

typedef void (*DiceType)(struct CharaData* _car);

static DiceType Critical[6];
static DiceType Magic[6];
static DiceType Guarf[6];
static DiceType Heal[6];
static DiceType Pandora[6];

static char doubleFlg = 0;  //ダメージ倍フラグ//
static char fireFlg = 0; //ファイアーボールフラグ//

void diceInit(void);

#endif