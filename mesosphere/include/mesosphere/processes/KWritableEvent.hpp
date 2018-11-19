#pragma once

#include <mesosphere/core/util.hpp>
#include <mesosphere/core/Result.hpp>
#include <mesosphere/interfaces/ISetAllocated.hpp>
#include <mesosphere/interfaces/IServer.hpp>

namespace mesosphere
{

class KReadableEvent;
class KEvent;

class KWritableEvent final : public KAutoObject, public IServer<KEvent, KReadableEvent, KWritableEvent> {
    public:
    MESOSPHERE_AUTO_OBJECT_TRAITS(AutoObject, WritableEvent);
    MESOSPHERE_SERVER_TRAITS(Event);

    virtual ~KWritableEvent();

    Result Signal();
    Result Clear();

    private:
    friend class KEvent;

    SharedPtr<KReadableEvent> client{};
};

MESOSPHERE_AUTO_OBJECT_DEFINE_INCREF(WritableEvent);

}