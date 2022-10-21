#pragma once
#include <Windows.h>
#include <Ole2.h>
class __declspec(uuid("{BA26B256-65D1-4E55-812D-A77C678912C0}"))      IAlpha : public IUnknown{
public:
	virtual HRESULT STDMETHODCALLTYPE Open() = 0;//“®ŽŒ‚Ì open
	virtual HRESULT STDMETHODCALLTYPE Test() = 0;
};
class __declspec(uuid("{C830A995-F577-49AC-801E-10C3D1D49EF3}")) IBeta : public IAlpha{
public:
	virtual HRESULT STDMETHODCALLTYPE IsOpen(BOOL* pResult) = 0;//Œ`—eŽŒ‚Ì open
};
