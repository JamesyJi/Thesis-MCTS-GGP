#include <models/model.h>

namespace Models
{

template<typename GameState, typename Move>
GameState& Model<GameState, Move>::DecideMove(Common::Resource& resource)
{
    while (resource.UseResource())
    {
        ExecuteStrategy();
    }
    

    mRoot = mRoot.GetMostVisitedChild();
    mRoot.mParent.NullParent();

    return mRoot.GetLastMove();
}

}