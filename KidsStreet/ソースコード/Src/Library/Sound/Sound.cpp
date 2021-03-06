#include "DxLib.h"
#include "Sound.h"

CSound::BGMInfo CSound::bgm[BGM_NUM];
CSound::SEInfo CSound::se[SE_NUM];


//BGMのファイルパス
const char bgm_FilePath[CSound::BGM_NUM][256] =
{
 "Data/Sound/Opening.mp3",  //タイトル時のBGM
 "Data/Sound/CitySound.mp3",  //プレイ時のBGM
 "Data/Sound/Clear.mp3",  //クリア時のBGM
 "Data/Sound/GameOver.mp3",  //ゲームオーバー時のBGM
 "Data/Sound/Escape.mp3",    //エネミーに追われた時のBGM
 "Data/Sound/Controll.mp3",  //メインのBGM
 "Data/Sound/BossBattle.mp3",    //ボスバトル時のBGM
 "Data/Sound/JunpStart.mp3"
};

//効果音のファイルパス
const char se_FilePath[CSound::SE_NUM][256] =
{
 "Data/Sound/JumpStart.mp3",    //足音
 "Data/Sound/GetItem.mp3",       //アイテム獲得音
 "Data/Sound/EscapeNice.mp3",   //成功音
 "Data/Sound/impact.mp3",       //衝撃音
 "Data/Sound/Punch.mp3",         //ダメージ音
 "Data/Sound/Swing.mp3"         //スイング音
};


//サウンドの初期化
void CSound::InitSound()
{
    //BGMの初期化
    for (int bgm_index = 0; bgm_index < BGM_NUM; bgm_index++)
    {
        bgm[bgm_index].handle = 0;
        bgm[bgm_index].kind = BGM_NONE;
    }

    //効果音の初期化
    for (int se_index = 0; se_index < SE_NUM; se_index++)
    {
        se[se_index].handle = 0;
        se[se_index].kind = SE_NONE;
    }
}

void CSound::LoadBGM(BGM_KIND kind)
{
    for (int bgm_index = 0; bgm_index < BGM_NUM; bgm_index++)
    {
        //未使用なら
        if (bgm[bgm_index].handle == 0)
        {
            //読み込み
            bgm[bgm_index].handle = LoadSoundMem(bgm_FilePath[kind]);
            bgm[bgm_index].kind = kind;

            break;
        }
    }
}

//効果音サウンドの読み込み
void CSound::LoadSE(SE_KIND kind)
{
    for (int se_index = 0; se_index < SE_NUM; se_index++)
    {
        //未使用なら
        if (se[se_index].handle == 0)
        {
            //読み込み
            se[se_index].handle = LoadSoundMem(se_FilePath[kind]);
            se[se_index].kind = kind;

            break;
        }
    }
}

//BGMの再生
void CSound::PlayBGM(BGM_KIND kind)
{
    for (int bgm_index = 0; bgm_index < BGM_NUM; bgm_index++)
    {
        //該当のBGM発見
        if (bgm[bgm_index].kind == kind)
        {
            switch (kind) {
            case CSound::BGM_TITLE:ChangeVolumeSoundMem(80, bgm[bgm_index].handle);
                break;

                //プレイシーン効果音調整
            case CSound::BGM_PLAY:ChangeVolumeSoundMem(80, bgm[bgm_index].handle);
                break;

                //クリアシーンBGM調整
            case CSound::BGM_CLEAR:ChangeVolumeSoundMem(80, bgm[bgm_index].handle);
                break;

                //ゲームオーバーシーンBGM調整
            case CSound::BGM_GAMEOVER:ChangeVolumeSoundMem(80, bgm[bgm_index].handle);
                break;

                //敵に追われた時のBGM調整
            case CSound::BGM_ESCAPE:ChangeVolumeSoundMem(80, bgm[bgm_index].handle);
                break;

                //メインBGM音量調整
            case CSound::BGM_MAIN:ChangeVolumeSoundMem(80, bgm[bgm_index].handle);
                break;

                //ボスBGM音量調整
            case CSound::BGM_BOSS:ChangeVolumeSoundMem(80, bgm[bgm_index].handle);
                break;

                //
            case CSound::MOVE:break;

            case CSound::BGM_NUM:break;
            }

            PlaySoundMem(bgm[bgm_index].handle, DX_PLAYTYPE_LOOP, true);
            break;
        }
    }
}

void CSound::StopBGM(BGM_KIND kind)
{
    for (int bgm_index = 0; bgm_index < BGM_NUM; bgm_index++)
    {
        //該当のBGM発見
        if (bgm[bgm_index].kind == kind)
        {
            StopSoundMem(bgm[bgm_index].handle);
            break;
        }
    }
}

//効果音の再生
void CSound::PlaySE(SE_KIND kind)
{
    for (int se_index = 0; se_index < SE_NUM; se_index++)
    {
        //該当の効果音発見
        if (se[se_index].kind == kind)
        {
            switch (kind) {
                //足音の音量調整
            case CSound::SE_FOOT:ChangeVolumeSoundMem(80, bgm[se_index].handle);
                break;

                //入手音の音量調整
            case CSound::SE_GET:ChangeVolumeSoundMem(80, bgm[se_index].handle);
                break;

                //衝撃音の音量調整
            case CSound::SE_IMPACT:ChangeVolumeSoundMem(80, bgm[se_index].handle);
                break;

                //ダメージ音の音量調整
            case CSound::SE_DMG:ChangeVolumeSoundMem(80, bgm[se_index].handle);
                break;

                //スイング音の音量調整
            case CSound::SE_SWING:ChangeVolumeSoundMem(80, bgm[se_index].handle);
                break;

            case CSound::SE_NUM:break;
            }

            PlaySoundMem(se[se_index].handle, DX_PLAYTYPE_BACK, true);
            break;
        }
    }
}

//サウンドの後処理
void CSound::FinSound()
{
    //BGMを全て停止して破棄
    for (int bgm_index = 0; bgm_index < BGM_NUM; bgm_index++)
    {
        StopSoundMem(bgm[bgm_index].handle);
        DeleteSoundMem(bgm[bgm_index].handle);
    }

    //効果音を全て破棄
    for (int se_index = 0; se_index < SE_NUM; se_index++)
    {
        DeleteSoundMem(se[se_index].handle);
    }
}

void CSound::FinBGMSound()
{
    //BGMを全て停止して破棄
    for (int bgm_index = 0; bgm_index < BGM_NUM; bgm_index++)
    {
        StopSoundMem(bgm[bgm_index].handle);
        DeleteSoundMem(bgm[bgm_index].handle);
    }
}

void CSound::FinSESound()
{
    //効果音を全て破棄
    for (int se_index = 0; se_index < SE_NUM; se_index++)
    {
        DeleteSoundMem(se[se_index].handle);
    }
}