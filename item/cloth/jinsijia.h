//jinsijia.h

//Sample for ITEM: ��˿��
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjinsijia);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��˿��");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(10000);		//set item weight
          
	set("unit", "��");
	set("value", 30000);
	set("apply/per", 4);
	set("material", "leather");
	set("apply/armor", 100);

};

virtual void owner_is_killed(CChar *me)
{
	if(me)
		tell_object(me,"ֻ����ǰ���һ��...������.....");

	destruct(this);
} 

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp