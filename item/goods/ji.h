//zhupi.h

//use macro ITEM_BEGIN(item_name) to declare room
//and use macro ITEM_END end declare
ITEM_BEGIN(CIJi);

//npc_name must use "CI-" begin since it belongs npc class
//Example: ��Ƥ named "CIXiangYang_ZhuPi"

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Сĸ��");	//set item name
	set("value", 100);		//set item value
	
	set("long",	"һֻ���������Сĸ���������������л������Ϻ����ӡ�");
	set("unit", "ֻ");
	set_weight(200);
};


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp