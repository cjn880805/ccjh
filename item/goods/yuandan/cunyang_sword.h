//cunyang_sword.h
EQUIP_BEGIN(CIcunyang_sword)

virtual void create(int nFlag = 0)		
{
	set_name("纯阳剑", "cun yang jian");
	
    set("wield_position", WIELD_RIGHT_HAND);	
	set("skill_type", "sword");	
	set_weight(8000);
	
	set("unit", "把");
	set("long", "吕纯阳赠送的一柄宝剑，通体透红，神光闪现！");
	set("value", 1);

	set("apply/damage", random(101)+300);
	set("apply/per", 5);

	set("material", "steel");
	set("wield_msg", "$N掣出一把$n，天地间为之一亮。$N在剑光的映照下，威风凛凛，气势逼人。");
	set("unwield_msg", "$N把$n反别身后，华光顿敛，一切恢复正常。");

	call_out(do_die, 3600);	

};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	//检查系统时间
	time_t t;	
	struct tm * newtime;

	time(&t);
	newtime = localtime(&t); 

	int month = newtime->tm_mon + 1;
	int day = newtime->tm_mday;

	if(month!=1 ||day>13)
	{
		CContainer * env = load_room("jy");
		if(!env->query("活动"))
			destruct(ob);
	}
	else
		ob->call_out(do_die, 3600);
}
EQUIP_END;
