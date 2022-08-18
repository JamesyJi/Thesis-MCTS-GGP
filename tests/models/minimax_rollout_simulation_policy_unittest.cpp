#include <gtest/gtest.h>
#include "gmock/gmock.h"

#include "model.h"

// Call SimulationPolicy on a state and check the returned move
// Can mock the actual state passed in to constructor
// Can also mock the gameState (no I cannot depth func depends on this gg)

class MockMinimaxRollout : public <Model