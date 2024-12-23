// writen by HuaKua-Wang
// Email: huakui@china.com

#ifndef PLEX_H
#define PLEX_H

typedef unsigned int UINT;
typedef unsigned char BYTE;

struct CPlex
{
	CPlex * pNext;
	 void* data() {
        return this;  // 假设返回当前对象的指针
    }
	static CPlex * Create(CPlex*& pHead, UINT nMax, UINT cbElement) {
        // 创建新的 CPlex 实例并初始化
        CPlex* p = new CPlex;
        p->pNext = pHead;
        pHead = p;
        return p;
    }
	void FreeDataChain() {
        CPlex* p = this;
        while (p != nullptr) {
            CPlex* pNext = p->pNext;
            delete p;
            p = pNext;
        }
    }
};

#endif
