//zhen_zhu.h
//Sample for ITEM: 大珍珠


EQUIP_BEGIN(CIzhen_zhu);

virtual void create(int nFlag = 0)
{
	set_name( "珍珠");
 	set_weight(8000);
                
	set("material", "cloth");
	set("unit", "颗");
	set("long", "这是一颗珍珠，看起来晶莹亮泽。");
	set("value", 1);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp