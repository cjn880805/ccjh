//tieyanling.h
//Lanwood
//2001-01-09

ITEM_BEGIN(CItieyanling)

virtual void create(int nFlag = 0)		
{
	set_name("������", "tieyan ling");
    set_weight(500);
        
    set("unit", "��");
    set("long","����һ�����������ƣ��ɽ���ǩ����ƾ�˿�������ս��");
    set("material", "steel");
};

ITEM_END;
