//basi_shanyao.h

//Sample for ITEM °ÎË¿É½Ò©
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbasi_shanyao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "°ÎË¿É½Ò©");	//set item name
	
	set_weight(200);
	
	set("long", "Ò»ÅèÉ«ÈôÃµ¹å£¬ÌğÄÛÏãÄÛµÄ°ÎË¿É½Ò©¡£");
	set("unit", "Åè");
	set("value", 150);
	set("food_remaining", 4);
	set("food_supply", 40);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp