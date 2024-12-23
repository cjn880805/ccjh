//18niou.h

//Sample for ITEM: 十八泥偶
//coded by Fisho
//data: 2000-10-30

//use macro ITEM_BEGIN(item_name) to declare equip
//and use macro ITEM_END end declare

//npc_name must use "CI-" begin since it belongs item class
ITEM_BEGIN(CI18niou);

void create(int nFlag = 0)		
{
	set_name( "十八泥偶");	

	set_weight(600);		

	set("unit", "盒");
	set("long", "这是一个小木盒，盒中并列着三排泥制玩偶，每排六个，共是一十八个。可以捏。");
	set("value", 5000);
	set("material", "mud");
	set("skill/name","force");	
	set("skill/exp_required",0l);
	set("skill/jing_cost",30);	
	set("skill/difficulty",20);	
	set("skill/max_skill",59);	
	set("skill/min_skill",30);  

};

int do_look(CChar * me)
{
	CItem::do_look(me);

	if(environment() == me)
	{
		AddMenuItem("捏碎", "$0nie $1", me);
		AddMenuItem("停止观察", "", me);
		SendMenu(me);
	}
	
	return 1;
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(strcmp(comm, "nie") == 0)
		return do_nie(me);
	return 0;
}

int do_nie(CChar * me)
{
	if(environment() != me) return 0;
	if(query_temp("yongren/rent"))return 0;

	load_item("18muou")->move(me);

	message_vision("$N轻轻一捏，刷刷刷几声，裹在泥人外面的粉饰、油彩和泥底纷纷掉落。露出一个裸体的木偶来。", me);
	
	destruct(this);
	return 1;
}

ITEM_END;
