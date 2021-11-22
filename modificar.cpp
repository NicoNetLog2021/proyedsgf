#include "modificar.h"
#include "Sistema.h"

//(*InternalHeaders(modificar)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(modificar)
const long modificar::ID_STATICTEXT1 = wxNewId();
const long modificar::ID_STATICTEXT2 = wxNewId();
const long modificar::ID_TEXTCTRL1 = wxNewId();
const long modificar::ID_TEXTCTRL2 = wxNewId();
const long modificar::ID_TEXTCTRL3 = wxNewId();
const long modificar::ID_TEXTCTRL4 = wxNewId();
const long modificar::ID_STATICTEXT3 = wxNewId();
const long modificar::ID_STATICTEXT4 = wxNewId();
const long modificar::ID_STATICTEXT5 = wxNewId();
const long modificar::ID_TOGGLEBUTTON1 = wxNewId();
const long modificar::ID_TOGGLEBUTTON2 = wxNewId();
const long modificar::ID_TOGGLEBUTTON3 = wxNewId();
const long modificar::ID_STATICTEXT6 = wxNewId();
const long modificar::ID_TOGGLEBUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(modificar,wxFrame)
	//(*EventTable(modificar)
	//*)
END_EVENT_TABLE()

modificar::modificar(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(modificar)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(399,467));
	Move(wxDefaultPosition);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Complete todos los datos !!! "), wxPoint(144,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Ingrese el codigo"), wxPoint(56,96), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	tc12 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(264,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	tc15 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(264,168), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	tc16 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(264,224), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	tc17 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(264,280), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Stock minimo:"), wxPoint(56,176), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Stock maximo:"), wxPoint(56,232), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Precio:"), wxPoint(56,288), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	ToggleButton1 = new wxToggleButton(this, ID_TOGGLEBUTTON1, _("Enviar"), wxPoint(48,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON1"));
	ToggleButton2 = new wxToggleButton(this, ID_TOGGLEBUTTON2, _("Nuevo"), wxPoint(160,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON2"));
	ToggleButton3 = new wxToggleButton(this, ID_TOGGLEBUTTON3, _("Cerrar"), wxPoint(280,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON3"));
	st12 = new wxStaticText(this, ID_STATICTEXT6, _("Label"), wxPoint(168,408), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	ToggleButton4 = new wxToggleButton(this, ID_TOGGLEBUTTON4, _("Buscar"), wxPoint(160,128), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TOGGLEBUTTON4"));

	Connect(ID_TOGGLEBUTTON4,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&modificar::OnToggleButton4Toggle);
	//*)
}

modificar::~modificar()
{
	//(*Destroy(modificar)
	//*)
}


void modificar::OnToggleButton4Toggle(wxCommandEvent& event)
{

    Sistema reg,sis;
    fstream arch;
    int c,ex,sMin,sMax;//codigo
    double p;
    wxString descr;

    arch.open("sistema.dat",ios::app|ios::binary); // abrir archivo
    if(!arch)
    {
        st12->SetLabel("Error de apertura de archivo");
        Close();
    }
    arch.close();
    arch.open("sistema.dat",ios::in|ios::out |ios::binary);
    if(!arch)
    {
        st12->SetLabel("Error de apertura de archivo");
        Close();
    }
    wxString str = tc12->GetValue();
    c=wxAtoi(str);
    sis.buscar(arch);
    if(!arch.eof())
            st12->SetLabel("Modificacion inexistente");

    else
        {
             arch.seekg(arch.tellg()-sizeof(Sistema),ios::beg);
             arch.read(reinterpret_cast<char *>(&reg),sizeof(Sistema));
             wxString str2 = tc4->GetValue();
             sMin=wxAtoi(str);
             wxString str3 = tc8->GetValue();
            sMax=wxAtoi(str);
            str = tc6->GetValue();
            str.ToDouble(&p);
            arch.seekp(arch.tellg()-sizeof(Sistema),ios::beg);
                arch.write(reinterpret_cast<const char *>(&reg),sizeof(Sistema));


        }
}
