#include "../../StdInc.h"

EGCResults ProxiedGameCoordinator::SendMessage( uint32 unMsgType, const void *pubData, uint32 cubData )
{
    //HHSDBG();
    return EGCResults::k_EGCResultOK;
}

bool ProxiedGameCoordinator::IsMessageAvailable( uint32 *pcubMsgSize )
{
    //HHSDBG();
    return false;
}

EGCResults ProxiedGameCoordinator::RetrieveMessage( uint32 *punMsgType, void *pubDest, uint32 cubDest, uint32 *pcubMsgSize )
{
    //HHSDBG();
    return EGCResults::k_EGCResultOK;
}