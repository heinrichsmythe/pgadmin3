//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2005, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// slTable.h PostgreSQL Slony-I Node
//
//////////////////////////////////////////////////////////////////////////

#ifndef SLTABLE_H
#define SLTABLE_H

// wxWindows headers
#include <wx/wx.h>

// App headers
#include "pgAdmin3.h"
#include "pgObject.h"
#include "pgServer.h"
#include "pgDatabase.h"
#include "slObject.h"


class slTable : public slSetObject
{
public:
    slTable(slSet *set, const wxString& newName = wxT(""));
    ~slTable();

    int GetIcon() { return PGICON_TABLE; }
    void ShowTreeDetail(wxTreeCtrl *browser, frmMain *form=0, ctlListView *properties=0, ctlSQLBox *sqlPane=0);
    static pgObject *ReadObjects(slSetCollection *coll, wxTreeCtrl *browser, const wxString &restriction);
    static pgObject *ReadObjects(slSetCollection *coll, wxTreeCtrl *browser);

    bool GetAltered() const { return altered; }
    void iSetAltered(bool b) { altered=b; }
    wxString GetIndexName() const { return indexName; }
    void iSetIndexName(const wxString s) { indexName = s; }
    const wxArrayString &GetTriggers() { return triggers; }

    bool DropObject(wxFrame *frame, wxTreeCtrl *browser);
    wxString GetSql(wxTreeCtrl *browser);
    pgObject *Refresh(wxTreeCtrl *browser, const wxTreeItemId item);

private:
    bool altered;
    wxString indexName;
    wxArrayString triggers;
};

#endif

