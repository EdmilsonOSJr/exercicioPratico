/***************************************************************
 * Name:      exercicioPraticoMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2020-11-10
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "exercicioPraticoMain.h"
#include <wx/msgdlg.h>
#include <wx/textfile.h>
#include <wx/wfstream.h>
#include <wx/txtstrm.h>
#include <stdio.h>
#include <stdlib.h>



//(*InternalHeaders(exercicioPraticoFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(exercicioPraticoFrame)
const long exercicioPraticoFrame::ID_SLIDER1 = wxNewId();
const long exercicioPraticoFrame::ID_STATICTEXT1 = wxNewId();
const long exercicioPraticoFrame::ID_BUTTON1 = wxNewId();
const long exercicioPraticoFrame::ID_STATICTEXT2 = wxNewId();
const long exercicioPraticoFrame::ID_STATICTEXT4 = wxNewId();
const long exercicioPraticoFrame::ID_STATICLINE1 = wxNewId();
const long exercicioPraticoFrame::ID_STATICTEXT5 = wxNewId();
const long exercicioPraticoFrame::ID_STATICTEXT6 = wxNewId();
const long exercicioPraticoFrame::ID_STATICTEXT7 = wxNewId();
const long exercicioPraticoFrame::ID_STATICTEXT3 = wxNewId();
const long exercicioPraticoFrame::ID_PANEL1 = wxNewId();
const long exercicioPraticoFrame::idMenuQuit = wxNewId();
const long exercicioPraticoFrame::idMenuAbout = wxNewId();
const long exercicioPraticoFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(exercicioPraticoFrame,wxFrame)
    //(*EventTable(exercicioPraticoFrame)
    //*)
END_EVENT_TABLE()

exercicioPraticoFrame::exercicioPraticoFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(exercicioPraticoFrame)
    wxBoxSizer* BoxSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("Teste de pontuação"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetMaxSize(wxSize(-1,-1));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(407,293), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    escolheNotaSlider = new wxSlider(Panel1, ID_SLIDER1, 0, 0, 100, wxPoint(184,16), wxSize(200,37), wxSL_LABELS|wxSL_SELRANGE, wxDefaultValidator, _T("ID_SLIDER1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Escolha a nota de hispótese:"), wxPoint(24,32), wxSize(152,24), 0, _T("ID_STATICTEXT1"));
    comparaNotaButton = new wxButton(Panel1, ID_BUTTON1, _("Comparar Nota"), wxPoint(288,216), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    comparaNotaButton->Disable();
    notaEscolhidaStaticText = new wxStaticText(Panel1, ID_STATICTEXT2, _("0"), wxPoint(208,112), wxSize(32,16), 0, _T("ID_STATICTEXT2"));
    notaEscolhidaStaticText->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    notaEscolhidaStaticText->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    notaDoTesteStaticTex = new wxStaticText(Panel1, ID_STATICTEXT4, _("0"), wxPoint(208,152), wxSize(32,16), 0, _T("ID_STATICTEXT4"));
    notaDoTesteStaticTex->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    notaDoTesteStaticTex->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(0,72), wxSize(408,8), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    valorExcolhidoStaticText = new wxStaticText(Panel1, ID_STATICTEXT5, _("Valor escolhido:"), wxPoint(40,112), wxSize(88,16), 0, _T("ID_STATICTEXT5"));
    precisoStaticText = new wxStaticText(Panel1, ID_STATICTEXT6, _("Precisão:"), wxPoint(72,192), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT7, _("0%"), wxPoint(208,192), wxSize(32,16), 0, _T("ID_STATICTEXT7"));
    StaticText2->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    StaticText2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INACTIVEBORDER));
    valorDoTesteStaticText = new wxStaticText(Panel1, ID_STATICTEXT3, _("Valor do teste SUS:"), wxPoint(24,152), wxSize(112,16), 0, _T("ID_STATICTEXT3"));
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxSHAPED|wxFIXED_MINSIZE, 5);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_SLIDER1,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&exercicioPraticoFrame::OnescolheNotaSliderCmdScrollChanged);
    Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&exercicioPraticoFrame::OnescolheNotaSliderCmdScrollChanged);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&exercicioPraticoFrame::OncomparaNotaButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&exercicioPraticoFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&exercicioPraticoFrame::OnAbout);
    //*)
}

exercicioPraticoFrame::~exercicioPraticoFrame()
{
    //(*Destroy(exercicioPraticoFrame)
    //*)
}

void exercicioPraticoFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void exercicioPraticoFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void exercicioPraticoFrame::OnescolheNotaSliderCmdScrollChanged(wxScrollEvent& event)
{
    // Ao mudar o valor do slider o valor é colocado dentro da região de texto notaEscolhidaTextCtrl.
    notaEscolhidaStaticText->SetLabel(wxString::Format("%d",escolheNotaSlider->GetValue()));

    // Verifica se o slider está com um valor maior ou menor que 0.
    if(escolheNotaSlider->GetValue()>0)
        comparaNotaButton->Enable(true);// se maior que 0 botão para comparar é ativado.
    else
        comparaNotaButton->Enable(false);// se igual ou menor que 0 o botão para comparar é desativado.
}

// Retorna a nota total de um participante.
int notaParticipante(wxString linha, wxString delimitador)
{
    int valorTotal = 0, nota = 0;
    int cont =  0;
    size_t pos = 0;
    wxString token;

    // Loop que percorre os elementos de uma linha do arquivo.
    while ((pos = linha.find(delimitador)) != std::string::npos) {
        if(cont!=0)
        {
            //  Pega um elemento.
           token = linha.substr(0, pos);
           if(cont%2==0)
                nota = (5 - wxAtoi(token.substr(1,1)));// Para perguntas pares 5 é subtraído da nota.
           else
                nota = (wxAtoi(token.substr(1,1)) - 1);// Para perguntas ímpares é subtraído 1 da nota.

           valorTotal+=nota;// soma todos as notas de um usuário.
           linha.erase(0, pos + delimitador.length());// apaga o elemento da linha.

        }
        else
        {
            // Descarta o primeiro elemento da linha.
            token = linha.substr(0, pos);
            linha.erase(0, pos + delimitador.length());
        }

        cont++;

    }

    // Pega a última nota.
    nota = ( 5 - wxAtoi(linha.substr(1,1)));
    valorTotal+=nota;

    return valorTotal;
}


// Abre arquivo para ter acesso as notas de score SUS.
void manipulaArquivo(int *valorDoTeste)
{
    wxFileInputStream entrada(wxT("arq\\teste.csv"));// abre o auquivo .csv do score SUS.

    wxTextInputStream  text( entrada, wxT("\x09"),wxConvUTF8);

    int valorTotal=0,// soma de todas as notas dos participantes.
        numDePessoas = 0;// calcula o número de participantes do SUS.

    wxString line = text.ReadLine();// descarta a primeira linha do arquivo.

    while(entrada.IsOk() && !entrada.Eof())// caminha pelo arquivo.
    {
        line = text.ReadLine();

        // As notas de cada participante deve ser multiplicado por 2,5.
        valorTotal+=notaParticipante(line,",")*2.5;

        numDePessoas++;// calcula o total de participantes do SUS. Cada um representado por uma linha.
    }

    *valorDoTeste = valorTotal/numDePessoas;// Média de todas as notas.
}


// Evento de clique no botão
void exercicioPraticoFrame::OncomparaNotaButtonClick(wxCommandEvent& event)
{
    // Valor do score SUS.
    int valorDoTeste;

    // Pega a nota que o usuário estipulou.
    int notaUsuario = wxAtoi(notaEscolhidaStaticText->GetLabel());

    // Calcula o valor do score SUS.
    manipulaArquivo(&valorDoTeste);

    // Fornece a nota do score SUS para o usuário.
    notaDoTesteStaticTex->SetLabel(wxString::Format("%d",valorDoTeste));

    // Fornece o quanto o usuário se aproximou do valor verdadeiro.
    StaticText2->SetLabel(wxString::Format("%d %%", notaUsuario*100/valorDoTeste));
}
