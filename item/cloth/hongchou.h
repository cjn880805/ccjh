//hongchou.h

//Sample for ITEM: 红绸
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIhongchou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "红绸");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(800);		//set item weight

	set("long", "一块很完整的红绸，但已经开始变色了。");
	set("unit", "件");
	set("material", "cloth");
	set("no_get", "这块红绸已经被牢牢的钉住了。");
	set("cloth_count",1);
};
/*******************************
int do_tear(string arg)
{
        object me , ob;
        me = this_player();
        if (arg == "hong chou" && !present("zhanyi", me) && query("cloth_count")>= 1)
        {
                add("cloth_count", -1);
                ob=new("/clone/book/zhanyi");
                ob->move("/d/meizhuang/dingduan");
                message_vision("$N把红绸撕开，发现里面包着一件衣服。\n", me);
                return 1;
        }
        else {
                message_vision("$N把红绸撕开，但里面什么都没有。\n", me);
                return 1;
             }
}

*******************************/
EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp