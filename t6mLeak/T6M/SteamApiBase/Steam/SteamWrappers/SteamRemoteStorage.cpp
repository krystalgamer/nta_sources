#include "../../StdInc.h"
bool SteamRemoteStorage008::FileWrite( const char *pchFile, const void *pvData, int32 cubData )
{
    return ProxiedRemoteStorage::FileWrite(pchFile, pvData, cubData);
}
int32 SteamRemoteStorage008::FileRead( const char *pchFile, void *pvData, int32 cubDataToRead )
{
    return ProxiedRemoteStorage::FileRead(pchFile, pvData, cubDataToRead);
}
bool SteamRemoteStorage008::FileForget( const char *pchFile )
{
    return ProxiedRemoteStorage::FileForget(pchFile);
}
bool SteamRemoteStorage008::FileDelete( const char *pchFile )
{
    return ProxiedRemoteStorage::FileDelete(pchFile);
}
SteamAPICall_t SteamRemoteStorage008::FileShare( const char *pchFile )
{
    return ProxiedRemoteStorage::FileShare(pchFile);
}
bool SteamRemoteStorage008::SetSyncPlatforms( const char *pchFile, ERemoteStoragePlatform eRemoteStoragePlatform )
{
    return ProxiedRemoteStorage::SetSyncPlatforms(pchFile, eRemoteStoragePlatform);
}

GID_t SteamRemoteStorage008::FileWriteStreamOpen( const char *pchFile )
{
    return ProxiedRemoteStorage::FileWriteStreamOpen(pchFile);
}
EResult SteamRemoteStorage008::FileWriteStreamWriteChunk( GID_t hStream, const void *pvData, int32 cubData )
{
    return ProxiedRemoteStorage::FileWriteStreamWriteChunk(hStream, pvData, cubData);
}
EResult SteamRemoteStorage008::FileWriteStreamClose( GID_t hStream )
{
    return ProxiedRemoteStorage::FileWriteStreamClose(hStream);
}
EResult SteamRemoteStorage008::FileWriteStreamCancel( GID_t hStream )
{
    return ProxiedRemoteStorage::FileWriteStreamCancel(hStream);
}

// file information
bool SteamRemoteStorage008::FileExists( const char *pchFile )
{
    return ProxiedRemoteStorage::FileExists(pchFile);
}
bool SteamRemoteStorage008::FilePersisted( const char *pchFile )
{
    return ProxiedRemoteStorage::FilePersisted(pchFile);
}
int32 SteamRemoteStorage008::GetFileSize( const char *pchFile )
{
    return ProxiedRemoteStorage::GetFileSize(pchFile);
}
int64 SteamRemoteStorage008::GetFileTimestamp( const char *pchFile )
{
    return ProxiedRemoteStorage::GetFileTimestamp(pchFile);
}
ERemoteStoragePlatform SteamRemoteStorage008::GetSyncPlatforms( const char *pchFile )
{
    return ProxiedRemoteStorage::GetSyncPlatforms(pchFile);
}

// iteration
int32 SteamRemoteStorage008::GetFileCount()
{
    return ProxiedRemoteStorage::GetFileCount();
}
const char *SteamRemoteStorage008::GetFileNameAndSize( int iFile, int32 *pnFileSizeInBytes )
{
    return ProxiedRemoteStorage::GetFileNameAndSize(iFile, pnFileSizeInBytes);
}

// configuration management
bool SteamRemoteStorage008::GetQuota( int32 *pnTotalBytes, int32 *puAvailableBytes )
{
    return ProxiedRemoteStorage::GetQuota(pnTotalBytes, puAvailableBytes);
}
bool SteamRemoteStorage008::IsCloudEnabledForAccount()
{
    return ProxiedRemoteStorage::IsCloudEnabledForAccount();
}
bool SteamRemoteStorage008::IsCloudEnabledForApp()
{
    return ProxiedRemoteStorage::IsCloudEnabledForApp();
}
void SteamRemoteStorage008::SetCloudEnabledForApp( bool bEnabled )
{
    return ProxiedRemoteStorage::SetCloudEnabledForApp(bEnabled);
}

