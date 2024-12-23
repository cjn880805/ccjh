//rose.h

//Sample for ITEM: ��õ��
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIrose);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��õ��");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(1500);		//set item weight
   
	set("unit", "��");
	set("long","һ��ʢ���ĺ�õ�壬�������Ρ�������һ��СС�ķۺ�練�������ϸϸһ��С�֣���ӭ�ص���ļҡ�");
	set("value", 2);
	set("material", "plant");
	set("apply/armor", 0l);
	set("apply/per", 3);
	set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�");
	set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp