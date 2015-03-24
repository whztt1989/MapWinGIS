// DrawingRectangle.h : Declaration of the CDrawingRectangle

#pragma once

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

// CDrawingRectangle
class ATL_NO_VTABLE CDrawingRectangle :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CDrawingRectangle, &CLSID_DrawingRectangle>,
	public IDispatchImpl<IDrawingRectangle, &IID_IDrawingRectangle, &LIBID_MapWinGIS, /*wMajor =*/ VERSION_MAJOR, /*wMinor =*/ VERSION_MINOR>
{
public:
	CDrawingRectangle()
	{
		_x = _y = _width = _height = 0.0;
		_visible = VARIANT_TRUE;
		_referenceType = dlScreenReferencedList;
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_DRAWINGRECTANGLE)


	BEGIN_COM_MAP(CDrawingRectangle)
		COM_INTERFACE_ENTRY(IDrawingRectangle)
		COM_INTERFACE_ENTRY(IDispatch)
	END_COM_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(get_X)(DOUBLE* pVal);
	STDMETHOD(put_X)(DOUBLE newVal);
	STDMETHOD(get_Y)(DOUBLE* pVal);
	STDMETHOD(put_Y)(DOUBLE newVal);
	STDMETHOD(get_Width)(DOUBLE* pVal);
	STDMETHOD(put_Width)(DOUBLE newVal);
	STDMETHOD(get_Height)(DOUBLE* pVal);
	STDMETHOD(put_Height)(DOUBLE newVal);
	STDMETHOD(get_Visible)(VARIANT_BOOL* pVal);
	STDMETHOD(put_Visible)(VARIANT_BOOL newVal);
	STDMETHOD(get_ReferenceType)(tkDrawReferenceList* pVal);
	STDMETHOD(put_ReferenceType)(tkDrawReferenceList newVal);

private:
	double _x;
	double _y;
	double _width;
	double _height;
    VARIANT_BOOL _visible;
	tkDrawReferenceList _referenceType;

};

OBJECT_ENTRY_AUTO(__uuidof(DrawingRectangle), CDrawingRectangle)
