//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2005, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// slSubscription.h PostgreSQL Slony-I Node
//
//////////////////////////////////////////////////////////////////////////

#ifndef SLSUBSCRIPTION_H
#define SLSUBSCRIPTION_H

// wxWindows headers
#include <wx/wx.h>

// App headers
#include "pgAdmin3.h"
#include "pgObject.h"
#include "pgServer.h"
#include "pgDatabase.h"
#include "slObject.h"


class slSubscription : public slSetObject
{
public:
    slSubscription(slSet *set, const wxString& newName = wxT(""));
    ~slSubscription();

    int GetIcon() { return SLICON_SUBSCRIPTION; }
    void ShowTreeDetail(wxTreeCtrl *browser, frmMain *form=0, ctlListView *properties=0, ctlSQLBox *sqlPane=0);
    static pgObject *ReadObjects(slSetCollection *coll, wxTreeCtrl *browser, const wxString &restriction);
    static pgObject *ReadObjects(slSetCollection *coll, wxTreeCtrl *browser);

    bool WantDummyChild();
    bool RequireDropConfirm() { return true; }

    bool GetActive() const { return active; }
    void iSetActive(bool b) { active=b; }
    bool GetForward() const { return forward; }
    void iSetForward(bool b) { forward=b; }
    wxString GetProviderNode() const { return providerNode; }
    void iSetProviderNode(const wxString &s) { providerNode=s; }
    wxString GetReceiverNode() const { return receiverNode; }
    void iSetReceiverNode(const wxString &s) { receiverNode=s; }
    long GetProviderId() const { return providerId; }
    void iSetProviderId(long l) { providerId=l; }
    long GetReceiverId() const { return receiverId; }
    void iSetReceiverId(long l) { receiverId=l; }
    bool GetIsSubscribed() { return isSubscribed; }
    void iSetIsSubscribed(bool b) { isSubscribed=b; }


  
    bool CanCreate();

    bool DropObject(wxFrame *frame, wxTreeCtrl *browser);
    wxString GetSql(wxTreeCtrl *browser);
    pgObject *Refresh(wxTreeCtrl *browser, const wxTreeItemId item);

private:
    bool active, forward, isSubscribed;
    long providerId, receiverId;
    wxString providerNode, receiverNode;
};

#endif

