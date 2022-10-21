#include "Alpha.h"
#include <fstream>

//����� IAlpha �C���^�[�t�F�C�X�̎�����
// IBeta �C���^�[�t�F�C�X���������Ă݂�
class Alpha : public IBeta {
	ULONG refcnt;
	std::ofstream file;
public:
	Alpha()
		: refcnt(1UL)
	{
	}
	HRESULT STDMETHODCALLTYPE QueryInterface
	( REFIID riid     //�C���^�[�t�F�C�XID (IID)
	, void** ppvObject//���ʏo�͗p�|�C���^
	)
	{
		if (riid == __uuidof(IAlpha) || riid == __uuidof(IUnknown)) {
			(reinterpret_cast<IAlpha*&>(*ppvObject) = this)->AddRef();
			return S_OK;
		}
		else if (riid == __uuidof(IBeta)) {
			(reinterpret_cast<IBeta*&>(*ppvObject) = this)->AddRef();
			return S_OK;
		}
		else
			return E_NOINTERFACE;
	}

	ULONG STDMETHODCALLTYPE AddRef() override
	{
		return ++refcnt;
	}
	ULONG STDMETHODCALLTYPE Release() override
	{
		const auto result = --refcnt;
		if (result == 0)
			delete this;
		return result;
	}

	HRESULT STDMETHODCALLTYPE Open() override
	{
		file.open("nul");
		return S_OK;//���������� S_OK
	}
	HRESULT STDMETHODCALLTYPE Test() override
	{
		file << "TEST\n";
		return S_OK;
	}
	HRESULT STDMETHODCALLTYPE IsOpen(BOOL* pResult) override
	{
		if (pResult) {
			*pResult = file.good();
			return S_OK;
		}
		else
			return E_POINTER;
	}
};
IAlpha* CreateInstance()
{
	return new Alpha;
}
