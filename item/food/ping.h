//ping.h

//Sample for ITEM �佬ƿ
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIping);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�佬ƿ");	//set item name

	set_weight(4500);
	
	set("unit", "��");
	set("value", 0l);
	set("jian",5) ;
	set("material", "��");
	set("long", "����һ�����Ϲ������ɵ�Сƿ����δ�ο�ƿ�����Ϳ����ŵ�һ��Ũ������ζ�������������䡣") ;
 	
};

virtual int do_use(CChar * me,char * arg)
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp