//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2005, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// dlgRepSubscription.h - Slony-I Subscription property
//
//////////////////////////////////////////////////////////////////////////


#ifndef __DLG_REPSUBSCPROP
#define __DLG_REPSUBSCPROP

#include "dlgRepProperty.h"

class slSubscription;
class slSet;

class dlgRepSubscription : public dlgRepProperty
{
public:
    dlgRepSubscription(frmMain *frame, slSubscription *sub, slSet *s);
    int Go(bool modal);

    void CheckChange();
    wxString GetSql();
    pgObject *CreateObject(pgCollection *collection);
    pgObject *GetObject();

private:
    slSubscription *subscription;
    slSet *set;

    DECLARE_EVENT_TABLE();
};


#endif