// user generated content
SteamAPICall_t SteamRemoteStorage008::UGCDownload( UGCHandle_t hContent )
{
    return ProxiedRemoteStorage::UGCDownload(hContent, 0);
} // Returns a RemoteStorageDownloadUGCResult_t callback
bool SteamRemoteStorage008::GetUGCDownloadProgress( UGCHandle_t hContent, uint32 *puDownloadedBytes, uint32 *puTotalBytes )
{
    return ProxiedRemoteStorage::GetUGCDownloadProgress(hContent, puDownloadedBytes, puTotalBytes);
}
bool SteamRemoteStorage008::GetUGCDetails( UGCHandle_t hContent, AppId_t *pnAppID, char **ppchName, int32 *pnFileSizeInBytes, CSteamID *pSteamIDOwner )
{
	return ProxiedRemoteStorage::GetUGCDetails(hContent, pnAppID, ppchName, pnFileSizeInBytes, pSteamIDOwner);
}
int32 SteamRemoteStorage008::UGCRead( UGCHandle_t hContent, void *pvData, int32 cubDataToRead )
{
	return ProxiedRemoteStorage::UGCRead(hContent, pvData, cubDataToRead, 0, EUGCReadAction::k_EUGCRead_ContinueReadingUntilFinished);
}

// user generated content iteration
int32 SteamRemoteStorage008::GetCachedUGCCount()
{
    return ProxiedRemoteStorage::GetCachedUGCCount();
}
UGCHandle_t SteamRemoteStorage008::GetCachedUGCHandle( int32 iCachedContent )
{
    return ProxiedRemoteStorage::GetCachedUGCHandle(iCachedContent);
}

// publishing UGC
SteamAPICall_t SteamRemoteStorage008::PublishWorkshopFile( const char *pchFile, const char *pchPreviewFile, AppId_t nConsumerAppId, const char *pchTitle, const char *pchDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags, EWorkshopFileType eWorkshopFileType )
{
    return ProxiedRemoteStorage::PublishWorkshopFile(pchFile, pchPreviewFile, nConsumerAppId, pchTitle, pchDescription, eVisibility, pTags, eWorkshopFileType);
}
JobID_t SteamRemoteStorage008::CreatePublishedFileUpdateRequest( PublishedFileId_t unPublishedFileId )
{
    return ProxiedRemoteStorage::CreatePublishedFileUpdateRequest(unPublishedFileId);
}
bool SteamRemoteStorage008::UpdatePublishedFileFile( JobID_t hUpdateRequest, const char *pchFile )
{
    return ProxiedRemoteStorage::UpdatePublishedFileFile(hUpdateRequest, pchFile);
}
bool SteamRemoteStorage008::UpdatePublishedFilePreviewFile( JobID_t hUpdateRequest, const char *pchPreviewFile )
{
    return ProxiedRemoteStorage::UpdatePublishedFilePreviewFile(hUpdateRequest, pchPreviewFile);
}
bool SteamRemoteStorage008::UpdatePublishedFileTitle( JobID_t hUpdateRequest, const char *pchTitle )
{
    return ProxiedRemoteStorage::UpdatePublishedFileTitle(hUpdateRequest, pchTitle);
}
bool SteamRemoteStorage008::UpdatePublishedFileDescription( JobID_t hUpdateRequest, const char *pchDescription )
{
    return ProxiedRemoteStorage::UpdatePublishedFileDescription(hUpdateRequest, pchDescription);
}
bool SteamRemoteStorage008::UpdatePublishedFileVisibility( JobID_t hUpdateRequest, ERemoteStoragePublishedFileVisibility eVisibility )
{
    return ProxiedRemoteStorage::UpdatePublishedFileVisibility(hUpdateRequest, eVisibility);
}
bool SteamRemoteStorage008::UpdatePublishedFileTags( JobID_t hUpdateRequest, SteamParamStringArray_t *pTags )
{
    return ProxiedRemoteStorage::UpdatePublishedFileTags(hUpdateRequest, pTags);
}
SteamAPICall_t SteamRemoteStorage008::CommitPublishedFileUpdate( JobID_t hUpdateRequest )
{
    return ProxiedRemoteStorage::CommitPublishedFileUpdate(hUpdateRequest);
}

