#include "stdafx.h"
#include "Glmfcn.h"

#include "GlmfcnDoc.h"
#include "GlmfcnView.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include "glaux.h"

#include "SetLightPositionDlg.h"
#include "SetLightDirectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGlmfcnView

IMPLEMENT_DYNCREATE(CGlmfcnView, CView)

BEGIN_MESSAGE_MAP(CGlmfcnView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
    ON_COMMAND(ID_VIEW_SETLIGHT, &CGlmfcnView::OnViewSetlight)
    ON_COMMAND(ID_VIEW_SETLIGHT32780, &CGlmfcnView::OnViewSetlightDirection)
END_MESSAGE_MAP()

CGlmfcnView::CGlmfcnView()
{
	// TODO: add construction code here

}

CGlmfcnView::~CGlmfcnView()
{
}

BOOL CGlmfcnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

BOOL CGlmfcnView::InitializeOpenGL()
{
	CGlmfcnDoc* pDoc = GetDocument();
    pDoc->m_pDC = new CClientDC(this);
	m_hDC = pDoc->m_pDC->GetSafeHdc();

    if ( NULL == pDoc->m_pDC )
        {
		::AfxMessageBox("Couldn't get a valid DC.");
        return FALSE;
        }

    if ( !SetupPixelFormat() )
        {
		::AfxMessageBox("SetupPixelFormat failed.\n");
        return FALSE;
        }
	m_hRC=wglGetCurrentContext();
	if (m_hRC==NULL)
    if ( 0 == (m_hRC = ::wglCreateContext( m_hDC ) ) )
        {
		::AfxMessageBox("wglCreateContext failed.");
        return FALSE;
        }


    return makeCurrent();
}


BOOL CGlmfcnView::SetupPixelFormat()
{
	CGlmfcnDoc* pDoc = GetDocument();
    PIXELFORMATDESCRIPTOR pfd = 
        {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW |
        PFD_DOUBLEBUFFER |
        PFD_SUPPORT_OPENGL,
        PFD_TYPE_RGBA,
        24,
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        16,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
        };

    int pixelformat;
    PIXELFORMATDESCRIPTOR* pPFDtoUse;
    pPFDtoUse =  &pfd ; 

    if ( 0 == (pixelformat = 
        ::ChoosePixelFormat( m_hDC, pPFDtoUse )) )
        {
    ::AfxMessageBox("ChoosePixelFormat failed.");
    return FALSE;
        }

    if ( FALSE == ::SetPixelFormat( m_hDC,
        pixelformat, pPFDtoUse ) )
        {
    ::AfxMessageBox("SetPixelFormat failed.");
        return FALSE;
        }

    return TRUE;
}

void CGlmfcnView::myReshape()
{
	CGlmfcnDoc* pDoc = GetDocument();
    pDoc->m_AspectRatio = (GLdouble)pDoc->m_WindowWidth/(GLdouble)pDoc->m_WindowHeight;

    ::glViewport(0, 0, pDoc->m_WindowWidth, pDoc->m_WindowHeight);

    if ( GL_NO_ERROR != ::glGetError() )
    {
    ::AfxMessageBox("Error while trying to set viewport.");
    }
    ::glMatrixMode(GL_PROJECTION);
    ::glLoadIdentity();
    gluPerspective( 45.0f, pDoc->m_AspectRatio, 0.1f, 20.0f );

    if ( GL_NO_ERROR != ::glGetError() )
    {
		::AfxMessageBox("Error while trying to set viewing frustum.");
		return ;
    }
    ::glMatrixMode(GL_MODELVIEW);
    ::glLoadIdentity();
}

BOOL CGlmfcnView::makeCurrent()
{
	CGlmfcnDoc* pDoc = GetDocument();
    if ( FALSE == ::wglMakeCurrent(m_hDC, m_hRC ) )
        {
		::AfxMessageBox("wglMakeCurrent failed.");
        return FALSE;
        }
    ::glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    ::glClearDepth( 1.0f );
    ::glEnable( GL_DEPTH_TEST );
    
return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CGlmfcnView drawing

void CGlmfcnView::OnDraw(CDC* pDC)
{
	CGlmfcnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	glClearColor(0.1, 0.1, 0.1, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
    glLoadIdentity();
    const GLfloat mat_specular[] = { pDoc->m_Red, pDoc->m_Green, pDoc->m_Blue, 1.0};
    const GLfloat mat_dif[] = { pDoc->m_Red, pDoc->m_Green, pDoc->m_Blue, 1.0 };
    const GLfloat mat_shininess[] = { 50.0 };
    const GLfloat light_position[] = { pDoc->l_x, pDoc->l_y, pDoc->l_z, pDoc->l_w };
    const GLfloat light_direction[] = { pDoc->d_x, pDoc->d_y, pDoc->d_z };
    const GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
    const GLfloat light1_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_dif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
    glLightfv(GL_LIGHT1, GL_AMBIENT, mat_ambient);
    glEnable(GL_LIGHT1);
    
    glTranslatef(0.0, 0.0, -5.0);
    auxSolidSphere(pDoc->radius);
	glFlush();

	BOOL ok=SwapBuffers(m_hDC);
}

/////////////////////////////////////////////////////////////////////////////
// CGlmfcnView diagnostics

#ifdef _DEBUG
void CGlmfcnView::AssertValid() const
{
	CView::AssertValid();
}

void CGlmfcnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGlmfcnDoc* CGlmfcnView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGlmfcnDoc)));
	return (CGlmfcnDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGlmfcnView message handlers

int CGlmfcnView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
     InitializeOpenGL();
	
	return 0;
}


void CGlmfcnView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CGlmfcnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
    if ( 0 >= cx || 0 >= cy )
        {
        return;
        }

    // save the width and height of the current window
    pDoc->m_WindowWidth = cx;
    pDoc->m_WindowHeight = cy;

	myReshape();
}


BOOL CGlmfcnView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;//CView::OnEraseBkgnd(pDC);
}



void CGlmfcnView::OnViewSetlight()
{
    // TODO: Add your command handler code here
    CGlmfcnDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    SetLightPositionDlg S;
    S.l_x = pDoc->l_x;
    S.l_y = pDoc->l_y;
    S.l_z = pDoc->l_z;
    S.l_w = pDoc->l_w;
    int result = S.DoModal();
    if (result == IDOK) {
        pDoc->l_x = S.l_x;
        pDoc->l_y = S.l_y;
        pDoc->l_z = S.l_z;
        pDoc->l_w = S.l_w;
        Invalidate();
    }
}


void CGlmfcnView::OnViewSetlightDirection()
{
    // TODO: Add your command handler code here
    CGlmfcnDoc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    SetLightDirectionDlg S;
    S.d_x = pDoc->d_x;
    S.d_y = pDoc->d_y;
    S.d_z = pDoc->d_z;
    int result = S.DoModal();
    if (result == IDOK) {
        pDoc->d_x = S.d_x;
        pDoc->d_y = S.d_y;
        pDoc->d_z = S.d_z;
        Invalidate();
    }
}
