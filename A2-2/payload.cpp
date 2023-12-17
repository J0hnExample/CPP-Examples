#include "payload.h"

// instantiate the payload's static count
size_t Payload::count_ = 0;
size_t Payload::copyCount_ = 0;
size_t Payload::moveCount_ = 0;


