#pragma once

#include "utilities.h"
#include "globals.h"

enum GJLevelType {
    kGJLevelTypeLocal = 1,
    kGJLevelTypeEditor = 2,
    kGJLevelTypeSaved = 3
};

enum GJDifficulty {
    kGJDifficultyAuto = 0,
    kGJDifficultyEasy = 1,
    kGJDifficultyNormal = 2,
    kGJDifficultyHard = 3,
    kGJDifficultyHarder = 4,
    kGJDifficultyInsane = 5,
    kGJDifficultyDemon = 6,
    kGJDifficultyDemonEasy = 7,
    kGJDifficultyDemonMedium = 8,
    kGJDifficultyDemonInsane = 9,
    kGJDifficultyDemonExtreme = 10
};

class GJGameLevel : public CCNode {
public:
    CCDictionary* m_pLastBuildSave;
    int m_nLevelID_rand;
    int m_nLevelID_seed;
    int m_nLevelID;
    std::string m_sLevelName;
    std::string m_sLevelDesc;
    std::string m_sLevelString;
    std::string m_sCreatorName;
    std::string m_sRecordString;
    std::string m_sUploadDate;
    std::string m_sUpdateDate;
    int m_nUserID_rand;
    int m_nUserID_seed;
    int m_nUserID;
    int m_nAccountID_rand;
    int m_nAccountID_seed;
    int m_nAccountID;
    GJDifficulty m_eDifficulty;
    int m_nAudioTrack;
    int m_nSongID;
    int m_nLevelRev;
    bool m_bUnlisted;
    int m_nObjectCount_rand;
    int m_nObjectCount_seed;
    int m_nObjectCount;
    int m_nLevelIndex;
    int m_nRatings;
    int m_nRatingsSum;
    int m_nDownloads;
    bool m_bIsEditable;
    bool m_bGauntletLevel;
    bool m_bGauntletLevel2;
    int m_nWorkingTime;
    int m_nWorkingTime2;
    bool m_bLowDetailMode;
    bool m_bLowDetailModeToggled;
    int m_nIsVerified_rand;
    int m_nIsVerified_seed;
    bool m_bIsVerified;
    bool m_bIsUploaded;
    bool m_bHasBeenModified;
    int m_nLevelVersion;
    int m_nGameVersion;
    int m_nAttempts_rand;
    int m_nAttempts_seed;
    int m_nAttempts;
    int m_nJumps_rand;
    int m_nJumps_seed;
    int m_nJumps;
    int m_nClicks_rand;
    int m_nClicks_seed;
    int m_nClicks;
    int m_nAttemptTime_rand;
    int m_nAttemptTime_seed;
    int m_nAttemptTime;
    int m_nChk;
    bool m_bIsChkValid;
    bool m_bIsCompletionLegitimate;
    int m_nNormalPercent;
    int m_nNormalPercent_seed;
    int m_nNormalPercent_rand;
    int m_nOrbCompletion_rand;
    int m_nOrbCompletion_seed;
    int m_nOrbCompletion;
    int m_nNewNormalPercent2_rand;
    int m_nNewNormalPercent2_seed;
    int m_nNewNormalPercent2;
    int m_nPracticePercent;
    int m_nLikes;
    int m_nDislikes;
    int m_nLevelLength;
    int m_nFeatured;
    bool m_bIsEpic;
    bool m_bLevelFavorited;
    int m_nLevelFolder;
    int m_nDailyID_rand;
    int m_nDailyID_seed;
    int m_nDailyID;
    int m_nDemon_rand;
    int m_nDemon_seed;
    int m_nDemon;
    int m_nDemonDifficulty;
    int m_nStars_rand;
    int m_nStars_seed;
    int m_nStars;
    bool m_bAutoLevel;
    int m_nCoins;
    int m_nCoinsVerified_rand;
    int m_nCoinsVerified_seed;
    int m_nCoinsVerified;
    int m_nPassword_rand;
    int m_nPassword_seed;
    int m_nOriginalLevel_rand;
    int m_nOriginalLevel_seed;
    int m_nOriginalLevel;
    bool m_bTwoPlayerMode;
    int m_nFailedPasswordAttempts;
    int m_nFirstCoinVerified_rand;
    int m_nFirstCoinVerified_seed;
    int m_nFirstCoinVerified;
    int m_nSecondCoinVerified_rand;
    int m_nSecondCoinVerified_seed;
    int m_nSecondCoinVerified;
    int m_nThirdCoinVerified_rand;
    int m_nThirdCoinVerified_seed;
    int m_nThirdCoinVerified;
    int m_nStarsRequested;
    bool m_bShowedSongWarning;
    int m_nStarRatings;
    int m_nStarRatingsSum;
    int m_nMaxStarRatings;
    int m_nMinStarRatings;
    int m_nDemonVotes;
    int m_nRateStars;
    int m_nRateFeature;
    std::string m_sRateUser;
    bool m_bDontSave;
    bool m_bLevelNotDownloaded;
    int m_nRequiredCoins;
    bool m_bIsUnlocked;
    CCPoint m_obLastCameraPos;
    float m_fLastEditorZoom;
    int m_nLastBuildTab;
    int m_nLastBuildPage;
    int m_nLastBuildGroupID;
    GJLevelType m_eLevelType;
    int m_nM_ID;
    std::string m_sTempName;
    std::string m_sCapacityString;
    bool m_bHighObjectsEnabled;
    std::string m_sPersonalBests;

    void dataLoaded(DS_Dictionary* dict) {
        return reinterpret_cast<void(__thiscall*)(GJGameLevel*, DS_Dictionary*)>( utilities::getBase() + 0xbded0 )(this, dict);
    }

    static GJGameLevel* create() {
        return reinterpret_cast<GJGameLevel*(__stdcall*)()>(utilities::getBase() + 0xbd2b0)();
    }

    static GJGameLevel* createWithCoder(DS_Dictionary* dict) {
        auto ret = GJGameLevel::create();
        ret->dataLoaded(dict);
        return ret;
    }

    std::string getAudioFileName() {
        std::string ret;

        reinterpret_cast<void(__thiscall*)(GJGameLevel*, std::string*)>(utilities::getBase() + 0xbdc70)(this, &ret);

        return ret;
    }

    void setLevelData(const char* data) {
        auto len = strlen(data);
        auto addedLvlStr = reinterpret_cast<uintptr_t>(this) + 0x12c;

        *reinterpret_cast<size_t*>(addedLvlStr + 16) = len;
        *reinterpret_cast<size_t*>(addedLvlStr + 20) = max(len, 15);

        if (len <= 15)
            memcpy(reinterpret_cast<char*>(addedLvlStr), data, len + 1);
        else {
            void* newb = malloc(len + 1);
            memcpy(newb, data, len + 1);
            *reinterpret_cast<void**>(addedLvlStr) = newb;
        }
    }

    void setLevelData(std::string const& data) {
        this->setLevelData(data.c_str());
    }

    GJDifficulty getAverageDifficulty() {
        return reinterpret_cast<GJDifficulty(__thiscall*)(GJGameLevel*)>( utilities::getBase() + 0xbd9b0 )(this);
    }
};