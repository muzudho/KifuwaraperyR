#include "muz_hand_stand_model.hpp"


// ========================================
// アクセッサー
// ========================================


unsigned int MuzHandStandModel::get_count(const HandPiece handPiece) const
{
    switch (handPiece)
    {
    case HPawn:  return fu_;
    case HLance: return kyo_;
    case HKnight:return kei_;
    case HSilver:return gin_;
    case HGold:  return kin_;
    case HBishop:return kaku_;
    case HRook:  return hi_;
    default:
        // ここは本来は例外を投げるべきだが、今回はとりあえず0を返す
        return 0;
    }
}
void MuzHandStandModel::set_count(const HandPiece handPiece, unsigned int count)
{
    switch (handPiece)
    {
    case HPawn:  fu_ += count;
    case HLance: kyo_ += count;
    case HKnight:kei_ += count;
    case HSilver:gin_ += count;
    case HGold:  kin_ += count;
    case HBishop:kaku_ += count;
    case HRook:  hi_ += count;
    default:
        break;
    }
}
