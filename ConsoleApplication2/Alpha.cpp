#include "Alpha.h"
#include <fstream>

//これは IAlpha インターフェイスの実装例
// IBeta インターフェイスも実装してみる
class Alpha : public IBeta {
	ULONG refcnt;
	std::ofstream file;
public:
	Alpha()
		: refcnt(1UL)
	{
	}
	HRESULT STDMETHODCALLTYPE QueryInterface
	( REFIID riid     //インターフェイスID (IID)
	, void** ppvObject//結果出力用ポインタ
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
		return S_OK;//成功したら S_OK
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
