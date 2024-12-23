ITEM_BEGIN(CItianmen_map);

void create(int nFlag = 0)
{
    set_name("天门设计图", "tianmen tu");
    set_weight(100);
    
	set("long", "一副发黄的设计图,据说有了此图就可以建造「玉虚门」。");
	set("value", 400);
}

int Can_Use()
{
	return 1;
}

int do_use(CChar * me, CContainer * target)
{
	if(!me->querymap("corps")) 
		return notify_fail("你必须是一宫之主方可使用「天门设计图」！");
	if(me->query("corps/level")!=1)
		return notify_fail("你必须是一宫之主方可使用「天门设计图」！");

	CContainer * corps = load_room(me->querystr("corps/id"));
	if(corps->query("index")!=1)
		return notify_fail("「天门设计图」只能由宫主方可使用！");

	CContainer * env = me->environment();
	if(! env) return 0;
	if(!EQUALSTR(env->querystr("area"),corps->querystr("area")))
		return notify_fail("「天门设计图」必须要在新月大殿中方可使用！");
	if(!EQUALSTR(env->querystr("name"),"新月大殿"))
		return notify_fail("「天门设计图」必须要在新月大殿中方可使用！");
	
	char msg[255];
	if(corps->query("level")>1)
		return notify_fail(snprintf(msg, 255,"你的「%s」似乎已经建造过了「玉虚门」！",corps->querystr("name")));
	if(corps->query("corps/repute")<250)
		return notify_fail(snprintf(msg, 255,"你的「%s」在江湖中的声望，还不够资格建造「玉虚门」！",corps->querystr("name")));
	if(corps->query("corps/money")<50000)
		return notify_fail(snprintf(msg, 255,"你的「%s」目前的财力，还没有足够的能力去建造「玉虚门」！",corps->querystr("name")));
	if(corps->query("corps/member_count")<10)
		return notify_fail(snprintf(msg, 255,"你的「%s」目前的势力，还没有足够的能力去建造「玉虚门」！",corps->querystr("name")));

	if(me->query("level") < 122) 
		return notify_fail("以你在江湖中的地位，还不够资格建设帮会！");
	if(me->query("repute") < -80000 ||me->query("repute") > 80000)
		return notify_fail("以你在江湖中的声望，还不够资格建设帮会！");
	if(me->query("威望") < 110)	
		return notify_fail("以你在江湖中的威望，还不够资格建设帮会！");
	if(me->query("balance") < 10000000l)
		return notify_fail("请在你的帐号里存足一千万！");

	me->add("balance", -10000000l);

	corps->set("level",2);
	corps->add("corps/money",-20000);
	corps->add("corps/repute",10);
	
	corps->set("玉虚门/level",1);
	corps->set("玉虚门/sh_hp",10000+me->query_temp("max_hp")+me->query("int")*100+me->query("str")*150+me->query("dex")*50+me->query("con")*200);
	corps->set("玉虚门/sh_mp",100+me->query("max_mp")/100);
	corps->set("玉虚门/sh_level",1);
	corps->set("玉虚门/sh_index",random(17));
	corps->set("玉虚门/sh_combat_exp",1);

	//随机生成侍剑的先天属性
	int num=random(7)+18;
	int count=84-num;
	corps->set("玉虚门/sh_str",num);
	num=random(7)+18;
	count=count-num;
	corps->set("玉虚门/sh_dex",num);
	num=random(7)+18;
	count=count-num;
	corps->set("玉虚门/sh_con",num);
	corps->set("玉虚门/sh_int",count);
	corps->set("玉虚门/sh_per",18+random(15));
	
	//动态更新出口
	char corps_id[40];

	sprintf(corps_id, "g2_玉虚门_%s", me->querystr("corps/id"));
	((CRoom *)corps)->remove_doors(snprintf(msg, 255,"g1_新月大殿_%s",me->querystr("corps/id")));
	((CRoom *)corps)->add_door("玉虚门",corps_id, me->querystr("corps/id"));
	
	corps->Save();

	CRoom * corps1= load_room(corps_id);
	
	corps1->set_name("玉虚门", corps_id);
	corps1->set("area", corps->querystr("area"));
	corps1->set("corps_id",corps->querystr("corps_id"));
	corps1->set("corps",1);
	corps1->set("level",corps->query("玉虚门/level"));
	corps1->del("fail_ob");
	corps1->remove_all_doors();
	corps1->setup();

	corps = load_room(snprintf(msg, 255,"g1_新月大殿_%s",me->querystr("corps/id")));

	((CRoom *)corps)->remove_doors(me->querystr("corps/id"));
	((CRoom *)corps)->add_door("玉虚门",corps_id,  "新月大殿");
	
	char msg1[512];
	message_vision("$HIR「天门设计图」发出一阵耀眼的光芒，然后消失了。",me);
	g_Channel.do_channel(this, NULL, "news", 
		snprintf(msg1, 512,"$HIC「%s」$HIW%s(%s)恭恭敬敬的将$HIC「天门设计图」$HIW放在新月大殿祭坛之上，俯身叩拜，口中默念：$HIR\n                        新月初升，如日中天                        天门洞开，玉虚立现\n                        飞莹流转，烟波浩渺                        赐我神宫，予我侍剑!\n$HIW一轮皎洁的月光射向祭坛，渐渐笼罩整个新月大殿，瞬息间地动山摇，一座牌楼从地底缓缓升起，牌楼上豁然三个镏金大字“$HIC玉虚门$HIW”。"
						,env->querystr("area"),me->name(),me->id()));
	
	//所有在场的人需要重新刷新一下场景,否则将无法出去
	DTItemList * list = env->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		target->move(env);
	}
	destruct(this);
	return 1;
}

ITEM_END;



