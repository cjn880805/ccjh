//sengmao.h

//Sample for ITEM: É®Ã±
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIsengmao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "É®Ã±");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(500);		//set item weight
           
    set("unit", "¶¥"); 
	set("long", "ÕâÊÇÒ»¶¥²ØÉ®´÷µÄÉ®Ã±¡£"); 
	set("value", 100); 
	set("material", "head"); 
	set("apply/armor", 10); 
	set("xueshan",1); 
	 
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp