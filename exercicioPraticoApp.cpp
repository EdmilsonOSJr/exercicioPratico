/***************************************************************
 * Name:      exercicioPraticoApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2020-11-10
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "exercicioPraticoApp.h"

//(*AppHeaders
#include "exercicioPraticoMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(exercicioPraticoApp);

bool exercicioPraticoApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	exercicioPraticoFrame* Frame = new exercicioPraticoFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
