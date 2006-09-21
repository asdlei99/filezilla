#ifndef __ASYNCREQUESTQUEUE_H__

#define __ASYNCREQUESTQUEUE_H__

class CMainFrame;
class CQueueView;
class CAsyncRequestQueue
{
public:
	CAsyncRequestQueue(CMainFrame *pMainFrame);
	~CAsyncRequestQueue();

	void AddRequest(CFileZillaEngine *pEngine, CAsyncRequestNotification *pNotification);
	void ClearPending(const CFileZillaEngine* pEngine);
	void RecheckDefaults();

	void SetQueue(CQueueView *pQueue);

protected:
	CMainFrame *m_pMainFrame;
	CQueueView *m_pQueueView;

	void ProcessNextRequest();
	bool ProcessDefaults(CFileZillaEngine *pEngine, CAsyncRequestNotification *pNotification);

	struct t_queueEntry
	{
		CFileZillaEngine *pEngine;
		CAsyncRequestNotification *pNotification;
	};
	std::list<t_queueEntry> m_requestList;
};

#endif //__ASYNCREQUESTQUEUE_H__
