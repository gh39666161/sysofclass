// DlgTchInputscore.cpp : implementation file
//

#include "stdafx.h"
#include "sys_jwxt.h"
#include "DlgTchInputscore.h"
#include "DlgLoginedTeacher.h"
#include "DlgPopInputscore.h"
#include "_recordset.h"
#include "Column.h"
#include "Columns.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTchInputscore dialog


CDlgTchInputscore::CDlgTchInputscore(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTchInputscore::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgTchInputscore)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgTchInputscore::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTchInputscore)
	DDX_Control(pDX, IDC_ADODC_SC, m_adoc_sc);
	DDX_Control(pDX, IDC_DATAGRID_INPUTSCORE, m_datagrid_inputscore);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgTchInputscore, CDialog)
	//{{AFX_MSG_MAP(CDlgTchInputscore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTchInputscore message handlers

BOOL CDlgTchInputscore::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CWnd *dlg=GetParent();
	CDlgLoginedTeacher *p=(CDlgLoginedTeacher *)dlg;
	m_courseid=p->m_courseselect;
	t_course=new T_Course;
	_RecordsetPtr rst;
	rst=t_course->course_select();
	while(!rst->adoEOF)
	{
		if((_bstr_t)rst->GetCollect("id")==m_courseid)
		{
			SetDlgItemText(IDC_HEADER,"正在为["+(_bstr_t)rst->GetCollect("name")+"]录入成绩");
			break;
		}
		rst->MoveNext();
	}
	rst=NULL;
	delete t_course;
	t_course=NULL;
	CString SQL;
	SQL.Format("SELECT s_id AS '学号',score AS '成绩' FROM sc WHERE c_id='%s'",m_courseid);
	m_adoc_sc.SetRecordSource(SQL);
	m_adoc_sc.Refresh();
	_variant_t index=long(0);
	CColumns cols=m_datagrid_inputscore.GetColumns();
	CColumn Item=cols.GetItem(index);
	Item.SetWidth(108);
	index=long(1);
	Item=cols.GetItem(index);
	Item.SetWidth(108);
	t_sc=NULL;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BEGIN_EVENTSINK_MAP(CDlgTchInputscore, CDialog)
    //{{AFX_EVENTSINK_MAP(CDlgTchInputscore)
	ON_EVENT(CDlgTchInputscore, IDC_DATAGRID_INPUTSCORE, -601 /* DblClick */, OnDblClickDatagridInputscore, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CDlgTchInputscore::OnDblClickDatagridInputscore() 
{
	// TODO: Add your control notification handler code here
	if(m_adoc_sc.GetRecordset().GetEof()==1)
	{
		MessageBox("没有记录","提示",MB_OK|MB_ICONWARNING);
		return;
	}
	CString score;
	CString studentid;
	CDlgPopInputscore dlg;
	if(dlg.DoModal()==IDOK)
	{
		score=dlg.m_score;
		_variant_t index=long(0);
		CColumns cols=m_datagrid_inputscore.GetColumns();
		CColumn Item=cols.GetItem(index);
		studentid=Item.GetText();
		t_sc=new T_SC;
		t_sc->sc_update(m_courseid,studentid,score);
		delete t_sc;
		t_sc=NULL;
		m_adoc_sc.Refresh();
		Item=cols.GetItem(index);
		Item.SetWidth(108);
		index=long(1);
		Item=cols.GetItem(index);
		Item.SetWidth(108);
	}
}