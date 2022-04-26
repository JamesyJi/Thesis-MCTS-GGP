#include <models/model.h>

namespace Models
{

template<typename M, typename TTraits>
Model<M,TTraits>::MoveT Model<M, TTraits>::DecideMove(Common::Resource& resource)
{
    while (resource.UseResource())
    {
        static_cast<M*>(this)->ExecuteStrategy();
    }

    mRoot = mRoot.GetMostVisitedChild();
    mRoot.mParent.NullParent();

    return mRoot.GetLastMove();
}

}