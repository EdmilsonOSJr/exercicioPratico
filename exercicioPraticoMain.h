/***************************************************************
 * Name:      exercicioPraticoMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2020-11-10
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef EXERCICIOPRATICOMAIN_H
#define EXERCICIOPRATICOMAIN_H

//(*Headers(exercicioPraticoFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class exercicioPraticoFrame: public wxFrame
{
    public:

        exercicioPraticoFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~exercicioPraticoFrame();

    private:

        //(*Handlers(exercicioPraticoFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnescolheNotaSliderCmdScrollChanged(wxScrollEvent& event);
        void OncomparaNotaButtonClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(exercicioPraticoFrame)
        static const long ID_SLIDER1;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT3;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(exercicioPraticoFrame)
        wxButton* comparaNotaButton;
        wxPanel* Panel1;
        wxSlider* escolheNotaSlider;
        wxStaticLine* StaticLine1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* notaDoTesteStaticTex;
        wxStaticText* notaEscolhidaStaticText;
        wxStaticText* precisoStaticText;
        wxStaticText* valorDoTesteStaticText;
        wxStaticText* valorExcolhidoStaticText;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // EXERCICIOPRATICOMAIN_H
