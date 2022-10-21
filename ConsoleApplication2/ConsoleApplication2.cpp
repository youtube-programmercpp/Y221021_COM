//参照カウンタ
//reference counter
#include "Alpha.h"
int main()
{
	IAlpha* const pAlpha = CreateInstance();

	IBeta* pBeta;
	HRESULT hr = pAlpha->QueryInterface(__uuidof(pBeta), (void**) & pBeta);
	//成否判定…失敗判定は FAILED
	if (SUCCEEDED(hr)) {
		//成功した
		BOOL bOpen;
		if (SUCCEEDED(pBeta->IsOpen(&bOpen))) {
			if (bOpen) {
			}
			else {
			}
		}
		pBeta->Release();
	}

	pAlpha->Open();
	//COM の決まり：ポインタをコピーしたら AddRef
	IAlpha* const q = pAlpha;
	pAlpha->AddRef();//これで refcnt は 2 になる

	//pAlpha ポインタを破棄
	pAlpha->Release();//これで refcnt は 1 になる

	q->Test();
	//q ポインタを破棄
	q->Release();//これで refcnt は 0 になる
}
