//guanfu.h
EQUIP_BEGIN(CIguanfu)

virtual void create(int nFlag = 0)		
{
	set_name("官服", "guan fu");
	
	set("wield_position", WIELD_ARMOR);		
	set("unit", "件");
	set("material", "leather");

	set("long",	"一件青色官服，前裾盘龙，后裾描凤。");
	set_weight(1000);
	set("value", 1);
	
	set("apply/armor",10);
	set("apply/per",2);

	set("wield_msg","穿上了$n，$N摇身一变，俨然似一个真正的官场显贵模样。");
 	set("unwield_msg", "$N脱下了$n，官爷的威风立时荡然无存！");

	set("no_beg",1);

	call_out(do_armor, 5);
	call_out(do_die, 3600);	

};

static void do_armor(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * env=(ob->environment())->environment();

	if(ob->query("equipped")==WIELD_ARMOR)
	{
		if(DIFFERSTR(ob->querystr("环境"),env->name(1)) )
		{
			if(DIFFERSTR("fight_room",env->querystr("base_name")))
			{
				ob->set("环境",env->name(1));
				
				CContainer * me=ob->environment();
				
				DTItemList * list = env->Get_ItemList();  
				POSITION p = list->GetHeadPosition(); 
				while(p) 
				{ 
					CContainer * obj = list->GetNext(p);
					if(! obj->is_character()) continue; 
					CChar * target = (CChar *)obj;  
					if(userp(target))	continue;
					char msg[255];
					message_vision(snprintf(msg, 255,"$N：小民$N叩见%s大人！",(CChar *)me->querystr("name")),target, (CChar *)me);
				}
			}
		}
	}
	ob->call_out(do_armor, 5);
}

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