SteamAPICall_t SteamRemoteStorage008::GetPublishedFileDetails( PublishedFileId_t unPublishedFileId )
{
    return ProxiedRemoteStorage::GetPublishedFileDetails(unPublishedFileId, 0);
}
SteamAPICall_t SteamRemoteStorage008::DeletePublishedFile( PublishedFileId_t unPublishedFileId )
{
    return ProxiedRemoteStorage::DeletePublishedFile(unPublishedFileId);
}
SteamAPICall_t SteamRemoteStorage008::EnumerateUserPublishedFiles( uint32 uStartIndex )
{
    return ProxiedRemoteStorage::EnumerateUserPublishedFiles(uStartIndex);
}
SteamAPICall_t SteamRemoteStorage008::SubscribePublishedFile( PublishedFileId_t unPublishedFileId )
{
    return ProxiedRemoteStorage::SubscribePublishedFile(unPublishedFileId);
}
SteamAPICall_t SteamRemoteStorage008::EnumerateUserSubscribedFiles( uint32 uStartIndex )
{
    return ProxiedRemoteStorage::EnumerateUserSubscribedFiles(uStartIndex);
}
SteamAPICall_t SteamRemoteStorage008::UnsubscribePublishedFile( PublishedFileId_t unPublishedFileId )
{
    return ProxiedRemoteStorage::UnsubscribePublishedFile(unPublishedFileId);
}

bool SteamRemoteStorage008::UpdatePublishedFileSetChangeDescription( JobID_t hUpdateRequest, const char *cszDescription )
{
    return ProxiedRemoteStorage::UpdatePublishedFileSetChangeDescription(hUpdateRequest, cszDescription);
}
SteamAPICall_t SteamRemoteStorage008::GetPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId )
{
    return ProxiedRemoteStorage::GetPublishedItemVoteDetails(unPublishedFileId);
}
SteamAPICall_t SteamRemoteStorage008::UpdateUserPublishedItemVote( PublishedFileId_t unPublishedFileId, bool bVoteUp )
{
    return ProxiedRemoteStorage::UpdateUserPublishedItemVote(unPublishedFileId, bVoteUp);
}
SteamAPICall_t SteamRemoteStorage008::GetUserPublishedItemVoteDetails( PublishedFileId_t unPublishedFileId )
{
    return ProxiedRemoteStorage::GetUserPublishedItemVoteDetails(unPublishedFileId);
}
SteamAPICall_t SteamRemoteStorage008::EnumerateUserSharedWorkshopFiles( AppId_t nAppId, CSteamID creatorSteamID, uint32 uStartIndex, SteamParamStringArray_t * pRequiredTags, SteamParamStringArray_t * pExcludedTags )
{
    return ProxiedRemoteStorage::EnumerateUserSharedWorkshopFiles(nAppId, creatorSteamID, uStartIndex, pRequiredTags, pExcludedTags);
}
SteamAPICall_t SteamRemoteStorage008::PublishVideo( EWorkshopVideoProvider eVideoProvider, const char *cszVideoAccountName, const char *cszVideoIdentifier, const char *cszFileName, AppId_t nConsumerAppId, const char *cszTitle, const char *cszDescription, ERemoteStoragePublishedFileVisibility eVisibility, SteamParamStringArray_t *pTags )
{
    return ProxiedRemoteStorage::PublishVideo(eVideoProvider, cszVideoAccountName, cszVideoIdentifier, cszFileName, nConsumerAppId, cszTitle, cszDescription, eVisibility, pTags);
}
SteamAPICall_t SteamRemoteStorage008::SetUserPublishedFileAction( PublishedFileId_t unPublishedFileId, EWorkshopFileAction eAction )
{
    return ProxiedRemoteStorage::SetUserPublishedFileAction(unPublishedFileId, eAction);
}
SteamAPICall_t SteamRemoteStorage008::EnumeratePublishedFilesByUserAction( EWorkshopFileAction eAction, uint32 uStartIndex )
{
    return ProxiedRemoteStorage::EnumeratePublishedFilesByUserAction(eAction, uStartIndex);
}
SteamAPICall_t SteamRemoteStorage008::EnumeratePublishedWorkshopFiles( EWorkshopEnumerationType eType, uint32 uStartIndex, uint32 cDays, uint32 cCount, SteamParamStringArray_t *pTags, SteamParamStringArray_t *pUserTags )
{
    return ProxiedRemoteStorage::EnumeratePublishedWorkshopFiles(eType, uStartIndex, cDays, cCount, pTags, pUserTags);
}