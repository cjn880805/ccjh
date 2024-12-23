//fojing11.h

//Sample for ITEM: 佛经
//coded by Fisho
//data: 2000-11-20

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIfojing11);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	char titles[][30] = {
		"般若经",
		"维摩经",
		"法华经",
		"华严经",
    //    "无量寿经",
    //    "大般涅磐经",
    //    "阿含经",
    //    "金刚经",
    //    "波罗蜜多心经",
	};

	set_name( titles[random(4)]);	//set item name

	set_weight(200);		//set item weight

	set("unit", "本");
	set("value", 500);
	set("long", "这是一册佛经。");
	set("material", "paper");
	set("skill/name", "buddhism");
	set("skill/exp_required", 0l);
	set("skill/jing_cost", 20);
	set("skill/difficulty", 20);
	set("skill/max_skill",100 );
	
};
 
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp