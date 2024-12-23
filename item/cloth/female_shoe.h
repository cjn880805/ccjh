//female_shoe.h

//Sample for ITEM 绣花小鞋
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIFemaleShoe);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "绣花小鞋");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(900);		//set item weight

	set("material", "cloth");
	set("unit", "双");
	set("long", "一双女人穿的缝制得很精美的绣花鞋。");
	set("value", 300);
	set("apply/armor", 1 );
	set("female_only", 1);
     	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp