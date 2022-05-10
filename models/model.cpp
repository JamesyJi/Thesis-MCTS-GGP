#include "model.h"

namespace Models
{

template<typename M, typename TTraits>
typename Model<M, TTraits>::MoveT Model<M, TTraits>::DecideMove(Common::Resource& resource)
{
    while (resource.UseResource())
    {
        static_cast<M*>(this)->ExecuteStrategy();
    }

    mRoot = mRoot.GetMostVisitedChild();
    mRoot.NullParent();

    return mRoot.GetLastMove();
}

template<typename M, typename TTraits>
void Model<M, TTraits>::NotifyOfOpponentMove(MoveT& move)
{
    mRoot = mRoot.GetChild(move);
    mRoot.NullParent();
}


}