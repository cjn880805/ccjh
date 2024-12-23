//ytjian.h

//Sample for ITEM: 倚天剑
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIytjian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "倚天剑");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(20000);		//set item weight
	
	set("unit", "把");
	set("value", 5000000);
	set("material", "steel");
	set("long", "这是一柄四尺来长的古剑，剑鞘上金丝镶着两个字“倚天”。整个剑身隐隐发出一层青气，剑未出鞘，已可见其不凡。");
   	set("wield_msg","直如矫龙吞水，长虹冠日一般，$n已在$N手中，天地为之变色。");
   	set("unwield_msg", "$N将$n插回腰间，华光顿敛，天地间只闻龙鸣。");
	set("unequip_msg",  "倚天剑幻作一道白光，「唰」地飞入剑鞘。" );
	//	init_sword(1000);
	set("apply/damage", 1000);					//set the modifiers of attribute
	
	set("no_drop", "如此宝贵的武器再世难求啊。");
	set("no_give", "送人？亏你想的出来！");
	set("no_put", "珍惜它吧。");
	set("no_duo",1);//不可以夺走

//	call_out(do_die, 5);	
	
};

virtual void owner_is_killed(CChar * killer)
{
	destruct(this);
}

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	if(!ob->query_temp("save"))//save---可以使用
		destruct(ob);
	else
		ob->call_out(do_die, 3600);
}

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



