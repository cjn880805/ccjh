//zhen_zhu.h
//Sample for ITEM: ������


EQUIP_BEGIN(CIzhen_zhu);

virtual void create(int nFlag = 0)
{
	set_name( "����");
 	set_weight(8000);
                
	set("material", "cloth");
	set("unit", "��");
	set("long", "����һ�����飬��������Ө����");
	set("value", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp