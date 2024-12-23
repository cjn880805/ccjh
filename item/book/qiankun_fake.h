//qiankun_fake.h

//Sample for ITEM: 假乾坤大挪移心法
//coded by cat
//data: 2001-3-16

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CIqiankun_fake);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "羊皮");	//set item name

 	set_weight(600);		//set item weight

	set("unit", "张");
 	set("long", "这是一张羊皮，一面有毛，一面光滑。一眼看上去似乎没有什么特别之处，可能你要找个识货之人帮你鉴定一下。");
	set("value",  50000 );
	set("material", "paper");

};


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp